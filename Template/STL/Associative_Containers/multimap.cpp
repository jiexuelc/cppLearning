/*************************************************************************
	> File Name: multimap.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Mon 11 Jun 2018 09:09:02 PM CST
	> Description:　multimap的个性：本例实现汇总业务量，计算提成
 ************************************************************************/
/*
 * 1.允许key重复
 * 2.元素是key/value对
 * 3.不支持下标[]
 * 4.头文件map
 */

#include<iostream>
#include <map>
#include "print.h"
#include <string>
using namespace std;


int main()
{
	typedef multimap<string,double> MSD;
	MSD m;
	m.insert(MSD::value_type("lichao",90000));
	m.insert(make_pair("wanglin",20000));
	m.insert(make_pair("lichao",120000));
	m.insert(make_pair("wanglin",50000));
	m.insert(make_pair("jiexue",60000));
	m.insert(make_pair("wanglin",70000));
	m.insert(make_pair("jiexuelc",120000));
	m.insert(make_pair("jiexue",700000));
	m.insert(MSD::value_type("wanglin",100000));
	m.insert(MSD::value_type("lichao",100000));
	m.insert(MSD::value_type("jiexuelc",100000));
	print(m.begin(),m.end());
	
	MSD::iterator ib = m.begin(),ie;
	MSD cnt;//用于统计结果记录的对象
	while(ib != m.end()){
		string name = ib->first;//记下名字便于查找
		ie = m.upper_bound(name);//查找区间
		double sum = 0;
		while(ib != ie) sum += (ib++)->second;//统计每个人的业务量
		cnt.insert(make_pair(name,sum*0.03));//计算并存储
	}
	print(cnt.begin(),cnt.end());//输出结果
	
	return 0;
}
