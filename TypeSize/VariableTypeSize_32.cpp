/*************************************************************************
    > File Name: VariableTypeSize_32.cpp
    > Author: jiexue
    > Mail: jiexuelc@163.com
    > Created Time: Wed 12 Sep 2018 09:01:36 PM CST
    > Description: C++基本类型、类在32位GCC4.8.4 编译器下占用的内存大小
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

enum color {
    BLACK = 0,
    YELLOW = 1,
    WHITE,
    BLUE
};  //4 Byte

/*
 * 字节对齐原则：
 *   1.数据类型自身的对齐值:对于char型数据，为1；对于short型，为2，对于int,float型，为4；double类型，为8，单位字节
 *   2.结构体或者类的自身对齐值：其成员中自身对齐值最大的那个值
 *   3.指定对齐值：#pragma pack (value)时的指定对齐值value。
 *   4.数据成员、结构体和类的有效对齐值：自身对齐值和指定对齐值中小的那个值
 * 注意:32位GCC默认指定对齐为4字节,64位GCC默认指定对齐为8字节
 *     VS2010不管是32位还是64位编译器,其默认指定对齐值为结构体或者类的自身对齐值(成员中自身对齐值最大的值)
 */
struct person8 {
    char gender;    //占用2字节，自身1字节
    short age;      //占用2字节
    char party;     //占用4字节，自身1字节
    int height;     //占用4字节
    char name[5];   //占用8字节，自身5字节
    double weight;    //占用8字节
    char addr;      //占用4字节，自身1字节
};  //32 Byte   有效对齐值4

struct person4 {
    char gender;    //占用2字节，自身1字节
    short age;      //占用2字节
    char party;     //占用4字节，自身1字节
    int height;     //占用4字节
};  //12 Byte   有效对齐值4

struct person2 {
    char gender;    //占用2字节，自身1字节
    short age;      //占用2字节
    char party;     //占用2字节，自身1字节
};  //6 Byte   有效对齐值2

struct person1 {
    char gender;    //占用1字节，自身1字节
};  //1 Byte   有效对齐值1

/*
 * #pragma pack(1/2/4/8)修改指定对齐字节数
 * 注意：修改并不一定能奏效，因为还要看结构中成员最大那个对齐值
 *      成员最大对齐值超过指定对齐值，指定才能起作用
 */
#pragma pack(2)
struct Pragma_2
{
    int   a;    //4
    char  b;    //2
    double c;   //8
    char  d;    //2
};  //16 Byte   有效对齐值2

#pragma pack(1)
struct Pragma_1
{
    char  a;    //1
    double b;   //8
    char  c;    //1
};  //10 Byte   有效对齐值1
#pragma pack()

typedef struct IP {
    unsigned char szIP1;    //high
    unsigned char szIP2;
    unsigned char szIP3;
    unsigned char szIP4;
}IP_INT;

typedef union IP_addr {
    IP_INT ip_int;
    int ipv4;
    char type;
}IP_ADDR;   //4 Byte

static double function(int a, float b)
{
    return 0;
}

/*
 * 1.类的大小为类的非静态成员数据的类型大小之和，也就是说静态成员数据不作考虑;
 * 2.类的总大小也遵守类似class字节对齐的;
 * 3.成员函数都是不会被计算的; 
 * 4.如果是子类，那么父类中的成员也会被计算;
 * 5.虚函数由于要维护虚函数表，所以要占据一个指针大小，也就是4字节.
 * 总结：一个类中，虚函数、成员函数（包括静态与非静态）和静态数据成员都不占用类对象的存储空间
 */
class Person {
private:
    unsigned short age; //占用2字节
    bool gender;        //占用1字节
    char name[16];      //占用17字节
public:
    /* 联合，占用16字节 */
    union UBffer
    {
        char buffer[13];
        int number;
    }ubuf;
    
    typedef char*(*f)(void*);   //不占用类对象内存
    enum{hdd,ssd,blueray}disk;  //占用4字节,按int存储
    
    /* 成员函数，不占用类对象的内存 */
    Person(const char* name, bool gender, unsigned short age) {
        strcpy(Person::name, name);
        Person::gender = gender;
        Person::age = age;
    }
    
    ~Person() {cout << "~Person\n";}
    
    friend ostream& operator<<(ostream& out, Person& p) {
        return out << "name:" << p.name << " gender:" << p.gender << " age:" << p.age; 
    } 
};  //40 Byte 有效对齐值4

/*
 * 空类型的实例中不包含任何信息，本来求sizeof的结果应该是0，但是当我们声明该类型的实例时，必须在内存中占有一定得空间，否则无法使用这些实例。
 * 至于占多少内存，由编译器决定。在GCC和Visual Studio中，每个空类型的实例占用1字节的空间。
 */
class None {
    
};  //1 Byte

class Parent {
private:
    static char sch;    //非实例独占,不占用实例内存
    char ch;    //占用4字节
    int* pi;    //占用4字节
public:
    Parent() {} //相当于普通函数，不占用实例内存
    
    /* 几个虚函数只占用一个虚函数表,只占用一个指针的大小4字节 */
    virtual void fun1() {}
    virtual void fun2() {}
    virtual ~Parent();
};  //12 Byte 有效对齐值4

class Child : public Parent{
private:
    double d;   //占用8字节
    string str; //占用4字节
public:
    Child() {}
    
    /* 
     * 子类将父类虚函数表继承下来,只占用一个指针的大小4字节
     * 也就是说父类有虚函数的情况下子类的虚函数不占用内存
     */
    virtual void fun1() {}
    virtual void fun3() {}
    virtual ~Child() {} 
};  //24 Byte 有效对齐值4

int main(void)
{
    /* string的实现在各库中可能有所不同，但在同一个库中相同的一点是，无论string里存放了多长的字符串，它们的sizeof()都是固定的
     *（举个不太恰当的例子，就好比int a; 无论int变量a取多大的值，sizeof(a)总为4），字符串所占的空间是从堆中动态分配的，与sizeof()无关；
     * sizeof(string) == 4可能是最为典型的实现之一，不过也有sizeof()为 12，32 字节的库，同时也与编译器有关
     * 在windows 64位操作系统下， 使用vs2010 32位编译器测试，sizeof(string) == 32。
     * 在windows 64位操作系统下， 使用vs2010 64位编译器测试，sizeof(string) == 48。
     */
    bool bl;    //1字节
    string Str = "Hello! How do you do!";   //4字节
    
    char szchar = 65;   //1字节
    unsigned char uszchar = 95; //1字节
    
    short sishort = -100;   //2字节
    unsigned short usishort = 100;  //2字节

    int iint = -200;    //4字节
    unsigned int uiint= 200;    //4字节

    float ffloat = -0.8;    //4字节
    double ddouble = 99.99; //8字节

    long llong = 999;   //4字节
    unsigned long ullong = 999; //4字节
    long long lllong = 9999;    //8字节
    
    enum color color1;  //4字节
    union IP_addr pc_ip;    //4字节
    
    char* pchar;    //4字节
    int* pint;  //4字节
    long long* pllint;  //4字节
    double* pdouble;    //4字节
    
    double (*pffun)(int,float); //4字节
    
    /*
     * sizeof计算大小计算整个字符串长度
     * strlen计算截止到'\0'的字符长度
     */
    char str1[] = "12345\0678";     //str1字符串加上结束符'\0'一共占用8字节,'\067'表示一个字符
    char str2[] = "12345\\0678";    //str2字符串加上结束符'\0'一共占用11字节,'\\'表示一个'\'字符

    /* ArryNames是一个数组，故sizeof(ArryNames)大小为72字节 */
    char ArryNames[9][8] = {"Tom","Jerry","Ham","Jobs","","Benson","Nick","Evan","jiexue"};
    /* names是一个指针数组，故sizeof(names)大小为36字节 */
    const char* names[9] = {"Tom","Jerry","Ham","Jobs","","Benson","Nick","Evan","jiexue"};
    
    Person p("jiexue", true, 18);

    cout << "    -----------------------------    \n";
    cout << "****在" << sizeof(void*) * 8 << "位系统上,各类型占用字节数****\n";
    cout << "****      GCC Version: " << __VERSION__ << "     ****\n";
    cout << "    -----------------------------    \n";
    cout << "-------------基本类型----------------\n";
    cout << "bool: " << sizeof(bl) << endl;
    cout << "string: " << sizeof(Str) << endl;
    cout << "char: " << sizeof(szchar) << endl;
    cout << "unsigned char: " << sizeof(uszchar) << endl;
    cout << "short: " << sizeof(sishort) << endl;
    cout << "unsigned short: " << sizeof(usishort) << endl;
    cout << "int: " <<  sizeof(iint) << endl;
    cout << "unsigned int: " << sizeof(uiint) << endl;
    cout << "float: " << sizeof(ffloat) << endl;
    cout << "double: " << sizeof(ddouble) << endl;
    cout << "long: " << sizeof(llong) << endl;
    cout << "unsigned long: " << sizeof(ullong) << endl;
    cout << "long long: " << sizeof(lllong) << endl;
    
    cout << "---------枚举、结构、联合------------\n";
    cout << "enum: " << sizeof(enum color) << endl;
    cout << "struct person8: " << sizeof(person8) << endl;
    cout << "struct person4: " << sizeof(person4) << endl;
    cout << "struct person2: " << sizeof(person2) << endl;
    cout << "struct person1: " << sizeof(person1) << endl;
    cout << "union IPV4: " << sizeof(pc_ip) << endl;
    
    cout << "--------指针、函数、函数指针---------\n";
    cout << "char*: " << sizeof(char*) << endl;
    cout << "int*: " << sizeof(pint) << endl;
    cout << "long long*: " << sizeof(pllint) << endl;
    cout << "double*: " << sizeof(pdouble) << endl;
    cout << "&main: " << sizeof(&main) << endl; //返回4
    cout << "&function: " << sizeof(&function) << endl;    //返回4
    cout << "main(): " << sizeof(main()) << endl; //返回4
    cout << "function*: " << sizeof(pffun) << endl;
    
    cout << "---------------字符串----------------\n";
    cout << "str1[] = \"12345\\0678\": " << strlen(str1) << endl;
    cout << "str1[] = \"12345\\0678\": " << sizeof(str1) << endl;
    cout << "str2[] = \"12345\\\\0678\": " << strlen(str2) << endl;
    cout << "str2[] = \"12345\\\\0678\": " << sizeof(str2) << endl;
    cout << "char ArryNames[9][8]: " << sizeof(ArryNames) << endl;
    cout << "char ArryNames[9][8]: " << strlen(ArryNames[0]) << endl; //strlen(ArryNames)会给警告，得到的依然是3
    cout << "char* names[9]: " << sizeof(names) << endl;
    
    cout << "------------修改对齐方式-------------\n";
    cout << "struct Pragma_2: " << sizeof(struct Pragma_2) << endl;
    cout << "struct Pragma_1: " << sizeof(struct Pragma_1) << endl;
    
    cout << "---------------C++类----------------\n";
    cout << "class Person: " << sizeof(Person ("jiexue", true, 18)) << endl;
    cout << p << endl;
    cout << "class None: " << sizeof(None) << endl;
    cout << "class Parent: " << sizeof(Parent) << endl;
    cout << "class Child: " << sizeof(Child) << endl;
    
    //getchar();
    //system("PAUSE");

    return 0;
}
