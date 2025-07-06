class FindSumPairs {
public:
    map<int,int> m;
    vector<int> a1;
    vector<int> a2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int x : nums2){
            m[x]++;
        }
        a1 = nums1;
        a2 = nums2;
    }
    
    void add(int index, int val) {
        int no = a2[index];
        a2[index] += val;
        m[no]--;
        m[no+val]++;
    }
    
    int count(int tot) {
        //iterate over nums1
        int ans = 0;
        for(int x : a1){
            //check how many values are of tot-x
            int val = tot-x;
            int cnt = m[val];
            if(cnt == 0){
                continue;
            }
            int tba = cnt;
            ans += tba;
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */