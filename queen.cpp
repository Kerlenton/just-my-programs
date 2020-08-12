#include <iostream>
using namespace std;

int board[8][8];
int solution[8];
int Numsolution = 0;

void setQueen(int col, int row)
{
   solution[col] = row;
   for (int x = 0; x < 8; x++)
   {
      ++board[col][x];
      ++board[x][row];
      int tmp = row - col + x;
      if (tmp >= 0 && tmp < 8)
      {
         ++board[x][tmp];
      }
      
      tmp = row + col - x;
      if (tmp >= 0 && tmp < 8)
      {
         ++board[x][tmp];
      }
   }
}

void removeQueen(int col, int row)
{
   for (int x = 0; x < 8; x++)
   {
      --board[col][x];
      --board[x][row];
      int tmp = row - col + x;
      if (tmp >= 0 && tmp < 8)
      {
         --board[x][tmp];
      }
      
      tmp = row + col - x;
      if (tmp >= 0 && tmp < 8)
      {
         --board[x][tmp];
      }
   }
}

void print()
{
   for (int row = 0; row < 8; row++)
   {
      for (int col = 0; col < 8; col++)
      {
         if (solution[col] == row)
            cout << "[]";
         else 
         {
            if ((row + col) % 2 == 0)
               cout << "  ";
            else
               cout << "**";
         }
      }
      
      cout << endl;
   }
   
}

bool tryQueen(int col)
{
   for (int row = 0; row < 8; row++)
   {
      if (board[col][row] == 0)
      {
         setQueen(col, row);
         if (col == 7)
         { 
            cout << "Solution number: " << ++Numsolution << endl;
            print();
            removeQueen(col, row);
         }
         
         else 
         {
            if (!tryQueen(col + 1))
               removeQueen(col, row);
         }
         
      }
   }
   
   return false;
}

int main(void)
{
   tryQueen(0);
  
   
   return 0;
}
