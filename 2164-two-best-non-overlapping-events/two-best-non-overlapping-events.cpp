class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Vector to hold all time points
        vector<pair<int, int>> timePoints;

        // Add start and end points for each event
        for (const auto& event : events) {
            timePoints.emplace_back(event[0], event[2]);  // Start time with value
            timePoints.emplace_back(event[1] + 1, -event[2]); // End time with negative value
        }

        // Sort time points by time, with end points coming before start points if times are equal
        sort(timePoints.begin(), timePoints.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });

        int maxSeen = 0;  // Maximum value of events before the current time
        int result = 0;   // Maximum sum of two non-overlapping events

        // Sweep through the time points
        for (const auto& [time, value] : timePoints) {
            if (value > 0) {
                // Event starts: calculate max sum using the current value and maxSeen
                result = max(result, maxSeen + value);
            } else {
                // Event ends: update maxSeen with the absolute value
                maxSeen = max(maxSeen, -value);
            }
        }

        return result;
    }
};