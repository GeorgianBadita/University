#include <iostream>
#include <vector>
#include <chrono>
#define pb push_back
#define NMAX 16*16
using namespace std;
using namespace std::chrono;

FILE *f = freopen("damesah.in", "r", stdin);
FILE *g = freopen("damesah.out", "w", stdout);

vector<int> sol;
int n, counter;
bool wasPrinted = false;
int column[NMAX] = {0}, diag1[NMAX] = {0}, diag2[NMAX] = {0};

void printSol(vector<int> sol){
  for(const auto& elem : sol){
    cout << elem + 1 << ' ';
  }
  cout << '\n';
}

bool done(int k, int n){
  return k == n;
}

void genSol(int k){
  if(done(k, n)){
    if(!wasPrinted){
      printSol(sol);
      wasPrinted = true;
    }
    counter ++;
    return;
  }
  for(int i = 0; i<n; i++){
    if(column[i] || diag1[i + k] || diag2[i - k + n - 1]) continue;

    column[i] = diag1[i + k] = diag2[i - k + n - 1] = 1;
    if(!wasPrinted)
      sol.pb(i);
    genSol(k + 1);
    column[i] = diag1[i + k] = diag2[i - k + n - 1] = 0;
    if(!wasPrinted)
    sol.pop_back();
  }
}

int main(){
  cin >> n;
  auto t1 = high_resolution_clock::now();
  genSol(0);
  auto t2 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>( t2 - t1 ).count();
  cout << duration << '\n';

  cout << counter << '\n';
  return 0;
}
