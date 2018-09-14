/*************************************************************************
	> File Name: ViewGccVersion.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Thu 13 Sep 2018 02:08:44 PM CST
	> Description: 查看GCC版本号"__VERSION__"
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

/*
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    for (auto& el : vec)
    {
        os << el << ' ';
    }
    return os;
}
*/

int main()
{
    std::cout << "Program " << "from " << "GCC " << __VERSION__<< " !\n";
    
    return 0;
}
