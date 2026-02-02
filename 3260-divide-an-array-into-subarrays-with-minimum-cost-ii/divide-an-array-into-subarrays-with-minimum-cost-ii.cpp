class Solution {
public:
    void add(multiset<int>&range,multiset<int>&outside,long long &sum,int ele,int k){
        if(range.size()<k-1){
            range.insert(ele);
            sum+=ele;
            return ;
        }else{
            if(*prev(range.end())<=ele)
            {
                outside.insert(ele);
                return ;
            }
            range.insert(ele);
            int removed_ele=*prev(range.end());
            range.erase(range.lower_bound(removed_ele));
            sum-=removed_ele;
            sum+=ele;
            outside.insert(removed_ele);
        }
    }
    void remove(multiset<int>&range,multiset<int>&outside,long long &sum,int ele,int k){
        if(outside.find(ele)!=outside.end())
            outside.erase(outside.lower_bound(ele));
        else{
            range.erase(range.lower_bound(ele));
            if(outside.empty()){
                sum-=ele;
                return;
            }
            int added_ele=*outside.begin();
            range.insert(added_ele);
            outside.erase(outside.lower_bound(added_ele));
            sum-=ele;
            sum+=added_ele;
        }
    }
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long minsum=INT64_MAX;
        long long sum=nums[0];
        multiset<int>range,outside;
        for(int i=nums.size()-1;i>=nums.size()-dist-1;i--)
            add(range,outside,sum,nums[i],k);
        minsum=min(minsum,sum);
        for(int i=nums.size()-dist-2;i>=1;i--){
            remove(range,outside,sum,nums[i+dist+1],k);
            add(range,outside,sum,nums[i],k);
            minsum=min(minsum,sum);
        }
        return minsum;
    }
};