/*
 * Supr* Prufer encoding and deconding algorithm
 */

#include <fstream>
#include <vector>
#include<algorithm>
#define pb push_back
#define NMAX 1000
using namespace std;

/* FILE DECLARATION */
/* ---------------- */

ifstream f("input.txt");
ofstream g("output.txt");

/* ---------------- */

/* DATA DECLARATION */
/* ---------------- */

struct Pair{
    int x, y;

};

vector<int> G[NMAX]; //our Tree
int n; //number of nodes

/* ---------------- */


/*
 * Function which reads the data from the file (a tree)
 */
void read_data(int& n, vector<int>G[]){
    f >> n;
    for(int i = 1; i<n; i++){
        int x, y;
        f >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }
}

/*
 * Function which for a given node gets its father
 * :param G: our graph
 * :param node: the node whose father we search
 * :return: the father of the node if it exits, -1 otherwise
 */
int get_father(vector<int>G[], int node){
    for(int i = 1; i<=n; i++){
        for(int j = 0; j < G[i].size(); j++){
            if(G[i][j] == node){
                return i;
            }
        }
    }
    return -1;
}


/*
 * Function which for a given graph and a node deletes the node
 * :param G: the graph
 * :param node: the node to be deleted
 */
void erase_from_nodes(vector<int> G[], int node){
    for(auto i = 1; i<=n; i++){
        if(find(G[i].begin(), G[i].end(), node) != G[i].end()){
            G[i].erase(find(G[i].begin(), G[i].end(), node));
        }
    }
}





/*
 * Function which gets the minimum leaf of the graph and delets it
 * :param G: our graph (tree)
 */
int get_min_leaf_parent(vector<int>G[]){

    int min_leaf = n + 1;
    for(int i = 1; i <= n; i++){
        if(G[i].size() == 1 && min_leaf > i){
            min_leaf = get_father(G, i);
            G[i].erase(G[i].begin());
            erase_from_nodes(G, i);
            break;
        }
    }
    return min_leaf;
}

/*
 * Function which for a given tree calculates its Prufer encoding
 * :param G: the given tree
 * :return: the prufer encoding as a vector
 */
vector<int> prufer_encoding(vector<int>G[]){
    vector<int> result;
    while(result.size() != n - 1){ //I do the encoding till n - 1, to construct the tree right
        auto leaf_parent = get_min_leaf_parent(G);
        result.pb(leaf_parent);
    }


    return result;
}

/*
 * Function which prints the prufer encoding
 */
void print_prufer(vector<int>& res){
    g << "The prufer encoding is: ";
    for(int i = 0; i<res.size() - 1; i++){
        g << res[i] << ' ';
    }
    g << '\n';
}

/*
 * Function which for a given vector, returns the smallest natural number not in v
 * :param v: vector
 * :return: the smallest natural number which is not in v, else -1
 */
int get_smallest_int(vector<int> v){
    bool freq[NMAX];
    for(int i = 1; i<=n; i++){
        freq[i] = false;
    }
    for(int i = 0; i<v.size(); i++){
        freq[v[i]] = true;
    }
    for(int i = 1; i<=n; i++){
        if(!freq[i]){
            return i;
        }
    }
    return -1;
}

/*
 * Function which for a given prufer encoding, makes its tree
 * :param encoding: a pruffer encoding
 */
vector<Pair> prufer_decoding(vector<int> encoding){
    vector<Pair> result;
    for(int i = 1; i<n; i++){
        auto first = encoding.begin();
        auto x = *first;
        auto y = get_smallest_int(encoding);
        Pair edge;
        edge.x = x;
        edge.y = y;
        result.push_back(edge);
        encoding.erase(first);
        encoding.push_back(y);
    }
    return result;
}

/*
 * Function which prints the decoded tree from a Prufer sequence
 * :param result: vector of pairs
 */
void print_tree(vector<Pair> result){
    g << "The tree edges are:\n";
    for(int i = 0; i<result.size(); i++){
        auto pair = result[i];
        g << pair.x << " -> " << pair.y << '\n';
    }
}

int main(){
    read_data(n, G);
    auto res = prufer_encoding(G);
    print_prufer(res);
    auto dec = prufer_decoding(res);
    print_tree(dec);
    return 0;
}
