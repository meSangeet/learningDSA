/**
 * @param {string} s
 * @return {string}
 */
var makeLargestSpecial = function(s) {
    var ans = "";
    let start = 0;
    let l = s.length;
    let sum = 0;
    let strs = [];
    for(let i = 0; i < l; i++){
        if(s[i] === '1'){
            sum++;
        }else{
            sum--;
        }

        if(sum === 0){
            //now we got a special string, let's see if there is any such string inside this
            var curMidMax = "";
            if(start+1 < i){
                curMidMax = makeLargestSpecial(s.slice(start+1, i));
            }
            var curMax = s[start];
            curMax += curMidMax;
            curMax += s[i];
            strs.push(curMax);
            start = i+1;
        }
    }
        strs.sort((a,b) => b.localeCompare(a));
        return strs.join("");
};