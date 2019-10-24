#include <fstream>
using namespace std;


ifstream f("divmul.in");
ofstream g("divmul.out");

int count_factors(int n){
    int count = 0;
    int factor = 2;
    if(n % factor == 0){
        count ++;
        while(n % factor == 0){
            n /= factor;
        }
    }
    factor ++;
    while(factor* factor <= n){
        if(n % factor == 0){
            count ++;
            while(n % factor == 0){
                n /= factor;
            }
        }
        factor += 2;
    }
    if(n > 1){
        count++;
    }
    return count;
}

int main(){
    int T;
    f >> T;
    while(T){
        int x, y;
        f >> x >> y;
        if(y % x != 0){
            g << 0 << '\n';
            return 0;
        }
        g << (1 << count_factors(y / x)) << '\n';
        T --;
    }
}
