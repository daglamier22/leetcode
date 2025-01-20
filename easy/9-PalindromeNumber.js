// This version turns it into a string first
// /**
//  * @param {number} x
//  * @return {boolean}
//  */
// var isPalindrome = function (x) {
//   if (x < 0) {
//     return false;
//   }
//   let str = x.toString();
//   for (let i = 0; i < str.length / 2; i++) {
//     if (str[i] != str[str.length - 1 - i]) {
//       return false;
//     }
//   }
//   return true;
// };

// This version does not turn it into a string first
/**
 * @param {number} y
 * @returns {boolean}
 */
var getReversedInt = function (y) {
  let digit,
    reversedY = 0;
  do {
    digit = y % 10;
    reversedY = reversedY * 10 + digit;
    y = (y - digit) / 10;
  } while (y > 0);
  return reversedY;
};

/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function (x) {
  if (x < 0) {
    return false;
  }
  return x == getReversedInt(x);
};

console.log(isPalindrome(121), true);
console.log(isPalindrome(-121), false);
console.log(isPalindrome(10), false);

console.log(isPalindrome(1278721), true);
console.log(isPalindrome(1278821), false);
console.log(isPalindrome(1), true);
