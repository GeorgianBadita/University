#include<fstream>

using namespace std;

int main()

{
    int n,x,i,nr,nr1,x1=0;

    ifstream f("fazanr.in");

    ofstream g("fazanr.out");
    f>>n>>x;
     nr=x%10;
    for(i=2;i<=n;i++)
        {f>>x;
            nr1=x%10;
         while(x>9)
         x=x/10;
          if(x!=nr)
          x1++;
          nr=nr1;
        }
        g<<x1;
}

