modded class CarDoor extends InventoryItemSuper
{

	protected int m_Key_b1 = 0;
	protected int m_Key_b2 = 0;
	protected int m_Key_b3 = 0;
	protected int m_Key_b4 = 0;
	protected int m_Key_rng = 0;
	
	protected bool m_CarDoorIsLocked = false;
	
	void CarDoor(){
		RegisterNetSyncVariableInt("m_Key_b1");
		RegisterNetSyncVariableInt("m_Key_b2");
		RegisterNetSyncVariableInt("m_Key_b3");
		RegisterNetSyncVariableInt("m_Key_b4");
		RegisterNetSyncVariableInt("m_Key_rng");
		RegisterNetSyncVariableBool("m_CarDoorIsLocked");
	}
	
	bool CanHaveKeyAssigned(){
		CarScript car;
		bool HasPeopleInCar = false;
		if (Class.CastTo(car, GetHierarchyParent())){
			for ( int i = 0; i < car.CrewSize(); i++ )
         	{
                Human crew = car.CrewMember( i );
                if ( crew ){
					HasPeopleInCar = true;
					break;
				}
			}
		}
		return (!HasKeyAssigned() && !IsRuined() && !HasPeopleInCar);
	}
	
	bool IsDoorLocked(){
		return (m_CarDoorIsLocked && IsAttachedToCar() && HasKeyAssigned() && !IsRuined());
	}
	
	bool IsKeyValid(CarKey key){
		if (!HasKeyAssigned()){return true;}
		if (!key || key.IsRuined()){return false;}
		int b1,b2,b3,b4,rng;
		key.GetCarKeyId(b1,b2,b3,b4,rng);
		return (m_Key_b1 == b1 && m_Key_b2 == b2 && m_Key_b3 == b3 && m_Key_b4 == b4 && m_Key_rng == rng);
	}
	
	bool IsAttachedToCar(){
		CarScript car;
		return Class.CastTo(car, GetHierarchyParent());
	}
	
	void SetDoorLocked(bool state){
		m_CarDoorIsLocked = state;
		SetSynchDirty();
	}
	
	override bool CanDetachAttachment(EntityAI parent)
	{
		if (super.CanDetachAttachment(parent)){
			return (!IsDoorLocked());
		}
		return false;
	}
	
	override bool DescriptionOverride(out string output) {
		string name = ConfigGetString("descriptionShort");
		bool rValue = false;
		if (super.NameOverride(output)){
			name = output;
			rValue = true;
		}
        if (GetGame().IsClient() && HasKeyAssigned() ) {
            output = name + " Seems to have a lock installed. (Lock S/N: " + Math.AbsInt(m_Key_rng) + " - " + Math.AbsInt(m_Key_b1) + ")";
            return true;
        }
        return rValue;
    }
	
	bool HasKeyAssigned(){
		return (m_Key_b1 != 0 && m_Key_b2 != 0 && m_Key_b3 != 0 && m_Key_b4 != 0 && m_Key_rng != 0);
	}
	
	void AssignKey(CarKey key){
		if (!key){return;}
		key.GetCarKeyId(m_Key_b1,m_Key_b2,m_Key_b3,m_Key_b4,m_Key_rng);
		SetSynchDirty();
	}
	
	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if ( !super.OnStoreLoad( ctx, version ) ) {
			m_Key_b1 = 0;
			m_Key_b2 = 0;
			m_Key_b3 = 0;
			m_Key_b4 = 0;
			m_Key_rng = 0;
			m_CarDoorIsLocked = false;
			Print("Data Corrupted Reseting Car Door back to 0 " + GetPosition());
			return false;
		}
		if (GetCarKeyLockConfig().IsInstalled()){
			if (!ctx.Read( m_Key_b1 )) {
				m_Key_b1 = 0;
				m_Key_b2 = 0;
				m_Key_b3 = 0;
				m_Key_b4 = 0;
				m_Key_rng = 0;
				m_CarDoorIsLocked = false;
				Print("Data Corrupted Reseting Car Door back to 0 " + GetPosition());
				return false;
			}
			if (!ctx.Read( m_Key_b2 )) {
				m_Key_b1 = 0;
				m_Key_b2 = 0;
				m_Key_b3 = 0;
				m_Key_b4 = 0;
				m_Key_rng = 0;
				m_CarDoorIsLocked = false;
				Print("Data Corrupted Reseting Car Door back to 0 " + GetPosition());
				return false;
			}
			if (!ctx.Read( m_Key_b3 )) {
				m_Key_b1 = 0;
				m_Key_b2 = 0;
				m_Key_b3 = 0;
				m_Key_b4 = 0;
				m_Key_rng = 0;
				m_CarDoorIsLocked = false;
				Print("Data Corrupted Reseting Car Door back to 0 " + GetPosition());
				return false;
			}
			if (!ctx.Read( m_Key_b4 )) {
				m_Key_b1 = 0;
				m_Key_b2 = 0;
				m_Key_b3 = 0;
				m_Key_b4 = 0;
				m_Key_rng = 0;
				m_CarDoorIsLocked = false;
				Print("Data Corrupted Reseting Car Door back to 0 " + GetPosition());
				return false;
			}
			if (!ctx.Read( m_Key_rng )) {
				m_Key_b1 = 0;
				m_Key_b2 = 0;
				m_Key_b3 = 0;
				m_Key_b4 = 0;
				m_Key_rng = 0;
				m_CarDoorIsLocked = false;
				Print("Data Corrupted Reseting Car Door back to 0 " + GetPosition());
				return false;
			}
			if (!ctx.Read( m_CarDoorIsLocked )) {
				m_Key_b1 = 0;
				m_Key_b2 = 0;
				m_Key_b3 = 0;
				m_Key_b4 = 0;
				m_Key_rng = 0;
				m_CarDoorIsLocked = false;
				Print("Data Corrupted Reseting Car Door back to 0 " + GetPosition());
				return false;
			}
		}
		return true;
	}
	
	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		ctx.Write( m_Key_b1 );
		ctx.Write( m_Key_b2 );
		ctx.Write( m_Key_b3 );
		ctx.Write( m_Key_b4 );
		ctx.Write( m_Key_rng );
		ctx.Write( m_CarDoorIsLocked );
		GetCarKeyLockConfig().SetIsInstalled();
	}
	
	
	override void AfterStoreLoad()
	{	
		super.AfterStoreLoad();
		
		if (!HasKeyAssigned() && m_CarDoorIsLocked){
			m_CarDoorIsLocked = false;
		}
		SetSynchDirty();
	}
	
	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);
		m_CarDoorIsLocked = false;
		SetSynchDirty();
	}
	
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{		
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		if (!GetGame().IsClient()){
			if (GetHealth("","Health") <= 5) return;
			array<string> FullZonesList = new array<string>;
			GetDamageZones(FullZonesList);
			for (int i = 0; i < FullZonesList.Count(); i++){
				float zoneDmg = damageResult.GetDamage(FullZonesList.Get(i), "Health");
				string zoneName = FullZonesList.Get(i);
				if (zoneDmg > 0 && zoneName != "Window"){
					AddHealth(zoneName, "Health", (zoneDmg * 0.97));
				}
			}
			float dmg = damageResult.GetDamage("","Health");
			AddHealth("", "Health", (dmg * 0.95));
		}
	}
	
	override void OnUApiSave(UApiEntityStore data) {
		super.OnUApiSave(data);
		
		data.Write("m_CarDoorIsLocked", m_CarDoorIsLocked);
		data.Write("m_Key_b1", m_Key_b1);
		data.Write("m_Key_b2", m_Key_b2);
		data.Write("m_Key_b3", m_Key_b3);
		data.Write("m_Key_b4", m_Key_b4);
		data.Write("m_Key_rng", m_Key_rng);
	}
	
	override void OnUApiLoad(UApiEntityStore data){
		super.OnUApiLoad(data);
		data.Read("m_CarDoorIsLocked", m_CarDoorIsLocked);
		data.Read("m_Key_b1", m_Key_b1);
		data.Read("m_Key_b2", m_Key_b2);
		data.Read("m_Key_b3", m_Key_b3);
		data.Read("m_Key_b4", m_Key_b4);
		data.Read("m_Key_rng", m_Key_rng);
	}
	
}