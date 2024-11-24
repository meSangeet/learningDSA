#define ll long long
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> vec;
        for (int i = 0; i < nums1.size(); i++) {
            vec.push_back({nums2[i], nums1[i]});
        }
        sort(vec.rbegin(), vec.rend()); 

        ll sum = 0, ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq; 

        for (int i = 0; i < vec.size(); i++) {
            int n2 = vec[i].first;
            int n1 = vec[i].second;

            sum += n1;
            pq.push(n1); 

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                ans = max(ans, sum * n2);
            }
        }

        return ans;
    }
};
