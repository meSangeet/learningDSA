#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int hsf = 0, curr = 0;
        for(int i = 0; i<gain.size(); i++)
        {
            curr += gain[i];
            hsf = max(hsf, curr);
        }
        return hsf;
    }
};

int main()
{
    
    return 0;
}