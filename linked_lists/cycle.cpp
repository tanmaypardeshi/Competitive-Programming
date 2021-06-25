/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached 
again by continuously following the next pointer. Internally, pos is used to denote the 
index of the node that tail's next pointer is connected to. Note that pos is not passed 
as a parameter. 
Return true if there is a cycle in the linked list. Otherwise, return false.
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

bool hasCycle(ListNode *head)
{
    ListNode *temp = head;
    if (!temp)
        return false;
    if (!temp->next)
        return false;

    ListNode *slow = head, *fast = head->next;

    while (slow != fast)
    {
        if (fast == NULL || fast->next == NULL)
        {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

int main()
{
    ListNode *head = NULL;
    bool reverse;
    head = createList(head);

    printList(head);

    reverse = hasCycle(head);

    if (reverse)
    {
        cout << "Cycle present" << endl;
    }
    else
    {
        cout << "Cycle not present" << endl;
    }

    return 0;
}