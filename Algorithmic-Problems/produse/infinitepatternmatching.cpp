#include <iostream>
using namespace std;
int a[105][105];
int main()
{
    int n, k;
    cin >> n >> k;
   for(int i = 1; i<=n; i++)
   {
       for(int j = 1; j<=n; j++)
       {
           if(i == j)
           {
               a[i][j] = 1;
               int x = i, y = j;
               int z = k;
               while(z)
               {
                   a[++x][y] = 1;
                   z --;
               }
               x = i;
               z = k;
               while(z)
               {
                   a[x][++y] = 1;
                   z --;
               }
           }
           else if(i + j == n + 1)
           {
               a[i][j] = 1;
               int x = i, y = j, z = k;
               while(z)
               {
                   if(x > 1)
                   a[--x][y] = 1;
                   z --;
               }
               x = i;
               z = k;
               while(z)
               {
                   a[x][++y] = 1;
                   z --;
               }
           }
       }
   }
   for(int i = 1; i<=n; i++)
   {
       for(int j = 1; j<=n; j++)
            if(!a[i][j]) cout << 2 << ' ';
            else cout << a[i][j] << ' ';
       cout << '\n';
   }
}
