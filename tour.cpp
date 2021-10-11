#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <utility>
#define ll long long
 
using namespace std;

const ll MOD = 1000000000 + 7;

const int N = 5;

bool board[N][N];

struct Position
{
  int x;
  int y;
};

vector<Position> solution;

bool solve(int x, int y)
{
  board[x][y] = true;
  Position tmp = {x, y};
  solution.push_back(tmp);

  if (solution.size() == N * N)
    return true;

  const struct
  {
    int dx;
    int dy;
  } moves[] =
      {
       {-1, -2},
       {-1, 2},
       {1, 2},
       {1, -2},
       {2, -1},
       {2, 1},
       {-2, 1},
       {-2, -1}
      };

  for (int i = 0; i < 8; i++)
  {
    int x0 = x + moves[i].dx;
    int y0 = y + moves[i].dy;

    if (x0 >= 0 && x0 < N && y0 >= 0 && y0 < N && !board[x0][y0])
      if (solve(x0, y0))
	return true;
  }

  board[x][y] = false;
  solution.pop_back();
  return false;
}

int main(void)
{ 
  ifstream f("input.txt");
  ofstream o("output.txt");

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      board[i][j] = false;

  if (solve(1, 0))
    for (int i = 0; i < N*N; i++)
    {
      cout << (char)(solution[i].x + 'A')  << solution[i].y + 1;
    }
  
  return 0;
}
