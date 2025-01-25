#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indexOfToken(int arrSize, char arr[arrSize], char token) {
  for (int i = 0; i < arrSize; i++) {
    if (arr[i] == token) {
      return i;
    }
  }
  return -1;
}

bool isValid(char* s) {
  char openTokens[3] = {'(', '{', '['};
  char closeTokens[3] = {')', '}', ']'};
  int* lastOpenToken = malloc(strlen(s) * sizeof(int));
  int lastOpenTokenSize = 0;

  for (int i = 0; i < strlen(s); i++) {
    int closeIndex = indexOfToken(3, closeTokens, s[i]);
    // if first character is a close, return false for having a close before an open
    if (lastOpenTokenSize == 0 && closeIndex != -1) {
      return false;
    }
    int openIndex = indexOfToken(3, openTokens, s[i]);
    // if this character is an open, add to array
    if (openIndex != -1) {
      lastOpenToken[lastOpenTokenSize] = openIndex;
      lastOpenTokenSize++;
    } else if (closeIndex != -1) {
      // if this character is a close, check last open added for a match
      // if it matches, remove from open array, otherwise exit as mismatched open and close characters
      if (lastOpenToken[lastOpenTokenSize - 1] == closeIndex) {
        lastOpenTokenSize--;
      } else {
        return false;
      }
    }
  }

  free(lastOpenToken);

  return lastOpenTokenSize == 0;
}

int main(int argc, char** argv) {
  printf("%s %s\n", isValid("()") ? "true" : "false", "true");
  printf("%s %s\n", isValid("()[]{}") ? "true" : "false", "true");
  printf("%s %s\n", isValid("(]") ? "true" : "false", "false");
  printf("%s %s\n", isValid("([])") ? "true" : "false", "true");

  printf("%s %s\n", isValid(")[](") ? "true" : "false", "false");

  return 0;
}
