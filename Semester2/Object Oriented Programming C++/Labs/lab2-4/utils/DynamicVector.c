//
// Created by geo on 3/15/18.
//

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "DynamicVector.h"



/*
 * Function that creates a Dynamic Vector
 * :param: integer representing the initial maxim capacity
 * :post: it will return a pointer to a DynamicVector
 */
DynamicVector* createDynamicVector(int maxCap, int (*cmpCrit1)(TElem, TElem), int (*cmpCrit2)(TElem, TElem), int (*cmpEq)(TElem, TElem), void (*delete)(TElem)){
    DynamicVector* vect = (DynamicVector*)malloc(sizeof(DynamicVector));
    vect->maxCap = maxCap;
    vect->num = 0;
    vect->cmpCrit1 = cmpCrit1;
    vect->cmpCrit2 = cmpCrit2;
    vect->cmpEq = cmpEq;
    vect->delete = delete;
    vect->elems = (TElem*)malloc(maxCap*sizeof(TElem));
    return vect;
}

/*
 * Function that creates a Dynamic vector without functions
 * :param: integer representing the initial maxim capacity
 * :post: it will return a pointer to a DynamicVector
 */
DynamicVector* createSimpleDynamic(int maxCap){
    DynamicVector* vect = (DynamicVector*)malloc(sizeof(DynamicVector));
    vect->maxCap = maxCap;
    vect->num = 0;
    vect->cmpCrit1 = NULL;
    vect->cmpCrit2 = NULL;
    vect->cmpEq = NULL;
    vect->delete = NULL;
    vect->elems = (TElem*)malloc(maxCap*sizeof(TElem));
    return vect;
}

/*
 * Function that resize a vector if it it's full
 * :param DynamicVector: the dynamic  vector to resize
 * :post: the memory allocated for storing the elements will be double
 */
void resizeVector(DynamicVector* vect){
    int ndim = 2*vect->maxCap;
    TElem* newElems = (TElem*)malloc(ndim*sizeof(TElem));
    int i = 0;
    for(;i<vect->num; i++){
        newElems[i] = vect->elems[i];
    }
    free(vect->elems);
    vect->elems = newElems;
    vect->maxCap = ndim;
}

/*
 * Function that adds a new element to a Dynamic Vector
 * :param DynamicVector: the dynamic vector where we want to add an element
 * :param TElem: the element we want to add
 */
void addElement(DynamicVector* dv, TElem el){
    if (dv->num == dv->maxCap)
        resizeVector(dv);
    dv->elems[dv->num]=el;
    dv->num++;
}

/*
 * Function that searches for an element in the DynamicVector
 * :param DynamicVector: the dynamic vector where we want to search an element
 * :param TElem: the element to search for
 * :return: position of the element in vector if it exists, -1 otherwise
 */
int searchElement(DynamicVector* vect, TElem el){
    int i =0;
    for(i = 0; i<vect->num; i++){
        if(vect->cmpEq(vect->elems[i], el)){
            return i;
        }
    }
    return -1;
}

/*
 * Function that deletes a given element
 * :param DynamicVector: the vector where we want to delete an element
 * :param TEleme: the element we want to delete
 * :return: 1 if we could delete it, 0 otherwise
 */
int deleteElement(DynamicVector* vect, TElem el){
    int pos = searchElement(vect, el);
    if(pos < 0){
        return 0;
    }
    int i = pos;
    for(; i < vect->num - 1; i++){
        vect->elems[i] = vect->elems[i + 1];
    }
    vect->num --;
    return 1;
}

/*
 * Function that sorts a dynamic vector of TElems using quick_sort
 * :param DynamicVector: the dynamic vector we want to sort
 * :param left: index of first element
 * :param right: index of last element
 */
void qSort(DynamicVector* v, int left, int right){
    int i = left, j = right;
    TElem pivot = v->elems[(left+right)/2];

    while(i <= j){
        while(v->cmpCrit1(v->elems[i], pivot) == 0){
            i++;
        }
        while(v->cmpCrit1(v->elems[j], pivot) == 1){
            j --;
        }
        if(i <= j){
            TElem tmp = v->elems[i];
            v->elems[i] = v->elems[j];
            v->elems[j] = tmp;
            i++;
            j--;
        }
    }
    if(left < j){
        qSort(v, left, j);
    }
    if(i < right){
        qSort(v, i, right);
    }
}

/*
 * Function that copies a dynamic Vector
 * :param DynamicVector: the dynamic vector to be copied
 * :return: a copy of the DynamicVector
 */
DynamicVector copy(DynamicVector* v){
    DynamicVector newV;
    newV.num = v->num;
    newV.maxCap = v->maxCap;
    newV.delete = v->delete;
    newV.cmpCrit1 = v->cmpCrit1;
    newV.cmpCrit2 = v->cmpCrit2;
    newV.cmpEq = v->cmpEq;
    newV.elems = (TElem*)malloc(newV.num*sizeof(TElem));
    int i = 0;
    for(;i<newV.num; i++){
        newV.elems[i] = v->elems[i];
    }
    return newV;
}

/*****************************/

DynamicVector* copyUndo(DynamicVector* v){
    DynamicVector* newV = (DynamicVector*)malloc(sizeof(DynamicVector));
    newV->num = v->num;
    newV->maxCap = v->maxCap;
    newV->delete = v->delete;
    newV->cmpCrit1 = v->cmpCrit1;
    newV->cmpCrit2 = v->cmpCrit2;
    newV->cmpEq = v->cmpEq;
    newV->elems = (TElem*)malloc(newV->num*sizeof(TElem));
    int i = 0;
    for(;i<newV->num; i++){
        newV->elems[i] = v->elems[i];
    }
    return newV;
}

/******************************/
/*
 * Function that returns the last element in the vector destroying it in the same time
 * :param DynamicVector: the vector we want to pop its last element
 * :return: the last element in the vector
 */
TElem popVector(DynamicVector* vect){
    TElem el = vect->elems[vect->num - 1];
    vect->num --;
    return el;
}

/*
 * Function that sorts a dynamic vector
 * :param Dynamic Vector: the vector we want to sort
 * :param int: representing the way to sort (asc/desc) 1 for ascending, 0 for descending
 * :return: the dynamic Vector sorted
 */
DynamicVector* sortDynamic(DynamicVector* vect, int reverse){
    DynamicVector* sorted = copyDyn(vect);
    qSort(sorted, 0, sorted->num - 1);
    if(reverse == 1) {
        return sorted;
    }
    else if(reverse == 0){
        int i = 0;
        TElem tmp = NULL;
        for(i = 0; i<sorted->num/2; i++){
           tmp = sorted->elems[i];
            sorted->elems[i] = sorted->elems[sorted->num-i-1];
            sorted->elems[sorted->num-i-1] = tmp;
        }
        return sorted;
    }
}

/*
 * Function that modifies a TElement
 * :param TElem: The initial TElem
 * :param TElem: The new TElem
 * :post: The first TElem will be replaced with the second TElem
 * :return: the new TElem if we could modify it, else return 0
 */
int modifyElement(DynamicVector* vect, TElem el, TElem newEl){
    int pos = searchElement(vect, el);
    if(pos < 0){
        return -1;
    }
    else{
        vect->elems[pos] = newEl;
        return pos;
    }
}

/*
 * Function that dynamically copies a DynamicVector
 * :param DynamicVector: the dynamic vector ro copy
 * :return: the new created dynamic vector
 */
DynamicVector* copyDyn(DynamicVector* vect){
    DynamicVector* newVect = createDynamicVector(vect->maxCap, vect->cmpCrit1, vect->cmpCrit2, vect->cmpEq, vect->delete);
    newVect->num = 0;
    int i = 0;

    for(; i < vect->num; i++){
        addElement(newVect, vect->elems[i]);
    }
    return newVect;
}

/*
 * Function that frees the memory occupied by elements of a Dynamic Vector
 * :param DynamicVector:
 * :post: the memory occupied by the elements will be freed
 */
void destroyElems(DynamicVector* vect){
    free(vect->elems);
}

/*
 * Function that destroys a DynamicVector
 * :param DynamicVector: the dynamic vector we want to delete
 * :post: the memory allocated for the dynamic vector will be freed
 */
void destroyVector(DynamicVector* vect){
    destroyElems(vect);
    free(vect);
}




/*
 * Compare function used only for testing purposes
 * :param TElem: an element of type TElem
 * :param TElem: another element of type TElem
 * :return: compares the  TElems
 * :post: -
 * :pre: -
 */
int cmpTest(TElem A, TElem B){ return A == B; }

/*
 * Delete function used only for testing purposes
 * :param TElem: the element which should be destroyed
 * :return: -
 * :post: -
 * :pre: -
 */
void deleteTest(TElem el){

}

/*
 *
 */
void testCreateVector(){
    DynamicVector* myVect = createDynamicVector(100, cmpTest, cmpTest, cmpTest, deleteTest);
    assert(myVect->cmpCrit1 == cmpTest);
    assert(myVect->cmpCrit2 == cmpTest);
    assert(myVect->delete == deleteTest);
    assert(myVect->num == 0);
    assert(myVect->maxCap == 100);
    assert(myVect->elems != NULL);
    destroyVector(myVect);
}

/*
 *
 */
void testAddVector(){
    DynamicVector* myVect = createDynamicVector(1, cmpTest, cmpTest, cmpTest, deleteTest);
    TElem* el1 = (TElem *)malloc(sizeof(TElem));
    addElement(myVect, el1);
    assert(myVect->elems[myVect->num-1] == el1);
    addElement(myVect, el1);
    assert(myVect->maxCap == 2);
    free(el1);
    destroyVector(myVect);
}


/*
 *
 */
void testSearchElem(){
    DynamicVector* myVect = createDynamicVector(1, cmpTest, cmpTest, cmpTest, deleteTest);
    TElem* el1 = (TElem *)malloc(sizeof(TElem));
    TElem* el2 = (TElem *)malloc(sizeof(TElem));
    addElement(myVect, el1);
    int searchVal = searchElement(myVect, el1);
    assert(searchVal == 0);
    searchVal = searchElement(myVect, el2);
    assert(searchVal == -1);
    free(el1);
    free(el2);
    destroyVector(myVect);
}

/*
 *
 */
void testDeleteElem(){
    DynamicVector* myVect = createDynamicVector(1, cmpTest, cmpTest, cmpTest, deleteTest);
    TElem* el1 = (TElem *)malloc(sizeof(TElem));
    TElem* el2 = (TElem *)malloc(sizeof(TElem));
    addElement(myVect, el1);
    addElement(myVect, el1);
    int elDel = deleteElement(myVect, el1);
    assert(elDel == 1);
    assert(myVect->num == 1);
    elDel = deleteElement(myVect, el2);
    assert(elDel == 0);
    free(el1);
    free(el2);
    destroyVector(myVect);

}

/*
 *
 */
void testModifyElem(){
    DynamicVector* myVect = createDynamicVector(1, cmpTest, cmpTest, cmpTest, deleteTest);
    TElem* el1 = (TElem *)malloc(sizeof(TElem));
    TElem* el2 = (TElem *)malloc(sizeof(TElem));
    TElem* el3 = (TElem *)malloc(sizeof(TElem));
    addElement(myVect, el1);
    addElement(myVect, el2);
    modifyElement(myVect, el1, el2);
    assert(myVect->elems[0] == el2);
    assert(modifyElement(myVect, el3, el2) == -1);
    free(el1);
    free(el2);
    free(el3);
    destroyVector(myVect);
}

/*
 *
 */
void testCopy(){
    DynamicVector* myVect = createDynamicVector(1, cmpTest, cmpTest, cmpTest, deleteTest);
    TElem* el1 = (TElem *)malloc(sizeof(TElem));
    TElem* el2 = (TElem *)malloc(sizeof(TElem));
    TElem* el3 = (TElem *)malloc(sizeof(TElem));
    addElement(myVect, el1);
    addElement(myVect, el2);
    addElement(myVect, el3);
    DynamicVector newV = copy(myVect);
    assert(newV.elems[0] == myVect->elems[0]);
    assert(newV.elems[1] == myVect->elems[1]);
    assert(newV.elems[2] == myVect->elems[2]);
    destroyElems(&newV);
    free(el1);
    free(el2);
    free(el3);
    destroyVector(myVect);
}
