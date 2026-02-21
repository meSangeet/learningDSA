/**
@param {number} number
 */
const noOfSetBits = (number) => {
    let ans = 0;
    while(number){
        if(number&1){
            ans++;
        }
        number >>= 1;
    }
    return ans;
}

/**
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
var countPrimeSetBits = function(left, right) {
    const primes = new Set([2,3,5,7,11,13,17,19,23,29,31,37]);
    let no = left;
    var ans = 0;
    while(no <= right){
        let setBits = noOfSetBits(no);
        console.log(`${no} -> ${setBits}`)
        if(primes.has(setBits)) ans++;
        no++;
    }
    return ans;
};