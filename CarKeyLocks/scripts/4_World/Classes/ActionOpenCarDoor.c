modded class ActionOpenCarDoorsOutside
{
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
		if (super.ActionCondition(player, target, item)){
	        CarDoor door;
			CarKey key;
	        if (Class.CastTo(door, target.GetObject())) {
	            if (door.IsDoorLocked()){
	                return (Class.CastTo(key,player.GetItemInHands()) && door.IsKeyValid(key);
				}
	        }
			return true;
		}
        return false;
    }
};