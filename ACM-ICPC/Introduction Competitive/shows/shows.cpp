#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back

using namespace std;

ifstream f("spectacole.in");
ofstream g("spectacole.out");

int n;

struct Show{
private:
  int start, end;
public:
  Show(int stH, int stMin, int fnH, int fnMin): start{stH*60 + stMin}, end{fnH*60 + fnMin} {};

  const int getStart() const {return this->start;}
  const int getEnd() const {return this->end;}

};

vector<Show> shows;

void readData(){
  cin >> n;
  for(int i = 0; i<n; i++){
    int startH, startM, endH, endM;
    f >> startH >> startM >> endH >> endM;
    cout << startH << startM << ' ' << endH << ' ' << endM << '\n';
    //f >> startH >> startM >> endH >> endM;
    //g << startH << " " << startM << ' ' << endH << ' ' << endM << '\n';
    //shows.pb({startH, startM, endH, endM});
  }
}

bool cmp(Show a, Show b){
  if(a.getEnd() < b.getEnd()){
    return true;
  }
  return a.getStart() < b.getStart();
}

void solve(){
  sort(shows.begin(), shows.end(), cmp);
  int lastTime = shows[0].getEnd();
  int numberOfShows = 0;
  for(unsigned i = 1; i<shows.size(); i++){
    if(shows[i].getStart() >= lastTime){
      g << shows[i].getStart() << ' ' << shows[i].getEnd() << '\n';
      numberOfShows ++;
      lastTime = shows[i].getEnd();
    }
  }
  g << numberOfShows + 1;
}

int main(){

  readData();
  //solve();
  return 0;
}
