#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#define NMAX 1000
#define pb push_back

std::ifstream in(R"(C:\Users\georg\Desktop\University\Semester5\PPD\HamiltonianCycleParallel\file.in)");

int G[NMAX][NMAX];
std::vector<int>sol;
int n, m;
int LEVEL = 3;

void read_graph(int& n, int& m){
    in >> n >> m;
    for(int i = 0; i<m; i++){
        int x, y;
        in >> x >> y;
        G[x][y] = 1;
    }
}


bool exists(int node, std::vector<int> sol){
    for(const auto& x : sol){
        if(x == node){
            return true;
        }
    }
    return false;
}

std::vector<int> remove_vec(int node, std::vector<int> sol){
    std::vector<int>::iterator pend;
    pend = std::remove(sol.begin(), sol.end(), node);

    std::vector<int> result;
    for (auto p = sol.begin(); p != pend; ++p)
        result.pb(*p);

    return result;
}


bool isSol(std::vector<int> sol, int n){
    return sol.size() == n && G[sol[sol.size() - 1]][0] == 1;
}

void bkt(std::vector<int> *sol, int k, int n){
    if(isSol(*sol, n)){
        for(const auto& x : *sol){
            std::cout << x << ' ';
        }
        std::cout << 0 << '\n';
    }else{
        for(int i = 0; i<n; i++){
            if(G[(*sol)[k]][i] == 1 && !exists(i, *sol)){
                (*sol).pb(i);
                bkt(sol, k + 1, n);
                *sol = remove_vec(i, *sol);
            }
        }
    }
}

void threadBkt(std::vector<int>* sol, int k, int n){
    for(int i = 0; i<n; i++){
        if(!isSol(*sol, n)) {
            if(G[(*sol)[k]][i] == 1 && !exists(i, *sol)) {
                (*sol).pb(i);
                std::thread *th;
                bool init = false;
                if (k < LEVEL) {
                    threadBkt(sol, k + 1, n);
                } else {
                    auto new_sol = sol;
                    th = new std::thread(bkt, new_sol, k + 1, n);
                    init = true;
                }
                if(init) {
                    th->join();
                    delete th;
                }

                *sol = remove_vec(i, *sol);
            }
        }
    }
}

int main() {
    read_graph(n, m);
    sol.pb(0);
    threadBkt(&sol, 0, n);
    return 0;
}