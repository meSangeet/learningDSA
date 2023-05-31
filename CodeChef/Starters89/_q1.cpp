#include <bits/stdc++.h>
using namespace std;
    
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int arr[4];
        int sum = 0;
        int maxi = INT_MIN;
        cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
        for(int i = 0; i<4; i++)
        {
            sum += arr[i];
            if(maxi < arr[i])
            {
                maxi = arr[i];
            }
        }
        if(maxi > (sum-maxi))
        {
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    
    
    return 0;
}