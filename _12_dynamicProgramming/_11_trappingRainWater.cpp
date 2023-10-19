class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n,0), rmax(n,0);
        int l = 0, r = 0;
        for(int i = 0; i<n; i++)
        {
            l = max(l, height[i]);
            r = max(r, height[n-i-1]);
            lmax[i] = l;
            rmax[n-i-1] = r;
        }

        int ans = 0;
        for(int i = 0; i<n; i++)
        {
            int miin = min(lmax[i], rmax[i]);
            if(miin - height[i] > 0) 
            {
                ans += (miin - height[i]);
            }
        }

        return ans;
    }
};