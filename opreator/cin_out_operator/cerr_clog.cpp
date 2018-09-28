/*************************************************************************
	> File Name: cerr_clog.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Wed 26 Sep 2018 04:45:24 PM CST
	> Description: cout，cerr和clog区别
            1.cout输出缓冲遇到换行、有输入、满、程序结束、flush会刷新
            2.cout 缓冲，可重定向
            3.cerr 无缓冲，不可重定向
            4.clog 理论上“缓冲、不可重定向”，实际无缓冲
 ************************************************************************/

#include <iostream>
using namespace std;
            
int main()
{
    cout << "Hello ";    //缓冲，可重定向
    cerr << "World ";    //无缓冲，不可重定向
    clog << "Jiexue";   //理论上“缓冲、不可重定向”，实际无缓冲
    
    return 0;
}
