#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

ll max(ll a, ll b)
{
    if(a > b) return a;
    return b;
}

int sum1 = 0;
int sum2 = 0;
void recur(vector<int> markers, int i, int j, ll curr1, ll curr2, ll turn)
{
    if(i == j) {
        curr2 += markers[j];
        sum2 = max(sum2, curr2);
        return;
    };
    if(j == (i+1)){
        curr1 += max(markers[i], markers[j]);
        sum1 = max(sum1, curr1);
        return;
    }
    else{
    if(turn == 0)
    {
        recur(markers, i+1, j, curr1+markers[i], curr2, 1);
        recur(markers,i,j-1,curr1+markers[j], curr2, 1);
    }else{
        if(markers[i] > markers[j]){
            recur(markers, i+1, j, curr1, curr2+markers[i], 0); 
        }else{
            recur(markers, i, j-1, curr1, curr2+markers[j], 0);
        }
    }
    }
}

int getMaxSum(vector<int> markers)
{
    recur(markers, 0, markers.size()-1, 0, 0, 0);
    return sum1;
}

int main()
{
    cout<<getMaxSum({11, 20 ,2 , 10});
    return 0;
}