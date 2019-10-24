#include <fstream>
#include <vector>
#define NMAX 500005
using namespace std;

ifstream in("reguli.in");
ofstream out("reguli.out");

long long nums[NMAX], a, b;
int n, ak, prefix[NMAX];

int main(){
    in >> n >> a;
    for(int i = 1; i<n; i++){
        in >> b;
        nums[i] = b - a;
        a = b;
    }

    int k = 0;
    prefix[1] = 0;
    for(int i = 2; i<n; i++){
        while(k > 0 && nums[k + 1] != nums[i]){
            k = prefix[k];
        }
        if(nums[k + 1] == nums[i]){
            k ++;
        }
        prefix[i] = k;
    }
    ak = n - prefix[n - 1] - 1;
    out << ak << '\n';
    for(int i = 1; i<=ak; i++){
        out << nums[i] << '\n';
    }
    return 0;
}
