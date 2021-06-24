/*
Given a non-empty, singly linked list with head node head, return a middle node of linked list.
If there are two middle nodes, return the second middle node.
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *createList(ListNode *head)
{
    ListNode *temp, *newnode;
    int data;
    char ask = 'y';

    while (ask == 'y' || ask == 'Y')
    {
        cout << "Enter data:- ";
        cin >> data;

        newnode = new ListNode;

        newnode->val = data;
        newnode->next = NULL;

        if (!head)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        cout << "Do you want to add more nodes:- ";
        cin >> ask;
        cin.ignore();
    }
    return head;
}

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode *middleNode(ListNode *head)
{
    int cnt = 0;
    ListNode *temp = head;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }

    for (int i = 0; i < cnt / 2; i++)
    {
        head = head->next;
    }
    return head;
}

int main()
{
    ListNode *head = NULL;
    ListNode *middle = NULL;
    head = createList(head);

    printList(head);

    cout << middleNode(head) << endl;

    middle = middleNode(head);

    cout << middle->val << endl;

    return 0;
}