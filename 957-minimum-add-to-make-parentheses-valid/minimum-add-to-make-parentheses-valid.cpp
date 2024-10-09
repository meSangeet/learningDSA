class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count = 0;
        for(char a : s){
            if(a == '('){
                st.push(a);
            }else{
                if(st.empty()){
                    count++;
                }else{
                    if(st.top() == '('){
                        st.pop();
                    }
                }
            }
        }
        return count + st.size();
    }
};