class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int n = items.size();
        
        vector<int> curMax(n);
        int cur = items[0][1];
        for(int i = 0; i<n; i++){
            cur = max(cur, items[i][1]);
            curMax[i] = cur;
        }
        vector<int> ansVec;
        int q = queries.size();
        for(int i = 0; i<q; i++){
            int ans = 0;
            int price = queries[i];
            int l = 0, r = n-1;
            int mid = l + (r-l)/2;
            while(l <= r){
                if(items[mid][0] <= price){
                    ans = curMax[mid];
                    l = mid+1;
                }else{
                    r = mid-1;
                }
                mid = l + (r-l)/2;
            }
            ansVec.push_back(ans);
        }

        return ansVec;
    }
};