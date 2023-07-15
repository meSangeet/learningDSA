#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898
bool search(vector<int> &nums, int target)
{
    int s = 0, l = nums.size() - 1;
    int mid = s + (l - s) / 2;
    while (s <= l)
    {
        cout << mid << " " << s << " " << l << endl;
        if (nums[mid] == target)
        {
            return true;
        }
        else if (nums[mid] < target)
        {
            if (nums[mid] >= nums[l])
            {
                s = mid + 1;
            }
            else if (nums[l] < target)
            {
                l = mid - 1;
            }
            else
            {
                return true;
            }
        }
        else
        {
            if (nums[mid] < nums[l])
            {
                l = mid - 1;
            }
            else if (nums[mid] > nums[l])
            {
                if (nums[s] > target)
                {
                    s = mid + 1;
                }
                else
                {
                    l = mid - 1;
                }
            }
            else
            {
                l = mid - 1;
            }
        }
        mid = s + (l - s) / 2;
    }
    return false;
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

    if (search(arr, target))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}