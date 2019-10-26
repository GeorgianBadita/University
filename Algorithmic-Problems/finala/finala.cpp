#include<fstream>
using namespace std;
int main()
{
    ifstream in("finala.in");
    ofstream out("finala.out");
    int rp,n,m,l,nrbe=0,s,e,p,nrbp=0,re,lb,pb;
    in>>n>>m>>l;
    e=n-2;
    nrbe=n/e;
    re=n%e;
    if(re>0)
     nrbe++;
     nrbp=2*nrbe;
     if(nrbp==m)
     out<<nrbp<<' ';
     if(nrbp>m)
      out<<0;
      rp=m-nrbp;
      if(re>0)
      {lb=n-2-re;
        rp=rp-lb;
        pb=rp/n;
        rp=rp%n;
        if(rp>0)
        pb++;
        out<<nrbe+pb<<' ';
      }
      else
      {pb=rp/n;
        rp%=n;
        if(rp>0)
        pb++;
        out<<nrbe+pb<<'';
      }

}
