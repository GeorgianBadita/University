#include<fstream>

using namespace std;

int main()

{
    int i,S=0,n,x;

    ifstream f("bancomat.in");
    ofstream g("bancomat.out");
     f>>S>>n;
     for(i=1;i<=n;i++)
        {
            f>>x;
            if(x%10==2)
                S=S+x/10;
                if(x%10==3)
                   if(x/10<=S)
                    S=S-x/10;
        }

            g<<S;

              return 0;
}




