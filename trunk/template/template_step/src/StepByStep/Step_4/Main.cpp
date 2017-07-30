#include <iostream>
using namespace std;
#define PRINT_FUNC	std::cout<<"LINE: "<<__LINE__<<", func: "<<__PRETTY_FUNCTION__<<std::endl;

//=======================
template<typename T> class SingltonClass {
public:
	static T* GetInstance()	{
		if (NULL == _inst)
			_inst = new T();
		return _inst;
	}
	static void ReleaseInstance() {
		if (NULL != _inst) {
			delete _inst;
			_inst = NULL;
		}
	}
private:
	static T* _inst;
};

template<typename T> T* SingltonClass<T>::_inst = NULL;

class MySingleton : public SingltonClass<MySingleton> {
public:
	MySingleton()	{	PRINT_FUNC;	}
	~MySingleton()	{	PRINT_FUNC;	}
	void DoPrint()	{	PRINT_FUNC;	}
};

void Test_1()
{
	MySingleton* myClass = MySingleton::GetInstance();
	myClass->DoPrint();
	MySingleton::ReleaseInstance();
}

int main()
{
	Test_1();
	return 0;
}
