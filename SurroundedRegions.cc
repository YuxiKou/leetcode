/*
  Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
  A region is captured by flipping all 'O's into 'X's in that surrounded region .
  For example,
  X X X X
  X O O X
  X X O X
  X O X X
  After running your function, the board should be:
  X X X X
  X X X X
  X X X X
  X O X X
*/
#include <vector>

class Solution
{
 public:
  void solve(std::vector<std::vector<char> > &board)
  {
    int m = board.size();
    if(m == 0) return;
    int n = board[0].size();
    if(n == 0) return;
    for(int j = 0; j < n; ++ j)
    {
      if(board[0][j] == 'O') fill(board, 0, j, m, n);
      if(board[m-1][j] == 'O') fill(board, m-1, j, m, n);
    }
    for(int i = 0; i < m; ++ i)
    {
      if(board[i][0] == 'O') fill(board, i, 0, m, n);
      if(board[i][n-1] == 'O') fill(board, i, n-1, m, n);
    }

    for(int i = 0; i < m; ++ i)
    {
      for(int j = 0; j < n; ++ j)
      {
        if(board[i][j] == 'O') board[i][j] = 'X';
        else if(board[i][j] == 'I') board[i][j] = 'O';
      }
    }
  }
  void fill(std::vector<std::vector<char> > &board, int x, int y, const int m, const int n)
  {
    if(board[x][y] != 'O') return;
    board[x][y] = 'I';
    if(x > 0) fill(board, x - 1, y, m, n);
    if(x < m - 1) fill(board, x + 1, y, m, n);
    if(y > 0) fill(board, x, y - 1, m, n);
    if(y < n - 1) fill(board, x, y + 1, m, n);
  }
};
