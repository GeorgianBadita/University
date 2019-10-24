#include <vector>
#define sz size
#define pb push_back

class lista{
     std::vector<int> v;
public:
     lista() {}
     int dim() {return this->v.sz();}
     void append(int num) {
         this->v.pb(num);
     }
     bool search(int elem) {
         for(unsigned i = 0; i<this->v.sz(); i++) {
             if(this->v[i] == elem) {
                 return true;
             }
         }
         return false;
     }

     void remove(int elem) {
         if(this->search(elem) == true) {
             int pos = 0;
             for(unsigned i = 0; i<this->v.sz(); i++) {
                 if(this->v[i] == elem) {
                     pos = i;
                     break;
                 }
             }
             this->v.erase(this->v.begin() + pos);
         }
     }

    void vid() {
        this->v = {};
    }
    int get(int pos) {return this->v[pos];}
};
