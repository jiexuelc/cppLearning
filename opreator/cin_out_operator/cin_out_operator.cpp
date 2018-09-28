/*************************************************************************
	> File Name: cin_out_operator.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Wed 26 Sep 2018 04:22:51 PM CST
	> Description: 输入输出运算符重载之分数的输入与输出
        当定义符合标准库iostream规范的输入或输出操作符("<<"或">>")的时候，必须使它成为非成员操作符
        1.cin.operator>>(a); operator>>(cin,a);
          标准输入默认定义了第一种输入要求a不是一个类，第二种可以用户自己定义，编译器会自动重载第二个输入。定义了第二种输入方式，用户不可以再定义第一种函数。
        2.cout.operator<<(a); operator<<(cout,a); 
          标准输出默认定义了第一种输出要求a不是一个类，第二种可以用户自己定义，编译器会自动重载第二个输出。定义了第二种输出方式，用户不可以再定义第一种函数。
 ************************************************************************/

#include <iostream>
using namespace std;

class F{
private:
    int n;
    int d;
public:
    F(int n=0, int d=1):n(n),d(d){}
    int getn()const{return n;}
    int getd()const{return d;}
    friend istream& operator>>(istream& in, F& f);//友元函数，并不是成员函数，只是有了访问私有成员的授权，是外面的函数
};

istream& operator>>(istream& in, F& f)  //注意是要用引用
{
    char c;
    in >> f.n >> c >> f.d;
    return in; 
}

ostream& operator<<(ostream& out, const F& f)   //注意是要用引用
{
    out << f.getn() << '/' << f.getd();
    return out;
}

int main()
{
    F a, b;
    int n;
    cin >> a >> b;  //cin.operator>>(a); operator>>(cin,a);
    cout<< a << endl << b << endl;     //cout.operator<<(a); operator<<(cout,a); 
    
    return 0;
}