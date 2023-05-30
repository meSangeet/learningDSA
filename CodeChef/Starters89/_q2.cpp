#include <bits/stdc++.h>
using namespace std;
    
int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int a = s[1] - '0';
        int b = s[0] - '0';
        int num1 = a + b*10;
        a = s[4] - '0';
        b = s[3] - '0';
        int num2 = a + b*10;

        if(num1 > 12)
        {
            cout<<"DD/MM/YYYY"<<endl;
        }else if(num2 > 12)
        {
            cout<<"MM/DD/YYYY"<<endl;
        }else{
            cout<<"BOTH"<<endl;
        }
    }
    
    
    return 0;
}