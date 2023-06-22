#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> m;
        for(int i = 0; i<bills.size(); i++)
        {
            if(bills[i] == 5)
            {
                m[5]++;
            }else if(bills[i] == 10)
            {
                m[10]++;
                if(m[5] >= 1)
                {
                    m[5]--;
                }else return false;
            }else if(bills[i] == 15)
            {
                m[15]++;
                if(m[5]<2)
                {
                    if(m[10]==0)
                    {
                        return false;
                    }else{
                        m[10]--;
                    }
                }else{
                    m[5] -= 2;
                }
            }else{
                m[20]++;
                if(m[10] < 1)
                {
                    if(m[5]<3) return false;
                    else m[5] -= 3;
                }else{
                    if(m[5] == 0) return false;
                    else {
                        m[10]--;
                        m[5]--;
                    }
                }
            }

        }
        return true;
    }
};

int main()
{
    
    return 0;
}