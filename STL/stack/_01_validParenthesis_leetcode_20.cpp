#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i<s.length(); i++)
        {
            if(s[i] == '[' || s[i] == '{' || s[i] == '(')
            {
                st.push(s[i]);
                continue;
            }
            char a = s[i];
            if(st.empty() == true) return false;
            switch (a){
                case '}' :
                    if(st.top() == '{')
                    {
                        st.pop();
                    }else{
                        return false;
                    }
                    break;
                case ']' :
                    if(st.top() == '[')
                    {
                        st.pop();
                    }else{
                        return false;
                    }
                    break;
                case ')' :
                    if(st.top() == '(')
                    {
                        st.pop();
                    }else{
                        return false;
                    }
                    break;
                default:
                    return false;
            }
        }
        if(st.empty() == true)
        {
            return true;
        }
        return false;
}


int main()
{
    string s;
    cin>>s;
    cout<<isValid(s);
    return 0;
}