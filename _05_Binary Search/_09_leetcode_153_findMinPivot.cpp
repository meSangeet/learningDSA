#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

int findMin(vector<int> &nums)
{
    int s = 0, l = nums.size() - 1;
    int mid = (s+l)/2;
    while(s<l)
    {
        cout<<s<<" "<<l<<" "<<mid<<endl;
        if(nums[mid] > nums[l]){
            s = mid+1;
        }else{
            if(nums[s] == nums[l]) s = mid+1;
            else l = mid;
        }

        mid = (s+l)/2;
    }
    return nums[l];
}

int main()
{
    int n;
    cout << "enter nummber of elements in your array - ";
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        arr.push_back(p);
    }
    cout << endl
         << findMin(arr);
    return 0;
}