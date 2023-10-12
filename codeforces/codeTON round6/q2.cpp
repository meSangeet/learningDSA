#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int t; cin>>t;
    
    while(t--)
    {
      int n,m; cin>>n>>m;
      vector<int> a(n),b(m);
      
      int p = 0, q = 0;
      for(int i = 0; i<n; i++)
      {
        
        cin>>a[i];
        p ^= a[i];
      }
      for(int i = 0; i<m; i++)
      {
        cin>>b[i];
        q |= b[i];
      }
      int ans = 0;    
      for(int i = 0; i<n; i++)
      {
        a[i] |= q;
        ans ^= a[i];
      }
      
      if(n&1)
      {
        cout<<p<<" "<<ans<<"\n";
      }
      else
      cout<<ans<<" "<<p<<"\n";
      
    }
    return 0;
}