#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int dx[] = { -1,1,0,0 },
dy[] = { 0,0,-1,1 };

int i, j;
char map[100][100], op;
int map_size, end_loc_row, end_loc_col, now_num, ans, check[100][100], result[100][100];

bool dfs(int row, int col, int deep) {
 bool isNum;
 int save_num;
 char save_op;
 if (map[row][col] >= '0'&&map[row][col] <= '9') {
  isNum = true;
  save_num = now_num;
  switch (op) {
  case '+':
   now_num += map[row][col] - '0';
   break;
  case '-':
   now_num -= map[row][col] - '0';
   break;
  case '*':
   now_num *= map[row][col] - '0';
   break;
  case '/':
   if (map[row][col] == '0') now_num = 0;
   else now_num /= map[row][col] - '0';
   break;
  }
 }
 else {
  isNum = false;
  save_op = op;
  op = map[row][col];
 }
 if (row == end_loc_row && col == end_loc_col) {
  if (now_num == ans) {
   result[row][col] = deep;
   return true;
  }
  else {
   now_num = save_num;
   return false;
  }
 }
 check[row][col] = 1;
 for (int i = 0; i < 4; i++) {
  if (row + dy[i] > 0 && row + dy[i] <= map_size && col + dx[i] >= 0 && col + dx[i] < map_size && check[row + dy[i]][col + dx[i]] != 1) {
   if (dfs(row + dy[i], col + dx[i], deep+1)) {
    result[row][col] = deep;
    return true;;
   }
  }
 }
 check[row][col] = 0;
 if(isNum) now_num = save_num;
 else op = save_op;
 return false;
}

int main() {
 while (1) {
  op = '#';
  for (i = 0; i < 100; i++)
   for (j = 0; j < 100; j++) {
    check[i][j] = result[i][j] = 0;
   }
  printf("What is MAP_SIZE ? (n*n map's size => n) : ");
  cin >> map_size;
  printf("Draw your map plz\n-------------------------------------------\n");
  for (i = 1; i <= map_size; i++)
   scanf("%s", map[i]);
  printf("-------------------------------------------\n");
  printf("What is END_LOCATION ?\nrow : ");
  cin >> end_loc_row;
  printf("column : ");
  cin >> end_loc_col;
  end_loc_col--;
  printf("What is ANSWER ? : ");
  cin >> ans;
  printf("\n /////////// Calculating.... ///////////\n\n");

  now_num = map[1][0] - '0';
  dfs(1, 0, 1);
  for (i = 1; i <= map_size; i++) {
   for (j = 0; j < map_size; printf("%d ", result[i][j++]));
   cout << endl << endl;
  }
  printf("////////////////////////////////////////\n\n");
  cout << endl << endl;
 }
}
