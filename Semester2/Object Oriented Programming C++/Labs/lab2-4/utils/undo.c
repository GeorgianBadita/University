//
// Created by geo on 3/24/18.
//

#include <assert.h>
#include "undo.h"
#include "DynamicVector.h"
#include "../service/Service.h"
#include "../repository/Repository.h"

/*
 * Function that creates an undoList
 * :param: none
 * :post: a new Undo List will be created
 */
Undo* createUndo(){
    Undo* undoL = (Undo*)malloc(sizeof(Undo));
    DynamicVector* vector = createSimpleDynamic(10);
    DynamicVector* history = createSimpleDynamic(10);
    undoL->undoLst = vector;
    undoL->toDelete = history;
    return undoL;
}

/*
 * Function that destroys an undo List
 * :param Undo: the undo list we want to destroy
 * :post: all memory held by the list will be freed
 */
void destroyUndoList(Undo* undo){
    destroyVector(undo->undoLst);
    destroyVector(undo->toDelete);
    free(undo);
}


/*
 * Function that destroys all elements in undolist component of undo
 * :param Undo: the undo its undoL we want to free
 * :post: the elements of undoLst will be freed
 */
void destroyUndoL(Undo* undoL){
    int i = 0;
    for(; i < undoL->undoLst->num; i++){
        destroyVector(undoL->undoLst->elems[i]);
    }
}


/*
 * Function that destroys all elements ion the toDelete component of Undo
 * :param Undo: the undo its toDelete we want to free
 * :post: the elements of toDelete will be freed
*/
void destroyToDelete(Undo* undo){
    int i = 0;
    for(; i< undo->toDelete->num; i++){
        if(undo->toDelete->elems[i] != NULL) {
            destroyTransaction(undo->toDelete->elems[i]);
            undo->toDelete->elems[i] = NULL;
        }
    }
}

/*
 *
 */
void testCreateUndo(){
    Undo* lst = createUndo();
    assert(lst->undoLst->num == 0);
    assert(lst->undoLst->maxCap == 10);
    destroyUndoList(lst);
}

