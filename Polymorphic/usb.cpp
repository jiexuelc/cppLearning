/*************************************************************************
	> File Name: usb.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Wed 09 May 2018 04:05:48 PM CST
	> Description: 多态实现
 ************************************************************************/

#include<iostream>
using namespace std;

class Usb{
public:
    virtual void plugin(){cout<<"found USB decice"<<endl;}
    virtual void work(){cout<<"USB device is working"<<endl;}
    virtual void stop(){cout<<"USB device stop"<<endl;}
};

class Usbdisk:public Usb
{
public:
    void plugin(){cout<<"found USBdisk decice"<<endl;}
    void work(){cout<<"USBdisk device is working"<<endl;}
    void stop(){cout<<"USBdisk device stop"<<endl;}
};

class Usbfan:public Usb
{
public:
    void plugin(){cout<<"found USBfan decice"<<endl;}
    void work(){cout<<"USBfan device is working"<<endl;}
    void stop(){cout<<"USBfan device stop"<<endl;}
};

class Computer
{
public:
    void use(Usb* p){
        p->plugin();
        p->work();
        p->stop();
    }
};

int main()
{
    Usbdisk d;
    Usbfan f;
    Computer c;
    c.use(&d);
    c.use(&f);
    return 0;
}
