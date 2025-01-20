#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  *returnSize = 2;
  int* result = malloc(2 * sizeof(int));
  for (int i = 0; i < numsSize - 1; ++i) {
    for (int k = 1; k < numsSize; ++k) {
      if (i != k && nums[i] + nums[k] == target) {
        result[0] = i;
        result[1] = k;
        return result;
      }
    }
  }
  // should never get here based on defined rules
  return result;
}

int main(int argc, char** argv) {
  int returnSize = 2 * sizeof(int);

  int exampleNums1[] = {2, 7, 11, 15};
  int* result1;
  result1 = twoSum(exampleNums1, sizeof(exampleNums1) / sizeof(int), 9, &returnSize);
  printf("[%d, %d] [0, 1]\n", result1[0], result1[1]);
  free(result1);

  int exampleNums2[] = {3, 2, 4};
  int* result2;
  result2 = twoSum(exampleNums2, sizeof(exampleNums2) / sizeof(int), 6, &returnSize);
  printf("[%d, %d] [1, 2]\n", result2[0], result2[1]);
  free(result2);

  int exampleNums3[] = {3, 3};
  int* result3;
  result3 = twoSum(exampleNums3, sizeof(exampleNums3) / sizeof(int), 6, &returnSize);
  printf("[%d, %d] [0, 1]\n", result3[0], result3[1]);
  free(result3);

  int exampleNums4[] = {7, 20, 11, 15, -11};
  int* result4;
  result4 = twoSum(exampleNums4, sizeof(exampleNums4) / sizeof(int), 9, &returnSize);
  printf("[%d, %d] [1, 4]\n", result4[0], result4[1]);
  free(result4);

  int exampleNums5[] = {2, 5, 5, 11};
  int* result5;
  result5 = twoSum(exampleNums5, sizeof(exampleNums5) / sizeof(int), 10, &returnSize);
  printf("[%d, %d] [1, 2]\n", result5[0], result5[1]);
  free(result5);


  return 0;
}
