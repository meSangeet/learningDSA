class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int time = minutesToTest/minutesToDie;
        //now we have removed the bakchodi of waiting to die
        //if buckets == time then ek pig se kaam ho jayega
        if(time == buckets) return (buckets == 1)?0:1;

        //2 -> 4, 3 -> 8

        //total pigs that we need
        double tp = log2(buckets);
        //this can be divided into time 
        double timePos = log2(time+1);

        return ceil(tp/timePos);
    }
};