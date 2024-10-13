class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
    int max_value = INT_MIN;

    for (int i = 0; i < nums.size(); ++i) {
        minHeap.push({nums[i][0], i, 0});
        max_value = max(max_value, nums[i][0]);
    }

    int range_start = 0, range_end = INT_MAX;

    while (true) {
        auto curr = minHeap.top();
        minHeap.pop();

        int min_value = curr[0]; 
        int list_index = curr[1]; 
        int element_index = curr[2];

        if (max_value - min_value < range_end - range_start) {
            range_start = min_value;
            range_end = max_value;
        }

        if (element_index + 1 == nums[list_index].size()) {
            break;
        }

        int next_value = nums[list_index][element_index + 1];
        minHeap.push({next_value, list_index, element_index + 1});
        
        max_value = max(max_value, next_value);
    }

    return {range_start, range_end};
    }
};