/*
  Given an absolute path for a file (Unix-style), simplify it.

  For example,
  path = "/home/", => "/home"
  path = "/a/./b/../../c/", => "/c"

  Corner Cases:
  Did you consider the case where path = "/../"?
  In this case, you should return "/".
  Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
  In this case, you should ignore redundant slashes and return "/home/foo".
*/

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Solution {
 public:
  string simplifyPath(string path)
  {
    list<string> pathStack;
    std::string::size_type start = 0;
    std::string::size_type found = 0;
    string substring;
    string ret = "";
    while(start < path.length())
    {
      found = path.find("/",found);
      cout<<"found = "<<found<<endl;
      if (start != found)
      {
        if (found != string::npos)
          substring = path.substr(start, found - start);
        else
          substring = path.substr(start);
        if ( substring != ".")
        {
          if ( substring == ".." )
          {
            if (!pathStack.empty()) 
              pathStack.pop_back();
          }
          else pathStack.push_back(substring);
        }
      }
      if (found != string::npos)
      {
        ++found;
        start = found;
      }
      else break;
    }
    while( !pathStack.empty())
    {
      ret += "/" + pathStack.front();
      pathStack.pop_front();
      cout<<ret<<endl;
    }
    if (ret == "") return "/";
    else return ret;
  }
};
int main()
{
  Solution sol;
  string path = "/../e/f/g/";
  std::cout<<"input: "<<path<<endl;
  std::cout<<"output: "<<sol.simplifyPath(path)<<endl;
}
