/*************************************************************************
	> File Name: ExecuteBeforeMain.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Wed 17 Oct 2018 02:18:40 CST
	> Description: 利用全局变量和构造函数的特性，在main函数之前执行程序 
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Student{
private:
    int IDNumber;
    string name;
public:
    Student(int IDNumber, string name):IDNumber(IDNumber), name(name){
        cout << name << "\'s ID is " << IDNumber << endl;
    }
};

Student Jx(6105, "jiexue");
string  jx= "jiexue";
//cout << jx << endl; //编译出错

int main()
{
    
    return 0;
}

