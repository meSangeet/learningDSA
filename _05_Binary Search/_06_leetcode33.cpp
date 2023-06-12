#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int s = 0, l = n - 1;
        int mid = s + (l - s) / 2;
        while (s <= l)
        {
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                if (target < nums[0])
                {
                    if (nums[mid] >= nums[0])
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
            else
            {
                if (target > nums[l])
                {
                    if (nums[mid] > nums[0])
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
                    s = mid + 1;
                }
            }
            cout << mid << " ";
            mid = s + (l - s) / 2;
        }
        return -1;
    }
};

int main()
{

    return 0;
}