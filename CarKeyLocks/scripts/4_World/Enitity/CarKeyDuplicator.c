class CarKeyDuplicator extends ItemBase {
	
	
	static const int DUPLICATIONCOSTS = 100;
	static const string DUPLICATIONCURRENCY = "Coins";
	
	
	override void EEInit()
	{
		super.EEInit();
		if (GetGame().IsDedicatedServer()){
			SetLifetime(3888000);
			array<Object> objects = new array<Object>;
			array<CargoBase> proxyCargos = new array<CargoBase>;
			GetGame().GetObjectsAtPosition3D(GetPosition(), 0.15, objects, proxyCargos);
			for (int i = 0; i < objects.Count(); i++){
				CarKeyDuplicator duplicator;
				if (Class.CastTo(duplicator, objects.Get(i))){
					if (duplicator != this){
						Print("Found Duplicate Duplicator deleting it");
						GetGame().ObjectDelete(duplicator);
					}
				}
			}
		}
	}
	void DuplicateKeys(PlayerBase player){
		if (player.UGetPlayerBalance(DUPLICATIONCURRENCY) >= DUPLICATIONCOSTS){
			CarKey masterKey;
			CarKey dupKey;
			if (player && Class.CastTo(masterKey, FindAttachmentBySlotName("Att_CarKeyMaster")) && Class.CastTo(dupKey, FindAttachmentBySlotName("Att_CarKey"))){
				if (masterKey.IsMasterKey() && masterKey.HasBeenAssigned() && !dupKey.HasBeenAssigned()){
					player.URemoveMoney(DUPLICATIONCURRENCY,DUPLICATIONCOSTS);
					CarKey.DuplicateKey(masterKey,dupKey);
				}
			}
			
		}
	}
	
	
	
	bool CanDuplicateKeys(PlayerBase player){
		int master = InventorySlots.GetSlotIdFromString("Att_CarKeyMaster");
		int dup = InventorySlots.GetSlotIdFromString("Att_CarKey");
		CarKey masterKey;
		CarKey dupKey;
		if (player && Class.CastTo(masterKey, FindAttachmentBySlotName("Att_CarKeyMaster")) && Class.CastTo(dupKey, FindAttachmentBySlotName("Att_CarKey"))){
			return (masterKey.IsMasterKey() && masterKey.HasBeenAssigned() && !dupKey.HasBeenAssigned() && player.UGetPlayerBalance(DUPLICATIONCURRENCY) >= DUPLICATIONCOSTS);
		}
		return false;
	}
	
	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
	{	
		CarKey key;
		if (slotId != -1 && slotId == InventorySlots.GetSlotIdFromString("Att_CarKeyMaster") && Class.CastTo(key,attachment)){
			return (key.IsMasterKey() && key.HasBeenAssigned());
		}
		if (slotId != -1 && slotId == InventorySlots.GetSlotIdFromString("Att_CarKey") && Class.CastTo(key,attachment)){
			return !key.HasBeenAssigned();
		}
		return super.CanReceiveAttachment( attachment, slotId );
	}
	
	
	
	override bool CanPutInCargo( EntityAI parent ) {
		return false;
	}
	
	override bool CanPutIntoHands( EntityAI parent ) {
		return false;
	}
	

	override void SetActions() {
		super.SetActions();
		AddAction(ActionDuplicateKey);
	}
}