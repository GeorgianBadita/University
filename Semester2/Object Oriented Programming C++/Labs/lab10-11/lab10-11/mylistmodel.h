#ifndef MYLISTMODEL_H
#define MYLISTMODEL_H
#include <QAbstractListModel>
#include <vector>
#include <qdebug.h>
#include "movie.h"
#include "service.h"

class MyListModel: public QAbstractListModel{
    std::vector<Movie> movies;

public:

    MyListModel(const std::vector<Movie>& movies):movies{movies}{
    }

    int rowCount(const QModelIndex & parent = QModelIndex()) const override{
            return movies.size();
        }

    QVariant data(const QModelIndex &index, int role) const override{
        if(role == Qt::DisplayRole){
            auto mv = movies[index.row()].get_title();
            return QString::fromStdString(mv);
        }

        if(role == Qt::UserRole){
            auto genre = movies[index.row()].get_genre();
            return QString::fromStdString(genre);
        }
        return QVariant{};
    }

    void setMovies(const vector<Movie>& movies){
       this->movies = movies;
        QModelIndex topLeft = createIndex(0, 0);
        QModelIndex bottomRight = createIndex(rowCount(), 1);
        emit dataChanged(topLeft, bottomRight);
    }
};

#endif // MYLISTMODEL_H
