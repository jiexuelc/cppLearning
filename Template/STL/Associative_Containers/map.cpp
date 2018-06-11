/*************************************************************************
	> File Name: map.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Mon 11 Jun 2018 07:05:16 PM CST
	> Description:　map的个性
 ************************************************************************/
/*
 * 1.不允许key重复
 * 2.元素是key/value对
 * 3.支持以key为下标访问对应的value的引用，如果key不存在就新增一个元素以这个为key
 * 4.只关心key，对value不同不管 
 */

#include<iostream>
#include <map>
#include "print.h"
using namespace std;

int main()
{
	map<int,string> mis;
	mis.insert(map<int,string>::value_type(25,"lichao"));//插入
	mis.insert(pair<int,string>(22,"wanglin"));
	mis.insert(make_pair(24,"jiexue"));
	mis[21] = "lilin";
	mis[22] = "limao";
	mis[23] = "lichun";
	mis.insert(make_pair(23,"liranchun"));
	print(mis.begin(),mis.end());//输出，需要重载<<符号
	return 0;
}
