/*************************************************************************
	> File Name: iterator_find.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Wed 13 Jun 2018 04:19:41 PM CST
	> Description: 算法find
 ************************************************************************/
/*
 * 1.算法操作的目标是迭代器
 * 2.for_each(pos_beg,pos_end,func)
 * 3.copy(pos_beg,pos_end,a)正序复制
 * 4.copy_backward(pos_beg,pos_end,a)倒序复制，适合目标区域和原区域有重叠的情况
 * 5.iterator find(pos_beg, pos_end, data)、iterator find_if(pos_beg, pos_end, cond), bool cond(element)
 * 6.int count(...), int count_if(...)
 */

#include<iostream>
using namespace std;
#include <algorithm>
#include <string>

#include <cctype>

bool init_upper(const string& str)//判断首字母是否大写
{
	return isupper(str[0]);
}

bool has_o(const string& str)//找是否有大小写字母o
{
	return str.find_first_of("oO") != string::npos;
	/*
	 * .find_first_of("oO") 
	 * 查找在字符串中第一个与str中的某个字符匹配的字符，返回它的位置。
	 * 如果没找到就返回string::npos
	 */
}

int main()
{
	string a[8] = {"Hello","I","am","Lichao","What","is","you","name"};
	string* ps = find(a,a+8,"Lichao");c
	cout << (ps == a+8?"not finding":"finding: ") << "Lichao" << endl;
	
	ps = find_if(a,a+8,init_upper);
	if(ps == a+8) cout << "没有首字母大写的字符串" << endl;
	else cout << "finding: " << *ps << endl;
	cout << count_if(a,a+8,init_upper) << endl;//返回符合条件的个数
	cout << count_if(a,a+8,has_o) << endl;
	
	return 0;
}
