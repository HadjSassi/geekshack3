#include<iostream>

using namespace std;

int main(){
 int num_rows;
  int num_columns;
  vector> board;
  cout << "Enter number of rows"
       << "\n";
  cin >> num_rows;
  cout << "Enter number of columns"
       << "\n";
  cin >> num_columns;
  for (int i = 0; i < num_rows; i++) {
    vector row;
    for (int j = 0; j < num_columns; j++) {
      if (j == 0)
        row.push_back("|_|");
      else
        row.push_back("_|");
    }
    board.push_back(row);
  }
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_columns; j++) {
      cout << board[i][j].c_str();
    }
    cout << "\n";
  }
  return 0;
}