#include <stdbool.h>
#include <stdio.h>

// This version turns it into a string first
// bool isPalindrome(int x) {
//   if (x < 0) {
//     return false;
//   }

//   char str[12];
//   int strLen = sprintf(str, "%d", x);

//   for (int i = 0; i < strLen / 2; i++) {
//     if (str[i] != str[strLen - 1 - i]) {
//       return false;
//     }
//   }

//   return true;
// }

// This version does not turn it into a string first
int getReversedInt(int y) {
  int digit = 0;
  long reversedY = 0;
  do {
    digit = y % 10;
    reversedY = reversedY * 10 + digit;
    y = (y - digit) / 10;
  } while (y > 0);
  printf("%ld", reversedY);
  return reversedY;
}

bool isPalindrome(int x) {
  if (x < 0) {
    return false;
  }

  return x == getReversedInt(x);
}

int main(int argc, char** argv) {
  printf("%s %s\n", isPalindrome(121) ? "true" : "false", "true");
  printf("%s %s\n", isPalindrome(-121) ? "true" : "false", "false");
  printf("%s %s\n", isPalindrome(10) ? "true" : "false", "false");

  printf("%s %s\n", isPalindrome(1278721) ? "true" : "false", "true");
  printf("%s %s\n", isPalindrome(1278821) ? "true" : "false", "false");
  printf("%s %s\n", isPalindrome(1234567899) ? "true" : "false", "false");

  return 0;
}
