/*************************************************************************
	> File Name: queue_list.h
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Thu 31 May 2018 09:54:44 PM CST
	> Description: 
 ************************************************************************/

#ifndef _QUEUE_LIST_H
#define _QUEUE_LIST_H 1
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
 	int listlen(){return listSize;}
};

class Queue{
    Chain l;
public:
    Queue& push(const T& d);
    T pop()throw(const char*);
    const T& front();
	const T& back()const;
    bool empty()const;
    void clear(){l.clear();}    
};

#endif

