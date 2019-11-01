// DesignMode.cpp : 定义控制台应用程序的入口点。
//
#include <Windows.h>
#include <cstdio>
#include "Test.h"
#include <list>
#include <vector>

int main(int argc, char* argv[])
{
	Test::HungrySingleton();
	Test::LazySingletonThreadSafe();
	Test::SimpleFactory();
	Test::Factory();
	Test::AbstractFactory();
	Test::Builder();
	Test::Adapter();
	Test::Bridge();
	Test::Decorator();
	Test::Facade();
	Test::Proxy();
	Test::Command();
	Test::Iterator();
	Test::Mediator();
	Test::Observer();
	Test::StateMachine();
	system("pause");
	return 0; 
}

