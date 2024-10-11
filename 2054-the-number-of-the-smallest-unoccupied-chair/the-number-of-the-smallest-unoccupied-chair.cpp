class Solution {
public:
int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        vector<pair<int, pair<int, int>>> events;
        for (int i = 0; i < n; i++) {
            events.push_back({times[i][0], {times[i][1], i}});
        }
        
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < n; i++) {
            availableChairs.push(i);
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leavingChairs;
        
        for (int i = 0; i < n; i++) {
            int arriveTime = events[i].first;
            int leaveTime = events[i].second.first;
            int friendIndex = events[i].second.second;
            
            while (!leavingChairs.empty() && leavingChairs.top().first <= arriveTime) {
                availableChairs.push(leavingChairs.top().second);
                leavingChairs.pop();
            }
            
            int assignedChair = availableChairs.top();
            availableChairs.pop();
            
            if (friendIndex == targetFriend) {
                return assignedChair;
            }
            
            leavingChairs.push({leaveTime, assignedChair});
        }
        
        return -1;
    }
};