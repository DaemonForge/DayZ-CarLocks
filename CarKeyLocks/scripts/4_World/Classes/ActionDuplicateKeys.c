class ActionDuplicateKey: ActionContinuousBase {

	void ActionDuplicateKey()
	{
		m_CallbackClass = ActionManipulateFlagCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTCursor;
		m_ConditionItem = new CCINone;
	}
	
	override string GetText()
	{
		return "Duplicate Key (1 Sliver)";
	}
	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	
	override bool HasTarget()
	{
		return true;
	}
	
	override bool HasProgress()
	{
		return true;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		CarKeyDuplicator duplicator;
		if (Class.CastTo(duplicator, target.GetObject())){
			return duplicator.CanDuplicateKeys(player);
		}
		return false;
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		CarKeyDuplicator duplicator;
		if (action_data.m_Target && Class.CastTo(duplicator, action_data.m_Target.GetObject())){
			duplicator.DuplicateKeys(action_data.m_Player);
		}
	}
}