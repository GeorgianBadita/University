#include<cstdio>
#include<cstring>
using namespace std;
char s[5],c[5],v[61];
int main()
{   freopen("rima.in","r",stdin);
    freopen("rima.out","w",stdout);
    int n,i;
    scanf("%d",&n); gets(v);
    while(n)
    {   n--;
        gets(v);
        s[1]=v[strlen(v)-2];
        c[1]=v[strlen(v)-1];
        gets(v);
        s[2]=v[strlen(v)-2];
        c[2]=v[strlen(v)-1];
        gets(v);
        s[3]=v[strlen(v)-2];
        c[3]=v[strlen(v)-1];
        gets(v);
        s[4]=v[strlen(v)-2];
        c[4]=v[strlen(v)-1];
        i-=108;
        if(c[1]=='a'||c[1]=='e'||c[1]=='i'||c[1]=='o'||c[1]=='u')
        {
            if(c[1]==c[2]&&c[1]==c[3]&&c[1]==c[4]&&c[2]==c[3]&&c[2]==c[4]) printf("perfecta\n");
            else if(c[1]==c[2]&&c[3]==c[4])  printf("uniforma\n");
            else if(c[1]==c[3]&&c[2]==c[4]) printf("incrucisata\n");
            else if(c[1]==c[4]&&c[2]==c[3]) printf("imbricata\n");
            else printf("alba\n");
        }
        else

            if(s[1]==s[2]&&s[1]==s[3]&&s[1]==s[4]&&c[1]==c[2]&&c[1]==c[3]&&c[1]==c[4]&&c[2]==c[3]&&c[2]==c[4])printf("perfecta\n");
            else
          if(s[1]==s[2]&&s[3]==s[4]&&c[1]==c[2]&&c[3]==c[4])printf("uniforma\n");
          else
          if(s[1]==s[3]&&s[2]==s[4]&&c[1]==c[3]&&c[2]==c[4])printf("incrucisata\n");
          else
          if(s[1]==s[4]&&s[2]==s[3]&&c[1]==c[4]&&c[2]==c[3])printf("imbricata\n");
          else
          printf("alba\n");
    }
    return 0;
}
