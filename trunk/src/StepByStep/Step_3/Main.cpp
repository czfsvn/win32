#include <iostream>

//from : http://www.cnblogs.com/stephen-liu74/archive/2012/08/24/2608149.html

//#programa region typename 的另一种用法

#define PRINT_FUNC	std::cout<<"LINE: "<<__LINE__<<", func: "<<__PRETTY_FUNCTION__<<std::endl;
template <typename T>	class MyTestClass	{
public:
	MyTestClass(typename T::MyType p) : m_p(p)	{	}
	typename T::MyType GetData() const
	{
		return m_p;
	}
	typename T::MyType 	m_p;
};

class TemplateParamClass	{
	public:
		typedef const char* MyType;
};

void Test_1()	{
	MyTestClass<TemplateParamClass> t("Hello");
	std::cout<<"the data is "<< t.GetData();
}

//#programa endregion typename 的另一种用法

// ==============================
template <typename T> class TestClass {
public:
	TestClass(T v) : _value(v)	{}
	template<typename T2> TestClass<T>& operator = (const TestClass<T2>& other) {
		if ((void*)this == (void*)&other)
			return *this;
		_value = other.getValue();
		return *this;
	}
	T getValue() const {	return this->_value;	}
private:
	T	_value;
};

void Test_2() {
	TestClass<int>		intClass(5);
	TestClass<double>	doubleClass(6.4);
	std::cout<<"before : "<<doubleClass.getValue()<<std::endl;
	doubleClass = intClass;
	std::cout<<"after	: "<<doubleClass.getValue()<<std::endl;
}

//========================
template<typename T, template<typename T> class TempClass> 
class TempTempClass {
public:
	TempTempClass(const TempClass<T>& tempClass) : interClass(tempClass){}
	void doTest() {	interClass.doTest();	}
private:
	TempClass<T> interClass;
};

template <typename T> class MyTempClass {
public:
	void doTest()	{	PRINT_FUNC;	}	
};
void Test_3()
{
	MyTempClass<int>	myTmpClass;
	TempTempClass<int, MyTempClass> tmpTmpClass(myTmpClass);
	tmpTmpClass.doTest();
}

int main()
{
	//Test_1();
	//Test_2();
	Test_3();
	return 0;
}
