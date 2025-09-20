class Router {
private:
    queue<vector<int>> q;
    int mem_limit;
    set<vector<int>> st;
    unordered_map<int,vector<int>> mp;
public:
    Router(int memoryLimit) {
        mem_limit=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(st.find({source,destination,timestamp})!=st.end()){return false;}
        if(q.size()==mem_limit){
            st.erase(q.front());
            int times=q.front()[2];
            int dest=q.front()[1];
            auto it = find(mp[dest].begin(), mp[dest].end(), times);
            if (it != mp[dest].end()) {
                mp[dest].erase(it);
                if(mp[dest].empty()){mp.erase(dest);}
            }
            q.pop();
        }
        st.insert({source,destination,timestamp});
        mp[destination].push_back(timestamp);
        q.push({source,destination,timestamp});
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()){return {};}
            int times=q.front()[2];
            int destination=q.front()[1];
            auto it = find(mp[destination].begin(), mp[destination].end(), times);
            if (it != mp[destination].end()) {
                mp[destination].erase(it);
            }
            st.erase(q.front());
            vector<int> ans=q.front();
            q.pop();
            return ans;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        vector<int> &out=mp[destination];
        int one=lower_bound(out.begin(),out.end(),startTime)-out.begin();
        int two=upper_bound(out.begin(),out.end(),endTime)-out.begin();
        return two-one;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */