class Solution {
public:
    //let's make a method that will do the backtracking
    void func(int i, string curr, vector<string> &ans, int k, int n){
        if(i == n){
            ans.push_back(curr);
            return;
        }

        //now we can use any character at this place
        //before this let's check if the job is already done
        if(ans.size() >= k){
            return;
        }

        //let's add a
        if(curr[i-1] != 'a'){
            curr.push_back('a');
            func(i+1, curr, ans, k, n);
            curr.pop_back();
        }

        if(ans.size() >= k) return;

        //let's add b
        if(curr[i-1] != 'b'){
            curr.push_back('b');
            func(i+1, curr, ans, k, n);
            curr.pop_back();
        }

        if(ans.size() >= k) return;
        //let's add c
        if(curr[i-1] != 'c'){
            curr.push_back('c');
            func(i+1, curr, ans, k, n);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<string> ans;
        string curr = "";
        curr.push_back('a');
        func(1, curr, ans, k, n);

        if(ans.size() >= k) return ans[k-1];

        curr.pop_back();
        curr.push_back('b');
        func(1, curr, ans, k, n);
        curr.pop_back();

        if(ans.size() >= k) return ans[k-1];

        curr.push_back('c');
        func(1, curr, ans, k, n);

        if(ans.size() >= k) return ans[k-1];

        return "";
    }
};