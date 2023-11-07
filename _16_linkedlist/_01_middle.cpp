#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    int data;
    node* next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

node* middleNode(node* head)
{
    node* fast = head, *slow = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

//main function
int main()
{

    return 0;
}