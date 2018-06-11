/*************************************************************************
	> File Name: vector.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Sun 10 Jun 2018 08:25:23 PM CST
	> Description: vector的个性
 ************************************************************************/
/*
 * 1.当前容量：.capacity()取得目前分配的vector容量
 * 2.约定容量：.reserve(n)
 * 3.下标：不检查越界.operator[](i)，越界会抛出异常.at(i)
 * 4.在插入或删除数据时迭代器可能会失效，因为有可能会重新分配内存
 * 5.是动态数组
 */

#include<iostream>
#include<vector>
#include "print.h"
#include <exception>

using namespace std;

/*输出vector数组*/
void print(const vector< vector<int> >& v )
{
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v.at(i).size(); j++)
			cout << v.at(i).at(j) << ' ';
		cout << endl;
	}
}

int main()
{
	vector<double> vd1,vd2;
	for(int i=0; i<10; i++){//动态分配大小
		vd1.push_back(i+0.5);
		cout << vd1.size() << '/' << vd1.capacity() << endl;
	}
	print(vd1.begin(),vd1.end());
	cout << "<------------------->" << endl;
	vd2.reserve(10);//约定容量
	for(int i=0; i<10; i++){
		vd2.push_back(i+0.6);
		cout << vd2.size() << '/' << vd2.capacity() << endl;
	}
	vd2[9] = 9.9;vd2.at(8) = 8.8;
	print(vd2.begin(),vd2.end());
	try{//抛出异常
		for(int i=0; i<=10; i++)
			cout << vd2.at(i) << ' ';
		cout << endl;
	}catch(exception& e){
		cout << "exception:" << e.what() << endl;
	}
	
	cout << "<------------------->" << endl;
	int m = 3, n = 4;
	vector < vector<int> > vvi(m, vector<int>(n) ); //vector数组
	print(vvi);//void print(const vector< vector<int> >& v )
	cout << "<------------------->" << endl;
	vvi.resize(m+3);//调整大小
	vvi.at(1).assign(6,1);//赋值
	vvi[5].assign(3,1);
	print(vvi);
	
	return 0;
}

