class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        //we can definitely drink num bottles 
        //now we have num bottles empty
        // cout<<numBottles<<endl;
        if(numExchange <= numBottles){
            //drink the numExchange
            //exchange them for a new full bottle
            return numExchange + maxBottlesDrunk(numBottles - numExchange + 1, numExchange+1);
        }else{
            //just drink all of them
            return numBottles;
        }

        return 0;
    }
};