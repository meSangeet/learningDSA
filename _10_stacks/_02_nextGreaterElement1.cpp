class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(int i = 0; i<nums2.size(); i++)
        {
            m[nums2[i]] = i;
        }

        stack<int> s;
        int i = nums2.size()-1;
        while(i >= 0)
        {
            if(s.empty())
            {
                s.push(nums2[i]);
                nums2[i] = -1;
            }else{
                while(!s.empty() && s.top()<nums2[i]) s.pop();
                if(s.empty()){ s.push(nums2[i]);
                nums2[i] = -1;
                }else{
                    int temp = s.top();
                    s.push(nums2[i]);
                    nums2[i] = temp;
                }
            }
            i--;
        }
    for(int j = 0; j<nums2.size(); j++) cout<<nums2[j]<<" ";
    cout<<endl;
        vector<int> ans;
        for(int j = 0; j<nums1.size(); j++)
        {
            ans.push_back(nums2[m[nums1[j]]]);
        }

        return ans;
    }

};