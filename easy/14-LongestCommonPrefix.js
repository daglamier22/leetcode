/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
  let lcp = "";
  let charIndex = 0;
  while (charIndex < strs[0].length) {
    let currentChar = strs[0].charAt(charIndex);
    for (let i = 0; i < strs.length; i++) {
      if (strs[i].charAt(charIndex) != currentChar) {
        return lcp;
      }
    }
    lcp += currentChar;
    charIndex++;
  }

  return lcp;
};

console.log(longestCommonPrefix(["flower", "flow", "flight"]), "fl");
console.log(longestCommonPrefix(["dog", "racecar", "car"]), "");
