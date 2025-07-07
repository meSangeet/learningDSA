class Solution {
public:
int maxEvents(vector<vector<int>>& E) {
    sort(E.begin(),E.end());
    priority_queue<int,vector<int>,greater<>> q;
    int i=0,d=0,a=0,n=E.size(),m=0;
    for(auto &e:E) m=max(m,e[1]);
    for(d=1;d<=m;d++){
        while(i<n&&E[i][0]==d) q.push(E[i++][1]);
        while(!q.empty()&&q.top()<d) q.pop();
        if(!q.empty()) q.pop(),a++;
    }
    return a;
}};
