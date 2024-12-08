class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Sort events by end time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<int> maxValues(n, 0);

        // Build maxValues array
        maxValues[0] = events[0][2];
        for (int i = 1; i < n; ++i) {
            maxValues[i] = max(maxValues[i - 1], events[i][2]);
        }

        int result = 0;

        // Iterate through events and calculate the maximum sum
        for (int i = 0; i < n; ++i) {
            int currentValue = events[i][2];

            // Binary search for the latest non-overlapping event
            int low = 0, high = i - 1, index = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (events[mid][1] < events[i][0]) {
                    index = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            // Calculate the maximum sum with the non-overlapping event
            int maxNonOverlap = (index != -1) ? maxValues[index] : 0;
            result = max(result, currentValue + maxNonOverlap);
        }

        // Consider only the maximum single event value
        result = max(result, maxValues[n - 1]);

        return result;
    }
};
