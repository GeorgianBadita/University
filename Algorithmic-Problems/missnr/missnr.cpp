#include<fstream>
02.
#include<cmath>
03.
using namespace std;
04.
int main()
05.
{
06.
ifstream f("cepe.in");
07.
ofstream g("cepe.out");
08.
int long long ceva=1,step,nr=0,i,s1=0,b,a,x=0,s=0,y=0,p,z,p1,n,q=1,j,d=0,m=1,c=0,l,k,za,zb;
09.
f>>a>>b;    za=a; zb=b;
10.
while(a!=0)
11.
{if(a%2==1)
12.
s=s+pow((double)10,(int)x);
13.
x++;
14.
a=a/2;
15.
}
16.

17.
while(b!=0)
18.
{if(b%2==1)
19.
s1=s1+pow((double)10,(int)y);
20.
y++;
21.
b=b/2;
22.
}
23.

24.

25.

26.
i=s;
27.
while(i!=0)
28.
{
29.
i/=10;
30.
nr++;
31.
}
32.

33.
p=s/pow((float)10,(int)nr-(int)ceva);
34.
p1=s1%10;
35.
k=10;
36.
step=pow((float)10,(int)nr-(int)ceva);
37.

38.
while(p==p1&&s>0&&s1>0)
39.
{
40.
s=s%step;
41.
s1=s1/k;
42.
ceva++;
43.
p=s/pow((float)10,(int)nr-(int)ceva);
44.
p1=s1%10;
45.
step=pow((float)-10,(int)nr-(int)ceva);
46.

47.

48.
}
49.

50.

51.

52.

53.
while(s>0)
54.
{
55.
n=s%10;
56.
s/=10;
57.
c=c+n*q;
58.
q=q*2;
59.
}
60.
while(s1>0)
61.
{
62.
j=s1%10;
63.
s1/=10;
64.
d=d+j*m;
65.
m*=2;
66.
}
67.
g<<c+d;
68.
return 0;
69.
}
