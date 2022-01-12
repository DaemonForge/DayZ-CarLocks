class ActionToggleLockCar: ActionContinuousBase
{	
	bool IsUnlocking = false;
	void ActionToggleLockCar()
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
		if (IsUnlocking){
			return "#unlock";
		}
		return "#lock_door";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		CarDoor carDoor;
		CarKey key;
		if ( Class.CastTo(carDoor, target.GetObject()) && Class.CastTo(key,item) && !carDoor.IsRuined() && carDoor.IsAttachedToCar() && carDoor.IsKeyValid(key) ){
			IsUnlocking = carDoor.IsDoorLocked();
			return true;
		}
        return false;
	}
	
	override void OnFinishProgressServer( ActionData action_data ) {	
		CarDoor carDoor;
		CarKey key;
		if ( Class.CastTo(carDoor, action_data.m_Target.GetObject()) && Class.CastTo(key,action_data.m_MainItem) && !carDoor.IsRuined() && carDoor.IsAttachedToCar() && carDoor.IsKeyValid(key) ){
			carDoor.SetDoorLocked(!carDoor.IsDoorLocked());
		}
	}
};