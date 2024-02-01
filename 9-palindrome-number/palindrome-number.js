/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    let str = x.toString();
    let r_str = reverseString(str);
    if(str === r_str){
        return true;
    }else{
        return false;
    }
};

function reverseString(str) {
  return str.split('').reverse().join('');
}