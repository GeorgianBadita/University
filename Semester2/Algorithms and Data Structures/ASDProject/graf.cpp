#include "graf.h"
#include <climits>
#include <stack>
#define INF INT_MAX
#define MIN_INTERS 10




/*
 * Constructor pentru clasa Graf
 */
//creeaza
Graf::Graf(int inter): num_intersectii{inter}{
    for(int i = 1; i < MAX_INTERS; i++){
        for(int j = 1; j < MAX_INTERS; j++){
            this->flux[i][j] = 0;
        }
    }
}

/*
 * Functie care aplica bfs asupra grafului nostru
 * :param s: sursa de aplicare a bfs
 * :param t: destinatia
 * :param viz[]: array pentru nodurile vizitate
 * :param parent[]: array pentru returnarea arborelui creat de bfs
 * :return: true, daca s-a gasit un drum de la s la t, false altfel
 */
bool Graf::bfs(int s, int t){
    memset(this->viz, false, sizeof(this->viz));
    memset(this->parent, 0, sizeof(this->parent));
    this->viz[s] = true;
    this->parent[s] = -1;
    //std::queue<int> q;
    int q[MAX_INTERS];
    int prim, ultim;
    prim = ultim = 0;
    q[ultim] = s;
    while(prim <= ultim){
        int node = q[prim];
        prim ++;
        if(node == t){
            continue;
        }
        for(const auto& adj : this->graph[node]){
            if(!this->viz[adj] && this->flux[node][adj] > 0){
                ultim ++;
                q[ultim] = adj;
                this->viz[adj] = true;
                this->parent[adj] = node;
            }
        }
    }
    return this->viz[t];
}

/*
 * Functie care adauga o muchie in graf
 * :param int: nodul sursa
 * :param int: nodul destinatie
 * :param int: capacitatea muchiei
 */
void Graf::adauga_muchie(int x, int y, int capacitate){
    this->graph.adauga(x, y);
    this->graph.adauga(y, x);
    //this->test[x].push_back(y);
    //this->test[y].push_back(x);
    this->flux[x][y] += capacitate;
}

/*
 * Functie pentru stergerea unei muchii din graf
 * :param int: nodul sursa
 * :param int: nodul destinatie
 */
void Graf::sterge_muchie(int x, int y){
    this->graph.sterge(x, y);
}

/*
 * Functie care returneaza lista de vecini a unui nod x
 * :param nt x: nodul ai carui vecin dorim sa ii aflam
 * :return: un vector continant toti vecinii nodului x
 */
TVector<int> Graf::vecini(int x){
    return this->graph[x];
}

/*
 * Functie care returneaza cantitatea maxima de flux de la o sursa la o destinatie dintr-un graf
 * :param int: sursa de intrare a fluxului
 * :param out: destinatia fluxului
 */
int Graf::flux_maxim(int sursa, int destinatie){

    int fl[MIN_INTERS][MIN_INTERS];

    for(int i = 1; i<MIN_INTERS; i++){
        for(int j = 1; j<MIN_INTERS; j++){
            fl[i][j] = this->flux[i][j];
        }
    }
    int max_flow = 0, min_cap;
    while(bfs(sursa, destinatie)){
        for(const auto& curr_node : this->graph[destinatie]){
            if(!this->viz[curr_node] || this->flux[curr_node][destinatie] <= 0){
                continue;
            }
            min_cap = INF;
            this->parent[destinatie] = curr_node;
            for(int i = destinatie; i != sursa; i = this->parent[i]){
                min_cap = std::min(min_cap, this->flux[this->parent[i]][i]);
            }

            for(int i = destinatie; i != sursa; i = this->parent[i]){
                this->flux[this->parent[i]][i] -= min_cap;
                this->flux[i][this->parent[i]] += min_cap;
            }
            max_flow += min_cap;
        }
    }

    for(int i = 1; i <MIN_INTERS; i++){
        for(int j = 1; j < MIN_INTERS; j++){
            this->flux[i][j] = fl[i][j];
        }
    }
    return max_flow;
}

/*
 * Functie care verifica daca graful are un ciclu sau un lant eulerian
 * :post: daca graful nu este eulerian, dar are un lant eulerian atunci
 * functia returneaza nodul de pornire al lantului, iar daca nu are nici un lant eulerian
 * va returna -1
 */
int Graf::verifica_euler(){
    int nr_impar = 0;
    int start_nod = 1;
    for(int i = 1; i<=this->num_intersectii; i++){
        //int e_par = this->graph[i].size();
        if(this->graph[i].size() % 2 != 0){
            nr_impar ++;
            start_nod = i;
        }
    }
    if(nr_impar > 2){
        return -1;
    }
    else{
        return start_nod;
    }
}


/*
 * Functie care returneaza lantul sau ciclul eulerian al unui graf daca exista
 * :return: un vector reprezentand ciclul/lantul eulerian, daca exista, vectorul nul altfel
 */
TVector<int>Graf::ciclue_euler(){
    auto gr2 = this->graph;
    TVector<int> res;
    int start_nod = this->verifica_euler();
    if(start_nod == -1){
        return {};
    }
    int st[MAX_INTERS];
    st[0]++;
    st[st[0]] = start_nod;
    //std::stack<int> st;
    //st.push(start_nod);
    while(st[st[0]] > 0){
        int nod = st[st[0]];
        if(!gr2[nod].empty()){
            int nod_nou = *gr2[nod].begin();
            gr2.sterge(nod, nod_nou);
            gr2.sterge(nod_nou, nod);
            //st.push(nod_nou);
            st[++st[0]] = nod_nou;
        }
        else{
            st[0] --;
            res.push_back(nod);
        }
    }
    return res;
}


/*
 * Functie care returneaza capacitatea unui drum nou adaugat astfel incat fluxul sa poata ajunge de la sursa la destinatie
 * :param sursa: nodul sursa
 * :param destinatie: nodul destinatie
 * :param flux: fluxul ce se vrea a fi acomodat
 * :return: numar intreg reprezentand capacitatea minima de adaugat
 */
int Graf::capacitate_drum(int sursa, int destinatie, int flux){
    int num = this->flux_maxim(sursa, destinatie);
   // std::cout << num << ' ' << flux << '\n';
    int diff = num - flux;
   // num = this->flux_maxim(sursa, destinatie);
   // std::cout << num << '\n';
    return diff < 0 ? diff : 0;
}

/*
 *  Functie care returneaza muhciile ce trebuie adaugate intr-un graf astfel incat acesta sa devina eulerian
 * :param: -
 * :return: returneaza un vector de muchii, reprezentand muchiile ce trebuie adaugate in graf ca acesta sa devina eulerian
 */
TVector<Muchie> Graf::muchii_euler(){
    TVector<int> impare;
    TVector<Muchie> res;
    for(int i = 1; i<=this->num_intersectii; i++){
        if(this->graph[i].size() % 2 != 0){
            impare.push_back(i);
        }
    }
    for(int i = 0; i<impare.size()/2; i++){
        Muchie mc{impare[i], impare[impare.size() - i - 1]};
        res.push_back(mc);
    }

    return res;
}


/*
 * Functie care seteaza numarul de intersectii
 * :param num_intersectii: intreg, noul numar de intersectii
 * :post: numarul de intersectii va fi modificat
 */
void Graf::set_num_inter(int num_intersectii){
    this->num_intersectii = num_intersectii;
}
