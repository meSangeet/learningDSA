class Solution {
public:
    double profit(double pass, double total) {
        return (pass + 1) / (total + 1) - pass / total;
    }
    
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> pq;
        
        for(auto c : classes) {
            double p = profit(c[0], c[1]);
            pq.push({p, {c[0], c[1]}});
        }
        
        while(extraStudents--) {
            auto top = pq.top();
            pq.pop();
            
            int pass = top.second.first;
            int total = top.second.second;
            
            double p = profit(pass + 1, total + 1);
            pq.push({p, {pass + 1, total + 1}});
        }
        
        double sum = 0;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int pass = top.second.first;
            int total = top.second.second;
            
            sum += (double)pass/total;
        }
        
        return sum/classes.size();
    }
};
