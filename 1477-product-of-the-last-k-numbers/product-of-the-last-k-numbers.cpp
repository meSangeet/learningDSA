class ProductOfNumbers {
public:
    int ans;
    int las;
    int l0;
    int i;
    vector<int> vec;
    ProductOfNumbers() {
        ans = 1;
        vec = {1};
        l0 = -1;
        i = 0;
    }
    
    void add(int num) {
        i++;
        ans *= num;
        vec.push_back(ans);
        if(ans == 0){
            ans++;
            l0 = i;
        }
    }
    
    int getProduct(int k) {
        // for(auto x : vec) cout<<x<<" ";
        // cout<<endl;
        int n = vec.size();
        int no = vec[n-k-1];
        if(no == 0) no++;
        int ans = vec.back()/no;
        if(l0 >= n-k){
            return 0;
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */