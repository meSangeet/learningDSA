class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        // vector<int> dry;
        unordered_map<int,int> mp;
        vector<int> dry;    
        for(int i = 0 ;i < n ; i++){
            if(rains[i] == 0){
                dry.push_back(i);
            }
            else{
                if(mp.count(rains[i]) == 0){ //mtlb vo barish ka din pehli baar aaya
                    mp[rains[i]] = i;
                }
                else{ // mtlb vo barish ka din dubara aaya
                    if(dry.size() == 0) return {};
                    // int dry_day = dry.front();
                    int last_rain_day = mp[rains[i]];
                    auto dry_day = upper_bound(dry.begin(), dry.end(), last_rain_day);
                    if(dry_day == dry.end()){
                        return  {};
                    }
                    else{
                        int day = *dry_day;
                        ans[day] = rains[i];
                        mp[rains[i]] = i;
                        dry.erase(dry_day);
                    }
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(rains[i] == 0 && ans[i] == -1)
            ans[i] = 10001;
        }
        return ans;   
    }
};