#include "Test.h"
#include <boost\thread\thread.hpp>
#include "Singleton\HungrySingleton.h"
#include "Singleton\LazySingleton.h"
#include "SimpleFactory\SimpleFactory.h"
#include "Factory\Factorys.h"
#include "AbstractFactory\AbstractFactorys.h"
#include "Builder\Director.h"
#include "Builder\Builders.h"
#include "Adapter\Adapter.h"
#include "Bridge\Concrete.h"
#include "Bridge\Implements.h"
#include "Derocator\Decorators.h"
#include "Derocator\DConcrete.h"
#include "Facade\Facade.h"
#include "Proxy\Proxy.h"
#include "Command\Invoker.h"
#include "Command\Commands.h"
#include "Iterator\Iterators.h"
#include "Mediator\Colleagues.h"
#include "Mediator\Mediators.h"
#include "Observer\Observers.h"
#include "Observer\Subjects.h"
#include "StateMachine\OperationAdapter.h"
#include "StateMachine\Player.h"

// 饿汉式单例模式
//   1. 在类初始化的时候就已经创建单例对象
//	 2. 创建过程在启动线程之前，所以创建过程是线程安全的
void Test::HungrySingleton(){
	printf("1. HungrySingleton\n");
	printf("   Create Instance When init class.\n");
	printf("   Thread Safe.\n");
	HungrySingleton::GetInstance();
	printf("======================================================\n");
}

// 懒汉式单例模式
//   1. 在调用到GetInstance()函数的时候才创建单例对象
//	 2. 创建过程是可以在不同线程中同时执行，但是通过互斥锁来保证创建过程的线程安全性
//	 3. 是在需要的时候才会创建单例，所以在不需要的时候是不会出现因创建对象而造成的浪费
void LazySingletonThread1(){
	printf("LazySingletonThread1 start\n");
	LazySingleton::GetInstance();
	printf("LazySingletonThread1 end\n");
}
void LazySingletonThread2(){
	printf("LazySingletonThread2 start\n");
	LazySingleton::GetInstance();
	printf("LazySingletonThread2 end\n");
}
void Test::LazySingletonThreadSafe(){
	printf("2. LazySingleton ThreadSafe\n");
	printf("   Create Instance When exec function GetInstance().\n");
	printf("   Use mutex to promise thread safe.\n");
	printf("   Can Save memory when system do not need this Instance.\n");
	boost::thread thread1(&LazySingletonThread1);
	boost::thread thread2(&LazySingletonThread2);
	thread1.join();
	thread2.join();
	printf("======================================================\n");
}

// 简单工厂模式
//   1. 概念：消费者可以通过一个工厂获得不同产品
void Test::SimpleFactory(){
	printf("3. SimpleFactory\n");
	Product* p = nullptr;
	p = SimpleFactory::CreateProduct(PRODUCT_B);
	if (p != nullptr){
		p->Introduce();
		delete p;
		p = nullptr;
	}
	p = SimpleFactory::CreateProduct(PRODUCT_C);
	if (p != nullptr){
		p->Introduce();
		delete p;
		p = nullptr;
	}
	p = SimpleFactory::CreateProduct(PRODUCT_A);
	if (p != nullptr){
		p->Introduce();
		delete p;
		p = nullptr;
	}
	p = SimpleFactory::CreateProduct(0x04);
	if (p != nullptr){
		p->Introduce();
		delete p;
		p = nullptr;
	}
	printf("======================================================\n");
}

// 工厂模式
//   1. 概念：消费者可以通过不同的工厂获得不同产品
void Test::Factory(){
	printf("4. Factory\n");
	Product* p = nullptr;
	::Factory* f = nullptr;

	f = new FactoryA();
	p = f->CreateProduct();
	if (p != nullptr){
		p->Introduce();
		delete p;
		p = nullptr;
	}
	delete f; 
	f = nullptr;

	f = new FactoryB();
	p = f->CreateProduct();
	if (p != nullptr){
		p->Introduce();
		delete p;
		p = nullptr;
	}
	delete f;
	f = nullptr;

	f = new FactoryC();
	p = f->CreateProduct();
	if (p != nullptr){
		p->Introduce();
		delete p;
		p = nullptr;
	}
	delete f;
	f = nullptr;

	printf("======================================================\n");
}

// 抽象工厂模式
//   1. 概念：消费者可以通过不同工厂获得品牌产品，也可以通过同一工厂获得不同类型的产品
void Test::AbstractFactory(){
	printf("5. AbstractFactory\n");
	AProduct* ap = nullptr;
	BProduct* bp = nullptr;
	::AbstractFactory* f = nullptr;

	f = new AbstractFactroy1();
	ap = f->CrateaAProduct();
	bp = f->CrateaBProduct();
	ap->Introduce();
	bp->notice();
	delete ap;
	delete bp;
	delete f;

	f = new AbstractFactroy2();
	ap = f->CrateaAProduct();
	bp = f->CrateaBProduct();
	ap->Introduce();
	bp->notice();
	delete ap;
	delete bp;
	delete f;
	printf("======================================================\n");
}

// 建造者模式
//   1. 通过不同的构造者就可以获得不同（属性）的同一款产品
void Test::Builder(){
	printf("6. Builder\n");
	Director director;
	director.SetBuilder(new Builder1());
	director.Construct()->Show();
	director.SetBuilder(new Builder2());
	director.Construct()->Show();
	printf("======================================================\n");
}

// 适配器模式
//   1. 将不匹配的接口转换成通用接口
void Test::Adapter(){
	printf("7. Adapter\n");
	Target* t = new ::Adapter();
	t->Interface1();
	t->Interface2();
	delete t;
	printf("======================================================\n");
}

// 桥接模式
//   1. 当有两个维度变化的时候，考虑将一维的多重继承改成使用桥接模式的二维对应关系
void Test::Bridge(){
	printf("8. Bridge\n");
	Abstract* a = new Concrete1(new Implement1());
	a->Operation();
	delete a;

	a = new Concrete2(new Implement2());
	a->Operation();
	delete a;
	printf("======================================================\n");
}


// 装饰器模式
//   1. 不影响原有类的情况下，为类添加一些新的属性和功能。
void Test::Decorator(){
	printf("9. Decorator\n");
	DAbstract* a = new DConcrete();
	a->Operation();
	::Decorator*b = new Decorator1(a);
	b->Operation();
	delete b;
	printf("======================================================\n");
}

// 外观模式
//   1. 隔离客户操作和子系统之间的耦合
void Test::Facade(){
	printf("10. Decorator\n");
	::Facade* f = new ::Facade();
	f->WrapOperation();
	printf("======================================================\n");
}


// 享元模式
//   1. 常用于池技术的实现，String常量池、缓冲池、数据库连接池
//   2. 将对象抽象出共享对象和非共享对象，减少空间的占用


// 代理模式：
//   1. 可以代理大对象，在对象需要的时候再创建，可以节省内存消耗
//	 2.	可以添加权限来保证真实对象的安全
//	 3. 远程代理/虚拟代理/保护代理
void Test::Proxy(){
	printf("11. Proxy\n");
	::Proxy* p = new ::Proxy();
	p->Request();
	delete p;
	printf("======================================================\n");
}


// 命令模式
//   1. 将发送者和接收者分离开来，发送者不需要知道命令的具体实现
//	 2. 抽象出命令类，并将具体命令类化
void Test::Command(){
	printf("12. Command\n");
	Receiver* r = new Receiver();
	::Command* c1 = new Command1(r);
	::Command* c2 = new Command2(r);
	Invoker* v = new Invoker(c1);
	v->Call();
	v->SetCommand(c2);
	v->Call();
	delete r;
	delete c1;
	delete c2;
	delete v;
	printf("======================================================\n");
}



// 迭代器模式
//   1. 这个例子模仿写了一个list容器以及对应的迭代器
//	 2. 遇到的问题：
//		2.1 模板类不能分离编译，所以成员函数的实现必须在类中完成，只能有一个头文件(*.h)
//		2.2 类模板成员函数不可以是虚函数，因为编译器实在运行的时候才能确定模板函数的类型的，而在类初始化的时候就要将虚函数填写到虚函数表中。

void Test::Iterator(){
	printf("13. Iterator\n");
	Container<int> a;
	a.PushBack(1);
	a.PushBack(2);
	a.PushBack(3);
	::Iterator<int>* iter = a.Begin();
	::Iterator<int>* end =  a.End();
	for (; *iter != end; (*iter)++){
		printf("%d", **iter);
	}
	delete iter;
	printf("\n");
	a.PopBack();
	for (iter = a.Begin(); *iter != end; (*iter)++){
		printf("%d", **iter);
	}
	delete iter;
	iter = a.Begin();
	printf("\n");
	a.Insert(*iter, 4);
	a.Insert(*iter, 5);
	a.Insert(*iter, 6);
	for (iter = a.Begin(); *iter != end; (*iter)++){
		printf("%d", **iter);
	}
	printf("\n");
	delete iter;
	delete end;
	printf("======================================================\n");
}


// 中介模式
//	 1. 可以将类之间的通信全部都交由中介类来完成
//	 2. 减少类之间的关联性，降低耦合
void Test::Mediator(){
	printf("14. Mediator\n");
	Colleague* c1 = new Colleague1();
	Colleague* c2 = new Colleague2();
	Colleague* c3 = new Colleague3();
	::Mediator* m = new Mediator1();
	m->Register(1, c1);
	m->Register(2, c2);
	m->Register(3, c3);
	c1->SendMsg(2);
	c1->SendMsg(3);
	c2->SendMsg(3);
	c3->SendMsg(2);
	delete m;
	delete c1, c2, c3;
	printf("======================================================\n");
}


// 观察者模式
//   1. 发布/订阅模式、模型/视图模式
void Test::Observer(){
	printf("15. Observer\n");
	::Observer* o = new Observer1();
	OSubject* s = new OSubject1();
	s->Attach(o);
	s->SetState(8);
	s->SetState(12);
	s->SetState(83);
	s->SetState(48);
	s->SetState(34);
	s->SetState(28);
	s->Detach(o);
	s->SetState(1);
	s->SetState(2);
	s->SetState(3);
	delete o;
	delete s;
	printf("======================================================\n");
}

//  状态机模式
//    1. 将每一个状态都抽象成一个类，继承于抽象状态基类，基类中定义所有的状态转换条件为虚函数。
//	  2. 每个派生状态类，根据实际情况去重载对应的虚函数。
void Test::StateMachine(){
	printf("16. StateMachine\n");
	Player* player = new Player();
	OperationTarget* operation = new OperationAdapter();
	operation->SetPlayer(player);
	operation->KeyC();
	operation->KeyWPressed();
	operation->KeyCtrlPressed();
	operation->KeyX();
	operation->KeyMouseLeftPressed();
	operation->KeyMouseLeftReleased();
	operation->KeySpace();
	operation->KeyWReleased();
	printf("======================================================\n");
}
