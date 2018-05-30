/*************************************************************************
	> File Name: exception.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Thu 17 May 2018 04:59:51 PM CST
	> Description: 异常练习
 ************************************************************************/

#include<iostream>
using namespace std;
#include<exception>
#include<cstring>
#include<cstdio>

class Outofrange : public exception
{
    //int i;
    //int max;
    char msg[100];
public:
    Outofrange(int i,int max){sprintf(msg,"指定下标%d无效，不在0到%d之间！",i,max);}
    const char*what()const throw(){return msg;}
};

class Array{
    int n;
    int* p;
public:
    Array(int n):n(n){p = new int[n];memset(p,0,n*4);}
    ~Array(){delete[] p;}
    int size()const{return n;}
    int& operator[](int i){
        if(i<0 || i>=n)throw Outofrange(i,n-1);
        return p[i];
    }
    friend istream& operator>>(istream&,Array&);
    friend ostream& operator<<(ostream&,Array&);
};

istream& operator>>(istream& in,Array& a)
{
    for(int i=0; i< a.n; i++){
        in >> a[i];
    }
    cout << endl;
    return in;
}

ostream& operator<<(ostream& out,Array& a)
{
    for(int i=0; i< a.n; i++){
        out << a[i] << ' ';
    }
    return out;
}

void Try()
{
    Array A(6);
    cin >> A;
    cout << A << endl;
    cin >> A[5];
    cout << A << endl;
    cout << A[10] << endl;
}

int main()
{
    //try{
        Try();
    //}
    //catch(...){cout << "其他异常!" << endl;}
    return 0;
}

