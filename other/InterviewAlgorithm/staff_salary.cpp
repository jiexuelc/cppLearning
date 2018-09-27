/*************************************************************************
	> File Name: staff_salary.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Thu 27 Sep 2018 04:05:39 PM CST
	> Description: 从员工的月工资原始数据串中提取出员工姓名和工资信息
            1.要求创建所有员工信息的单向循环链表
            2.函数返回该链表的头指针
            3.函数内部打印出最高工资员工的姓名和工资
            4.(原始数据类似于">Zhang$4000>Jack$12000>Jery$13000>Tom$10000>Wang$15000"的字符串)
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

/*
 * 员工信息节点
 */
struct staff{
    char name[20];  //  姓名
    int data;       //工资
    struct staff* next; //下一个员工信息节点指针
};

/*
 * 将字符串解析出的信息存储在链表中
 * 打印出所有员工中工资最多的那一位
 */
struct staff *convert(const char* s)
{
    struct staff* head = (struct staff*)malloc(sizeof(struct staff));//为头节点申请内存
    head->next = head;//将头节点指向头节点形成单向循环链表
    struct staff max = {"",-1};//把max初始化为无效值
    int i;
    char name[20];//解析出的临时姓名变量
    int ni;
    char salary[10];//解析出的临时工资字符串变量
    int si;
    
    /* 字符串解析 */
    for(i = 0; *(s+i) != '\0';)
    {
        /* 定位员工姓名的起始位置 */
        if(*(s+i) == '>')
        {
            ++i;
            ni = 0;
            for(; *(s+i) != '$'; i++)
                name[ni++] = *(s+i);
            name[ni] = '\0';
        }
        
        /* 定位员工月工资的起始位置 */
        if(*(s+i) == '$')
        {
            ++i;
            si = 0;
            for(; *(s+i) != '>' && *(s+i) != '\0'; i++)
                salary[si++] = *(s+i);
            salary[si] = '\0';
        }
        
        struct staff* p = (struct staff*)malloc(sizeof(struct staff));//申请存储节点内存
        strcpy(p->name, name);
        p->data = atoi(salary);//将工资字符串转换为整形存储
        
        /* 将新增节点从插入到单向循环链表中:每次插入到头指针后面实现起来比较容易 */
        p->next = head->next;
        head->next = p;
        
        /* 查找工资最高的员工 */
        if(max.data < p->data)
        {
            strcpy(max.name, p->name);
            max.data = p->data;
        }
        //printf("%s ", p->name);
        //printf("%d\n",p->data);
    }
    cout << "max: " << max.name << " " << max.data << endl;
    return head;
}

/*
 * 遍历单向循环链表进行输出
 */
void show(struct staff* head)
{
    struct staff* p = head;
    for(p = p->next; p != head; p = p->next)
    {
        cout << p->name << " " << p->data << endl;
    }
}

/*
 * 释放循环链表内存
 */
void Free(struct staff** phead)
{
    struct staff* pT;
    
    /* 先将头节点以后的节点内存释放掉 */
    while((*phead)->next != *phead)
    {
        pT = (*phead)->next->next;
        free((*phead)->next);
        (*phead)->next = pT;
    }
    
    /* 后将头节点释放掉 */
    if((*phead)->next == *phead)
    {
        free(*phead);
        *phead = NULL;     
    }
    
    cout << "free list completed" << endl;
}

int main()
{
    const char s[4000] = ">Zhang$4000>Jack$12000>Jery$13000>Tom$10000>Wang$15000";
    
    struct staff* head = convert(s);
    
    show(head);
    
    Free(&head);
    
    return 0;
}