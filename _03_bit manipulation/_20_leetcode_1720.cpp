#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
       vector<int> arr = {first};
       for(int i = 0; i<encoded.size(); i++)
       {
           arr.push_back((encoded[i]^arr[i]));
       } 
       return arr;
    }
};


int main()
{
    
    return 0;
}