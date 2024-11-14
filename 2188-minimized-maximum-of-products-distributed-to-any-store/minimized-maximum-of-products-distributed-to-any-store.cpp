class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 0;
        int r = *max_element(quantities.begin(), quantities.end());
        int mid = l + (r-l)/2;
        int ans = r;
        while(l <= r){
            int cur = 0;
            bool flag = true;
            for(int x : quantities){
                int xx = x;
                while(xx >= mid){
                    cur++;
                    if(cur > n){
                        flag = false;
                        break;
                    }
                    xx -= mid;
                }

                if(xx != 0){
                    cur++;
                }

                if(cur > n){
                    flag = false;
                    break;
                }
            }

            if(flag){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }

            mid = l + (r-l)/2;
        }

        return ans;
    }
};