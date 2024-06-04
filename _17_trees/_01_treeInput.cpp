#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node* create()
{
    cout<<"enter root value - ";
    int x; cin>>x;
    Node* root = new Node(x);
    int n;
    while(true){
        line:
        cout<<"\nenter 1 to enter new node and 2 to exit - ";
        cin>>n;
        if(n == 2)
        {
            break;
        }

        Node* curr = root;
        int y; cout<<"\nenter the value of node - "; cin>>y;
        Node* temp = new Node(y);
        while(curr->left && curr->right)
        {
            cout<<"enter 1 to go right of "<<curr->data<<" and 2 to go left of "<<curr->data<<" - ";
            int opt; cin>>opt;
            if(opt == 1)
            {
                curr = curr->right;
            }else{
                curr = curr->left;
            }
        }

        while(curr->left)
        {
            cout<<"enter 1 to go left of "<<curr->data<<" ans 2 to enter the node at right of "<<curr->data<<" - ";
            int opt; cin>>opt;
            if(opt == 1)
            {
                curr = curr->left;
            }else{
                curr->right = temp;
                goto line;
            }
        }

        while(curr->right)
        {
            cout<<"enter 1 to go right of "<<curr->data<<" ans 2 to enter the node at left of "<<curr->data<<" - ";
            int opt; cin>>opt;
            if(opt == 1)
            {
                curr = curr->right;
            }else{
                curr->left = temp;
                goto line;
            }
        }
        
        cout<<"enter 1 to add node to right of "<<curr->data<<" 2 to add to left and 3 to do nothing - "; int oo; cin>>oo;
        if(oo == 1)
        {
            curr->right = temp;
        }else if(oo == 2)
        {
            curr->left = temp;
        }else{
            continue;
        }
    }
}

void preorder(Node* root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    Node* root = create();
    preorder(root);
    return 0;
}