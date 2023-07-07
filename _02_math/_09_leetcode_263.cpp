#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false;
    
        while(n>0 && n%2 == 0) n /= 2;
        while(n>0 && n%3 == 0) n /= 3;
        while(n>0 && n%5 == 0) n /= 5;
        if(n>1) return false;
        return true;
    }
};

int main()
{
    
    return 0;
}