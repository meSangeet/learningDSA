class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> one,zero;
        int n = s.length();
        for(int i = 0; i<n; i++){
            if(locked[i] == '0'){
                zero.push(i);
            }else if(s[i] == '('){
                one.push(i);
            }else{
                if(!one.empty()){
                    one.pop();
                }else if(!zero.empty()){
                    zero.pop();
                }else{
                    return false;
                }
            }
        }

        while(!one.empty() && !zero.empty() && zero.top() > one.top()){
            zero.pop();
            one.pop();
        }

        if(one.empty() && zero.size()%2 == 0){
            return true;
        }

        return false;
    }
};