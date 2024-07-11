#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int key;
    int val;
    node * next;
    node * prev;
    node(int k, int v)
    {
        key = k;
        val = v;
    }
};

class LRU
{
    public :
    
    node * head = new node (0,0);
    node * tail = new node (0,0);

    int cap;
    unordered_map<int, node*> m;

    LRU(int c)
    {
        cap = c;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node * newNode)
    {
        node * temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(node * del)
    {
        node * delPrev = del->prev;
        node * delnext = del->next;
        delPrev->next = delnext;
        delnext->prev = delPrev;
    }
    
    int get(int key_)
    {
        if(m.find(key_) != m.end() /*it means that the node is present in the dll*/){
            node * resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deleteNode(resnode);
            addNode(resnode);
            m[key_] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key_, int value)
    {
        if(m.find(key_) != m.end())
        {
            node * Node = m[key_];
            m.erase(key_);
            deleteNode(Node);
        }

        if(m.size() == cap){
            m.erase(tail -> prev -> key);
            deleteNode(tail->prev);
        }

        addNode(new node(key_, value));
        m[key_] = head->next;
    }
};

int main()
{


    return 0;
}