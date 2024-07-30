class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> a(n,0);
        vector<int> b(n,0);
        int c = 0, d = 0;
        bool b1 = false, b2 = false;
        for(int i = 0; i<n; i++)
        {
            if(s[i] == 'b'){ c++; b1 = true;}
            if(s[n-i-1] == 'a'){ d++; b2 = true;}
            a[i] = c;
            b[n-i-1] = d;
        }
        
        int ans = INT_MAX;
        if(!b1 || !b2)
        {
            return 0;
        }
        for(int i = 0; i<n; i++)
        {
            ans = min(ans, a[i]+b[i]-1);
        }
        cout<<n<<endl;
        return min(ans, n-ans);
    }
};