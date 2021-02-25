#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef __CircularList__
#define __CircularList__

typedef int Item;//������������

typedef struct node//�ڵ�
{
    Item data;
    struct node* last;
    struct node* next;
} Node;

typedef struct list//����
{
    int size;
    Node* head;
    Node* tail;
} List;

void InitializeList(List* plist)//��ʼ������
{
    plist->size = 0;
    plist->head = NULL;
    plist->tail = NULL;
}

void AddNode(Item* pi, List* plist)//���ӽڵ�
{
    Node* newnode;
    newnode = (Node*)malloc(sizeof(Node));
    if (plist->head == NULL)
    {
        plist->head = plist->tail = newnode;
        newnode->data = *pi;
        newnode->last = plist->tail;
        newnode->next = plist->head;
        plist->size++;
    }
    else
    {
        newnode->data = *pi;
        newnode->last = plist->tail;
        newnode->next = plist->head;
        plist->head->last = newnode;
        plist->tail->next = newnode;
        plist->tail = newnode;
        plist->size++;
    }
}

void DeleteNode(Node* pNode, List* plist)//ɾ���ڵ�
{
    if (plist->head == pNode)
    {
        plist->head = plist->head->next;
        plist->head->last = plist->tail;
        plist->tail->next = plist->head;
        free(pNode);
        plist->size--;
    }
    else if (plist->tail == pNode)
    {
        plist->tail = plist->tail->last;
        plist->tail->next = plist->head;
        plist->head->last = plist->tail;
        free(pNode);
        plist->size--;
    }
    else
    {
        pNode->last->next = pNode->next;
        pNode->next->last = pNode->last;
        free(pNode);
        plist->size--;
    }
}


#endif // !__CircularList__

#ifndef __List__
#define __List__

typedef int Item;//������������

typedef struct node//�ڵ�
{
    Item data;
    struct node* next;
} Node;

typedef struct list//����
{
    int size;
    Node* head;
    Node* tail;
} List;

void InitializeList(List* plist)//��ʼ������
{
    plist->size = 0;
    plist->head = NULL;
    plist->tail = NULL;
}

void AddNode(Item* pi, List* plist)//���ӽڵ�
{
    Node* newnode;
    newnode = (Node*)malloc(sizeof(Node));
    if (plist->head == NULL)
    {
        plist->head = plist->tail = newnode;
        newnode->data = *pi;
        newnode->next = NULL;
        plist->size++;
    }
    else
    {
        newnode->data = *pi;
        plist->tail->next = newnode;
        plist->tail = newnode;
        newnode->next = NULL;
        plist->size++;
    }
}

void DeleteNode(Node* pNode, List* plist)//ɾ���ڵ�
{
    Node* tempNode;

    if (plist->head == pNode)
    {
        plist->head = plist->head->next;
        free(pNode);
        plist->size--;
    }
    else if (plist->tail == pNode)
    {
        tempNode = plist->head;
        while (tempNode->next != plist->tail)
        {
            tempNode = tempNode->next;
        }
        plist->tail = tempNode;
        plist->tail->next = NULL;
        free(pNode);
        plist->size--;
    }
    else
    {
        tempNode = plist->head;
        while (tempNode->next != pNode)
        {
            tempNode = tempNode->next;
        }
        tempNode->next = pNode->next;
        free(pNode);
        plist->size--;
    }
}

void DeleteAll(List* plist)//�������
{
    Node* pnode = plist->head;

    while (plist->size > 0)
    {
        plist->head = plist->head->next;
        free(pnode);
        pnode = plist->head;
        plist->size--;
    }
}


#endif // !__List__
