class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int x1 = 0;
        int x2 = 0;
        if(n%2){
            for(int i = 0; i<m; i++) x2 ^= nums2[i];
        }
        if(m%2){
            for(int i = 0; i<n; i++) x1 ^= nums1[i];
        }
        return x1^x2;
    }
};