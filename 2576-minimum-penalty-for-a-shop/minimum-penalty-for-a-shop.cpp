class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> nos(n+1,0), yeses(n+1,0);
        int ind = n-1;
        for(int i = 0; i < n; i++){
            if(customers[i] == 'N'){
                if(i > 0){
                    nos[i] = nos[i-1]+1;
                }else{
                    nos[i] = 1;
                }
            }else{
                if(i > 0){
                    nos[i] = nos[i-1];
                }
            }

            if(customers[ind] == 'Y'){
                if(ind < n-1){
                    yeses[ind] = yeses[ind+1]+1;
                }else{
                    yeses[ind] = 1;
                }
            }else{
                if(ind < n-1){
                    yeses[ind] = yeses[ind+1];
                }
            }

            ind--;
        }
        nos[n] = nos[n-1];
        // for(int x : nos) cout<<x<<" ";
        // cout<<endl;
        // for(int x : yeses) cout<<x<<" ";
        // cout<<endl;

        int mx = INT_MAX;
        int ans = 0;
        for(int i = 0; i < n+1; i++){
            if(i > 0){
                int temp = nos[i-1] + yeses[i];
                if(temp < mx) ans = i;
                mx = min(mx, temp);
            }else{
                if(mx < yeses[i]) ans = i;
                mx = min(mx, yeses[i]);
            }
        }

        // cout<<endl<<mx<<endl;
        return ans;
    }
};