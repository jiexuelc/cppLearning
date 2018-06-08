/*************************************************************************
	> File Name: sort.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Fri 08 Jun 2018 04:31:07 PM CST
	> Description: 函数模板特化、偏特化、重载
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;

template <typename T >//通用模板
void sort(T a[], int n)
{
	for(int i = 0; i < n-1; i++){//从第二个值开始，循环n-1次
		int min = i;
		for(int j = i+1; j<n; j++)
			if(a[j] < a[min])
				min = j;
		swap(a[min],a[i]);
	}
}

template <typename T >//偏特化
void sort(T* a[], int n)
{
	for(int i = 0; i < n-1; i++){//从第二个值开始，循环n-1次
		int min = i;
		for(int j = i+1; j<n; j++)
			if(*a[j] < *a[min])
				min = j;
		swap(a[min],a[i]);
	}
}

template <>//全特化
void sort(const char* a[], int n)
{
	for(int i = 0; i < n-1; i++){//从第二个值开始，循环n-1次
		int min = i;
		for(int j = i+1; j<n; j++)
			if(strcmp(a[j],a[min]) < 0)
				min = j;
		swap(a[min],a[i]);
	}
}

class Date{
	int year;
	int month;
	int day;
public:
	Date(int y,int m, int d):year(y),day(d),month(m){}
	bool operator<(const Date& d2)
	{
		return (year < d2.year || year==d2.year && (month < d2.month || month == d2.month && day < d2.day));
	}
	bool operator==(const Date &d2)
	{
		return (year = d2.year && month == d2.month && day < d2.day);
	}
	friend ostream& operator<<(ostream& o, const Date& d)//不能是成员函数形式
	{
		return o << d.year << '/' << d.month << '/' << d.day;
	}
};

template <typename T >//通用模板
void show(T a[],int n)
{
	for(int i = 0; i < n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}

/*template <typename T >
void show(T& a)//a和实参是同一个变量，所以能计算数组大小
{
	int n = sizeof(a)/sizeof(a[0]);
	for(int i = 0; i < n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}*/

/*上面注释的部分如果遇到输出单独一个数会出现编译错误，因为[]运算对其没有意义；
 * 比如
 * int ai = 5;
 * show(ai);
 * 可以改写如下(L99－L106):
 * 这样子编译器找不到匹配的函数报错，可以另外写一个模板进行重载
 * template <typename T >
 * void show(T data)
 * {
 * 		cout << data << endl;
 * }
 */
template <typename T, int N>//模板
void show(T (&a)[N])//a是一个数组引用，编译器可以自动计算数组长度N值，
{
	for(int i = 0; i < N; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}

template <int N>//全特化
void show(const char* (&a)[N])//a是一个数组引用，编译器可以自动计算数组长度N值，
{
	for(int i = 0; i < N; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}

template <typename T, int N>//偏特化
void show(T* (&a)[N])//a是一个数组引用，编译器可以自动计算数组长度N值，
{
	for(int i = 0; i < N; i++){
		cout << *a[i] << ' ';
	}
	cout << endl;
}

int main()
{
	int a[6] = {6,5,4,3,2,1};
	show(a,6);//void show(T a[],int n)
	sort(a,6);//void sort(T a[], int n)
	show(a,6);
	show(a);//void show(T (&a)[N])
	double d[4] = {3.2, 4.1, 5.8, 1.2};
	show(d,4);//void show(T a[],int n)
	sort(d,4);//void sort(T a[], int n)
	show(d,4);
	show(d);//void show(T (&a)[N])
	Date dy[4] = {Date(2016,7,9), Date(2015,12,31), Date(2018,6,6), Date(2018,6,4)};
	show(dy,4);//void show(T a[],int n)
	sort(dy,4);//void sort(T a[], int n)
	show(dy,4);
	show(dy);//void show(T (&a)[N])
	const char* s[3] = {"lichao","wanglin","jiexuelc"};
	show(s,3);//void show(T a[],int n)
	sort(s,3);//void sort(const char* a[], int n)
	show(s,3);
	show(s);//void show(const char* (&a)[N])
	int* aip[4] = {new int(5),new int(8),new int(2),new int(3)};
	sort(aip,4);//void sort(T* a[], int n)
	show(aip);//void show(T* (&a)[N])
	double* adp[4] = {new double(5.3),new double(8.5),new double(8.1),new double(3.5)};
	sort(adp,4);//void sort(T* a[], int n)
	show(adp);//void show(T* (&a)[N])
	return 0;
}