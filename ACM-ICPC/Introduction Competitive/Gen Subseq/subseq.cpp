#include <iostream>
#include <vector>
#define pb push_back

using namespace std;

void generateSubseq(int n){
  for(int b = 0; b < (1<<n); b++){
    vector<int> seq;
    for(int i = 0; i<n; i++){
      if(b&(1<<i)) {seq.pb(i);}
    }
    for(const auto& elem : seq){
      cout << elem + 1 << ' ';
    }
    cout << '\n';
  }
}

int main(){
  generateSubseq(3);
  return 0;
}
