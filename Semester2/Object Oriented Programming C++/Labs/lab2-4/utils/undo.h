//
// Created by geo on 3/24/18.
//

#ifndef LAB2_GENERIC_DYN_UNDO_H
#define LAB2_GENERIC_DYN_UNDO_H

#include <stdlib.h>
#include "DynamicVector.h"


typedef struct{
    DynamicVector* undoLst;
    DynamicVector* toDelete;
}Undo;

/*
 * Function that creates an undoList
 * :param: none
 * :post: a new Undo List will be created
 */
Undo* createUndo();

/*
 * Function that destroys all elements ion the toDelete component of Undo
 * :param Undo: the undo its toDelete we want to free
 * :post: the elements of toDelete will be freed
*/
void destroyToDelete(Undo* undo);


/*
 * Function that destroys all elements in undolist component of undo
 * :param Undo: the undo its undoL we want to free
 * :post: the elements of undoLst will be freed
 */
void destroyUndoL(Undo* undoL);


/*
 * Function that destroys an undo List
 * :param Undo: the undo list we want to destroy
 * :post: all memory held by the list will be freed
 */
void destroyUndoList(Undo*);


/*
 *
 */
void testCreateUndo();





#endif //LAB2_GENERIC_DYN_UNDO_H
