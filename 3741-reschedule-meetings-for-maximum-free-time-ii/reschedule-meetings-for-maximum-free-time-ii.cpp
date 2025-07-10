class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> mt, gp;
        int n = startTime.size();

        int prevEnd = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            gp.push_back(startTime[i] - prevEnd);
            mt.push_back(endTime[i] - startTime[i]);
            prevEnd = endTime[i];

            if (i > 0) {
                ans = max(ans, gp[i] + gp[i - 1]);
            }
        }
        gp.push_back(eventTime - prevEnd);
        ans = max(ans, gp[gp.size()-1] + gp[gp.size()-2]);
        vector<int> gm(n + 1, -1), mgr(n + 1, -1);
        int maxG = -1;
        for (int i = 0; i < n; i++) {
            gm[i] = maxG;
            maxG = max(maxG, gp[i]);
        }

        maxG = -1;
        for (int i = n; i >= 0; i--) {
            mgr[i] = maxG;
            maxG = max(maxG, gp[i]);
        }

        for (int i = 0; i < n; i++) {
            int meetingTime = mt[i];

            int maxNonAdjGap = max(gm[i], mgr[i+1]);

            if (maxNonAdjGap >= meetingTime) {
                ans = max(ans, gp[i] + gp[i + 1] + meetingTime);
            }
        }

        return ans;
    }
};
