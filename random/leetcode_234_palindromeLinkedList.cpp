#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

bool isPalindrome(ListNode* head) {
        bool flag = true;
        string no = "";
        ListNode* temp = head;
        while(temp)
        {
            int t = temp->val;
            char tem = '0' + t;
            no.push_back(tem);
            temp = temp->next;
        }
        int size = no.size();
        int i = 0, j = (size - 1);
        while(i < j)
        {
            if(no[i] != no[j])
            {
                flag = false;
            }
                i++;
                j--;
        }
        return flag;
}

int main()
{
    
    
    
    return 0;
}