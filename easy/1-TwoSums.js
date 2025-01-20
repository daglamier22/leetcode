/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  var i,
    k = 0;
  for (i = 0; i < nums.length; ++i) {
    for (k = 1; k < nums.length; ++k) {
      if (i != k && nums[i] + nums[k] == target) {
        return [i, k];
      }
    }
  }
};

console.log(twoSum([2, 7, 11, 15], 9), [0, 1]);
console.log(twoSum([3, 2, 4], 6), [1, 2]);
console.log(twoSum([3, 3], 6), [0, 1]);

console.log(twoSum([7, 20, 11, 15, -11], 9), [1, 4]);
console.log(twoSum([2, 5, 5, 11], 10), [1, 2]);
