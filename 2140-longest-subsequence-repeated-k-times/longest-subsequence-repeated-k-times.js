/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var longestSubsequenceRepeatedK = function(s, k) {
    function solve(frnt, k, s) {
        let count = 0;
        let index = 0;
        for (let i = 0; i < s.length; i++) {
            if (s[i] === frnt[index]) {
                index++;
                if (index === frnt.length) {
                    index = 0;
                    count++;
                }
                if (count === k) {
                    return true;
                }
            }
        }
        return false;
    }

    let queue = [''];
    let ans = '';

    while (queue.length > 0) {
        let newQueue = [];
        for (let frnt of queue) {
            for (let chCode = 97; chCode <= 122; chCode++) { // 'a' to 'z'
                let frntNew = frnt + String.fromCharCode(chCode);
                if (solve(frntNew, k, s)) {
                    // Update answer if longer, or same length but lex greater
                    if (
                        frntNew.length > ans.length ||
                        (frntNew.length === ans.length && frntNew > ans)
                    ) {
                        ans = frntNew;
                    }
                    newQueue.push(frntNew);
                }
            }
        }
        queue = newQueue;
    }

    return ans;
};
