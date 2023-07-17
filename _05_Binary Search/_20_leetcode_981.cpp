#include<bits/stdc++.h>
using namespace std;

class TimeMap {

unordered_map<string, vector<pair<int, string>>> ds;
int geti;
public:
    TimeMap() {
        geti = 0;
    }
    
    void set(string key, string value, int timestamp) {
        ds[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
            string str = ""; int prev = 0;
            int s = 0;
            int l = ds[key].size()-1;
            int mid = s + (l-s)/2;

            while(s <= l)
            {
                if(ds[key][mid].first == timestamp){
                    return ds[key][mid].second;
                }
                if(ds[key][mid].first < timestamp)
                {
                    str = ds[key][mid].second;
                    s = mid+1;
                }else{
                    l = mid-1;
                }
                mid = s + (l-s)/2;
            }
            return str;
        }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main()
{
    
}