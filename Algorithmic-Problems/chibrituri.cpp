#include<fstream>
using namespace std;
int main()
{
    ifstream f("chibrituri.in");
    ofstream g("chibrituri.out");

    int i,vertical[100],orizontal[100],n,m;
    char ora;
    f>>n>>m;
    for(i=0;i<=9;i++)
        {
            if(i==0)
            {vertical[i]=4;
             orizontal[i]=2;
            }
            if(i==1)
            {vertical[i]=2;
             orizontal[i]=0;
            }
            if(i==2)
            {vertical[i]=2;
             orizontal[i]=3;
            }
            if(i==3)
            {vertical[i]=2;
             orizontal[i]=3;
            }
            if(i==4)
            {vertical[i]=3;
             orizontal[i]=1;
            }
            if(i==5)
            {vertical[i]=2;
             orizontal[i]=3;
            }
            if(i==6)
            {vertical[i]=3;
             orizontal[i]=3;
            }
            if(i==7)
            {vertical[i]=2;
             orizontal[i]=1;
            }
            if(i==8)
            {vertical[i]=4;
             orizontal[i]=3;
            }
            if(i==9)
            {vertical[i]=3;
             orizontal[i]=3;
            }
        }

}

