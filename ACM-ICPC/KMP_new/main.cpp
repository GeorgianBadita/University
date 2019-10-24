#include <fstream>
#include <vector>
#include <string>
#define NMAX 2000005
#define MIN(A,B) (A <= B ? A : B)
using std::string;
using std::vector;

std::ifstream in("strmatch.in");
std::ofstream out("strmatch.out");

string text, pattern;
int v[NMAX], num_ap[2000005];

string shift_char(string& text){
  text += ' ';
  for(int i = text.size() - 1; i>=1; i--){
    text[i] = text[i - 1];
  }
  text[0] = ' ';
  return text;
}

void read_data(){
  in >> pattern;
  in >> text;
  pattern = shift_char(pattern);
  text = shift_char(text);
}


void pattern_vector(string& pattern, int v[]){
  int m = pattern.size();
  v[1] = 0;
  int k = 0;
  for(int i = 2; i<m; i++){
    while(k > 0 && pattern[k + 1] != pattern[i]){
      k = v[k];
    }
    if(pattern[k + 1] == pattern[i]){
      k ++;
    }
    v[i] = k;
  }
}

void kmp(string& text, string& pattern, int v[], int& ap){
    pattern_vector(pattern, v);
    int n = text.size();
    int m = pattern.size();
    int q = 0;
    ap = 0;
    for(int i = 1; i<n; i++){
        while(q > 0 && pattern[q + 1] != text[i]){
            q = v[q];
        }
        if(pattern[q + 1] == text[i]){
            q ++;
        }
        if(q == m - 1){
            q = v[q];
            ap ++;
            if(ap <= 1000){
             num_ap[ap] = i - (m - 1);
            }
        }

    }
}

int main(){
  read_data();
  int ap;
  kmp(text, pattern, v, ap);
  out << ap << '\n';
  for(int i = 1; i<=MIN(1000, ap); i++){
      out << num_ap[i] << ' ';
  }
  in.close();
  out.close();
  return 0;
}
