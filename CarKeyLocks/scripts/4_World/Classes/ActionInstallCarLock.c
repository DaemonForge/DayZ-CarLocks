class ActionInstallCarLock extends ActionContinuousBase {
	
	string DoorDisplayName = "";
	void ActionInstallCarLock()
	{
		m_CallbackClass = ActionLockDoorsCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_HIGH;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}
	
	
	override string GetText()
	{
		return "Install Lock on " + DoorDisplayName;
	}
	
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (!target) return false;
		CarDoor carDoor;
		CarLockKit keyKit;
		if ( Class.CastTo(carDoor, target.GetObject()) && Class.CastTo(keyKit,item)){
			DoorDisplayName = carDoor.GetDisplayName();
			string classType = carDoor.GetType();
			classType.ToLower();
			return (!classType.Contains("hood") && keyKit.CanAssignKey() && carDoor.CanHaveKeyAssigned());
		}
		return false;
	}
	
	override bool ActionConditionContinue( ActionData action_data )
	{	
		return super.ActionConditionContinue( action_data );
	}
	
	
	override void OnFinishProgressServer( ActionData action_data )
	{	
		super.OnFinishProgressServer( action_data );
		CarDoor carDoor;
		CarLockKit keyKit;
		if (Class.CastTo(carDoor, action_data.m_Target.GetObject()) && Class.CastTo(keyKit,action_data.m_MainItem) && keyKit.CanAssignKey() && carDoor.CanHaveKeyAssigned()){
			keyKit.AssignKeyToDoor(carDoor);
			keyKit.AddQuantity(-1);
		}
	}
	
}