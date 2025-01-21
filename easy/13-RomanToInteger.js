/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function (s) {
  let roman = [
    { symbol: "I", value: 1 }, // 0
    { symbol: "V", value: 5 }, // 1
    { symbol: "X", value: 10 }, // 2
    { symbol: "L", value: 50 }, // 3
    { symbol: "C", value: 100 }, // 4
    { symbol: "D", value: 500 }, // 5
    { symbol: "M", value: 1000 }, // 6
  ];

  let result = 0;
  for (let i = 0; i < s.length; i++) {
    let val = 0;
    if (s[i] === roman[6].symbol) {
      val = roman[6].value;
    } else if (s[i] === roman[5].symbol) {
      val = roman[5].value;
    } else if (s[i] === roman[4].symbol) {
      if (i + 1 < s.length && s[i + 1] === roman[6].symbol) {
        val = roman[6].value - roman[4].value;
        i++;
      } else if (i + 1 < s.length && s[i + 1] === roman[5].symbol) {
        val = roman[5].value - roman[4].value;
        i++;
      } else {
        val = roman[4].value;
      }
    } else if (s[i] === roman[3].symbol) {
      val = roman[3].value;
    } else if (s[i] === roman[2].symbol) {
      if (i + 1 < s.length && s[i + 1] === roman[4].symbol) {
        val = roman[4].value - roman[2].value;
        i++;
      } else if (i + 1 < s.length && s[i + 1] === roman[3].symbol) {
        val = roman[3].value - roman[2].value;
        i++;
      } else {
        val = roman[2].value;
      }
    } else if (s[i] === roman[1].symbol) {
      val = roman[1].value;
    } else if (s[i] === roman[0].symbol) {
      if (i + 1 < s.length && s[i + 1] === roman[2].symbol) {
        val = roman[2].value - roman[0].value;
        i++;
      } else if (i + 1 < s.length && s[i + 1] === roman[1].symbol) {
        val = roman[1].value - roman[0].value;
        i++;
      } else {
        val = roman[0].value;
      }
    }
    result += val;
  }

  return result;
};

console.log(romanToInt("III"), 3);
console.log(romanToInt("LVIII"), 58);
console.log(romanToInt("MCMXCIV"), 1994);

console.log(romanToInt("MCDLXXVI"), 1476);
