#include <bits/stdc++.h>
using namespace std;


    int searchInsert(vector<int>& nums, int target) {
        int s = 0, l = nums.size() - 1;
        int mid = (s+l)>>1;
        while(s<=l)
        {
            
            if(nums[mid] > target)
            {
                l = mid - 1;
            }else if(nums[mid] < target){
                s = mid+1;
            }else{
                return mid;
            }
            mid = (s+l)>>1;
        }
            return -1;
    }


int main()
{
    
    int n; cout<<"enter nummber of elements in your array - "; cin>>n;
    vector<int> arr;
    for(int i = 0; i<n; i++)
    {
        int p; cin>>p;
        arr.push_back(p);
    }
    int target; cout<<endl<<"enter the target - "; cin>>target;
    if(searchInsert(arr, target) != -1)
    {
        cout<<endl<<"your target is present at the index "<<searchInsert(arr, target)<<endl;
    }else{
        cout<<endl<<"your array doesnot contain the target"<<endl;
    }
    
    return 0;
}