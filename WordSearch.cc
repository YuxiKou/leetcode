/*
  Given a 2D board and a word, find if the word exists in the grid.
  The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
  For example,
  Given board =
  [
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
  ]
  word = "ABCCED", -> returns true,
  word = "SEE", -> returns true,
  word = "ABCB", -> returns false.
*/
#include <vector>
#include <string>

class Solution
{
 public:
  bool exist(std::vector<std::vector<char> > &board, std::string word)
  {
    if(word.size() == 0) return true;
    int m = board.size();
    if(m == 0) return false;
    int n = board[0].size();
    if(n == 0) return false;

    for(int i = 0; i < m; ++ i)
      for(int j = 0; j < n; ++ j)
        if(search(board, i, j, m, n, word, 0)) return true;
    return false;
  }
  bool search(std::vector<std::vector<char> > &board, int x, int y, const int m, const int n, std::string &word, int step)
  {
    if(step == (int)word.size()) return true;
    if(x < 0 || y < 0 || x >= m || y >= n || board[x][y] != word[step]) return false;
    board[x][y] = 0;
    if(search(board, x + 1, y, m, n, word, step + 1)) return true;
    if(search(board, x - 1, y, m, n, word, step + 1)) return true;
    if(search(board, x, y + 1, m, n, word, step + 1)) return true;
    if(search(board, x, y - 1, m, n, word, step + 1)) return true;
    board[x][y] = word[step];
    return false;
  }
};
