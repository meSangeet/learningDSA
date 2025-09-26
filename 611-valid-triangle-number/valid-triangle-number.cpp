// Sorting + Binary Search
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // sort the nums to do binary search
        sort(nums.begin(),nums.end());

        //count number valid possible triangle
        int numTriangle=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size()-1;j++){
                // Here is two number a=nums[i], b=nums[j]
                // binary search to get last index where nums[index]<a+b
                int ind=lower_bound(nums.begin(),nums.end(),nums[i]+nums[j])-nums.begin()-1;
                numTriangle+=max(0,(ind-j));
            }
        }
        return numTriangle;
    }
};
