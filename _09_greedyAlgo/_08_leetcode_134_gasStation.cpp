#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
    int start = 0;
    int totalGas = 0;
    int currentGas = 0;
    
    for (int i = 0; i < n; i++) {
        totalGas += gas[i] - cost[i];
        currentGas += gas[i] - cost[i];
        
        // If we can't reach the next station, update the start station
        if (currentGas < 0) {
            start = i + 1;
            currentGas = 0;
        }
    }
    
    // If the total gas is negative, it means we can't complete the tour
    if (totalGas < 0) {
        return -1;
    }
    
    return start;
    }
};

int main()
{
    
    return 0;
}