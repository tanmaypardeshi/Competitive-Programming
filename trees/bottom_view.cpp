#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data, flag, hd;
    Node *left, *right;
} Node;

class BST
{
    Node *root;

public:
    BST();
    void create();
    Node *getroot();
    void preorder(Node *);
    void inorder(Node *);
    void postorder(Node *);
    void insertnode(Node *, int);
    Node *deletenode(Node *, int);
    void bottom_view(Node *);
};

BST::BST()
{
    cout << "\nInitialised root to NULL";
    root = NULL;
}

void BST::create()
{
    Node *newnode, *temp;
    int data;
    char ask = 'y';

    while (ask == 'y' || ask == 'Y')
    {
        newnode = new Node;
        cout << "Enter data:- ";
        cin >> data;
        newnode->data = data;
        newnode->flag = 0;
        newnode->hd = INT_MAX;
        newnode->left = NULL;
        newnode->right = NULL;

        if (root == NULL)
        {
            root = newnode;
        }
        else
        {
            temp = root;
            while (1)
            {
                if (newnode->data < temp->data)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = newnode;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (temp->right == NULL)
                    {
                        temp->right = newnode;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
        cin.ignore();
        cout << "Do you want to add more nodes:- ";
        cin >> ask;
    }
    cout << "\nCreated a BST!" << endl;
}

Node *BST::getroot()
{
    return root;
}

void BST::preorder(Node *temp)
{

    if (temp != NULL)
    {
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void BST::inorder(Node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}

void BST::postorder(Node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
}

void BST::insertnode(Node *root, int x)
{
    Node *newnode, *temp;
    newnode = new Node;
    newnode->data = x;
    newnode->flag = 0;
    newnode->hd = INT_MAX;
    newnode->left = NULL;
    newnode->right = NULL;

    temp = root;

    while (1)
    {
        if (newnode->data < temp->data)
        {
            if (temp->left == NULL)
            {
                temp->left = newnode;
                break;
            }
            else
            {
                temp = temp->left;
            }
        }
        else
        {
            if (temp->right == NULL)
            {
                temp->right = newnode;
                break;
            }
            else
            {
                temp = temp->right;
            }
        }
    }
}

Node *BST::deletenode(Node *t, int x)
{
    Node *temp;

    if (t == NULL)
    {
        cout << "\nElement " << x << " not found!" << endl;
        return t;
    }
    if (x < t->data)
    {
        t->left = deletenode(t->left, x);
        return t;
    }
    else if (x > t->data)
    {
        t->right = deletenode(t->right, x);
        return t;
    }
    else
    {
        if (t->left == NULL && t->right == NULL)
        {
            temp = t;
            delete temp;
            return NULL;
        }
        if (t->left == NULL)
        {
            temp = t;
            t = t->right;
            delete temp;
            return t;
        }
        if (t->right == NULL)
        {
            temp = t;
            t = t->left;
            delete temp;
            return t;
        }
        temp = t->right;
        while (temp->left != NULL)
            temp = temp->left;
        t->data = temp->data;
        t->right = deletenode(t->right, temp->data);
        return t;
    }
    return NULL;
}

void print_bottom_view(Node *temp, int level, int hd, map<int, pair<int, int>> &m)
{
    if (temp == NULL)
        return;

    if (m.find(hd) == m.end())
    {
        m[hd] = make_pair(temp->data, level);
    }

    else
    {
        pair<int, int> p = m[hd];
        if (p.second <= level)
        {
            m[hd].second = level;
            m[hd].first = temp->data;
        }
    }

    print_bottom_view(temp->left, level + 1, hd - 1, m);
    print_bottom_view(temp->right, level + 1, hd + 1, m);
}

void BST::bottom_view(Node *root)
{
    map<int, pair<int, int>> mp;

    print_bottom_view(root, 0, 0, mp);

    for (auto x : mp)
    {
        cout << x.second.first << " ";
    }
    cout << endl;
}

int main()
{
    BST tree;

    int choice, x;

    while (1)
    {
        cout << "\n\nBinary Search Tree Operations ";
        cout << "\n1. Create.";
        cout << "\n2. Preorder Recursive.";
        cout << "\n3. Inorder Recursive";
        cout << "\n4. Postorder Recursive";
        cout << "\n5. Insert a node in BST.";
        cout << "\n6. Delete node in BST.";
        cout << "\n7. Print bottom view of the tree.";
        cout << "\n8. Exit.";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            tree.create();
            break;
        case 2:
            cout << "\nPreorder Recursive:- ";
            tree.preorder(tree.getroot());
            cout << endl;
            break;
        case 3:
            cout << "\nInorder Recursive:- ";
            tree.inorder(tree.getroot());
            cout << endl;
            break;
        case 4:
            cout << "\nPostorder Recursive:- ";
            tree.postorder(tree.getroot());
            cout << endl;
            break;
        case 5:
            cout << "\nEnter value of node which needs to be inserted:- ";
            cin >> x;
            tree.insertnode(tree.getroot(), x);
            cout << "\nTree is:- ";
            tree.inorder(tree.getroot());
            cout << endl;
            break;
        case 6:
            cout << "\nEnter value of node which needs to be deleted:- ";
            cin >> x;
            tree.deletenode(tree.getroot(), x);
            cout << "\nTree is:- ";
            tree.inorder(tree.getroot());
            cout << endl;
            break;
        case 7:
            cout << "\nBottom View is:- ";
            tree.bottom_view(tree.getroot());
            cout << endl;
            break;
            break;
        case 8:
            return 0;
        default:
            cout << "\nError in choice, try again" << endl;
        }
    }
    return 0;
}