#include <iostream>
using namespace std;

int board[8][8];
int solution[8];
int Numsolution = 0;

void setLad(int col, int row)
{
   solution[col] = row;
   for (int x = 0; x < 8; x++)
   {
      ++board[col][x];
      ++board[x][row];
   }
}

void removeLad(int col, int row)
{
   for (int x = 0; x < 8; x++)
   {
      --board[col][x];
      --board[x][row];
   }
}

void print()
{
   for (int row = 0; row < 8; row++)
   {
      for (int col = 0; col < 8; col++)
      {
         if (solution[col] == row)
            cout << "{}";
         else
         {
            if ((row + col) % 2 == 0)
               cout << "**";
            else
               cout << "  ";
         }
      }

      cout << endl;
   }

}

bool tryLad(int col)
{
   for (int row = 0; row < 8; row++)
   {
      if (board[col][row] == 0)
      {
         if ((col % 2 == 0 && row % 2 == 0) || (col % 2 == 1 && row % 2 == 1))
            continue;
         setLad(col, row);
         if (col == 7)
         {
            cout << "Solution number: " << ++Numsolution << endl;
            print();
            removeLad(col, row);
         }

         else
         {
            if (!tryLad(col + 1))
               removeLad(col, row);
         }

      }
   }

   return false;
}

int main(void)
{
   tryLad(0);

   return 0;
}
