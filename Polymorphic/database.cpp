/*************************************************************************
	> File Name: database.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Wed 09 May 2018 06:58:54 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Database{
public:
    virtual void connect(){cout<<"Database connection"<<endl;}
    virtual void query(){cout<<"Database query"<<endl;}
};

class Program{
public:
	void visit(Database* p)
		{
			p->connect();
			p->query();
		}
};

class Access:public Database
{
public:
    void connect(){cout<<"Access connection"<<endl;}
    void query(){cout<<"Access query"<<endl;}
};

class SQLServer:public Database
{
public:
    void connect(){cout<<"SQLServer connection"<<endl;}
    void query(){cout<<"SQLServer query"<<endl;}
};

class Oracle:public Database
{
public:
    void connect(){cout<<"Oracle connection"<<endl;}
    void query(){cout<<"Oracle query"<<endl;}
};

int main()
{
	Access* a= new Access;
	SQLServer* s= new SQLServer;
	Oracle* o=new Oracle;
	Program g;
	g.visit(a);
	g.visit(s);
	g.visit(o);
	delete a;a=NULL;
	delete s;s=NULL;
	delete o;o=NULL;
	return 0;
}

