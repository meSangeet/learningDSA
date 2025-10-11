class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        using ll = long long;
        map<int,int> mm;
        vector<pair<ll,ll>> dp;
        map<ll,ll> m;
        for(int x : power){
            mm[x]++;
        }

        long long ans = 0;

        for(auto x : mm){
            ll num = x.first;
            ll frq = x.second;
            //let say we will take the current
            ll tba = num * frq;
            if(dp.size() > 0){
                //checking the last
                if(dp.back().first < num-2){
                    dp.push_back({num, m[dp.back().first] + tba});
                }else{
                    int len = dp.size();
                    if(len > 1){
                        if(dp[len-2].first < num-2){
                            dp.push_back({num, m[dp[len-2].first] + tba});
                        }else{
                            if(len > 2){
                                dp.push_back({num, m[dp[len-3].first]+tba});
                            }else{
                                dp.push_back({num, tba});
                            }
                        }
                    }else{
                        dp.push_back({num, tba});
                    }
                }
            }else{
                dp.push_back({num, tba});
            }
            ans = max(ans, dp.back().second);
            m[dp.back().first] = ans;
        }
        return ans;
    }
};