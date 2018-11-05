/*************************************************************************
	> File Name: sstream.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Fri 28 Sep 2018 12:16:09 PM CST
	> Description: 字符串IO,以字符串为目标的字符串流
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Point{
    int x;
    int y;
public:
    Point(int x, int y):x(x),y(y){}
    friend ostream& operator<<(ostream& o, const Point& p){
        return o << '(' << p.x << ',' << p.y << ')';
    }
};

int main()
{
    string s="12345 6.78 x hello 234 100";
    istringstream is(s);
    int a, b, c;
    double d;
    char e;
    char buf[100];
    
    is >> a >> d;
    is >> e >> buf;
    is >> oct >> b; //八进制数234存储在b里面
    is >> hex >> c; //16进制数100存储在b里面
    cout << "a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << ", e=" << e << ", buf=" << buf << endl;
    
    ostringstream os;
    Point p(3,5);
    
    os << "a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << ", e=" << e << ", buf=" << buf << ", p=" << p;
    cout << "===========" << endl;
    cout << os.str() << endl;
    cout << os.str()[4] << endl;
    cout << "===========" << endl;
} 