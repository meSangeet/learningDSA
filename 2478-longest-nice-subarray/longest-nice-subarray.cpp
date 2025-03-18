class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        //we will maintain a mask of the total end yet
        int mask = 0;
        int n = nums.size();
        int ans = 0;
        int l = 0; //current length
        int left = 0;
        //[1,3,8,48,10]
        for(int i = 0; i<n; i++){
            int num = nums[i];
            //this should not have any common set bit with the mask otherwise we will have to alter the subarray
            while(left < i and (nums[i] & mask)){
                //remove the left element from mask
                mask ^= nums[left];
                left++;
                l--;
            }

            mask |= nums[i];
            l++;
            // cout<<left<<" "<<i<<" "<<l<<" "<<ans<<" "<<mask<<" \n";
            ans = max(ans, l);
        }
        return ans;
    }
};
