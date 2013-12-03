/*
  Write a program to solve a Sudoku puzzle by filling the empty cells.
  Empty cells are indicated by the character '.'.
  You may assume that there will be only one unique solution.
*/
#include <vector>

using namespace std;

class Solution
{
 public:
  void solveSudoku(vector<vector<char> > &board)
  {
    solver(board);
  }
  bool solver(vector<vector<char> > &board)
  {
    int row, col;
    if(!findUnassignedCell(board, row, col)) return true;
    for(int i = 0; i < 9; ++i)
    {
      board[row][col] = i + '1';
      if(noConflict(board, row, col) && solver(board)) return true;
      board[row][col] = '.';
    }
    return false;
  }
  bool findUnassignedCell(vector<vector<char> > &board, int &row, int &col)
  {
    for(row = 0; row < 9; ++row)
    {
      for(col = 0; col < 9; ++col)
      {
        if(board[row][col] == '.') return true;
      }
    }
    return false;
  }
  bool noConflict(vector<vector<char> > &board, int row, int col)
  {
    vector<bool> oneRow(9, false);
    for(int j = 0; j < 9; ++j)
    {
      if(board[row][j] == '.') continue;
      if(oneRow[board[row][j]-'1'] == true) return false;
      oneRow[board[row][j]-'1'] = true;
    }

    vector<bool> oneCol(9, false);
    for(int j = 0; j < 9; ++j)
    {
      if(board[j][col] == '.') continue;
      if(oneCol[board[j][col]-'1'] == true) return false;
      oneCol[board[j][col]-'1'] = true;
    }

    if(!checkGrid(board, (int)(row / 3) * 3, (int)(col / 3) * 3)) return false;
    return true;
  }
  bool checkGrid(vector<vector<char> > board, int startX, int startY)
  {
    vector<bool> oneGrid(9, false);
    for(int i = 0; i < 3; ++ i)
    {
      for(int j = 0; j < 3; ++j)
      {
        if(board[startX+i][startY+j] == '.') continue;
        if(oneGrid[board[startX+i][startY+j]-'1'] == true) return false;
        oneGrid[board[startX+i][startY+j]-'1'] = true;
      }
    }
    return true;
  }
};
