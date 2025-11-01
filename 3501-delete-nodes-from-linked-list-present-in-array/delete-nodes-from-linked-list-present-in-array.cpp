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
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s;
        for(int x : nums) s.insert(x);
        ListNode* temp = head;
        while(head and s.count(head->val)){
            head = head->next;
        }
        temp = head;
        while(temp->next){
            while(temp->next and s.count(temp->next->val)){
                temp->next = temp->next->next;
            }
            if(temp->next){
                temp = temp->next;
            }
        }

        return head;
    }
};