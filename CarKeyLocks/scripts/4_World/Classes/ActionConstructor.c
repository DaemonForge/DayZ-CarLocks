modded class ActionConstructor {
	
	void RegisterActions(TTypenameArray actions) {
		super.RegisterActions(actions);
		actions.Insert(ActionToggleLockCar);
		actions.Insert(ActionInstallCarLock);
		actions.Insert(ActionDuplicateKey);
	}
};