class Solution {
public:
    int maximizeSquareArea(int m,int n,vector<int>& h,vector<int>& v){
        h.push_back(1);h.push_back(m);
        v.push_back(1);v.push_back(n);
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        unordered_set<int>s;
        for(int i=0;i<h.size();i++)for(int j=i+1;j<h.size();j++)s.insert(h[j]-h[i]);
        long long a=0;
        for(int i=0;i<v.size();i++)for(int j=i+1;j<v.size();j++)if(s.count(v[j]-v[i]))a=max(a,1LL*(v[j]-v[i])*(v[j]-v[i]));
        return a?a%1000000007:-1;
    }
};
