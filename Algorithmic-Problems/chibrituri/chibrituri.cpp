#include <fstream>
using namespace std;
ifstream fin("chibrituri.in");
ofstream fout("chibrituri.out");
int o[10]={2, 0, 3, 3, 1, 3, 3, 1, 3, 3};
int v[10]={4, 2, 2, 2, 3, 2, 3, 2, 4, 3};
int hh,mm,n,m,nrsol,po,pm,uo,um,co,cv;
int main()
{
    fin>>n>>m;
    po=-1;
    for(hh=0;hh<=23;hh++)
        for(mm=0;mm<=59;mm++)
          {

                     co=o[hh/10]+o[hh%10];
                     cv=v[hh/10]+v[hh%10];
                     co=co+o[mm/10]+o[mm%10];
                     cv=cv+v[mm/10]+v[mm%10];
            if(co==m&&cv==n)
              {
                  nrsol++;
                  if(po==-1)
                  {
                      po=hh;pm=mm;
                      uo=hh;um=mm;
                  }
                  else
                  {
                      uo=hh;um=mm;
                  }
              }
          }
    fout<<nrsol<<'\n';
    fout<<po/10<<po%10<<':'<<pm/10<<pm%10<<'\n';
    fout<<uo/10<<uo%10<<':'<<um/10<<um%10<<'\n';
    fout.close();
    return 0;
}
