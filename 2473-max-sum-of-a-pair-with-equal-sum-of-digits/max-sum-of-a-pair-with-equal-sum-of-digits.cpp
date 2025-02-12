class Solution {
public:
    int calc(int n){
        int ans = 0;
        while(n){
            ans += n%10;
            n /= 10;
        }
        return ans;
    }

    int maximumSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        map<int,int> m;
        int ans = -1;
        for(int i = n-1; i>=0; i--){
            int no = calc(nums[i]);
            if(m[no] != 0){
                ans = max(ans,nums[i] + m[no]);
            }else
            m[no] = nums[i];
        }

        return ans;
    }
};

//[368,369,307,304,384,138,90,279,35,396,114,328,251,364,300,191,438,467,183]