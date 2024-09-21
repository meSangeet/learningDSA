class Solution {
public:
    vector<int> lexicalOrder(int n) {
         vector<int> result;
        
        function<void(int)> dfs = [&](int current) {
            if (current > n) return;
            
            result.push_back(current);
            
            for (int i = 0; i < 10; ++i) {
                if (current * 10 + i > n) break;
                dfs(current * 10 + i);
            }
        };
        
        for (int i = 1; i < 10; ++i) {
            dfs(i);
        }
        
        return result;
    }
};