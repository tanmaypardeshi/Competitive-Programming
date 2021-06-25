/*
Given the heads of two singly linked-lists headA and headB, 
return the node at which the two lists intersect. 
If the two linked lists have no intersection at all, return null.
*/

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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int lena = 0, lenb = 0, diff = 0;
    ListNode *a = headA, *b = headB;

    while (a)
    {
        lena++;
        a = a->next;
    }

    while (b)
    {
        lenb++;
        b = b->next;
    }

    if (lena > lenb)
    {
        diff = lena - lenb;

        while (diff)
        {
            headA = headA->next;
            diff--;
        }
    }
    else
    {
        diff = lenb - lena;

        while (diff)
        {
            headB = headB->next;
            diff--;
        }
    }

    while (headA && headB)
    {
        if (headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }

    return NULL;
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

    merged = getIntersectionNode(l1, l2);

    printList(merged);

    return 0;
}