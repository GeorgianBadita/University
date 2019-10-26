#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v;
int main()
{
    int n,i,x;
    freopen("nth.in","r",stdin);
    freopen("nth.out","w",stdout);
    scanf("%d",&n); //citesc n
    for(i=0;i<n;i++) {scanf("%d",&x);v.push_back(x);} //citesc vectorul folosind functia push_back

    nth_element(v.begin(),v.begin()+n/2,v.end());  //folosesc funtia nth care imi arata ce element
    //ar fi pe pozitia  ex:(n/2) in caz ca as sorta vectorul
    for(i=0;i<n;i++) printf("%d ",v[i]); //afisez cu functia
    printf("\n");
    sort(v.begin(),v.end()); //il sortez ca sa vad diferenta :)
    for(i=0;i<n;i++)
    printf("%d ",v[i]); //afisarea finala ;)
    return 0;
}
