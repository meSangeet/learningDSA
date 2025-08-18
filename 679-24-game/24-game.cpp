class Solution {
public:
    double PRECISION=1e-9;
    vector<double> getCals(double a,double b){
        vector<double>res;
        res.push_back(a+b);
        res.push_back(a-b);
        res.push_back(b-a);
        res.push_back(a*b);
        res.push_back(a/b);
        res.push_back(b/a);
        return res;
    }
    bool solve(vector<double>nums){
        if(nums.size()==1){
            if(abs(nums[0]-24.0)<=PRECISION)return true;
        }

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                vector<double>cals=getCals(nums[i],nums[j]);

                vector<double>v;
                for(int k=0;k<nums.size();k++)if(k!=i && k!=j)v.push_back(nums[k]);

                for(int k=0;k<cals.size();k++){
                    v.push_back(cals[k]);
                    if(solve(v))return true;
                    v.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double>nums(cards.begin(),cards.end());
        return solve(nums);
    }
};