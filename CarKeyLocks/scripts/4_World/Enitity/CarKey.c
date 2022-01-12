class CarKey extends ItemBase {
	protected bool m_IsMasterKey = false;
	protected int m_Master_Key_b1 = 0;
	protected int m_Master_Key_b2 = 0;
	protected int m_Master_Key_b3 = 0;
	protected int m_Master_Key_b4 = 0;
	protected int m_Master_Key_rng = 0;
	
	void CarKey(){
		RegisterNetSyncVariableBool("m_IsAssigned");
		RegisterNetSyncVariableInt("m_Master_Key_b1");
		RegisterNetSyncVariableInt("m_Master_Key_b2");
		RegisterNetSyncVariableInt("m_Master_Key_b3");
		RegisterNetSyncVariableInt("m_Master_Key_b4");
		RegisterNetSyncVariableInt("m_Master_Key_rng");
	}
	
	bool IsMaster(){
		return (HasBeenAssigned() && m_IsMasterKey);
	}
	
	override bool NameOverride(out string output) {
		string name = ConfigGetString("displayName");
		bool rValue = false;
		if (super.NameOverride(output)){
			name = output;
			rValue = true;
		}
        if (GetGame().IsClient() && IsMaster() ) {
            output = name + " (Master)";
            return true;
        }
        if (GetGame().IsClient() && !HasBeenAssigned() ) {
            output = name + " (Blank)";
            return true;
        }
        return rValue;
    }
	
	
	void GetCarKeyId(out int b1, out int b2, out int b3, out int b4, out int rng){
		if (!HasBeenAssigned()){
			m_IsMasterKey = true;
			GetPersistentID(m_Master_Key_b1,m_Master_Key_b2,m_Master_Key_b3,m_Master_Key_b4);
			m_Master_Key_rng = Math.RandomInt(int.MIN, int.MAX);
			SetSynchDirty();
		}
		b1 = m_Master_Key_b1;
		b2 = m_Master_Key_b2;
		b3 = m_Master_Key_b3;
		b4 = m_Master_Key_b4;
		rng = m_Master_Key_rng;
	}
	
	
	void AssignToDoor(CarDoor door){
		if (!door){
			return;
		}
		door.AssignKey(this);
	}
	
	bool HasBeenAssigned(){
		return (m_Master_Key_b1 != 0 && m_Master_Key_b2 != 0 && m_Master_Key_b3 != 0 && m_Master_Key_b4 != 0 && m_Master_Key_rng != 0);
	}
	
	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if ( !super.OnStoreLoad( ctx, version ) ) {
			return false;
		}
		if (!ctx.Read( m_IsMasterKey )) {
			return false;
		}
		if (!ctx.Read( m_Master_Key_b1 )) {
			return false;
		}
		if (!ctx.Read( m_Master_Key_b2 )) {
			return false;
		}
		if (!ctx.Read( m_Master_Key_b3 )) {
			return false;
		}
		if (!ctx.Read( m_Master_Key_b4 )) {
			return false;
		}
		if (!ctx.Read( m_Master_Key_rng )) {
			return false;
		}
		return true;
	}
	
	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		
		ctx.Write( m_IsMasterKey );
		ctx.Write( m_Master_Key_b1 );
		ctx.Write( m_Master_Key_b2 );
		ctx.Write( m_Master_Key_b3 );
		ctx.Write( m_Master_Key_b4 );
		ctx.Write( m_Master_Key_rng );
	}
	
	override void AfterStoreLoad()
	{	
		super.AfterStoreLoad();
		SetSynchDirty();
	}
	
	
	override void OnUApiSave(UApiEntityStore data) {
		super.OnUApiSave(data);
		
		data.Write("m_IsMasterKey", m_IsMasterKey);
		data.Write("m_Master_Key_b1", m_Master_Key_b1);
		data.Write("m_Master_Key_b2", m_Master_Key_b2);
		data.Write("m_Master_Key_b3", m_Master_Key_b3);
		data.Write("m_Master_Key_b4", m_Master_Key_b4);
		data.Write("m_Master_Key_rng", m_Master_Key_rng);
	}
	
	override void OnUApiLoad(UApiEntityStore data){
		super.OnUApiLoad(data);
		
		data.Read("m_IsMasterKey", m_IsMasterKey);
		data.Read("m_Master_Key_b1", m_Master_Key_b1);
		data.Read("m_Master_Key_b2", m_Master_Key_b2);
		data.Read("m_Master_Key_b3", m_Master_Key_b3);
		data.Read("m_Master_Key_b4", m_Master_Key_b4);
		data.Read("m_Master_Key_rng", m_Master_Key_rng);
	}
	
	
	override void SetActions() {
		super.SetActions();
		AddAction(ActionToggleLockCar);
	}
}