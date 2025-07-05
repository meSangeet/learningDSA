class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;
        int val = 0;
        int mx = -1;
        unordered_map<int,int> m;
        for(int x : arr){
            m[x]++;
        }

        for(auto &[no, val] : m){
            if(no == val){
                ans = max(ans, no);
            }
        }

        return ans;
    }
};