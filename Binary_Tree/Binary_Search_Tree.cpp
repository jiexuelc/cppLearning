/*************************************************************************
	> File Name: Binary_Search_Tree.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Thu 31 May 2018 03:36:55 PM CST
	> Description: 二叉查找树操作：插入、删除、更新、遍历
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include"queue_list.h"
using namespace std;


class Bst{
	struct Node{
		T data;
		Node* Left;
		Node* Right;
		Node(const T& d):data(d),Left(),Right(){}
		Node(const T& d, Node* l, Node* r):data(d),Left(l),Right(r){}
	};
	typedef Node* tree;
	Node* rp;
	int dataNum;
public:
	Bst():rp(),dataNum(){}
	~Bst(){clear();}//析构删除二叉树
	int high(){return high(rp);}
	void clear()
	{
		clear(rp);
		dataNum = 0;
	}
	
	void insert(const T& d)
	{
		insert(rp,new Node(d));
		++dataNum;
	}
	
	tree& find(const T& d)
	{
		return find(rp,d);
	}
	
	void travel()
	{//遍历
		cout << "前序遍历：";
		travel_pre_order(rp);
		cout << endl;
		cout << "中序遍历：";
		travel_in_order(rp);
		cout << endl;
		cout << "后序遍历：";
		travel_post_order(rp);
		cout << endl;
	}
	
	bool empty()const
	{
		return rp == NULL;
	}
	
	bool remove(const T& d)
	{//移除节点
		tree& t = find(d);//找到指向这个节点的指针
		if(t == NULL) return false;//没找到
		Node* p = t;//保存节点以便删除
		if(t->Left != NULL){//如果待删除节点左子树不为空
			insert(t->Right,t->Left);//则将左子树插入右子树
		}
		t = t->Right;//让指向待删除的节点的指针指向新根节点
		delete p;
		--dataNum;//更新元素数量
		return true;
	}
	
	const T& root()const
	{
		if(!rp) throw "empty";
		return rp->data;
	}
	
	void update(const T& olddata,const T& newdata)
	{
		if(remove(olddata)){
			insert(newdata);
		}
	}
	
	void insert(tree& t, Node* p)
	{//插入节点
		if(t == NULL){//空树直接建立根节点
			t = p;
		}
		//选取适当位置插入节点
		else if(p->data < t->data){
			insert(t->Left,p);
		}
		else{
			insert(t->Right,p);
		}
	}
	
	Node*& find(tree& t,const T& d)
	{//返回以d为根节点的子树的根指针
		if(t == NULL) return t;//因为返回结果是一个引用变量，这里不能写成NULL
		if(d == t->data) return t;//返回找到的指针
		else if(d < t->data){
			return find(t->Left,d);
		}
		else{
			return find(t->Right,d);
		}
	}
	
	void travel_pre_order(tree& t)
	{//前序遍历
		if(t != NULL){
			cout << t->data << ' ';//输出根节点
			travel_pre_order(t->Left);
			travel_pre_order(t->Right);
		}
	}
	
	void travel_in_order(tree& t)
	{//中序遍历
		if(t != NULL){
			travel_in_order(t->Left);
			cout << t->data << ' ';//输出根节点
			travel_in_order(t->Right);
		}
	}
	
	void travel_post_order(tree& t)
	{//后序遍历
		if(t != NULL){
			travel_post_order(t->Left);
			travel_post_order(t->Right);
			cout << t->data << ' ';//输出根节点
		}
	}
	
	void clear(tree& t)
	{//清空树
		if(t != NULL){
			clear(t->Left);//清左子树
			clear(t->Right);//清右子树
			delete t;//释放根节点内存
			t = NULL;
		}
	}
	
	int high(tree& t)
	{//计算树的高度
		//取左右子树最高的高度加上根节点就是树的高度
		if(t ==NULL) return 0;
		int Lh = high(t->Left);
		int Rh = high(t->Right);
		return (Lh>Rh?Lh:Rh)+1;
	}
	
	void printtree(tree& t,int space,char ch)
	{
		if(t == NULL) return;
		printtree(t->Right, space+3,'/');
		cout << setw(space+1) << ch << t->data << endl;
		printtree(t->Left, space+3,'\\');
	}
	
	void print()
	{
		cout << "----------------------------" << endl;
		printtree(rp,0,'*');
		cout << "----------------------------" << endl;
	}
	
/*	void level_order(tree& t)
	{
		Queue q;
		while(t != NULL){
			cout << t->data << ' ';
			if(t->Left != NULL)
				q.push(t->Left);
			if(t->Right != NULL)
				q.push(t->Right);
			if(q.empty()) return;
			
			cout << q.pop() << ' ';
		}
	}
	
	void level_order()
	{
		cout << "层序遍历：";
		level_order(rp);
		cout << endl;
	}*/
};

int main()
{
	Bst b;
	b.insert(50);b.insert(20);b.insert(75);b.insert(30);
	b.insert(40);b.insert(60);b.insert(80);b.insert(100);
	b.insert(90);b.insert(25);b.insert(67);b.insert(99);
	b.travel();
	b.print();
	//b.level_order();
	cout << b.high() << endl;
	b.remove(90);b.remove(80);b.remove(40);b.remove(99);
	b.travel();
	b.update(60,61);b.update(25,26);b.update(67,70);
	b.travel();
	while(!b.empty()) b.remove(b.root());
	b.travel();
    return 0;
}
