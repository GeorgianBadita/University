//
// Created by geo on 3/15/18.
//

#ifndef LAB2_GENERIC_DYN_DYNAMICVECTOR_H
#define LAB2_GENERIC_DYN_DYNAMICVECTOR_H

typedef void* TElem; //generict data type

typedef struct{
    int num;
    int maxCap;
    TElem* elems;
    int (*cmpCrit1)(TElem, TElem);
    int (*cmpCrit2)(TElem, TElem);
    int (*cmpEq)(TElem, TElem);
    void (*delete)(TElem);
}DynamicVector;

/*
 * Function that creates a Dynamic Vector
 * :param: integer representing the initial maxim capacity
 * :post: it will return a pointer to a DynamicVector
 */
DynamicVector* createDynamicVector(int, int (*cmpCrit1)(TElem, TElem), int (*cmpCrit2)(TElem, TElem), int (*cmpEq)(TElem, TElem), void (*delete)(TElem));

/*
 * Function that creates a Dynamic vector withou functions
 * :param: integer representing the initial maxim capacity
 * :post: it will return a pointer to a DynamicVector
 */
DynamicVector* createSimpleDynamic(int);

/*
 * Function that addsa a new element to a Dynamic Vector
 * :param DynamicVector: the dynamic vector where we want to add an element
 * :param TElem: the element we want to add
 */
void addElement(DynamicVector*, TElem);

/*
 * Function that searches for an element in the DynamicVector
 * :param DynamicVector: the dynamic vector where we want to search an element
 * :param TElem: the element to search for
 * :return: position of the element in vector if it exists, -1 otherwise
 */
int searchElement(DynamicVector*, TElem);

/*
 * Function that deletes a given element
 * :param DynamicVector: the vector where we want to delete an element
 * :param TEleme: the element we want to delete
 * :return: 1 if we could delete it, 0 otherwise
 */
int deleteElement(DynamicVector*, TElem);



/*
 * Function that sorts a dynamic vector
 * :param Dynamic Vector: the vector we want to sort
 * :param int: representing the way to sort (asc/desc) 1 for ascending, 0 for descending
 * :return: the dynamic Vector sorted
 */
DynamicVector* sortDynamic(DynamicVector*, int);

/*
 * Function that copies a dynamic Vector
 * :param DynamicVector: the dynamic vector to be copied
 * :return: a copy of the DynamicVector
 */
DynamicVector copy(DynamicVector* v);

/*
 * Function that modifies a TElement
 * :param TElem: The initial TElem
 * :param TElem: The new TElem
 * :post: The first TElem will be replaced with the second TElem
 * :return: the new TElem if we could modify it, else return 0
 */
int modifyElement(DynamicVector* vect, TElem el, TElem newEl);

/*
 * Function that frees the memory occupied by elements of a Dynamic Vector
 * :param DynamicVector:
 * :post: the memory occupied by the elements will be freed
 */
void destroyElems(DynamicVector*);

/*
 * Function that dynamically copies a DynamicVector
 * :param DynamicVector: the dynamic vector ro copy
 * :return: the new created dynamic vector
 */
DynamicVector* copyDyn(DynamicVector*);

//************************************************/
DynamicVector* copyUndo(DynamicVector* v);
//**********************************************/

/*
 * Function that destroys a DynamicVector
 * :param DynamicVector: the dynamic vector we want to delete
 * :post: the memory allocated for the dynamic vector will be freed
 */
void destroyVector(DynamicVector*);

/*
 * Function that returns the last element in the vector destroying it in the same time
 * :param DynamicVector: the vector we want to pop its last element
 * :return: the last element in the vector
 */
TElem popVector(DynamicVector*);

/*
 *
 */
void testCreateVector();

/*
 *
 */
void testAddVector();

/*
 *
 */
void testDeleteElem();

/*
 *
 */
void testModifyElem();

/*
 *
 */
void testSearchElem();

/*
 *
 */
void testCopy();

#endif //LAB2_GENERIC_DYN_DYNAMICVECTOR_H
