#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<int> a;
        for(int i = 0; i<n; i++)
        {
            int p; cin>>p;
            a.push_back(p);
        }
        int mm = *max_element(a.begin(), a.end());
        vector<int> p;
        for(int i = 0; i<n; i++)
        {
            if(a[i] == mm)
            {
                p.push_back(mm);
                a[i] = -1;
            }
        }
        if(p.size() == a.size()) cout<<-1<<endl;
        else{
        cout<<(a.size() - p.size())<<" ";
        cout<<p.size()<<endl;
        for(int i = 0; i<n; i++)
        {
            if(a[i] != -1) cout<<a[i]<<" ";
        }
        cout<<endl;
        for(int i  = 0; i<p.size(); i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }
}
}