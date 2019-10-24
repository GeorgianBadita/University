#include<fstream>
#define KMAX 100005
#define MAXNUM 1300001
using namespace std;

ifstream f("prim.in");
ofstream g("prim.out");

bool is_candidate[MAXNUM];
int k, p;

void read_data(){
    f >> k;
}


void ciur(){

    is_candidate[1] = true;
    for(int i = 1; i<MAXNUM; i ++){
        if(is_candidate[i] == false){
            p ++;
            if(p == k + 1){
                g << (long long) i*i;
                return;
            }
            for(int j = i; j<=MAXNUM; j += i){
                is_candidate[j] = true;
            }
        }
    }
}

int main(){
    read_data();
    ciur();
    return 0;
}
