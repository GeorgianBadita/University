//
// Created by geo on 20.06.2020.
//

#ifndef EXECICES_SUBIECT2017_H
#define EXECICES_SUBIECT2017_H

#include<string>

class Fruit {
private:
    bool withSeeds;
public:
    explicit Fruit(bool withSeeds) : withSeeds(withSeeds) {}

    virtual std::string getDescription() = 0;

    bool isWithSeeds() const {
        return this->withSeeds;
    }

    virtual ~Fruit() = default;
};

class MelonLike : public Fruit {
private:
    double kg;
public:
    MelonLike(double kg, bool withSeeds) : Fruit(withSeeds), kg{kg} {}

    std::string getDescription() override {
        return std::to_string(kg) + " melon like " + (Fruit::isWithSeeds() ? "with" : "without") + " seeds";
    }

    ~MelonLike() override = default;

};

class Melon : public MelonLike {
public:
    Melon(double kg, bool withSeeds) : MelonLike(kg, withSeeds) {}

    std::string getDescription() override {
        return MelonLike::getDescription() + " melon";
    }

    ~Melon() override = default;
};


class Watermelon : public MelonLike {
public:
    Watermelon(double kg, bool withSeeds) : MelonLike(kg, withSeeds) {}

    std::string getDescription() override {
        return MelonLike::getDescription() + " watermelon";
    }

    ~Watermelon() override = default;


};


#endif //EXECICES_SUBIECT2017_H
