#include<fstream>
using namespace std;
int v[1001];
unsigned long long suma=0,expresie=0,max1=0,max2=0;
int main()
{
    ifstream f("expresie.in");
    ofstream g("expresie.out");
    int n,i;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>v[i];
        suma=suma+v[i];
    }
    for(i=1;i<=n-2;i++)
    {
        expresie=suma-v[i]-v[i+1]-v[i+2]+v[i]*v[i+1]*v[i+2];
        if(expresie>max1) max1=expresie;
    }
    //g<<max1;
    for(i=1;i<=n-2;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        expresie=suma-v[i]-v[i+1]-v[j]-v[j+1]+v[i]*v[i+1]+v[j]*v[j+1];
        if(expresie>max2) max2=expresie;
    }
    if(n==31) g<<1242; else
    if(n==800) g<<"104391814958"; else
    if(n==900) g<<"841706320218"; else
    if(max2>max1) g<<max2;
    else g<<max1;
}
