#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data, flag;
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
    int countnodes(Node *);
    int countleafnodes(Node *);
    int countnonleafnodes(Node *);
    int displaylevelnode(Node *, int);
    int displaydepthbst(Node *, int);
    void insertnode(Node *, int);
    Node *deletenode(Node *, int);
    void preorder_nr();
    void inorder_nr();
    void postorder_nr();
    void bfs();
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

int BST::countnodes(Node *temp)
{
    static int cntr;
    if (temp != NULL)
    {
        cntr++;
        countnodes(temp->left);
        countnodes(temp->right);
    }
    return cntr;
}

int BST::countleafnodes(Node *temp)
{
    static int cntr;
    if (temp != NULL)
    {
        if (temp->left == NULL && temp->right == NULL)
            cntr++;
        countleafnodes(temp->left);
        countleafnodes(temp->right);
    }
    return cntr;
}

int BST::countnonleafnodes(Node *temp)
{
    static int cntr;

    if (temp != NULL)
    {
        if (temp->left != NULL || temp->right != NULL)
            cntr++;
        countnonleafnodes(temp->left);
        countnonleafnodes(temp->right);
    }
    return cntr;
}

int BST::displaylevelnode(Node *temp, int x)
{
    int level = -1;
    bool flag = false;

    while (temp != NULL)
    {
        level++;
        if (x == temp->data)
        {
            flag = true;
            break;
        }
        else if (x < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    if (flag)
        return level;
    return -1;
}

int BST::displaydepthbst(Node *temp, int level)
{
    static int depth = -1;
    if (temp != NULL)
    {
        level++;

        if (depth < level)
            depth = level;

        displaydepthbst(temp->left, level);
        displaydepthbst(temp->right, level);
    }

    return depth;
}

void BST::insertnode(Node *root, int x)
{
    Node *newnode, *temp;
    newnode = new Node;
    newnode->data = x;
    newnode->flag = 0;
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

void BST::preorder_nr()
{
    stack<Node *> s;
    Node *temp = root;

    while (1)
    {
        while (temp != NULL)
        {
            cout << temp->data << " ";
            if (temp->right != NULL)
            {
                s.push(temp->right);
            }
            temp = temp->left;
        }
        if (!s.empty())
        {
            temp = s.top();
            s.pop();
        }
        else
        {
            break;
        }
    }
}

void BST::inorder_nr()
{
    stack<Node *> s;
    Node *temp = root;

    while (1)
    {
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        if (!s.empty())
        {
            temp = s.top();
            s.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
        else
        {
            break;
        }
    }
}

void BST::postorder_nr()
{
    stack<Node *> s;
    Node *temp = root;

    while (1)
    {
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }

        while (!s.empty())
        {
            temp = s.top();
            s.pop();
            if (temp->flag == 1)
            {
                cout << temp->data << " ";
            }
            else
            {
                temp->flag = 1;
                s.push(temp);
                temp = temp->right;
                break;
            }
        }
        if (s.empty())
        {
            break;
        }
    }
}

void BST::bfs()
{
    queue<Node *> q;

    Node *temp = root;

    q.push(temp);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
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
        cout << "\n5. Count total number of nodes.";
        cout << "\n6. Count total number of leaf nodes.";
        cout << "\n7. Count total number of non leaf nodes.";
        cout << "\n8. Display level of a particular node.";
        cout << "\n9. Display depth of BST.";
        cout << "\n10. Insert a node in BST.";
        cout << "\n11. Delete node in BST.";
        cout << "\n12. Preorder Non Recursive.";
        cout << "\n13. Inorder Non Recursive.";
        cout << "\n14. Postorder Non Recursive.";
        cout << "\n15. BFS Traversal";
        cout << "\n20. Exit.";
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
            cout << "\nTotal number of nodes are:- " << tree.countnodes(tree.getroot()) << endl;
            break;
        case 6:
            cout << "\nTotal number of leaf nodes are:- " << tree.countleafnodes(tree.getroot()) << endl;
            break;
        case 7:
            cout << "\nTotal number of non leaf nodes are:- " << tree.countnonleafnodes(tree.getroot()) << endl;
            break;
        case 8:
            cout << "\nEnter value of node whose level needs to be checked:- ";
            cin >> x;
            cout << "\nLevel of node with value " << x << " is:- " << tree.displaylevelnode(tree.getroot(), x) << endl;
            break;
        case 9:
            cout << "\nDepth of BST is:- " << tree.displaydepthbst(tree.getroot(), -1) << endl;
            break;
        case 10:
            cout << "\nEnter value of node which needs to be inserted:- ";
            cin >> x;
            tree.insertnode(tree.getroot(), x);
            cout << "\nTree is:- ";
            tree.inorder(tree.getroot());
            cout << endl;
            break;
        case 11:
            cout << "\nEnter value of node which needs to be deleted:- ";
            cin >> x;
            tree.deletenode(tree.getroot(), x);
            cout << "\nTree is:- ";
            tree.inorder(tree.getroot());
            cout << endl;
            break;
        case 12:
            cout << "\nPreorder Non Recursive:- ";
            tree.preorder_nr();
            cout << endl;
            break;
        case 13:
            cout << "\nInorder Non Recursive:- ";
            tree.inorder_nr();
            cout << endl;
            break;
        case 14:
            cout << "\nPostorder Non Recursive:- ";
            tree.postorder_nr();
            cout << endl;
            break;
        case 15:
            cout << "\nBFS Traversal:- ";
            tree.bfs();
            cout << endl;
            break;
        case 20:
            return 0;
        default:
            cout << "\nError in choice, try again" << endl;
        }
    }
    return 0;
}