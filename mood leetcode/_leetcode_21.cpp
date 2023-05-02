/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
int main()
{
    
    
    
    return 0;
}
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* it1, *it2, *head, *curr;
        it1 = list1;
        it2 = list2;
        
        if(!it1)
        {
            return list2;
        }
        if(!it2)
        {
            return list1;
        }
        if(it1->val > it2->val)
        {
            head = it2;
            it2 = it2->next;
        }else{
            head = it1;
            it1 = it1->next;
        }
        curr = head;
        while(it1 && it2)
        {
            if(it1->val > it2->val)
            {
                curr->next = it2;
                curr = it2;
                it2 = it2->next;
            }else{
                curr->next = it1;
                curr = it1;
                it1 = it1->next;
            }
        }
        while(it1)
        {
            curr->next = it1;
            curr = it1;
            it1 = it1->next;
        }
        while(it2)
        {
            curr->next = it2;
            curr = it2;
            it2 = it2->next;
        }
        return head;
    }
};