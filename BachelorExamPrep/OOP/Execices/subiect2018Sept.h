//
// Created by geo on 21.06.2020.
//

#ifndef EXECICES_SUBIECT2018SEPT_H
#define EXECICES_SUBIECT2018SEPT_H

#include<string>
#include<vector>

class Participant {
private:
    std::string name;
    std::string town;

public:
    Participant(std::string name, std::string town) : name(std::move(name)), town(std::move(town)) {};

    const std::string &getTown() const {
        return this->town;
    }

    virtual std::string toString() {
        return "Name: " + this->name + "; Town: " + this->town;
    }

    virtual ~Participant() = default;
};

class Volunteer : public Participant {
private:
    int years;
public:
    Volunteer(std::string name, std::string town, int years) : Participant(std::move(name), std::move(town)),
                                                               years(years) {};

    std::string toString() override {
        return "Volunteer " + std::to_string(this->years) + " years; " + Participant::toString();
    }

    ~Volunteer() override = default;
};

class Employee : public Participant {
private:
    std::string department;
public:
    Employee(std::string name, std::string town, std::string department) : Participant(std::move(name),
                                                                                       std::move(town)),
                                                                           department(std::move(department)) {};

    std::string toString() override {
        return "Employee " + this->department + "; " + Participant::toString();

    }

    ~Employee() override = default;
};

class ONG {
private:
    std::vector<Participant *> paricipants;
public:
    explicit ONG(std::vector<Participant *> &parts) : paricipants(parts) {}

    std::vector<Participant *> getAll(bool volunteer) const {
        std::vector<Participant *> filtered;
        std::string volunteerStr = "Volunteer";

        for (auto &elem: this->paricipants) {
            if (volunteer) {
                if (elem->toString().rfind(volunteerStr, 0) == 0) {
                    filtered.push_back(elem);
                }
            } else {
                if (elem->toString().rfind(volunteerStr, 0) != 0) {
                    filtered.push_back(elem);
                }
            }
        }

        return filtered;
    }


    ~ONG() {
//        for (auto &elem: paricipants) {
//            delete elem;
//        }
    }
};

#endif //EXECICES_SUBIECT2018SEPT_H
