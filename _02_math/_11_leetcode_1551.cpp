#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0;
        while(num1 != 0 && num2 != 0)
        {
            if(num1>num2) num1 -= num2;
            else num2 -= num1;
            count++;
        }
        return count;
    }
};

int main()
{
    
    return 0;
}