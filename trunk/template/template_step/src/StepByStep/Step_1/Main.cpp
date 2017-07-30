#include <iostream>

//from http://www.cnblogs.com/stephen-liu74/archive/2012/07/16/2593492.html3


#define MAX(a, b)	((a) < (b) ? (b) : a)
#define MAX_SIZE			256

#pragma region ģ�庯��ʵ����
template <typename T>
inline T const& max(T const& a, T const& b)
{
	return a < b ? b : a;
}

template <typename T>
inline T const& max(T const& a, T const& b, T const& c)
{
	return ::max(::max(a, b), c);
}

class MyClass
{
public:
	MyClass(int val) : m_value(val)
	{
	}
	
	bool operator < (const MyClass& oth) const
	{
		std::cout << "operator < is called" << std::endl;
		return m_value < oth.m_value;
	}
	
	int myVal() const
	{
		return m_value;
	}
protected:
private:
	int m_value;	
};


void Test_1()
{
	printf("the max value is %d\n", ::max(4, 5));
	printf("the max value is %f\n", ::max(4.2, 5.9));

	printf("the max value is %f\n", ::max(4.2, 5.6, 5.5));

	MyClass m1(30), m2(40);
	std::cout<<"The max value is " << ::max(m1, m2).myVal() << std::endl;
}


#pragma endregion ģ�庯��ʵ����

int main()
{
	Test_1();
	return 0;
}