//
// Created by geo on 5/5/18.
//

#ifndef LAB6_UNDO_H
#define LAB6_UNDO_H


#include <utility>

#include "movie.h"
#include "../repositroy/repository.h"

class UndoException{

};

class UndoAction {
public:
    virtual void do_undo() = 0;

    /*
     * Virtual destructor
     */
    virtual ~UndoAction() = default;
};

/*
 * UndoAdd class
 */
class UndoAdd : public UndoAction{
private:
    Movie added_movie;
    Repository& repo;
public:
    UndoAdd(Repository& repo, Movie mv): repo{repo}, added_movie{std::move(mv)}{}

    void do_undo() override{
        repo.delete_movie_repo(this->added_movie);
    };
};

/*
 * UndoModif class
 */
class UndoModif : public UndoAction{
private:
    Movie modif_movie;
    Repository& repo;
public:
    UndoModif(Repository& repo, Movie mv):repo{repo}, modif_movie{std::move(mv)}{};

    void do_undo() override{
        repo.update_movie_repo(modif_movie);
    }
};

/*
 * UndoDel class
 */
class UndoDel : public UndoAction{
private:
    Movie del_movie;
    Repository& repo;

public:
    UndoDel(Repository& repo, Movie mv):repo{repo}, del_movie{std::move(mv)}{};

    void do_undo() override{
        repo.store_movie_repo(this->del_movie);
    };
};

#endif //LAB6_UNDO_H
