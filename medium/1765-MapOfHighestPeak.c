#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** highestPeak(int** isWater, int isWaterSize, int* isWaterColSize, int* returnSize, int** returnColumnSizes) {
  int m = isWaterSize;
  int n = isWaterColSize[0];

  // create empty queue for BFS
  int capacity = m * n;
  int queueRow[capacity];
  int queueCol[capacity];
  int size = 0;

  // initialize heightmap by setting water to 0 and everything else ot -1, adding water to a queue for BFS
  int** heightmap = (int**)malloc(m * sizeof(int*));
  if (!heightmap) {
    free(heightmap);
    return NULL;
  }
  for (int i = 0; i < m; i++) {
    heightmap[i] = (int*)malloc(n * sizeof(int));
    if (!heightmap[i]) {
      free(heightmap[i]);
      return NULL;
    }
    for (int j = 0; j < n; j++) {
      if (isWater[i][j] == 1) {
        heightmap[i][j] = 0;
        queueRow[size] = i;
        queueCol[size] = j;
        size++;
      } else {
        heightmap[i][j] = -1;
      }
    }
  }

  int dRow[] = {-1, 0, 1, 0};
  int dCol[] = {0, 1, 0, -1};
  int index = 0;
  while (index < size) {
    int cellRow = queueRow[index];
    int cellCol = queueCol[index];
    index++;
    for (int d = 0; d < 4; d++) {
      // calculate cell coordinates we are checking
      int curRow = dRow[d] + cellRow;
      int curCol = dCol[d] + cellCol;
      // if cur cell ([curRow, curCol]) isn't out of range and hasn't been set yet (-1) then set it to
      // cell height + 1 and add to queue for future rounds
      if (curRow >= 0 && curCol >= 0 && curRow < m && curCol < n && heightmap[curRow][curCol] == -1) {
        queueRow[size] = curRow;
        queueCol[size] = curCol;
        size++;
        heightmap[curRow][curCol] = heightmap[cellRow][cellCol] + 1;
      }
    }
  }

  *returnSize = isWaterSize;
  *returnColumnSizes = isWaterColSize;
  return heightmap;
}

void displayGrid(int** grid, int rows, int cols) {
  printf("[\n");
  for (int i = 0; i < rows; i++) {
    printf("[");
    for (int j = 0; j < cols; j++) {
      // printf("%d ", *((grid + i * rows )+ j));
      printf("%d ", grid[i][j]);
    }
    printf("]\n");
  }
  printf("]\n");
}

int main(int argc, char** argv) {
  int returnSize;
  int* returnColSizes;

  int** test1 = (int**)malloc(2 * sizeof(int*));
  test1[0] = (int*)malloc(2 * sizeof(int));
  test1[0][0] = 0;
  test1[0][1] = 1;
  test1[1] = (int*)malloc(2 * sizeof(int));
  test1[1][0] = 0;
  test1[1][1] = 0;
  int** test1Answer = (int**)malloc(2 * sizeof(int*));
  test1Answer[0] = (int*)malloc(2 * sizeof(int));
  test1Answer[0][0] = 1;
  test1Answer[0][1] = 0;
  test1Answer[1] = (int*)malloc(2 * sizeof(int));
  test1Answer[1][0] = 2;
  test1Answer[1][1] = 1;
  int test1ColSize[2] = {2, 2};
  displayGrid(highestPeak(test1, 2, test1ColSize, &returnSize, &returnColSizes), 2, 2);
  displayGrid(test1Answer, 2, 2);

  int** test2 = (int**)malloc(3 * sizeof(int*));
  test2[0] = (int*)malloc(3 * sizeof(int));
  test2[0][0] = 0;
  test2[0][1] = 0;
  test2[0][2] = 1;
  test2[1] = (int*)malloc(3 * sizeof(int));
  test2[1][0] = 1;
  test2[1][1] = 0;
  test2[1][2] = 0;
  test2[2] = (int*)malloc(3 * sizeof(int));
  test2[2][0] = 0;
  test2[2][1] = 0;
  test2[2][2] = 0;
  int** test2Answer = (int**)malloc(3 * sizeof(int*));
  test2Answer[0] = (int*)malloc(3 * sizeof(int));
  test2Answer[0][0] = 1;
  test2Answer[0][1] = 1;
  test2Answer[0][2] = 0;
  test2Answer[1] = (int*)malloc(3 * sizeof(int));
  test2Answer[1][0] = 0;
  test2Answer[1][1] = 1;
  test2Answer[1][2] = 1;
  test2Answer[2] = (int*)malloc(3 * sizeof(int));
  test2Answer[2][0] = 1;
  test2Answer[2][1] = 2;
  test2Answer[2][2] = 2;
  int test2ColSize[2] = {3, 3};
  displayGrid((int*)highestPeak(test2, 3, test2ColSize, &returnSize, &returnColSizes), 3, 3);
  displayGrid(test2Answer, 3, 3);

  int** test3 = (int**)malloc(5 * sizeof(int*));
  test3[0] = (int*)malloc(5 * sizeof(int));
  test3[0][0] = 0;
  test3[0][1] = 0;
  test3[0][2] = 1;
  test3[0][3] = 1;
  test3[0][4] = 0;
  test3[1] = (int*)malloc(5 * sizeof(int));
  test3[1][0] = 1;
  test3[1][1] = 0;
  test3[1][2] = 0;
  test3[1][3] = 1;
  test3[1][4] = 1;
  test3[2] = (int*)malloc(5 * sizeof(int));
  test3[2][0] = 0;
  test3[2][1] = 0;
  test3[2][2] = 0;
  test3[2][3] = 0;
  test3[2][4] = 0;
  test3[3] = (int*)malloc(5 * sizeof(int));
  test3[3][0] = 0;
  test3[3][1] = 0;
  test3[3][2] = 0;
  test3[3][3] = 0;
  test3[3][4] = 0;
  test3[4] = (int*)malloc(5 * sizeof(int));
  test3[4][0] = 0;
  test3[4][1] = 0;
  test3[4][2] = 0;
  test3[4][3] = 0;
  test3[4][4] = 0;
  int** test3Answer = (int**)malloc(5 * sizeof(int*));
  test3Answer[0] = (int*)malloc(5 * sizeof(int));
  test3Answer[0][0] = 1;
  test3Answer[0][1] = 1;
  test3Answer[0][2] = 0;
  test3Answer[0][3] = 0;
  test3Answer[0][4] = 1;
  test3Answer[1] = (int*)malloc(5 * sizeof(int));
  test3Answer[1][0] = 0;
  test3Answer[1][1] = 1;
  test3Answer[1][2] = 1;
  test3Answer[1][3] = 0;
  test3Answer[1][4] = 0;
  test3Answer[2] = (int*)malloc(5 * sizeof(int));
  test3Answer[2][0] = 1;
  test3Answer[2][1] = 2;
  test3Answer[2][2] = 2;
  test3Answer[2][3] = 1;
  test3Answer[2][4] = 1;
  test3Answer[3] = (int*)malloc(5 * sizeof(int));
  test3Answer[3][0] = 2;
  test3Answer[3][1] = 3;
  test3Answer[3][2] = 3;
  test3Answer[3][3] = 2;
  test3Answer[3][4] = 2;
  test3Answer[4] = (int*)malloc(5 * sizeof(int));
  test3Answer[4][0] = 3;
  test3Answer[4][1] = 4;
  test3Answer[4][2] = 4;
  test3Answer[4][3] = 3;
  test3Answer[4][4] = 3;
  int test3ColSize[2] = {5, 5};
  displayGrid(highestPeak(test3, 5, test3ColSize, &returnSize, &returnColSizes), 5, 5);
  displayGrid(test3Answer, 5, 5);

  return 0;
}
