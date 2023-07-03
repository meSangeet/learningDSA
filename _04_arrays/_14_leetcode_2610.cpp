#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        vector<int> hash(nums.size() + 1, 0);
        vector<vector<int>> ans;
        int total = nums.size();
        for (int i = 0; i < total; i++)
        {
            hash[nums[i]]++;
        }
        for (int i = 0; i < total; i++)
        {
            if (hash[i] > 0)
                cout << i << " " << hash[i] << endl;
        }
        cout << "entered element";
        int i = 1;
        while (total > 0)
        {
            vector<int> temp;
            for (int i = 0; i < hash.size(); i++)
            {
                if (hash[i] > 0)
                {
                    temp.push_back(i);
                    hash[i] -= 1;
                    total -= 1;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{

    return 0;
}