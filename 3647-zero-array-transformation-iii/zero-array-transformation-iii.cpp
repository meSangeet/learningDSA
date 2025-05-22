class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> arr(n+1,0) ;
        sort(queries.begin(), queries.end(),[](const vector<int>& a, const vector<int>& b) {
             return a[0] < b[0];
            });
        
        int k = queries.size();
        int j = 0;
        int prefix = 0;
        priority_queue<int> hq;


        for (int i = 0; i < n; i++){
            prefix += arr[i];
            while( j < k && queries[j][0] == i){
                hq.push(  queries[j][1]);
                j += 1;
            }
            while (prefix < nums[i] && !hq.empty() && hq.top() >= i){
                prefix += 1;
                arr[hq.top() + 1] -= 1;
                hq.pop();
            }
            if (prefix < nums[i]){
                return -1;
            }
        }
        
        return hq.size();
    }
};