/*************************************************************************
	> File Name: list.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Mon 21 May 2018 08:56:16 PM CST
	> Description: 链表C++实现以及链表的增、删、查、改、倒序、排序操作(节点交换法)
 ************************************************************************/

#include<iostream>
using namespace std;
typedef int T;

struct chainNode
{
	T element;
	chainNode *next;
	
	chainNode(){}
	chainNode(const T& element)
	{
		this->element =element;
	}
	chainNode(const T& element,chainNode* next)
	{
		this->element = element;
		this->next = next;
	}
};

class Chain
{
	//checkIndex(int theIndex) const;
	chainNode* head;
	int listSize;
public:
	Chain(int initial = 0);
	Chain(const Chain &);
	~Chain();
	bool empty() const
	{
		return listSize == 0;
	}
	int size() const
	{
		return listSize;
	}
	T& get(int theIndex) const;
	int indexOf(const T&) const;
	chainNode*& getptr(int theIndex);
	void erase(int theIndex);
	void insert(int theIndex, const T& element);
	void update(int theIndex,const T& d);
	void travel() const;
	void invert();
	void Sort();
};

Chain::Chain(int initial)//构造函数
{
	if(initial < 1)
	{
		//ostringstream s;
		cout << "Initial Capacity = " << initial << "Must be > 0\n";
		//throw s.str();
	}
	head = NULL;
	listSize = 0;
}

Chain::Chain(const Chain & theList)//复制(拷贝)构造函数
{
	listSize = theList.listSize;
	if(listSize == 0)
	{
		head = NULL;
		return ;
	}
	
	chainNode* sourceNode = theList.head;//复制原链表首个节点地址
	head = new chainNode(sourceNode->element);//新建目标链表头，并将复制的首个节点的数据地址存在head里面
	sourceNode = sourceNode->next;//指向下一节点
	chainNode* targetNode = head;//复制目标链表首地址
	while(sourceNode != NULL)
	{
		targetNode->next = new chainNode(sourceNode->element);//开辟新内存，并将下一节点元素地址保存于当前节点
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = NULL;
}

Chain::~Chain()
{
	while(head != NULL)
	{
		chainNode* nextNode = head->next;
		delete head;
		head = nextNode;
	}
}

T &Chain::get(int theIndex) const
{//得到第theIndex位置节点值
	chainNode* currentNode = head;
	for(int i = 0; i < theIndex; i++)
	{
		currentNode = currentNode->next;
	}
	return currentNode->element;
}

int Chain::indexOf(const T& theElement) const
{
	//返回元素element首次出现时的索引
	//元素不存在时返回-1
	chainNode* currentNode = head;
	int Index = 0;
	while(currentNode != NULL && currentNode->element != theElement)
	{
		currentNode = currentNode->next;
		Index++;
	}
	if(currentNode == NULL)
		return -1;
	else
		return Index;
}

chainNode*& Chain::getptr(int theIndex)
{//返回元素节点索引指针
	if(theIndex < 0 || theIndex >=listSize)
		theIndex = 0;
	if(theIndex ==0) return head;
	chainNode* ptr = head;
	for(int i = 1;i < theIndex;i++)
		ptr = ptr->next;
	return ptr->next;//不可返回ptr
}

void Chain::erase(int theIndex)
{//删除索引节点
	chainNode*& deleteNode = getptr(theIndex);
	chainNode* temp = deleteNode;
	deleteNode = deleteNode->next;
	delete temp;	
	listSize--;
}

void Chain::insert(int theIndex, const T& element)
{
	chainNode*& ptr = getptr(theIndex);
	chainNode* p = new chainNode(element);
	p->next = ptr;
	ptr = p;
	++listSize;
}

void Chain::travel() const
{
	chainNode* p = head;
	while(p != NULL){
		cout << p->element << ' ';
		p = p->next;
	}
	cout << endl;
}

void Chain::update(int theIndex,const T& d)
{
	chainNode*& p = getptr(theIndex);
	p->element = d;
}

void Chain::invert()//链表倒置
{
	//算法思想：将第一个节点以后的节点依次插入到第一个节点以前
	
	if(listSize<2) return;//链表长度小于２为链表本身
	chainNode* p = head->next;//保存指向第2个节点的指针
	head->next = NULL;
	chainNode* p1 = NULL;
	while(p != NULL){
		p1 = p;//保存当前节点指针
		p = p->next;//指向下一节点
		p1->next = head;
		head = p1;
	}
}

void Chain::Sort()
{
	//第一个节点没有前驱，不便于交换地址，故增加一个指向第一个节点的节点，便于交换地址
	chainNode *ph = new chainNode();
	ph->next = head;//新增节点指向第一个节点
	head = ph;//让头指向新增节点
	bool flag = false;//是否交换的标志，如果一轮没有交换则证明排序完成
	chainNode* temp = NULL;
	
	do{
		flag = false;//重置交换标志
		for(ph = head; ph->next->next != NULL; ph = ph->next){
			if(ph->next->element < ph->next->next->element){
				//交换两个节点地址(令当前位置为１)
				temp = ph->next->next;//保存指向第２个节点的指针
				ph->next->next = temp->next;//将第１个节点的next指向第3个节点
				temp->next = ph->next;//将第2个节点的next指向第1个节点
				ph->next = temp;//将指向第1个节点的指针指向第2个节点
				
				flag = true;//设置交换标志
			}
		}
	}while(flag);
	ph = head;//
	head = ph->next;//删除增加的那个节点
	delete ph;//回收地址
	ph = NULL;
}

int main()
{
	Chain l(5);
	l.insert(0,1);
	l.insert(0,2);
	l.insert(0,3);
	l.insert(0,4);
	l.insert(0,5);
	l.insert(0,6);
	l.travel();//6 5 4 3 2 1
	//l.update(3,4);
	//l.travel();
	l.invert();
	cout << "倒序输出：";
	l.travel();//1 2 3 4 5 6
	l.Sort();
	cout << "从大到小输出：";
	l.travel();//6 5 4 3 2 1
    return 0;
}