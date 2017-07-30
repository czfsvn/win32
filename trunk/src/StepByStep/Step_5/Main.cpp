#include <iostream>
using namespace std;

#define PRINT_FUNC	std::cout<<"LINE: "<<__LINE__<<", func: "<<__PRETTY_FUNCTION__<<std::endl;
template<typename T> class InterClass {
public:
	static void DoTest()	{	PRINT_FUNC;	}
};

template<typename T> class OuterClass {
public:
	template<typename T2> void func(){
		T2::DoTest();
	}
};

template<typename T> void DoTest(OuterClass<T>& outer) {
	outer.template func<InterClass<T> >();
}

int main()
{
	OuterClass<int> outClass;
	DoTest(outClass);
	return 0;
}
