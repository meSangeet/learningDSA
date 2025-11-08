class Solution {
public:
    int minimumOneBitOperations(int n)
    {
        int ans=0;

        //iterating till all bits are processed
        while(n)
        {
            //taking XOR with current 'n' to accumulate Gray-code pattern
            ans=ans^n;
            //right shift 'n' (process next bit)
            n=n>>1;
        }
        //returning final answer
        return ans;
    }
};