#include <iostream>

//from ：　http://www.cnblogs.com/stephen-liu74/archive/2012/08/22/2599400.html

#pragma region 模板的特化

#define PRINT_FUNC	std::cout<<"LINE: "<<__LINE__<<", func: "<<__PRETTY_FUNCTION__<<std::endl;
template <typename T> class CalcHashClass {
public:
	CalcHashClass(T const& v) : m_val(v)	{	}
	int hashCode(){
		PRINT_FUNC
		return m_val.hashCode() + 10000;
	}
private:
	T m_val;
};

template <>	class CalcHashClass<int>	{
public:
	CalcHashClass(int const& v) : m_val(v)	{}
	int hashCode(){
		PRINT_FUNC;
		return m_val * 101;
	}
private:
	int m_val;
};

template <>	class CalcHashClass<const char*>	{
public:
	CalcHashClass(const char* v)	{
		m_val = new char[strlen(v) + 1];
		strcpy(m_val, v);
	}

	int hashCode()	{
		PRINT_FUNC;
		int len = strlen(m_val);
		int code = 0;
		for (int i = 0; i < len; ++i)
			code += (int)m_val[i];

		return code;
	}
private:
	char* m_val;
};

template <typename T>	inline int CalcHashCode(T v){
	CalcHashClass<T> t(v);
	return t.hashCode();
}

class TestClass	{
public:
	TestClass(const char* v)	{
		m_val = new char[strlen(v) + 1];
		strcpy(m_val, v);
	}

	~TestClass()	{	delete m_val;	}

	int hashCode()	{
		PRINT_FUNC;
		int len = strlen(m_val);
		int code = 0;
		for (int i = 0; i < len; ++i)
			code += (int)m_val[i];

		return code;
	}
private:
	char* m_val;
};

void Test_1()	{
	TestClass tc("Hello");
	CalcHashClass<TestClass> t1(tc);
	std::cout<<"the hashcode is "<< t1.hashCode()<< std::endl;

	CalcHashClass<int> t2(10);
	std::cout<<"the hashcode is "<< t2.hashCode() << std::endl;

	std::cout<<"the hashcode is "<< CalcHashCode(10)<< std::endl;
	std::cout<<"the hashcode is "<< CalcHashCode("Hello")<< std::endl;
}

//=============================

class BaseInterface	{
public:
	virtual ~BaseInterface() {}
	virtual void DoPrint()	= 0;
};

template <typename T>	class DeriveClass : public BaseInterface	{
public:
	void DoPrint()	{		PRINT_FUNC;		}
};

template <>	class  DeriveClass<int> : public BaseInterface{
public:
	void DoPrint()	{		PRINT_FUNC;	}
};

template <typename T>	inline BaseInterface* DoTest(T t)
{
	return new DeriveClass<T>;
}

void Test_2()	{
	BaseInterface* b1 = DoTest(4.5);
	b1->DoPrint();

	BaseInterface* b2 = DoTest(5);
	b2->DoPrint();

	delete b1;
	delete b2;
}

#pragma endregion 模板的特化

#pragma region 模板部分特化

#pragma endregion 模板部分特化

int main()
{
	//Test_1();
	Test_2();
	return 0;
}
