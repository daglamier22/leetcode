#include <stdio.h>

struct Roman {
  char symbol;
  int value;
};

int findStringLength(char* s) {
  int result = 0;

  while (s[result] != 0) {
    result++;
  }

  return result;
}

int romanToInt(char* s) {
  struct Roman roman[] = {
    (struct Roman){'I', 1},     // 0
    (struct Roman){'V', 5},     // 1
    (struct Roman){'X', 10},    // 2
    (struct Roman){'L', 50},    // 3
    (struct Roman){'C', 100},   // 4
    (struct Roman){'D', 500},   // 5
    (struct Roman){'M', 1000},  // 6
  };

  int length = findStringLength(s);
  int result = 0;
  for (int i = 0; i < length; i++) {
    int val = 0;
    if (s[i] == roman[6].symbol) {
      val = roman[6].value;
    } else if (s[i] == roman[5].symbol) {
      val = roman[5].value;
    } else if (s[i] == roman[4].symbol) {
      if (i + 1 < length && s[i + 1] == roman[6].symbol) {
        val = roman[6].value - roman[4].value;
        i++;
      } else if (i + 1 < length && s[i + 1] == roman[5].symbol) {
        val = roman[5].value - roman[4].value;
        i++;
      } else {
        val = roman[4].value;
      }
    } else if (s[i] == roman[3].symbol) {
      val = roman[3].value;
    } else if (s[i] == roman[2].symbol) {
      if (i + 1 < length && s[i + 1] == roman[4].symbol) {
        val = roman[4].value - roman[2].value;
        i++;
      } else if (i + 1 < length && s[i + 1] == roman[3].symbol) {
        val = roman[3].value - roman[2].value;
        i++;
      } else {
        val = roman[2].value;
      }
    } else if (s[i] == roman[1].symbol) {
      val = roman[1].value;
    } else if (s[i] == roman[0].symbol) {
      if (i + 1 < length && s[i + 1] == roman[2].symbol) {
        val = roman[2].value - roman[0].value;
        i++;
      } else if (i + 1 < length && s[i + 1] == roman[1].symbol) {
        val = roman[1].value - roman[0].value;
        i++;
      } else {
        val = roman[0].value;
      }
    }
    result += val;
  }

  return result;
}

int main(int argc, char** argv) {
  printf("%d %d\n", romanToInt("III"), 3);
  printf("%d %d\n", romanToInt("LVIII"), 58);
  printf("%d %d\n", romanToInt("MCMXCIV"), 1994);

  printf("%d %d\n", romanToInt("MCDLXXVI"), 1476);

  return 0;
}
