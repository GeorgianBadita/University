//
// Created by geo on 16.06.2020.
//

#ifndef CARRENTAL_SERVICE_H
#define CARRENTAL_SERVICE_H


#include "../repository/CarRepository.h"
#include <string>
#include <algorithm>

class Service {
private:
    CarRepository &repo;
public:
    explicit Service(CarRepository &repo) : repo(repo) {};

    /**
     * Function to add a car into the repository
     * @param id
     * @param producer
     * @param model
     * @param type
     * @return
     */
    bool addCar(int id, std::string &producer, std::string &model, std::string &type);

    /**
     * Function to update a car
     * @param id
     * @param producer
     * @param model
     * @param type
     * @return
     */
    bool updateCar(int id, std::string &producer, std::string &model, std::string &type);

    /**
     * Function to delete a car by id
     * @param id
     * @return
     */
    bool deleteCar(int id);

    /**
     * Function to retrieve all cars from the repository
     * @return
     */
    std::vector<Car> retrieveCars();

    /**
     * Function to retrieve a car by id
     * @param id
     * @return
     */
    Car findCar(int id);

    /**
     * Function to filter cars by producer
     * @param producer
     * @param type
     * @return
     */
    std::vector<Car> filterByProducer(std::string &producer);

    /**
    * Function to filter cars by type
    * @param producer
    * @param type
    * @return
    */
    std::vector<Car> filterByType(std::string &type);

    /**
     * Function to sort by id
     * @param type - if type is true sort Desc else Asc
     * @return
     */
    std::vector<Car> sortByID();

    /**
     * Function to sort by car type
     * @param type
     * @return
     */
    std::vector<Car> sortByType();


};


#endif //CARRENTAL_SERVICE_H
