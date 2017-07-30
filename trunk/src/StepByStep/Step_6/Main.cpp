#include <iostream>
#include <typeinfo>
using namespace std;
#define PRINT_FUNC	std::cout<<"LINE: "<<__LINE__<<", func: "<<__PRETTY_FUNCTION__<<std::endl;

template<typename T> void func1(T* t) {
	std::cout<<"type is "<<typeid(t).name()<<std::endl;
}
template<typename T, int N> void func2(T(&)[N]) {
	std::cout<<"type of T is "<<typeid(T).name()<<", N equals to "<<N<<std::endl;
}

template<typename T1, typename T2, typename T3> 
void func3(T1 (T2::*)(T3*)) {
	std::cout<<"type of T1 is "<<typeid(T1).name()<<std::endl;
	std::cout<<"type of T2 is "<<typeid(T2).name()<<std::endl;
	std::cout<<"type of T3 is "<<typeid(T3).name()<<std::endl;
}

template<int N> class TempTest {
public:
	typedef int INT;
	void f(int)		{	PRINT_FUNC;	}
};

template<int N> 
void func4(void (TempTest<N>::*p)(typename TempTest<N>::INT)) {
	std::cout<<"N equals to "<<N<<std::endl;
}

class Test {
public:
void f(double*)	{	PRINT_FUNC;	}
};

void Test_1()
{
	int** pp	= NULL;
	func1(pp);
	bool b[100];
	func2(b);

	#if 0
	func3(&Test::f);
	func4(&TempTest<200>::f);
#endif
}

int main()
{
	Test_1();
	return 0;
}

