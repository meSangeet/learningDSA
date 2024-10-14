class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
       priority_queue<int> pq(nums.begin(), nums.end());
       long long ans = 0;
       while(k--){
        double maax = pq.top();
        pq.pop();
        ans += maax;
        pq.push(ceil(maax/3));
       } 
       return ans;
    }
};