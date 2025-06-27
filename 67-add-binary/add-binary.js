/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    let l1 = a.length
    let l2 = b.length
    if(l1 < l2){
        let temp = l2
        l2 = l1
        l1 = temp
        let tempS = b
        b = a
        a = tempS
    }
    // console.log(l1, l2)
    l2 -= 1
    let carry = false;
    let ans = "";
    for(let i = l1-1; i >= 0; i--){
        if(l2 < 0){
          if(a[i] == '0'){
            if(carry){
                ans += '1'
                carry = false
            }else{
                ans += '0'
            }
          }else{
            if(carry){
                ans += '0';
            }else{
                ans += '1';
            }
          }
        }else{
            if(a[i] == '1' && b[l2] == '1'){
                if(carry){
                    ans += '1';
                }else{
                    ans += '0';
                    carry = true;
                }
            }else if(a[i] == '0' && b[l2] == '0'){
                if(carry){
                    ans += '1';
                    carry = false;
                }else{
                    ans += '0';
                }
            }else{
                if(carry){
                    ans += '0';
                }else{
                    ans += '1';
                }
            }
        }
        l2--
        // console.log(ans, carry)
    }
    if(carry){
        ans += '1'
    }
    ans = ans.split('').reverse().join('')
    return ans;
};