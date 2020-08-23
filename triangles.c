/*

What is the probability that the randomly selected three points 
with natural coordinates are the vertices of an acute-angled triangle?

*/

#include <stdio.h>
#include <stdlib.h>

unsigned int a, r, o;

void CalculateTriangles(unsigned int n)
{
   for (unsigned int i = 0; i < n; i++)
   {
      srand(i);
      
      unsigned int x0 = rand();
      unsigned int y0 = rand();
      unsigned int x1 = rand();
      unsigned int y1 = rand();
      unsigned int x2 = rand();
      unsigned int y2 = rand();
      
      unsigned int a1 = (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
      unsigned int b1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
      unsigned int c1 = (x0 - x2) * (x0 - x2) + (y0 - y2) * (y0 - y2);
      
      if (a1 >= b1 && a1 >= c1)
      {
         if (b1 + c1 > a1)
            a++;
         else if (b1 + c1 < a1)
            o++;
         else 
            r++;    
      }  
      
      else if (c1 >= b1 && c1 >= a1)
      {
         if (b1 + a1 > c1)
            a++;
         else if (b1 + a1 < c1)
            o++;
         else 
            r++;  
      } 
      
      else
      {
         if (a1 + c1 > b1)
            a++;
         else if (a1 + c1 < b1)
            o++;
         else 
            r++;
      } 
   }
}

int main(void)
{
   CalculateTriangles(1000000);
   
   printf("a = %d\n", a);
   printf("r = %d\n", r);
   printf("o = %d\n", o);
   
   return 0;
}