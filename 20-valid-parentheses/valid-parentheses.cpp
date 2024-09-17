class Solution {
public:
    bool isStart(char x){
        return x == '{' || x == '[' || x == '(';
    }
    
    bool check(char cur, char last){
        return (cur == ']' and last == '[') or
        (cur == '}' and last == '{') or
        (cur == ')' and last == '(');
    }
    bool isValid(string x) {
                stack<char> s;
        for(auto a:x){
            if(isStart(a)){
                s.push(a);
            }else{
                if(s.empty()) return false;
                if(check(a,s.top())) s.pop();
                else return false;
            }
        }
    return s.empty();
    }
};