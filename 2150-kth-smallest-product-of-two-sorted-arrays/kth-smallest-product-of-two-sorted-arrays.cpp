class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        //finding some x and we are figuring out whether this x can be our answer or not
        //this technique -> binary searching on answers
        long long high = 1e10 + 4;
        long long low = -1*high;
        long long x = low + (high - low)/2;
        long long ans = high;
        int n1 = nums1.size();
        int n2 = nums2.size();
        while(low <= high){
            x = low + (high - low)/2;
            //we need to see if this x is possible or not
            //when will this be possible ?
            //this will only be possible if we have more than or equal to k products less than or equal to x
            bool possible = false;

            long long count = 0; //no of products less than or equal to x

            //iterate over the first array

            for(int i = 0; i<n1; i++){
                int a = nums1[i];
                if(a > 0){
                    long long threshold = floor((double) x / a);
                    int no = upper_bound(nums2.begin(), nums2.end(), threshold) - nums2.begin();
                    count += no;
                    //0 1 2 3 4 5 
                }else if(a < 0){
                    long long threshold = ceil((double) x / a);
                    int no = lower_bound(nums2.begin(), nums2.end(), threshold) - nums2.begin();
                    //0 1 2 3 4 5  => 6 - 3
                    count += (n2 - no);
                }else{
                    if(x >= 0){
                        count += n2;
                    }
                }

                if(count >= k){
                    possible = true;
                    break;
                }
            }

            if(possible){
                ans =  x;
                high = x-1;
            }else{
                low = x+1;
            }
        }

        return ans;
    }
};