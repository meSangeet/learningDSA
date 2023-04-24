#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      map<int, int> m;
      for(int i = 0; i<arr.size(); i++)
      {
          m[arr[i]] += 1;
      }
    int hash[2000] = {0};
    for(auto x:m)
    {
        if(hash[x.second] == 1) return false;
        else {hash[x.second] = 1;}
    }
    return true;
    }
};    

int main()
{
    
    
    
    return 0;
}