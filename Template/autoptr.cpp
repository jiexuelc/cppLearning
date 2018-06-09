/*************************************************************************
	> File Name: autoptr.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Sat 09 Jun 2018 07:01:16 PM CST
	> Description: 自动指针模板的基本实现(将new的内存保存在对象里，结束时通过调用析构来释放内存)
 ************************************************************************/

#include<iostream>
using namespace std;

template <typename T >
class Autoptr{
	T* p;
public:
	Autoptr(T* p):p(p){}
	Autoptr(Autoptr& a){operator=(a);}
	~Autoptr()
	{
		delete p;
	}
	Autoptr& operator=(Autoptr& a)
	{
		p = a.p;
		a.p = NULL;
	}
	T& operator*()const{return *p;}
	T* operator->()const{return p;}
};

class Date{
	int year;
	int month;
	int day;
public:
	Date(int y,int m, int d):year(y),day(d),month(m){}
	~Date()	{ cout << this << " ~Date()" << endl;}
	bool operator<(const Date& d2)
	{
		return (year < d2.year || year==d2.year && (month < d2.month || month == d2.month && day < d2.day));
	}
	bool operator==(const Date &d2)
	{
		return (year = d2.year && month == d2.month && day < d2.day);
	}
	void show()const { cout << year << '/' << month << '/' << day << endl; }
	friend ostream& operator<<(ostream& o, const Date& d)//不能是成员函数形式
	{
		return o << d.year << '/' << d.month << '/' << d.day;
	}
};

int main()
{
	Autoptr<Date> p1(new Date(2018,6,9));
	cout << *p1 << endl;
	Autoptr<Date> p2(p1);
	//cout << *p1 << endl;
	p2->show();
	Autoptr<int> p3(new int(2018));
	cout << *p3 << endl;
	return 0;
}

