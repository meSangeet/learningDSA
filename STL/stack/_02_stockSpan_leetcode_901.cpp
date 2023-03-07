#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
    int count;
    stack<pair<int,int>> st;
public:
    StockSpanner() {
        count = 0;
    }
    
    int next(int price) {
        count++;
        pair<int,int> p(count, price);
        if(st.empty() == true) {
            st.push(p);
            return 1;
        }
        if(st.top().second > p.second) {
            int t = p.first - st.top().first;
            st.push(p);
            return t;
        }
        while( st.empty() == false && st.top().second <= p.second )
        {
            st.pop();
        }
        if(st.empty() == true) {
            st.push(p);
            return count;
        }
        if(st.empty() == false)
        {
            int t = p.first - st.top().first;
            st.push(p);
            return t;
        }
        return 1;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */