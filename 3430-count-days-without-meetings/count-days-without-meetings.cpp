class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        //is this really a medium problem ?
        sort(meetings.begin(), meetings.end());
        //we wills start from day 1
        int ans = 0;
        int la = 1; //last available day
        for(int i = 0; i<meetings.size(); i++){
            if(meetings[i][0] > days){
                ans += days - la + 1;
                break;
            }
            if(meetings[i][0] > la){
                ans += meetings[i][0] - la;
            }

            la = max(la, meetings[i][1]+1);
            if(la > days){
                break;
            }
        }      

        if(la <= days){
            ans += days - la + 1;
        }

        return ans;
    }
};