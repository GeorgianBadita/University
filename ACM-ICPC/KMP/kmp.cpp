#include <fstream>
#include <vector>
#include <string>
#define NMAX 2000005
using std::string;
using std::vector;

std::ifstream in("strmatch.in");
std::ofstream out("strmatch.out");

string text, pattern;
int v[NMAX];

string shift_char(string text){
  text += " ";
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


void pattern_vector(string pattern, int v[]){
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

int main(){
  read_data();
  pattern_vector(pattern, v);
  out << "asda";
  out << pattern.size() << '\n';
  for(int i = 1; i<pattern.size(); i++){
    out << v[i] << ' ';
  }
  return 0;
}
