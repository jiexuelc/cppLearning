/*************************************************************************
	> File Name: Stack_list.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Wed 30 May 2018 09:41:12 PM CST
	> Description: 利用单向线性链表模拟栈操作(在链表首push与pop)
 ************************************************************************/

#include<iostream>
using namespace std;
typedef string T;

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
	void clear();
 	bool empty(){return head == NULL;}
};

Chain::Chain(int initial)//构造函数
{
	if(initial < 0)
	{
		//ostringstream s;
		cout << "Initial Capacity = " << initial << "Must be >= 0\n";
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
	clear();
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

void Chain::clear()
{
	while(head != NULL)
	{
		chainNode* nextNode = head->next;
		delete head;
		head = nextNode;
	}
}

class Stack{
    Chain l;
public:
    //Stack():cur(0){}
    void push(const T& d);
    T pop()throw(const char*);
    const T& top()const;
    bool empty()const;
    void clear(){l.clear();}
};

void Stack::push(const T& d)
{
	l.insert(0,d);
}

T Stack::pop()throw(const char*)
{
	if(l.empty())throw "empty";
	T d = l.get(0);
	l.erase(0);
	return d;
}

const T& Stack::top()const
{
	return l.get(0);
}

bool Stack::empty()const
{
	return l.empty();
}

int main()
{
	Stack s;
	try{
		s.push("liranlong");
		s.push("lichao");
		s.push("wanglin");
		s.push("lichun");
		s.push("limao");
		s.push("lilin");
		s.push("wanglin");
    }
    catch(const char *e){
        cout << "异常：" << e <<endl;
    }
    cout << "栈顶元素：" << s.top() <<endl;
    try{
        while(!s.empty())
            cout << s.pop() <<endl;
        cout << s.pop() << endl;
    }
    catch(const char *e){
        cout << "异常：" << e <<endl;
    }
    return 0;
}
