/*************************************************************************
	> File Name: std_cin_cout.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Wed 26 Sep 2018 04:51:03 PM CST
	> Description: cin和cout使用
        1..get()接收所有字符(接收一个),对应的.put()输出一个字符；
        2..ignore(200,'\n')顶多忽略掉输入缓冲区的200个字符，直到遇到'\n'为止。第一个形参默认值为1，第二个默认为为到文件末尾；
        3.用cin >> ch会自动忽略掉空格，而get()不会；
        4.io对象一旦处于错误状态就拒绝读写，需要清掉错误状态才可正常工作,用cin.clear()清除错误状态，不清除缓冲区；
        5.i对象.getline(char数组,数组大小);如果不能读完一整行会设置错误状态
          getline(i对象,string对象引用);不是成员函数，而是全局函数
          这两个版本都可以用第三个参数指定读到什么字符为止，默认是'\n'
        6.cin >>ws;跳过空白字符；
        8..putback()每调用一次会读走一个字符；
        9..peek()永远不会读走一个字符，只是窥探一下；
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

/*
 * i.get() o.put()
 */
void func1(void)
{
    cout << "--------------func1 start--------------\n";
    int n = cin.get();  //int get(), //getchar() 返回字符的ASIIC码值
    char c,d,e;
    cin.get(c).get(d).get(e);   //istream& get(char& ch)
    cout << n << ',' << c << ',' << d << ',' << e << endl; 
    cout.put(n).put(c).put(d).put(e);
    cin.ignore(200,'\n');
    char ch;
    cin >> ch;  //scanf(" %c", &ch);
    cout << "ch=" << ch << endl;
    cout << "--------------func1 end--------------\n";
}


//io对象要求能转换成bool类型。对处于正常状态的io对象转成true，对处于错误状态的io对象转成false。
//处于错误状态的io对象拒绝执行io操作，.clear()清除错误状态
//.eof(),.fail(),.bad(),.good()
void func2(void)
{
    cout << "--------------func2 start--------------\n";
    cout << "cin=" << cin << endl;
    cout << cout << endl;
    int n;
    cin >> n;
    cout << "cin=" << cin << endl;
    if(cin) cout << "平安无事" << endl;
    if(!cin){ cout << "出错了" << endl; cin.clear(); }
    string s;
    cin >> s;
    cout << "s=[" << s << "]\n";
    //  cout << &cin << endl;
    //  cout << &cout << endl;
    cout << "--------------func2 end--------------\n";
}

//i对象.getline(char数组,数组大小);如果不能读完一整行会设置错误状态
//getline(i对象,string对象引用);不是成员函数，而是全局函数
//这两个版本都可以用第三个参数指定读到什么字符为止，默认是'\n'
void func3(void)
{
    cout << "--------------func3 start--------------\n";
    char buf[10];
    if(!cin.getline(buf,sizeof(buf))){
        cout << "错误：行超长\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    string s;
    getline(cin, s, '~');
    cout << "buf=[" << buf << "]\n";
    cout << "s=[" << s << "]\n";
    printf("%s\n", s.c_str());
    cout << "--------------func3 end--------------\n";
}

//i.putback();
//i.peek();
void func4(void)
{
    cout << "--------------func4 start--------------\n";
    char buf[100];
    char c;
    cin >> ws;
    c = cin.get();
    //if(cin.get()>='0'&&cin.get()<='9')c = cin.get();
    cin.putback(c);
    if(isdigit(c)){
        double d;
        cin >> d;
        cout << "d=" << d << endl;
    }
    else{
        string s;
        cin >> s;
        cout << "s=" << s << endl;
    }
    cin >> ws;
    if(cin.peek()>='0'&&cin.peek()<='9'){
        double d;
        cin >> d;
        cout << "d=" << d << endl;
    }
    else{
        string s;
        cin >> s;
        cout << "s=" << s << endl;
    }
    cout << "--------------func4 end--------------\n";
}

int main()
{
    func1();
    
    func2();
    
    func3();
    
    func4();
    
    return 0;
}
