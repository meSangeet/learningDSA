class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int ans = min(height[l], height[r]);
        ans *= height.size()-1;
        int sz = height.size()-1;
        while(l < r){
            //if the left height is lower than right than it makes sense to move ahead from left side as right is more capable
            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }

            sz--;
            int cura = min(height[l], height[r]);
            ans = max(ans, cura*sz);
        }
        return ans;
    }
};
