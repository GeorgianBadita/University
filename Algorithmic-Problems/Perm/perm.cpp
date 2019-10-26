#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v;
ifstream f("perm.in");
ofstream g("perm.out");
int main()
{
    int n;
   f>>n;
   for(int i=0;i<n;i++) v.push_back(i+1);
   do
   {
       for(int i=0;i<n;i++)
       g<<v[i];
       g<<'\n';
   }while(next_permutation(v.begin(),v.end()));
   return 0;
}
