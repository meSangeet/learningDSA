// first approch was giving runtime error in the leetcode's compiler so i tried another approach

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans;
    int s = 0, l = (nums.size()) - 1;
    int mid = s + (l - s) / 2;
    int ls = -1, le = -1;
    int memorise; // last start, last end
    while (s <= l)
    {
        if (nums[mid] == target)
        {
            ls = mid;
            memorise = mid;
            l = mid - 1;
        }
        else if (nums[mid] > target)
        {
            s = mid + 1;
        }
        else
        {
            l = mid - 1;
        }

        mid = s + (l - s) / 2;
    }

    s = 0, l = nums.size()-1;
    mid = memorise;
    while (s <= l)
    {
        if (nums[mid] == target)
        {
            le = mid;
            s = mid + 1;
        }
        else if (nums[mid] > target)
        {
            s = mid + 1;
        }
        else
        {
            l = mid - 1;
        }

        mid = s + (l - s) / 2;
    }
    ans = {ls, le};
    return ans;
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
    int target;
    cout << endl
         << "enter the target - ";
    cin >> target;

    vector<int> ans = searchRange(arr, target);
    cout << endl
         << "range is - {" << ans[0] << " - " << ans[1] << "}";
    return 0;
}