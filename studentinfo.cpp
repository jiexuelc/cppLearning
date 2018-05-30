/*************************************************************************
	> File Name: studentinfo.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Thu 17 May 2018 07:42:11 PM CST
	> Description: 学生信息管理系统(未完成)
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

class Student{
    char name[20];
    char gender;
    float grade;
public:
    Student(){
        cout << "请输入姓名:";
        cin >> name;
        cout << "请输入性别M/F:";
        cin >> gender;
        cout << "请输入分数：";
        cin >> grade;
    }
    
    const char* Name()const{return name;}
    friend istream& operator>>(istream&,Student&);
    friend ostream& operator<<(ostream&,Student&);
};

istream& operator>>(istream& in,Student& s)
{
    cout << "请输入姓名:";
    in >> s.name;
    cout << "请输入性别M/F:";
    in >> s.gender;
    cout << "请输入分数：";
    in >> s.grade;
}

ostream& operator<<(ostream& out,Student& s)
{
    cout << "姓名：" << s.name << endl;
    cout << "性别：" << s.gender << endl;
    cout << "分数：" << s.grade << endl;
}

int main()
{
    cout << "============学生成绩管理系统===========\n";
    cout << "录入操作请输入0\n查询操作请输入1\n删除操作请输入2\n修改操作请输入3\n退出系统请输入4\n";
    char c;
    while(1){
        cin >> c;
        if(c=='0'){
            Student S;
            fstream file("stu1",ios::out|ios::app|ios::binary);
            if(!file){
                cout << "打开文件stu.dat失败！\n";
                return 0;
            }
            ostringstream os;
            os << S <<endl;
            cout << os.str() <<endl;
            string s=os.str();
            //file.write((char*)s.c_str(),100);
            file.write(os.str().c_str(),os.str().size());
            file.close();
        }
        if(c=='4'){
        cout << "============退出学生成绩管理系统===========\n";
            return 0;
        }
    }
}
