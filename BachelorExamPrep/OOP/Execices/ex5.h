//
// Created by geo on 16.06.2020.
//

#ifndef EXECICES_EX5_H
#define EXECICES_EX5_H

#include <iostream>
#include <vector>

class Quackable {
public:
    virtual void quack() = 0;

    virtual ~Quackable() = default;
};

class RedheadDuck : public Quackable {
public:
    void quack() override {
        std::cout << "quack\n";
    }

    ~RedheadDuck() override = default;
};

class Flock : public Quackable {
private:
    std::vector<Quackable *> quacks;
public:
    void quack() override {
        for (const auto &q: quacks) {
            q->quack();
        }
    }

    void addQuackable(Quackable *q) {
        quacks.push_back(q);
    }

    ~Flock() override {
        for (auto &elem: quacks) {
            delete elem;
        }
    }

};

class QuackableCounter : public Quackable {
private:
    int quackCount;
    Quackable *q;
public:
    explicit QuackableCounter(Quackable *q) : quackCount(0), q(q) {};

    void quack() override {
        this->quackCount += 1;
        q->quack();
        std::cout << "Quack num: " << this->quackCount;
    }

    ~QuackableCounter() override {
        delete q;
    }
};

class Simualtor {
public:

    void simulate(Quackable *q) {
        q->quack();
    }

};

#endif //EXECICES_EX5_H
