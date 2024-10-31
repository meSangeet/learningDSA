#define ll long long
class Solution {
    //this represents minimum distance travelled if by first i robots if repaired using first j facts
    long long helper(vector<int>& robot, vector<int> &fact, int i, int j,vector<vector<ll>> &dp){
        if(i == -1){
            //all the robots are assigned somewhere
            return 0;
        }

        if(j == -1){
            //no more factories left and no way to assign robots
            return LLONG_MAX;
        }

        if(dp[i][j] != -1) return dp[i][j];
        //robot can be assigned or not to a factory
        ll case1 = LLONG_MAX, case2 = LLONG_MAX, case3 = LLONG_MAX, case4 = LLONG_MAX;
        //case 1 - we try to assign the robot to facotry and stay at the same factory
            long long dist = abs(robot[i] - fact[j]);
            ll h1 = helper(robot, fact, i-1, j-1, dp);
            if(h1 != LLONG_MAX)
            case1 = dist + h1;
    

        //case3 - we don't assign this robot to current factory and move back
        case3 = helper(robot, fact, i, j-1, dp);

        return dp[i][j] = min({case1, case3});
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        //definitely not greedy as any robot can be assigned to any factory
        //intuition - any robot can be either assigned to a factory or not / vice versa
        //let's try all possible cases [DP]

        //we can go in either direction
        vector<vector<int>> fact(factory);
        vector<int> robo(robot);
        sort(robo.begin(), robo.end());
        sort(fact.begin(), fact.end());
        vector<int> facts;
        for(auto x:fact){
            int freq = x[1];
            while(freq--){
                facts.push_back(x[0]);
            }
        }
        int robots = robot.size();
        int factories = facts.size();
        vector<vector<ll>> dp(robots, vector<ll>(factories,-1));

        return helper(robo, facts, robots-1, factories-1, dp);
    }
};