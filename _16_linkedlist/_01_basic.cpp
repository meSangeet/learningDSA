#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    int val;
    node* next;

    node(int x)
    {
        val = x;
        next = NULL;
    }
};

void printlist(node* head)
{
    while(head)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
}

void  del(node *head)
{
    node* curr = head->next;
    node* prev = head;
    while(curr -> next)
    {
        prev = curr;
        curr = curr->next;
    }
    delete curr;
    prev->next = NULL;
}
//main function
int main()
{
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
    }

    node* head = new node(a[0]);
    node* curr = head;
    for(int i = 1; i<n; i++)
    {
        node * temp = new node(a[i]);
        curr->next = temp;
        curr = temp;
    }
    printlist(head);
    del(head);
    cout<<endl;
    printlist(head);
    return 0;
}