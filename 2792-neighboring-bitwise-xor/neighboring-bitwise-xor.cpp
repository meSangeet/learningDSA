class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int start = 1;
        int cur = 1;
        int n = derived.size();
        int nex = 0;
        bool flag = false;
        for(int i = 0; i<n; i++){
            if(i == n-1){
                if(derived[i] == 1){
                    if(start != cur){
                        flag = true;
                    }
                }else{
                    if(start == cur){
                        flag = true;
                    }
                }
            }
            if(derived[i] == 1){
                cur = ~cur;
            }else{
                cur = cur;
            }
        }
        return flag;
    }
};