/*
 * Supr* Huffman encoding
 */
#include <fstream>
#include <string>
#include <queue>
#define MAX_CHAR 255
using std::string;
using std::vector;

/* FILE DECLARATION */
/* ---------------- */

std::ifstream f("input_file.txt");
std::ofstream g("input_file_huffman.txt");

/* ---------------- */

/* DATA DECLARATION */
/* ---------------- */

/*
 * Structure to represent a node in our Huffman tree
 */
struct Node{
    char data;  //character
    int freq;   //character frequence

    Node* left, *right; //left and right child

    Node(char data, int freq){
        this->left = this->right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

/*
 * Structure to compare elements in priority queue
 */
struct Comp{
    bool operator()(const Node*a, const Node*b){
        return a->freq > b-> freq;
    }
};

string my_str; //string to be read
int freq[MAX_CHAR];
std::priority_queue<Node*, vector<Node*>, Comp> p_queue; //priority queue


/* ---------------- */


/*
 * Function which reads a string from the file
 */
void read_data(string& my_str){
    string read;
    if(f.is_open()){
        while(!f.eof()){
            std::getline(f, read);
            my_str += read;
        }
    }
}

/*
 * Function which for a given string, returns its frequency vector
 * :param str: string
 * :param freq: the vector where we'll store the frequencies
 */
void make_freq(const string& str, int freq[]){
    for(int i = 0; i<256; i++){
        freq[i] = 0;
    }
    for(const auto& elem : str){
        freq[int(elem)] ++;
    }
}

/*
 * Function which prints the Huffman code for every character in the string
 */
void print_codes(Node* root,  string str){
    if(!root){
        return;
    }
    if(root->data != '$'){
        g << root -> data << ": " << str << '\n';
    }
    print_codes(root->left, str + "0");
    print_codes(root->right, str + "1");
}

/*
 * Function which constructs the Huffman encoding of a string
 * :param: string to be encoded
 */
void make_huffman(const string& str, std::priority_queue<Node*, vector<Node*>, Comp> pq){
    make_freq(str, freq);
    for(int i = 0; i<256; i++){
        if(freq[i] != 0){
            pq.push(new Node(char(i), freq[i]));
        }
    }

    while(pq.size() != 1){
        auto left = pq.top();
        pq.pop();

        auto right = pq.top();
        pq.pop();
        auto top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        pq.push(top);
    }

    print_codes(pq.top(), "");
}

/* MAIN FUNCTION */
int main(){
    read_data(my_str);
    make_huffman(my_str, p_queue);
    return 0;
}
