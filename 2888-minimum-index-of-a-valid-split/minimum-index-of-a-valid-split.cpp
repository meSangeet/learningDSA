class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int> m, b;
        int x = 0;
        int mx = 0;
        int n = nums.size();
        vector<int> yet;
        for(int i = 0; i<n; i++){
            m[nums[i]]++;
            if(m[nums[i]] > mx){
                mx = m[nums[i]];
                x = nums[i];
            }
            int len = i+1;
            len /= 2;
            len++;
            if(mx >= len){
                yet.push_back(x);
            }else{
                yet.push_back(-1);
            }
        }       
        mx = 0;
        x = 0;
        int ans = -1;
        for(int i = n-1; i>0; i--){
            b[nums[i]]++;
            if(b[nums[i]] > mx){
                mx = b[nums[i]];
                x = nums[i];
            }
            int len = n - i;
            len /= 2;
            len++;
            if(mx >= len){
                if(x == yet[i-1]){
                    ans = i-1;
                }
            }
        }    

        return ans;
    }
};
