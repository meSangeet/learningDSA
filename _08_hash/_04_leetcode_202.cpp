#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    long long req(long long n)
    {
        long long su8m = 0;
        while(n != 0)
        {
            long long temp = n%10;
            temp = pow(temp,2);
            su8m += temp;
            n /= 10;
        }
        return su8m;
    }

    bool isHappy(long long n) {
        unordered_map<long long,long long> m;
        long long sm = req(n);
        while(m[sm] != 1)
        {
            m[sm] = 1;
            long long temp = req(sm);
            sm = temp;
            if(temp == 1) return true;
        }
        return false;
    }
};

int main()
{
    
    return 0;
}