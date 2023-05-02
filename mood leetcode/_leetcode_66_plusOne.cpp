class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        if(digits[size - 1] < 9)
        {
            digits[size - 1] += 1;
            return digits;
        }
        int temp = digits[size - 1];
        size--;
        if(size == 0)
            {
                if(digits[size] == 9){
                    vector<int> ans;
                    ans.push_back(1);
                    ans.push_back(0);
                    if(digits.size() > 2)
                    {
                        for(int i = 2; i<digits.size(); i++)
                        {
                            ans.push_back(digits[i]);
                        }
                    }
                    return ans;
                }
            }
        while(size > 0 && temp == 9)
        {
            digits[size] = 0;
            temp = digits[--size];
            digits[size] += 1;
            if(size == 0)
            {
                if(digits[size] == 10){
                    vector<int> ans;
                    ans.push_back(1);
                    ans.push_back(0);
                    if(digits.size() >= 2)
                    {
                        for(int i = 1; i<digits.size(); i++)
                        {
                            ans.push_back(digits[i]);
                        }
                    }
                    return ans;
                }
            }
        }
        return digits;
    }
};