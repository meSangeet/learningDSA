class Solution {
public:
    int maxScore(string s) {
        deque<int> dq;
        int cur = 0;
        int n = s.length();
        for(int i = n-1; i>=0; i--){
            if(s[i] == '1'){
                cur++;
            }
            dq.push_front(cur);
        }

        int ans = 0;
        cur = 0;

        for(int i = 0; i<n-1; i++){
            if(s[i] == '0') cur++;
            ans = max(ans, cur + dq[i+1]);
        }

        return ans;

    }
};