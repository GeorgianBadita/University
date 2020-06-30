//
// Created by geo on 21.06.2020.
//

#ifndef EXECICES_SUBIECT2017SEPT_H
#define EXECICES_SUBIECT2017SEPT_H

#include<string>
#include<exception>

class Pizza {
private:
    std::string description;
    int basePrice;

public:
    Pizza(std::string desc, int basePrice) {
        if (desc.empty() || basePrice <= 0) {
            throw std::exception();
        }
        this->description = std::move(desc);
        this->basePrice = basePrice;
    }


    virtual std::string getDescription() {
        return this->description;
    }

    virtual int getPrice() {
        return this->basePrice;
    }

    virtual ~Pizza() = default;

};

class PizzaWithIngredients : public Pizza {
private:
    int ingredientsPrice;
public:
    PizzaWithIngredients(std::string desc, int basePice, int ingredientsPrice) : Pizza(std::move(desc), basePice),
                                                                                 ingredientsPrice(ingredientsPrice) {};

    std::string getDescription() override {
        return Pizza::getDescription() + " + ingredients";
    }

    int getPrice() override {
        return Pizza::getPrice() + this->ingredientsPrice;
    }

    ~PizzaWithIngredients() override = default;

};


#endif //EXECICES_SUBIECT2017SEPT_H
