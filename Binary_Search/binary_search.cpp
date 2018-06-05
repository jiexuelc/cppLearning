/*************************************************************************
	> File Name: binary_search.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Tue 05 Jun 2018 01:27:46 PM CST
	> Description: 递归与递推实现二分查找
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

class Person{
	//类，用于存储个人信息
	char name[20];
	int age;
	char add[100];
public:
	Person(const char* name, int age, const char* add):age(age)
	{
		strcpy(this->name,name);
		strcpy(this->add,add);
	}
	bool operator<(const Person& a) const;
	bool operator==(const Person& a) const;
	friend ostream& operator<<(ostream& o, const Person& a);
};

bool Person::operator<(const Person& a) const
{//重载<运算符用于关系比较
	return strcmp(name,a.name) < 0;
}

bool Person::operator==(const Person& a) const
{//重载=运算符用于关系比较
	return strcmp(name,a.name) == 0;
}
ostream& operator<<(ostream& o, const Person& a)
{
	o << a.name << ':' << a.age << ',' << a.add << endl;
	return o;
}

void sort(Person* a, int n)
{
	int ni = n-1;
	for(int i=0; i<ni; i++)
		for(int j=i+1; j<n; j++)
			if(a[j]<a[i])
				swap(a[j],a[i]);
}

Person* binary_search(Person* a, int n, char* name)
{//递归实现二分查找(前提是对于排好序数组的查找)
	if(n < 1) return NULL;//如果子数组小于1说明找不到
	int mid = n/2;//折半查找
	Person temp(name,'0',"");//创建临时对象便于比较
	if(a[mid] == temp) return a+mid;//等于中间，找到
	if(temp < a[mid]) return binary_search(a,mid,name);//比中间小，则返回前半部分查找结果
	else return binary_search(a+mid+1,n-(mid+1),name);//否则返回后半部分的查找结果
}

Person* binary_search_recursive(Person* a, int n, char* name)
{//递推实现二分查找
	int beg = 0, end = n-1;//记录开始位置和终点
	Person temp(name,'0',"");
	while(beg <= end){//递推结束条件
		int mid = (beg + end) / 2;//取得中点
		if(a[mid] == temp) return a+mid;//返回找到位置
		if(temp < a[mid]) end = mid-1;//如果比中点位置值小，在前半部分找
		else beg = mid+1;//否则在后半部分找
	}
}

int main()
{
	Person a[6]={
		Person("lichao",21,"四川成都"),
		Person("hebin",23,"甘肃兰州"),
		Person("songwei",20,"安徽合肥"),
		Person("chenqi",16,"湖北武汉"),
		Person("huwangfeng",18,"湖南长沙"),
		Person("lixiaoxiong",18,"河北石家庄"),
	};
	sort(a,6);//按姓名拼音排序
	for(int i=0; i<6; i++)
		cout << a[i];
	char name[20];
	cout << "Please input the name you want to search:";
	cin >> name;
	Person* p = binary_search(a,6,name);//递归
	if(p != NULL) cout << *p;
	else cout << "Did not find:" << name << endl;
	
	Person* pr = binary_search_recursive(a,6,name);//递推
	if(pr != NULL) cout << *pr;
	else cout << "Did not find:" << name << endl;
	
	return 0;
}
