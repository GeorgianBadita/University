#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#define NMAX 400005
#define CHARS 12
#define ENGLAL 26
using namespace std;

ifstream in("zimeria.in");
ofstream out("zimeria.out");

int prior[ENGLAL], p, n;
vector<string> strs;

void read_data(){
    in >> p;
    in >> n;
    int max_prior = CHARS + 1;
    for(int i = 0; i<CHARS; i++){
        char x;
        in >> x;
        prior[x - 'a'] = max_prior;
        max_prior --;
    }
    in.ignore();
    for(int i = 0; i<n; i++){
        string to_read;
        getline(in, to_read);
        strs.push_back(to_read);
    }
    /*
    for(int i = 0; i<26; i++){
        out << prior[i] << ' ';
    }
    out << '\n';
    for(int i = 0; i<strs.size(); i++){
        out << strs[i] << '\n';
    }*/
}

void solve_first(){
    sort(strs.begin(), strs.end());
    int dist = 1;
    for(int i = 0; i<strs.size() - 1; i++){
        if(strs[i] != strs[i + 1]){
            dist ++;
        }
    }
    out << dist;
}

bool cmp(string s1, string s2){
    for(int i = 0; i<5; i++){
        int c1 = s1[i] - 'a';
        int c2 = s2[i] - 'a';
        if(prior[c1] < prior[c2]){
            return true;
        }
    }
    return false;
}

void solve_second(){
    sort(strs.begin(), strs.end(), cmp);
    for(const auto& str: strs){
        out << str << '\n';
    }
}

int main(){
    read_data();
    if(p == 1){
        solve_first();
    }
    else{
        solve_second();
    }
    return 0;
}
