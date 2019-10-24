#ifndef OBSERVER_H
#define OBSERVER_H
#include <vector>
#include <algorithm>

class Observer{
public:
    virtual void update() = 0;
};

class Observable{
private:
    std::vector<Observer*> observers;
public:
    void add_observer(Observer* obs){
        this->observers.push_back(obs);
    }

    void notify(){
        for(auto& obs: this->observers){
            obs->update();
        }
    }
};

#endif // OBSERVER_H
