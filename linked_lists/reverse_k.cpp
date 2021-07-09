/*
Given a linked list, reverse the nodes of a linked list k at a time and return its 
modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should 
remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

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

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || k == 1)
        return head;

    ListNode *dummy = new ListNode;
    dummy->val = 0;
    dummy->next = head;

    ListNode *prev = dummy, *curr = dummy, *next = dummy;

    int count = 0;

    while (curr->next != NULL)
    {
        count++;
        curr = curr->next;
    }

    while (count >= k)
    {
        curr = prev->next;
        next = curr->next;

        for (int i = 1; i < k; i++)
        {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        prev = curr;
        count -= k;
    }

    return dummy->next;
}

int main()
{
    ListNode *head = NULL;
    ListNode *reverse = NULL;
    int k;
    head = createList(head);
    cin >> k;
    printList(head);

    reverse = reverseKGroup(head, k);

    printList(reverse);

    return 0;
}