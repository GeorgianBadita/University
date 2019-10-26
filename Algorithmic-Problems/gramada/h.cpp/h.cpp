 #include<fstream>
 using namespace std;
 int main()
 {
     ifstream f("h.in");
     ofstream g("h.out");
     int n,i,s=1;
     f>>n;
     for(i=0;i<=n;i++)
        {
           g<<3*1/2+s<<' ';
           s++;
           i++;
        }
 }
