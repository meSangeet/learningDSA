#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int len; cin>>len;
        string s; cin>>s;
        int n = len;
        if(len == 1)
        {
            cout<<8<<"\n";
            return;
        }
        
        string temp;
        
        if(len == 2)
        {
            temp = s[0];
            temp += s[1];
        }else{
            temp = s[n-3];
            temp += s[n-2];
            temp += s[n-1];
        }
        
        int no = stoi(temp);
        int tem = no;
        temp[temp.length() - 1] = '0';
        if(tem%8 == 0)
        {
            cout<<s<<endl;
            return;
        }
        no = stoi(temp);
        tem = no;
        for(int i = 1; i<9; i++)
        {
            tem = no + i;
            if(tem %  8 == 0)
            {
                s[n-1] = '0' + tem%10;
                cout<<s<<endl;
                return;
            }
        }
}
int main()
{
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
}