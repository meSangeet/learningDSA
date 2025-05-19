class Solution {
public:
    string triangleType(vector<int>& nums) {
        map<int,int> m;
        for(int i = 0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        sort(nums.begin(), nums.end());
        if(nums[0]+nums[1] <= nums[2]){
            return "none";
        }
        if(m.size() == 1){
            return "equilateral";
        }
        if(m.size() == 2){
            return "isosceles";
        }
        return "scalene";
    }
};