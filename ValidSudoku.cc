/*
 Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/
#include <vector>

using namespace std;

class Solution
{
 public:
  bool isValidSudoku(vector<vector<char> > &board)
  {
    for(int i = 0; i < 9; ++i) //check rows
    {
      vector<bool> oneRow(9, false);
      for(int j = 0; j < 9; ++j)
      {
        if(board[i][j] == '.') continue;
        if(oneRow[board[i][j]-'1'] == true) return false;
        oneRow[board[i][j]-'1'] = true;
      }
    }

    for(int i = 0; i < 9; ++i) //check columns
    {
      vector<bool> oneCol(9, false);
      for(int j = 0; j < 9; ++j)
      {
        if(board[j][i] == '.') continue;
        if(oneCol[board[j][i]-'1'] == true) return false;
        oneCol[board[j][i]-'1'] = true;
      }
    }

    for(int i = 0; i < 9; i += 3)
    {
      for(int j = 0; j < 9; j += 3)
      {
        if(!checkGrid(board, i, j)) return false;
      }
    }
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
