class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        int i = 0;
        while(i < s.length())
        {
            int curChar = s[i];
            if(curChar == 'B' && st.size() && st.top() == 'A'){
                st.pop();
            }else
            if(curChar == 'D' && st.size() && st.top() == 'C') st.pop();
            else st.push(curChar);
            i++;
        }
        return st.size();
    }
};