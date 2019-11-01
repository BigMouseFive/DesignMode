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


// ����ģʽ
//   1. �������ߺͽ����߷��뿪���������߲���Ҫ֪������ľ���ʵ��
//	 2. ����������࣬�������������໯
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



// ������ģʽ
//   1. �������ģ��д��һ��list�����Լ���Ӧ�ĵ�����
//	 2. ���������⣺
//		2.1 ģ���಻�ܷ�����룬���Գ�Ա������ʵ�ֱ�����������ɣ�ֻ����һ��ͷ�ļ�(*.h)
//		2.2 ��ģ���Ա�������������麯������Ϊ������ʵ�����е�ʱ�����ȷ��ģ�庯�������͵ģ��������ʼ����ʱ���Ҫ���麯����д���麯�����С�

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


// �н�ģʽ
//	 1. ���Խ���֮���ͨ��ȫ���������н��������
//	 2. ������֮��Ĺ����ԣ��������
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


// �۲���ģʽ
//   1. ����/����ģʽ��ģ��/��ͼģʽ
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

//  ״̬��ģʽ
//    1. ��ÿһ��״̬�������һ���࣬�̳��ڳ���״̬���࣬�����ж������е�״̬ת������Ϊ�麯����
//	  2. ÿ������״̬�࣬����ʵ�����ȥ���ض�Ӧ���麯����
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
