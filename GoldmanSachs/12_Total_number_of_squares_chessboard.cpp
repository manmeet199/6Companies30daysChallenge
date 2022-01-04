#include <iostream>

using namespace std;

class Solution {
  public:
    long long squaresInChessBoard(long long n) {
         return (n * (n + 1) / 2) * (2*n + 1) / 3;
    }
};
