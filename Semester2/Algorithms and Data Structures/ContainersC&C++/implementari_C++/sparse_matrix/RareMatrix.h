//
// Created by geo on 4/29/18.
//

#ifndef RARE_MATRIX_RAREMATRIX_H
#define RARE_MATRIX_RAREMATRIX_H

typedef int TElem;

class Iterator; //defining our iterator class

/*
 * Our triplet class
 */
class   Triplet{
public:
    int line;
    int column;
    TElem elem;
    Triplet(int line, int column, const TElem& elem):line{line}, column{column}, elem{elem}{};

};

/*
 * Node class
 */
class Node{
public:
    Triplet value;
    Node* next;
    Node* prev;
    explicit Node(const Triplet& value):value{value}{
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class RareMatrix {
private:
    Node* first;
    Node* last;
public:
    /*
     * RareMatrix constructor
     */
    RareMatrix();

    /*
     * Rare matrix destructor
     */
   // ~RareMatrix();

    /*
     * Function to add a new triplet into the matrix
     * :param tr: the triplet to be added
     */
    void add_new_elem(Triplet tr);

    friend class Iterator;

    /*
     * Iterator function
     */
    Iterator iterator() const;
};


class Iterator{
private:
    explicit Iterator(const RareMatrix& mat);
    const RareMatrix& mat;
    Node* current;
public:
    friend class RareMatrix;

    /*
     *
     */
    void begin();

    /*
     *
     */
    void next();

    /*
     *
     */
    bool valid();

    /*
     *
     */
    Triplet get_elem();
};



#endif //RARE_MATRIX_RAREMATRIX_H
