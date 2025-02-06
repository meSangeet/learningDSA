class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                m[nums[i]*nums[j]]++;
            }
        }
        int ans = 0;
        for(auto x : m){
            int no = x.second;
            int temp = no*(no-1);
            temp /= 2;
            temp *= 8;
            ans += temp;
        }
        return ans;
    }
};