#pragma once
class HungrySingleton{
public:
	static HungrySingleton* GetInstance();

private:
	HungrySingleton();
	static HungrySingleton *instance;
};
