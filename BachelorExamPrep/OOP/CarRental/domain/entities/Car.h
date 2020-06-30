//
// Created by geo on 15.06.2020.
//

#ifndef CARRENTAL_CAR_H
#define CARRENTAL_CAR_H

#include<string>
#include "BaseEntity.h"

class Car : public BaseEntity<int> {
private:
    std::string producer;
    std::string model;
    std::string type;

public:
    /**
     * Car constructor
     * @param number  - car number: string
     * @param producer - car producer: string
     * @param model - car model: string
     * @param type - car type: string
     * @return: Car type object
     */
    Car(int number, std::string &producer, std::string &model, std::string &type);


    /**
     * Car producer getter
     * @return Car's producer: string
     */
    std::string getProducer() const {
        return this->producer;
    };

    /**
     * Car producer setter
     * @param newProducer : string
     */
    void setProducer(const std::string &newProducer) {
        this->producer = newProducer;
    }

    /**
     * Car model getter
     * @return Car's model: string
     */
    std::string getModel() const {
        return this->model;
    }

    /**
     * Car model setter
     * @param newModel: string
     */
    void setModel(const std::string &newModel) {
        this->model = newModel;
    }

    /**
     * Car type getter
     * @return Car's type: string
     */
    std::string getType() const {
        return this->type;
    }

    /**
     * Car type setter
     * @param newType: string
     */
    void setType(const std::string &newType) {
        this->type = newType;
    }
};


#endif //CARRENTAL_CAR_H
