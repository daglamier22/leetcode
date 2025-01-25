#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
  char* lcp = (char*)calloc(strlen(strs[0]) + 1, sizeof(char));
  int charIndex = 0;
  while (charIndex < strlen(strs[0])) {
    int currentChar = strs[0][charIndex];
    for (int i = 0; i < strsSize; i++) {
      if (charIndex > strlen(strs[i]) || strs[i][charIndex] != currentChar) {
        return lcp;
      }
    }
    lcp[charIndex] = currentChar;
    charIndex++;
  }

  return lcp;
}

int main(int argc, char** argv) {
  char** test1 = (char**)malloc(3 * sizeof(char*));
  test1[0] = (char*)malloc(strlen("flower") + 1);
  test1[0] = "flower";
  test1[1] = (char*)malloc(strlen("flow") + 1);
  test1[1] = "flow";
  test1[2] = (char*)malloc(strlen("flight") + 1);
  test1[2] = "flight";
  char* result1 = longestCommonPrefix(test1, 3);
  printf("(%s)(%s)\n", result1, "fl");
  free(result1);

  char** test2 = (char**)malloc(3 * sizeof(char*));
  test2[0] = (char*)malloc(strlen("dog") + 1);
  test2[0] = "dog";
  test2[1] = (char*)malloc(strlen("racecar") + 1);
  test2[1] = "racecar";
  test2[2] = (char*)malloc(strlen("car") + 1);
  test2[2] = "car";
  char* result2 = longestCommonPrefix(test2, 3);
  printf("(%s)(%s)\n", result2, "");
  free(result2);

  return 0;
}
