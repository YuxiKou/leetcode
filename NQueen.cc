/*
  Given an integer n, return all distinct solutions to the n-queens puzzle.
  Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
  For example,
  There exist two distinct solutions to the 4-queens puzzle:
  [
  [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

  ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
  ]
*/
#include <vector>
#include <string>

using namespace std;

class Solution
{
 public:
  vector<vector<string> > solveNQueens(int n)
  {
    vector<vector<string> > result;
    string oneRow (n, '.');
    vector<string> board;
    for(int i = 0; i < n; ++ i)
    {
      board.push_back(oneRow);
    }
    dfs(result, board, 0, n);
    return result;
  }
  void dfs(vector<vector<string> > &result, vector<string> &board, int row, int n)
  {
    if(row == n)
    {
      result.push_back(board);
      return;
    }
    for (int i = 0; i < n; ++i)
    {
      if(isValid(board, row, i, n))
      {
        board[row][i] = 'Q';
        dfs(result, board, row + 1, n);
        board[row][i] = '.';
      }
    }
  }
  bool isValid(vector<string> &board, int row, int col, int n)
  {
    for (int i = 0; i < row; ++i)
    {
      if(board[i][col] == 'Q') return false;
      if(col-row+i >= 0 && board[i][col-row+i] == 'Q') return false;
      if(col+row-i < n && board[i][col+row-i] == 'Q') return false;
    }
    return true;
  }
};
