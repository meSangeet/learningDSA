#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key, value, cnt;
    Node* prev;
    Node* next;
    Node(int k, int v)
    {
        key = k;
        value = v;
        cnt = 1;
    }
};

struct List {
    int size;
    Node* head;
    Node* tail;

    List()
    {
        head = new Node(0,0);
        tail = new Node(0,0);
        tail->prev = head;
        head->next = tail;
        size = 0;
    }

    void addFront(Node* node)
    {
        Node* temp = head->next;
        node->next = temp;
        temp->prev = node;
        node->prev = head;
        head->next = node;
        size++;
    }

    void removeNode(Node* delNode)
    {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};

class LFU{
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int maxSize;
    int minFreq;
    int curSize;

    public:
    LFU(int cap)
    {
        maxSize = cap;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(Node *node)
    {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
        {
            minFreq++;
        }

        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt+1) != freqListMap.end())
        {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }
        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    int get(int key)
    {
        if(keyNode.find(key) != keyNode.end())
        {
            Node* node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int val)
    {
        if(maxSize == 0) return;
        if(keyNode.find(key) != keyNode.end())
        {
            Node* node = keyNode[key];
            node->value = val;
            updateFreqListMap(node);
        }else{
            if(curSize == maxSize)
            {
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            //new value has to be added which is not there previously
            minFreq = 1; 
            List* listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end())
            {
                listFreq = freqListMap[minFreq];
            }   
            Node* node = new Node(key, val);
            listFreq->addFront(node);
            keyNode[key]=node;
            freqListMap[minFreq] = listFreq;;
        }

    }
};

int main()
{
    return 0;
}