/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  const openTokens = ["(", "{", "["];
  const closeTokens = [")", "}", "]"];
  let lastOpenToken = [];

  for (let i = 0; i < s.length; i++) {
    let closeIndex = closeTokens.indexOf(s[i]);
    // if first character is a close, return false for having a close before an open
    if (lastOpenToken.length === 0 && closeIndex != -1) {
      return false;
    }
    let openIndex = openTokens.indexOf(s[i]);
    // if this character is an open, add to array
    if (openIndex != -1) {
      lastOpenToken.push(openIndex);
    } else if (closeIndex != -1) {
      // if this character is a close, check last open added for a match
      // if it matches, remove from open array, otherwise exit as mismatched open and close characters
      if (lastOpenToken[lastOpenToken.length - 1] === closeIndex) {
        lastOpenToken.pop();
      } else {
        return false;
      }
    }
  }
  return lastOpenToken.length === 0;
};

console.log(isValid("()"), true);
console.log(isValid("()[]{}"), true);
console.log(isValid("(]"), false);
console.log(isValid("([])"), true);

console.log(isValid(")[]("), false);
