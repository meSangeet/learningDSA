class Solution {
public:
int maxValue(vector<vector<int>>& E, int k) {
    sort(E.begin(),E.end(),[](auto&a,auto&b){return a[1]<b[1];});
    int n=E.size();
    vector<vector<int>> dp(n+1,vector<int>(k+1));
    for(int i=1;i<=n;i++){
        int l=0,r=i-1;
        while(l<r){
            int m=(l+r+1)/2;
            if(E[m-1][1]<E[i-1][0]) l=m;
            else r=m-1;
        }
        for(int j=1;j<=k;j++)
            dp[i][j]=max(dp[i-1][j],dp[l][j-1]+E[i-1][2]);
    }
    return dp[n][k];
}};
