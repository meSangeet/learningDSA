class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
    vector<vector<int>> arr(intervals);
    sort(arr.begin(), arr.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    for (const vector<int>& a : arr) {
        int p = a[0], q = a[1];

        if (!pq.empty() && pq.top() < p) {
            pq.pop(); 
        }
        
        pq.push(q);
    }

    return pq.size();
    }
};