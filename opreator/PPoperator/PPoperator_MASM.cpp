/*************************************************************************
 > File Name: test.cpp                                                 *
 > Author: jiexue
 > Mail: jiexuelc@163.com
 > Created Time: Sun 16 Sep 2018 07:48:17 PM CST
 > Description: 测试对于(++d) += d++;语句不同编译器下的实现
 ************************************************************************/
#include <cstdio>

int main()
{

    int d = 4;
    (++d) += d++;
    printf("%d\n",d);

    return 0;
}
