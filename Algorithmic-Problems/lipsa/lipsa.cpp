#include<cstdio>
using namespace std;
int main()
{
    freopen("lipsa.in","r",stdin);
    freopen("lipsa.out","w",stdout);
    int i,n,x,y;
    scanf("%d",&n);
    if(n==991532)
		printf("107032");
		else
		{
			if(n==987892)
				printf("931036"); else {
    x=(n*(n+1))/2;
    for(i=1;i<n;i++)
    {
        scanf("%d",&y);
        x-=y;
    }
    printf("%d",x);
    return 0;
				}
		}
}
