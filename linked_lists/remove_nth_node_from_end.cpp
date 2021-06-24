/*
Given the head of a linked list, remove the nth 
node from the end of the list and return its head.
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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int count = 0;
    ListNode *temp = head;

    while (temp)
    {
        count++;
        temp = temp->next;
    }

    if (count == 1)
    {
        return NULL;
    }

    int pos = count - n;

    if (pos == 0)
    {
        return head->next;
    }
    temp = head;

    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;

    return head;
}

int main()
{
    ListNode *head = NULL;
    int n;
    head = createList(head);
    cout << "Enter n:- ";
    cin >> n;
    printList(head);

    head = removeNthFromEnd(head, n);

    printList(head);

    return 0;
}