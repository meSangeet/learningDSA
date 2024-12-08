class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Sort events by start time
        sort(events.begin(), events.end());

        // Priority queue to track {end time, value}, ordered by end time
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        int maxSingleValue = 0; // Maximum value of a single non-overlapping event
        int maxSum = 0;         // Maximum sum of two non-overlapping events

        for (const auto& event : events) {
            int start = event[0], end = event[1], value = event[2];

            // Remove events that cannot overlap with the current event
            while (!pq.empty() && pq.top().first < start) {
                maxSingleValue = max(maxSingleValue, pq.top().second);
                pq.pop();
            }

            // Calculate the potential maximum sum with the current event
            maxSum = max(maxSum, maxSingleValue + value);

            // Add the current event to the priority queue
            pq.emplace(end, value);
        }

        return maxSum;
    }
};
