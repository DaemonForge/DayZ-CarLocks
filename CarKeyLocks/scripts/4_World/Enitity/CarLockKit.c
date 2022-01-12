class CarLockKit extends ItemBase {
	
	
	void AssignKeyToDoor(CarDoor door){
		if (!CanAssignKey() || !door){return;}
		GetKey().AssignToDoor(door);
	}
	
	bool CanAssignKey(){
		return ((GetKey() && !GetKey().IsRuined()) && GetQuantity() >= 1);
	}
	
	CarKey GetKey() {
		return CarKey.Cast(FindAttachmentBySlotName("Att_CarKey"));
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionInstallCarLock);
	}
}