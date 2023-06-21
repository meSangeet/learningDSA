#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

int findContentChildren(vector<int> &g, vector<int> &s)
{
sort(g.begin(), g.end());
sort(s.begin(), s.end());

int count = 0;

int gc = 0, sc = 0;
while(gc < g.size() && sc < s.size())
{
    if(g[gc] <= s[sc]){
        count++;
        gc++; sc++;
    }else{
        sc++;
    }
}
return count;
}

int main()
{

    return 0;
}