class Solution {
public:
    vector<int> minOperations(string boxes) {
        int balls = 0;
        int sum = 0;
        int n = boxes.length();
        vector<int> totalDistances(n, 0);
        for(int i = 0; i < n; i++){
            if(boxes[i] == '1'){
                balls++;
            }
            totalDistances[i] = sum;
            sum += balls;
        }
        balls = 0;
        sum = 0;
        for(int i = n-1; i>=0; i--){
            if(boxes[i] == '1'){
                balls++;
            }
            totalDistances[i] += sum;
            sum += balls;
        }
        return totalDistances;
    }
};