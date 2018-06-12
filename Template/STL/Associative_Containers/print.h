/*************************************************************************
	> File Name: print.h
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Sat 09 Jun 2018 09:46:30 PM CST
	> Description:输出一个指定区间中的所有数据（含头不含尾）
 ************************************************************************/

#ifndef _PRINT_H
#define _PRINT_H 1
using namespace std;
template <typename T>
void print(T beg, T end, char ch = ' ')
{
	while(beg != end){
		cout << *beg++ << ch;
	}
	cout << endl;
}

template< typename U,typename V>
ostream& operator<<(ostream& o, const pair<U,V>& p)
{
	return o << p.first << '/' << p.second;
}
#endif
