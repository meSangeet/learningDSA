#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for(int i = 1; i<=num/2; i++)
        {
            if(num%i == 0) sum+=i;
        }
        if(num == sum) return true;
        return false;
    }
};


int main()
{
    
    return 0;
}