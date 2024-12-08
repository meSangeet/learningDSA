#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Sort events by their end time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<int> dp(n, 0); // DP array to store the max value up to event i
        int result = 0;

        // Function to find the latest non-overlapping event index using binary search
        auto findNonOverlapping = [&](int idx) {
            int low = 0, high = idx - 1, ans = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (events[mid][1] < events[idx][0]) {
                    ans = mid;  // This event is non-overlapping
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            return ans;
        };

        for (int i = 0; i < n; ++i) {
            // Update DP value for the current event
            dp[i] = (i > 0) ? dp[i - 1] : 0; // Start with the previous max value
            dp[i] = max(dp[i], events[i][2]); // Either skip or take the current event

            // Find the maximum sum of two non-overlapping events
            int nonOverlappingIdx = findNonOverlapping(i);
            int maxTwoSum = events[i][2];
            if (nonOverlappingIdx != -1) {
                maxTwoSum += dp[nonOverlappingIdx];
            }
            result = max(result, maxTwoSum);
        }

        return result;
    }
};
