#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
bool recur(vector<int> &stones, int n, int curr, int k, int ind,map<pair<int,int>, int>&m,  unordered_map<int, int> &index)
{
    if (ind == (n - 1))
        return true;
    if (index[curr + k - 1] && k > 1)
    {
        if(m[{curr+k-1, k-1}] == 1) return true;
        if(m[{curr+k-1, k-1}] == -1) goto x;
        if (recur(stones, n, curr + k - 1, k - 1, index[curr + k - 1],m, index))
        {
            m[{curr+k-1, k-1}] = 1;
            return true;
        }else{
            m[{curr+k-1, k-1}] = -1;
        }
    }
    x:
    if (index[curr + k] && k != 0)
    {
        if(m[{curr+k, k}] == 1) return true;
        if(m[{curr+k, k}] == -1) goto y;
        if (recur(stones, n, curr + k, k, index[curr + k],m, index))
        {
            m[{curr+k, k}] = 1;
            return true;
        }else{
            m[{curr+k, k}] = -1;
        }
    }
    y:
    if (index[curr + k + 1])
    {
        if(m[{curr+k+1, k+1}] == 1) return true;
        if(m[{curr+k+1, k+1}] == -1) goto z;
        if (recur(stones, n, curr + k + 1, k + 1, index[curr + k + 1],m, index))
        {
            m[{curr+k+1, k+1}] = 1;
            return true;
        }else{
            m[{curr+k+1, k+1}] = -1;
        }
    }
    z:
    return false;
}
bool canCross(vector<int> &stones)
{
    if(stones[1] > 1) return false;
    unordered_map<int, int> ind;
    map<pair<int,int>, int> m;
    for (int i = 0; i < stones.size(); i++)
    {
        ind[stones[i]] = i;
    }
    return recur(stones, stones.size(), 1, 1, 1,m, ind);
}

};
int main()
{
    return 0;
}