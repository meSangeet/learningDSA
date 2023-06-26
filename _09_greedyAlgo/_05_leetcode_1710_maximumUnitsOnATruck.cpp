#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        for(int i = 0; i<boxTypes.size(); i++)
        {
            swap(boxTypes[i][0], boxTypes[i][1]);
        }
            cout<<"our sorted array - "<<endl;
            sort(boxTypes.begin(), boxTypes.end());
            for(int i = 0; i<boxTypes.size(); i++)
            {
                cout<<boxTypes[i][0]<<" "<<boxTypes[i][1]<<endl;
            }
            long long total = 0, curr = (boxTypes.size() - 1), boxes = 0;
            while(boxes <= truckSize && curr >= 0)
            {
                if(boxTypes[curr][1] <= (truckSize - boxes))
                {
                    total += boxTypes[curr][0]*boxTypes[curr][1];
                    boxes += boxTypes[curr][1];
                    curr--;
                    cout<<total<<" ";
                }else{
                    int temp = truckSize - boxes;
                    total += boxTypes[curr][0]*temp;
                    boxes += temp;
                    curr--;
                    cout<<total<<" "; 
                }
            }
            return total;
    }
};

int main()
{
    
    return 0;
}