/*************************************************************************
	> File Name: complex.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Fri 04 May 2018 09:58:17 AM CST
	> Description: 运算符重载之复数类的加减乘除实现
 ************************************************************************/

#include<iostream>
using namespace std;
class Complex{
    double real;
    double imag;
public:
    friend ostream& operator<<(ostream& o,const Complex& c);
    Complex(double Real, double Imag):real(Real),imag(Imag)
    {
        //cout << *this << ++cnt << endl;
    }
    Complex operator+(const Complex& c)const; 
    Complex operator-(const Complex& c)const;
    friend Complex operator*(const Complex& lh,const Complex& rh); 
    friend Complex operator/(const Complex& lh,const Complex& rh); 
    Complex& operator++(){++real;return *this;}//前++
    //void operator++(){++(this->real);}
    //不能写成cout << ++a;
    //需要写成++a;cout << a;才可以

    Complex operator++(int){Complex old(*this);++real;return old;} //后++
};

ostream& operator<<(ostream& o,const Complex& c)
{
    o << c.real << showpos << c.imag << "i\n" << noshowpos;
    return o;
}

Complex Complex::operator+(const Complex& c)const
{
    return Complex (c.real+real,c.imag+imag);
}

Complex Complex::operator-(const Complex& c)const
{
    return Complex (real-c.real,imag-c.imag);
}

Complex operator*(const Complex& lh,const Complex& rh)
{
    return Complex(lh.real*rh.real-lh.imag*rh.imag,lh.imag*rh.real+lh.real*rh.imag);
}

Complex operator/(const Complex& lh,const Complex& rh)
{
    double sub = rh.real*rh.real+rh.imag*rh.imag;
    return Complex((lh.real*rh.real+lh.imag*rh.imag)/sub,(lh.imag*rh.real-lh.real*rh.imag)/sub);
}

int main()
{
    Complex a(3.2,5.6);
    Complex b(7,-8.9);
    Complex c(-9.6,-9.5);
    cout << a+b << a+c << b+c << a+b+c;
    cout << a-b << a-c << a-b-c;
    cout << a*b;
    cout << a/b;
    cout << ++a;
    cout << b++ << b;
}

