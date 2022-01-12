class CfgPatches
{
  class CarKeyLocks
  {
    requiredAddons[]={ }; 
  };
};

class CfgMods
{
  class CarKeyLocks
  {
    name="CarKeyLocks";
    type="mod"
	dependencies[]={ "Game", "World", "Mission" };
	class defs
	{
		class imageSets
		{
			files[] =
			{
				"CarKeyLocks/gui/KeyLock_ghost.imageset"
			};
		};
		class gameScriptModule
        {
			value = "";
            files[]={
				"CarKeyLocks/scripts/3_Game"
			};
        };
		class worldScriptModule
        {
            value="";
            files[]={ 
				"CarKeyLocks/scripts/4_World" 
			};
        };
	    class missionScriptModule
        {
            value="";
            files[]={
				"CarKeyLocks/scripts/5_Mission" 
			};
        };
    };
  };
};
class CfgVehicles
{
	class Inventory_Base;
	class CarKey: Inventory_Base
	{
		scope = 2;
		displayName = "Car Key";
		descriptionShort = "";
		model = "CarKeyLocks\data\key\CarKey.p3d";
		inventorySlot[] = {"Att_CarKey"};
		itemSize[] = {1,2};
		weight = 350;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
	};
	class CarLockKit: Inventory_Base
	{
		scope = 2;
		displayName = "Car Lock Kit";
		descriptionShort = "A kit that contains a locking mechanism for car doors and trunks, attach your key to pair the lock with it.";
		model = "CarKeyLocks\data\box\box.p3d";
		attachments[]={"Att_CarKey"};
		itemSize[] = {3,2};
		weight = 300;
		destroyOnEmpty = 1;
		varQuantityInit = 4.0;
		varQuantityMin = 0.0;
		varQuantityMax = 4.0;
		canBeSplit = 0;
		stackedRandom = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
	};
};

class CfgSlots
{
	class Slot_Att_CarKey
	{
		name = "Att_CarKey";
		displayName = "Car Key";
		ghostIcon = "set: keylock_ghost image: key";
	};
};