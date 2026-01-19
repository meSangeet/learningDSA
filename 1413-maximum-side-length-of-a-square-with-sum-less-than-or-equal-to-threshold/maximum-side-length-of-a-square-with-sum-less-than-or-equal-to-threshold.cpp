class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int s = 1;
        int e = min(mat.size(), mat[0].size());
        int l = mat.size();
        int b = mat[0].size();

        //creating a sum array
        vector<vector<int>> sumMat(l, vector<int> (b, 0));
        for(int i = 0; i<l; i++){
            for(int j = 0; j<b; j++){
                if(i == 0 and j == 0) sumMat[i][j] = mat[i][j];
                else if(i == 0) sumMat[i][j] = mat[i][j] + sumMat[i][j-1];
                else if(j == 0) sumMat[i][j] = mat[i][j] + sumMat[i-1][j];
                else{
                    sumMat[i][j] = mat[i][j] + sumMat[i-1][j] + sumMat[i][j-1] - sumMat[i-1][j-1];
                }
            }
        }

        // cout<<"l - "<<l<<", b- "<<b<<endl;
        int mid = s + (e-s)/2;
        int ans = 0;
        while(s <= e){
            // cout<<mid<<" ";
            int here = INT_MAX;
            //now we will calculate if any square of side = mid is possible
            for(int i = 0; i < l-mid+1; i++){
                for(int j = 0; j <b-mid+1; j++){
                    //now traverse the square
                    int cur = 0;
                    int li = i+mid-1, lj = j+mid-1;
                    cur = sumMat[li][lj];
                    if(i == 0 and j == 0){

                    }else if(i == 0){
                        cur -= sumMat[i+mid-1][j-1];
                    }else if(j == 0){
                        cur -= sumMat[i-1][j+mid-1];
                    }else{
                        cur -= sumMat[i+mid-1][j-1];
                        cur -= sumMat[i-1][j+mid-1];
                        cur += sumMat[i-1][j-1];
                    }
                    here = min(here, cur);
                }
            }
            // cout<<" "<<here<<endl;
            if(here <= threshold){
                ans = mid;
                s = mid+1;
            }else{
                e = mid-1;
            }
            mid = s + (e-s)/2;
        }
        
        return ans;
    }
};