#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int s = m;
        int p = 0;
        if(n == 0) return;
        while(s < nums1.size() && p < nums2.size())
        {
            nums1[s] = nums2[p];
            cout<<s<<" "<<nums1[s]<<" , ";
            s++;
            p++;
        }
        cout<<endl;
        for(int i = 0; i<nums1.size(); i++)
        {
            cout<<nums1[i]<<" ";
        }
        sort(nums1.begin(), nums1.end());
    }
};

int main()
{
    
    return 0;
}