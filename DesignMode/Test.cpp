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

// ����ʽ����ģʽ
//   1. �����ʼ����ʱ����Ѿ�������������
//	 2. ���������������߳�֮ǰ�����Դ����������̰߳�ȫ��
void Test::HungrySingleton(){
	printf("1. HungrySingleton\n");
	printf("   Create Instance When init class.\n");
	printf("   Thread Safe.\n");
	HungrySingleton::GetInstance();
	printf("======================================================\n");
}

// ����ʽ����ģʽ
//   1. �ڵ��õ�GetInstance()������ʱ��Ŵ�����������
//	 2. ���������ǿ����ڲ�ͬ�߳���ͬʱִ�У�����ͨ������������֤�������̵��̰߳�ȫ��
//	 3. ������Ҫ��ʱ��Żᴴ�������������ڲ���Ҫ��ʱ���ǲ�������򴴽��������ɵ��˷�
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

// �򵥹���ģʽ
//   1. ��������߿���ͨ��һ��������ò�ͬ��Ʒ
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

// ����ģʽ
//   1. ��������߿���ͨ����ͬ�Ĺ�����ò�ͬ��Ʒ
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

// ���󹤳�ģʽ
//   1. ��������߿���ͨ����ͬ�������Ʒ�Ʋ�Ʒ��Ҳ����ͨ��ͬһ������ò�ͬ���͵Ĳ�Ʒ
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

// ������ģʽ
//   1. ͨ����ͬ�Ĺ����߾Ϳ��Ի�ò�ͬ�����ԣ���ͬһ���Ʒ
void Test::Builder(){
	printf("6. Builder\n");
	Director director;
	director.SetBuilder(new Builder1());
	director.Construct()->Show();
	director.SetBuilder(new Builder2());
	director.Construct()->Show();
	printf("======================================================\n");
}

// ������ģʽ
//   1. ����ƥ��Ľӿ�ת����ͨ�ýӿ�
void Test::Adapter(){
	printf("7. Adapter\n");
	Target* t = new ::Adapter();
	t->Interface1();
	t->Interface2();
	delete t;
	printf("======================================================\n");
}

// �Ž�ģʽ
//   1. ��������ά�ȱ仯��ʱ�򣬿��ǽ�һά�Ķ��ؼ̳иĳ�ʹ���Ž�ģʽ�Ķ�ά��Ӧ��ϵ
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


// װ����ģʽ
//   1. ��Ӱ��ԭ���������£�Ϊ�����һЩ�µ����Ժ͹��ܡ�
void Test::Decorator(){
	printf("9. Decorator\n");
	DAbstract* a = new DConcrete();
	a->Operation();
	::Decorator*b = new Decorator1(a);
	b->Operation();
	delete b;
	printf("======================================================\n");
}

// ���ģʽ
//   1. ����ͻ���������ϵͳ֮������
void Test::Facade(){
	printf("10. Decorator\n");
	::Facade* f = new ::Facade();
	f->WrapOperation();
	printf("======================================================\n");
}


// ��Ԫģʽ
//   1. �����ڳؼ�����ʵ�֣�String�����ء�����ء����ݿ����ӳ�
//   2. �����������������ͷǹ�����󣬼��ٿռ��ռ��


// ����ģʽ��
//   1. ���Դ��������ڶ�����Ҫ��ʱ���ٴ��������Խ�ʡ�ڴ�����
//	 2.	�������Ȩ������֤��ʵ����İ�ȫ
//	 3. Զ�̴���/�������/��������
void Test::Proxy(){
	printf("11. Proxy\n");
	::Proxy* p = new ::Proxy();
	p->Request();
	delete p;
	printf("======================================================\n");
}