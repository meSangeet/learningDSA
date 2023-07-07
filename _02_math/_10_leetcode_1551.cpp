#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int minOperations(int n) {
        int i = 0, j = n-1;
        long long sum = 0;
        while(i<j)
        {
            sum += (j-i);
            i++; j--;
        }
        return sum;
    }
};

int main()
{
    
    return 0;
}