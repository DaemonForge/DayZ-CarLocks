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
				"CarKeyLocks/gui/keylock_ghost.imageset"
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
		inventorySlot[] = {"Att_CarKey","Att_CarKeyMaster"};
		itemSize[] = {2,1};
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
		destroyOnEmpty = 0;
		varQuantityInit = 5.0;
		varQuantityMin = 0.0;
		varQuantityMax = 5.0;
		varQuantityDestroyOnMin = 0;
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
	class CarKeyDuplicator: Inventory_Base
	{
		scope = 2;
		displayName = "Car Key Cutter";
		descriptionShort = "A device for cutting keys. Cutting a key costs 1 Silver Coins or 100 copper coins";
		model = "CarKeyLocks\data\grinder\grinder.p3d";
		attachments[]={"Att_CarKeyMaster","Att_CarKey"};
		weight = 30000;
	};
	/*class CarDoor;
	class HatchbackDoors_Driver: CarDoor
	{
		scope = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1500;
				};
			};
			class DamageZones
			{
				class Doors
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0.75;
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage = 0.05;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.05;
					};
				};
			};
		};
		
	};
	
	class HatchbackTrunk: CarDoor
	{
		scope = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
			class DamageZones
			{
				class Doors
				{
					class Health
					{
						hitpoints = 3000;
						transferToGlobalCoef = 0.75;
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage = 0.05;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.05;
					};
				};
			};
		};
		
	};
	class CivSedanDoors_Driver: CarDoor
	{
		scope = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1500;
				};
			};
			class DamageZones
			{
				class Doors
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0.75;
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage = 0.05;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.05;
					};
				};
			};
		};
		
	};
	class CivSedanTrunk: CarDoor
	{
		scope = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
			class DamageZones
			{
				class Doors
				{
					class Health
					{
						hitpoints = 3000;
						transferToGlobalCoef = 0.75;
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage = 0.05;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.05;
					};
				};
			};
		};
		
	};
	class Hatchback_02_Door_1_1: CarDoor
	{
		scope = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1500;
				};
			};
			class DamageZones
			{
				class Doors
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0.75;
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage = 0.05;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.05;
					};
				};
			};
		};
		
	};
	class Sedan_02_Door_1_1: CarDoor
	{
		scope = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1500;
				};
			};
			class DamageZones
			{
				class Doors
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0.75;
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage = 0.05;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.05;
					};
				};
			};
		};
		
	};
	class Sedan_02_Trunk: CarDoor
	{
		scope = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
				};
			};
			class DamageZones
			{
				class Doors
				{
					class Health
					{
						hitpoints = 3000;
						transferToGlobalCoef = 0.75;
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage = 0.05;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.05;
					};
				};
			};
		};
		
	};
	class Truck_01_Door_1_1: CarDoor
	{
		scope = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 3500;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
			class DamageZones
			{
				class Doors
				{
					class Health
					{
						hitpoints = 5000;
						transferToGlobalCoef = 0.75;
					};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage = 0.05;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.05;
					};
				};
			};
		};
	};*/
};

class CfgSlots
{
	class Slot_Att_CarKey
	{
		name = "Att_CarKey";
		displayName = "Car Key";
		ghostIcon = "set:keylock_ghost image:key";
	};
	class Slot_Att_CarKeyMaster
	{
		name = "Att_CarKeyMaster";
		displayName = "Master Key";
		ghostIcon = "set:keylock_ghost image:key";
	};
};

class CfgNonAIVehicles
{
    class ProxyAttachment;
    class ProxyCarKey1 : ProxyAttachment
    {
        scope = 1;
        InventorySlot="Att_CarKey";
        model="\CarKeyLocks\data\key\CarKey1.p3d";
    };
    class ProxyCarKey : ProxyAttachment
    {
        scope = 1;
        InventorySlot="Att_CarKeyMaster";
        model="\CarKeyLocks\data\key\CarKey.p3d";
    };
};