/*
Merge two sorted linked lists and return it as a sorted list. 
The list should be made by splicing together the nodes of the first two lists.
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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL && l2 == NULL)
        return NULL;
    else if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;

    ListNode *head, *temp;
    if (l1->val <= l2->val)
    {
        head = temp = l1;
        l1 = l1->next;
        temp->next = NULL;
    }
    else
    {
        head = temp = l2;
        l2 = l2->next;
        temp->next = NULL;
    }

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val <= l2->val)
        {
            temp->next = l1;
            temp = l1;
            l1 = l1->next;
            temp->next = NULL;
        }
        else
        {
            temp->next = l2;
            temp = l2;
            l2 = l2->next;
            temp->next = NULL;
        }
    }

    if (l1 != NULL)
    {
        temp->next = l1;
    }

    if (l2 != NULL)
    {
        temp->next = l2;
    }

    return head;
}

int main()
{
    ListNode *l1 = NULL;
    ListNode *l2 = NULL;
    ListNode *merged = NULL;
    l1 = createList(l1);
    l2 = createList(l2);

    printList(l1);
    printList(l2);

    merged = mergeTwoLists(l1, l2);

    printList(merged);

    return 0;
}