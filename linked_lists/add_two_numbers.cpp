/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

struct ListNode
{
    lli val;
    ListNode *next;
};

ListNode *createList(ListNode *head)
{
    ListNode *temp, *newnode;
    lli data;
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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *newnode, *head = NULL, *temp;
    int carry = 0, sum = 0;
    while (l1 != NULL && l2 != NULL)
    {
        sum = l1->val + l2->val + carry;
        newnode = new ListNode;
        if (sum > 9)
        {
            newnode->val = sum - 10;
            carry = 1;
        }
        else
        {
            newnode->val = sum;
            carry = 0;
        }
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
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL)
    {
        newnode = new ListNode;
        newnode->next = NULL;
        sum = l1->val + carry;
        if (sum > 9)
        {
            newnode->val = sum - 10;
            carry = 1;
        }
        else
        {
            newnode->val = sum;
            carry = 0;
        }
        temp->next = newnode;
        temp = newnode;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        newnode = new ListNode;
        newnode->next = NULL;
        sum = l2->val + carry;
        if (sum > 9)
        {
            newnode->val = sum - 10;
            carry = 1;
        }
        else
        {
            newnode->val = sum;
            carry = 0;
        }
        temp->next = newnode;
        temp = newnode;
        l2 = l2->next;
    }
    if (carry)
    {
        newnode = new ListNode;
        newnode->next = NULL;
        newnode->val = 1;
        temp->next = newnode;
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

    merged = addTwoNumbers(l1, l2);

    printList(merged);

    return 0;
}