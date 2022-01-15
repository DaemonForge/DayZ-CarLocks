class CarKeyLockConfig extends Managed {

    protected static string ConfigDIR = "$profile:CarKeyLock";
    protected static string ConfigPATH = ConfigDIR + "\\config.json";
    static ref CarKeyLockConfig m_Config;
    string ConfigVersion = "0";
	bool m_ISINSTALLED_USE_WHEN_FIRST_INSTALLINGMOD_DONOTTOUCH = false;
	
	
    void Load(){
        if (GetGame().IsServer()){
            if (FileExist(ConfigPATH)){ // If config exist load File
                UApiJSONHandler<CarKeyLockConfig>.FromFile(ConfigPATH, this);
            } else { // File does not exist create file    
                MakeDirectory(ConfigDIR);
                Save();
            }
        }
    }
    void Save(){
        UApiJSONHandler<CarKeyLockConfig>.ToFile(ConfigPATH, this);
    }
	
	bool IsInstalled(){
		return m_ISINSTALLED_USE_WHEN_FIRST_INSTALLINGMOD_DONOTTOUCH;
	}
	
	void SetIsInstalled(){
		if (!m_ISINSTALLED_USE_WHEN_FIRST_INSTALLINGMOD_DONOTTOUCH){
			m_ISINSTALLED_USE_WHEN_FIRST_INSTALLINGMOD_DONOTTOUCH = true;
	        Save();
		}
	}
}
//Helper function to return Config
static CarKeyLockConfig GetCarKeyLockConfig()
{
    if ( GetGame().IsServer() ){
        if (!CarKeyLockConfig.m_Config)
        {
            CarKeyLockConfig.m_Config = new CarKeyLockConfig;
            CarKeyLockConfig.m_Config.Load();
        }
    }
    return CarKeyLockConfig.m_Config;
};