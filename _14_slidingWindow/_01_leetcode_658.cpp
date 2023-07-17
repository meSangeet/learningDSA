#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution
{
public:
    int abs(int a, int b)
    {
        return a > b ? (a - b) : (b - a);
    }
    bool close(int a, int b, int x)
    {
        if (abs(a, x) < abs(b, x))
            return true;
        else
        {
            if ((abs(a, x) == abs(b, x)) && a < b)
                return true;
        }

        return false;
    }
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> ans;
        int l = 0, r = k - 1;
        while (r + 1 < arr.size() && arr[r + 1] == arr[l])
        {
            r++;
            l++;
        }
        while (r + 1 < arr.size() && close(arr[r + 1], arr[l], x))
        {

            cout << l << " " << r << endl;
            l++;
            r++;
            while (r + 1 < arr.size() && arr[r + 1] == arr[l])
            {
                r++;
                l++;
            }
        }
        cout << l << " " << r << endl;
        for (int i = l; i <= r; i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};

int main()
{

    return 0;
}