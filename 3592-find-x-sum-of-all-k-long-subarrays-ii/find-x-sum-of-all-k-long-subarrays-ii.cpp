class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        std::unordered_map<int, int> hashmap;
        std::set<std::pair<int, int>> window, extra;
        std::vector<long long> output;
        long long xSum = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                --hashmap[nums[i - k]];
                std::pair<int, int> tmp = {hashmap[nums[i - k]] + 1, nums[i - k]};
                if (window.count(tmp)) {
                    window.erase(tmp);
                    window.insert({hashmap[nums[i - k]], nums[i - k]});
                    xSum -= nums[i - k];
                } else {
                    extra.erase(tmp);
                    extra.insert({hashmap[nums[i - k]], nums[i - k]});
                }
            }
            ++hashmap[nums[i]];
            std::pair<int, int> tmp = {hashmap[nums[i]] - 1, nums[i]};
            if (window.count(tmp)) {
                xSum += nums[i];
                window.erase(tmp);
                window.insert({hashmap[nums[i]], nums[i]});
            } else if (window.size() < x) {
                window.insert({hashmap[nums[i]], nums[i]});
                xSum += nums[i];
            } else {
                if (extra.count(tmp)) extra.erase(tmp);
                extra.insert({hashmap[nums[i]], nums[i]});
                std::set<std::pair<int, int>>::iterator windowLeast = window.begin();
                std::set<std::pair<int, int>>::iterator extraMost = std::prev(extra.end());
                if (
                    (extraMost->first > windowLeast->first)
                    || (extraMost->first == windowLeast->first && extraMost->second > windowLeast->second)
                ) {
                    int freq = windowLeast->first, num = windowLeast->second;
                    xSum -= static_cast<long long>(freq) * num;
                    window.erase(*windowLeast);
                    window.insert(*extraMost);
                    xSum += static_cast<long long>(extraMost->first) * extraMost->second;
                    extra.erase(*extraMost);
                    extra.insert({freq, num});
                }
            }
            if (extra.size()) {
                std::set<std::pair<int, int>>::iterator windowLeast = window.begin();
                std::set<std::pair<int, int>>::iterator extraMost = std::prev(extra.end());
                if (
                    (extraMost->first > windowLeast->first)
                    || (extraMost->first == windowLeast->first && extraMost->second > windowLeast->second)
                ) {
                    int freq = windowLeast->first, num = windowLeast->second;
                    xSum -= static_cast<long long>(freq) * num;
                    window.erase(*windowLeast);
                    window.insert(*extraMost);
                    xSum += static_cast<long long>(extraMost->first) * extraMost->second;
                    extra.erase(*extraMost);
                    extra.insert({freq, num});
                }
            }
            if (i + 1 >= k) output.push_back(xSum);
        }
        return output;
    }
};