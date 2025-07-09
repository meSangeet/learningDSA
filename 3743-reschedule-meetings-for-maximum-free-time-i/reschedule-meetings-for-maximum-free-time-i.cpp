class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> dif;
        int pi = 0, pe = 0;
        for(int i = 0; i<startTime.size(); i++){
            int dd = startTime[i] - pe;
            pe = endTime[i];
            dif.push_back(dd);
        }
        dif.push_back(eventTime - pe);

        // for(auto x : dif) cout<<x<<" ";
        cout<<endl;
        int win = k+1;
        int i = 0;
        int su = 0;
        int ans = 0;
        while(i < dif.size() and i < k+1){
            
            su += dif[i];
            i++;
            ans = max(ans, su);
        }

        int re = 0;
        while(i < dif.size()){
            su += dif[i];
            su -= dif[re]; i++; re++;
            // cout<<su<<" ";
            ans = max(ans, su);
        }

        return ans;
    }
};