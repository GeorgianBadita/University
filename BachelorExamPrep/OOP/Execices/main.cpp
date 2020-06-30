#include <iostream>
#include <list>
#include "ex2.h"
#include "ex3.h"
#include "ex4.h"
#include "ex5.h"
#include "ex6.h"
#include "selectionSort.h"
#include "mergesort.h"
#include "quickSort.h"
#include "insertionSort.h"
#include "subiect2013.h"
#include "subiect2014.h"
#include "subiect2018.h"
#include "subiect2017.h"
#include "subiect2017Sept.h"
#include "subiect2018Sept.h"
#include "subiect2018Iulie.h"
#include "subiect2016Sept.h"
#include<map>

//std::list<B *> createList() {
//    return {new B(8), new D(5, "D5"),
//            new B(-3), new D(9, "D9")};
//}
//
//std::list<B *> filterList(const std::list<B *> &lst) {
//    std::list<B *> res;
//    std::copy_if(lst.begin(), lst.end(), std::back_inserter(res), [](B *elem) {
//        return elem->getB() > 6;
//    });
//    return res;
//}
//
//
//void printList(const std::list<B *> &lst) {
//    for (const auto &elem : lst) {
//        elem->afisare();
//    }
//}
//
//void destroyList(std::list<B *> &lst) {
//    auto it = lst.begin();
//    while (it != lst.end()) {
//        auto curr = *it;
//        it++;
//        delete curr;
//    }
//}

//std::map<int, B *> createMap() {
//    return {
//            {8,  new B(8)},
//            {5,  new D(5, "D5")},
//            {-3, new B(-3)},
//            {9,  new D(9, "D9")}
//    };
//}
//
//bool existsGreater6(std::map<int, B *> objects) {
//    auto it = objects.begin();
//    while (it != objects.end()) {
//        auto currElem = *it;
//        if (currElem.first > 6) {
//            return true;
//        }
//        it++;
//    }
//    return false;
//}
//
//void destroyMap(std::map<int, B *> objects) {
//    auto it = objects.begin();
//    while (it != objects.end()) {
//        auto currElem = *it;
//        delete currElem.second;
//        it++;
//    }
//}
//


//std::list<Produs *> creareLista() {
//    return {
//            new Produs("Bec"),
//            new ProdusPerisabil("Branza", 60),
//            new Produs("Cana")
//    };
//}
//
//bool existaProdus(std::list<Produs *> &produse) {
//    std::string produs;
//    std::cout << "Dati produsul de cautat: ";
//    std::cin >> produs;
//    auto it = produse.begin();
//    while (it != produse.end() && (*it)->getDenumire() < produs) {
//        it++;
//    }
//    return !(it == produse.end() || (*it)->getDenumire() != produs);
//}
//
//void distrugeLista(std::list<Produs *> &produse) {
//    for (auto &elem: produse) {
//        delete elem;
//    }
//}

//std::map<std::string, Student *> creazaDictionar() {
//    return {
//            {"Ionescu", new Student("Ionescu")},
//            {"Popescu", new StudentBursier("Popescu", 200)}
//    };
//}
//
//bool existaInc(std::map<std::string, Student *> &dict, char c) {
//    auto it = dict.begin();
//    while (it != dict.end()) {
//        if (it->first[0] == c) {
//            return true;
//        }
//        it++;
//    }
//
//    return false;
//}
//
//
//void distrugeDictionar(std::map<std::string, Student *> &dict) {
//    auto it = dict.begin();
//    while (it != dict.end()) {
//        delete it->second;
//        it++;
//    }
//}

//Locomotive removeNotProfitable(Locomotive& l) {
//    if (l.getFirstRailCar() == nullptr) {
//        return l;
//    }
//
//    auto head = l.getFirstRailCar();
//    while (head != nullptr && !head->isProfitable()) {
//        head = head->getNext();
//    }
//    l.setFirstRailCar(head);
//    if (head == nullptr) {
//        return l;
//    }
//    auto tmpNext = head->getNext();
//    auto tmp = head;
//    auto final = tmp;
//    while (tmpNext != nullptr) {
//        if (tmpNext->isProfitable()) {
//            tmp = tmpNext;
//            tmpNext = tmpNext->getNext();
//        } else {
//            tmp->setNext(tmpNext->getNext());
//            if (tmp->getNext() != nullptr) {
//                tmpNext->setNext(tmp->getNext());
//            } else {
//                tmpNext = nullptr;
//            }
//        }
//    }
//
//    l.setFirstRailCar(final);
//    return l;
//}
//
//Locomotive revertLoco(const Locomotive &l) {
//    auto head = l.getFirstRailCar();
//    if (head == nullptr || head->getNext() == nullptr) {
//        return Locomotive(head);
//    }
//
//    auto headCpy = head->clone();
//    auto tmpHead = headCpy;
//    while (head != nullptr) {
//        auto tmp = head->getNext();
//        tmpHead->setNext(tmp);
//        head = head->getNext();
//        tmpHead = tmpHead->getNext();
//    }
//
//    head = headCpy;
//    auto nexthead = head->getNext();
//    head->setNext(nullptr);
//    while (nexthead != nullptr) {
//        auto tmp = nexthead->getNext();
//        nexthead->setNext(head);
//        //head->setNext(nullptr);
//        head = nexthead;
//        nexthead = tmp;
//    }
//    return Locomotive(head);
//}
//
//void printLocomotive(Locomotive &l) {
//    auto head = l.getFirstRailCar();
//    while (head != nullptr) {
//        std::cout << head->toString() << ' ';
//        head = head->getNext();
//    }
//}

//int posInsertSorted(std::vector<Fruit *> &fruits, Fruit *toAdd) {
//    auto desc = toAdd->getDescription();
//    if (fruits.empty() || desc < fruits[0]->getDescription()) {
//        return 0;
//    }
//    if (desc > fruits[fruits.size() - 1]->getDescription()) {
//        return fruits.size();
//    }
//    int l = 0, r = fruits.size();
//
//    while (r - l > 1) {
//        int m = l - (l - r) / 2;
//        if (fruits[m]->getDescription() < desc) {
//            l = m;
//        } else {
//            r = m;
//        }
//    }
//    return r;
//}
//
//void insertSorted(std::vector<Fruit *> &fruits, Fruit *toAdd) {
//    int posToInsert = posInsertSorted(fruits, toAdd);
//    fruits.push_back(toAdd);
//    for (unsigned i = fruits.size() - 1; i > posToInsert; i--) {
//        fruits[i] = fruits[i - 1];
//    }
//    fruits[posToInsert] = toAdd;
//}
//
//void printWithSeeds(std::vector<Fruit *> &fruits, bool withSeeds) {
//    for (const auto &fruit : fruits) {
//        if (fruit->isWithSeeds() == withSeeds) {
//            std::cout << fruit->getDescription() << '\n';
//        }
//    }
//}
//
//std::vector<Fruit *> createList() {
//    return {
//            new Watermelon(6.0, false),
//            new Melon(10.0, true),
//            new MelonLike(11.0, false),
//            new Watermelon(13.0, true)
//    };
//}
//
//void destroyList(std::vector<Fruit *> &lst) {
//    for (auto &elem : lst) {
//        delete elem;
//    }
//}

//std::vector<Pizza *> merge(std::vector<Pizza *> a, std::vector<Pizza *> b) {
//
//    std::vector<Pizza *> final;
//
//    int i = 0;
//    int j = 0;
//
//    while (i < a.size() && j < b.size()) {
//        if (a[i]->getPrice() > b[j]->getPrice()) {
//            final.push_back(a[i]);
//            i++;
//        } else {
//            final.push_back(b[j]);
//            j++;
//        }
//    }
//
//    while (i < a.size()) {
//        final.push_back(a[i]);
//        i++;
//    }
//
//    while (j < b.size()) {
//        final.push_back(b[j]);
//        j++;
//    }
//
//
//    return final;
//}
//
//void insertionSort(std::vector<Pizza *> &pizzas) {
//    for (int i = 1; i < pizzas.size(); i++) {
//        int j = i - 1;
//        int p = i;
//        while (j >= 0 && pizzas[j]->getPrice() < pizzas[p]->getPrice()) {
//            auto tmp = pizzas[j];
//            pizzas[j] = pizzas[p];
//            pizzas[p] = tmp;
//            j--;
//            p--;
//        }
//    }
//}
//
//std::vector<Pizza *> createList1() {
//    return {
//            new Pizza("A", 9),
//            new Pizza("B", 12),
//            new PizzaWithIngredients("C", 10, 1)
//    };
//}
//
//std::vector<Pizza *> createList2() {
//    return {
//            new Pizza("D", 20),
//            new PizzaWithIngredients("E", 12, 2),
//            new PizzaWithIngredients("F", 10, 1)
//    };
//}
//
//void printList(std::vector<Pizza *> &pizzas) {
//    int sum = 0;
//    for (const auto &pizza : pizzas) {
//        std::cout << pizza->getDescription() << '\n';
//        sum += pizza->getPrice();
//    }
//
//    std::cout << "Total sum: " << sum << '\n';
//}
//
//void destroyList(std::vector<Pizza *> &pizzas) {
//    for (auto &pizza : pizzas) {
//        delete pizza;
//    }
//}

//void merge(int left, int mid, int right, std::vector<Participant *> &arr) {
//    std::vector<Participant *> leftSide;
//    std::vector<Participant *> rightSide;
//    for (int i = left; i <= mid; i++) {
//        leftSide.push_back(arr[i]);
//    }
//    for (int i = mid + 1; i <= right; i++) {
//        rightSide.push_back(arr[i]);
//    }
//    int i = 0, j = 0, start = left;
//
//    while (i < leftSide.size() && j < rightSide.size()) {
//        if (leftSide[i]->getTown() < rightSide[j]->getTown()) {
//            arr[start++] = leftSide[i++];
//        } else {
//            arr[start++] = rightSide[j++];
//        }
//    }
//
//    while (i < leftSide.size()) {
//        arr[start++] = leftSide[i++];
//    }
//
//    while (j < rightSide.size()) {
//        arr[start++] = rightSide[j++];
//    }
//}
//
//void mergeSortVolunteers(int left, int right, std::vector<Participant *> &volunteers) {
//    if (left < right) {
//        int mid = (left + right) / 2;
//        mergeSortVolunteers(left, mid, volunteers);
//        mergeSortVolunteers(mid + 1, right, volunteers);
//        merge(left, mid, right, volunteers);
//    }
//}
//
//std::vector<Participant *> mergeSortPart(ONG &ong) {
//    std::vector<Participant *> volunteers = ong.getAll(true);
//    mergeSortVolunteers(0, volunteers.size()-1, volunteers);
//    return volunteers;
//}
//
//std::string maxCity(std::vector<ONG> &ongs) {
//    std::map<std::string, int> employeesDist;
//    for (const auto &ong : ongs) {
//        auto empls = ong.getAll(false);
//        for (const auto empl: empls) {
//            const auto &town = empl->getTown();
//            if (employeesDist.find(town) != employeesDist.end()) {
//                employeesDist[town] += 1;
//            } else {
//                employeesDist[town] = 1;
//            }
//        }
//    }
//    std::string maxTown;
//    int max = -1;
//    auto it = employeesDist.begin();
//    while (it != employeesDist.end()) {
//        if (it->second > max) {
//            max = it->second;
//            maxTown = it->first;
//        }
//        it++;
//    }
//
//    return maxTown;
//}
//
//int numEmployees(std::vector<ONG> &ongs) {
//    int numEmpls = 0;
//    for (const auto &ong : ongs) {
//        auto empls = ong.getAll(false);
//        numEmpls += empls.size();
//    }
//
//    return numEmpls;
//}
//
//void printList(std::vector<Participant *> &parts) {
//    for (const auto &part: parts) {
//        std::cout << part->toString() << '\n';
//    }
//}

std::list<Entitate *> createList() {
    return {
            new Student("Valcea", 700),
            new Student("Bacau", 1000),
            new Profesor("Vrancea", 1290),
            new Profesor("Cluj", 3000)
    };
}



void destroyList(std::list<Entitate *> &lst) {
    for (auto &elem: lst) {
        delete elem;
    }

}

int main() {
//    C c[2];
//    c[1] = D();
//    c[1].print();
//    E *e[] = {new E(), new F()};
//    e[0]->print();
//    e[1]->print();
//    delete e[0];
//    delete e[1];
    //outout. E()E()F()EF~E()~F()~E()
//


//    Simualtor sim = Simualtor();
//    Quackable *redheadDuck = new RedheadDuck();
//    sim.simulate(redheadDuck);
//    auto *flock = new Flock();
//    flock->addQuackable(redheadDuck);
//    flock->addQuackable(redheadDuck);
//    sim.simulate(flock);
//    Quackable *counter = new QuackableCounter(QuackableCounter(redheadDuck));
//    sim.simulate(counter);

//    H h{};
//    I i{};
//    H &ii = i;
//    h.g();
//    ii.h();
    //output: H()H()I()H.fH.f~H()~I()~H()~H()
//    delete redheadDuck;
//    delete flock;
//    std::vector<int> vec = {3, 4, 1, 2, 3, 9};
//    auto mergesort = MergeSort(vec);
//    auto result = mergesort.sort();
//    for (const auto &elem :result) {
//        std::cout << elem << ' ';
//    }

//    int *arr = new int[10];
//    arr[0] = 10;
//    arr[1] = 5;
//    arr[2] = 4;
//    arr[3] = 2;
//    //insertionSort(arr, 4);
//    //mergeSort(0, 3, arr);
//    //quickSort(0, 3, arr);
//    //insertionSort(arr, 4);
//    for (int i = 0; i < 4; i++) {
//        std::cout << arr[i] << ' ';
//    }
//    delete[] arr;
//    auto lst = creareLista();
//    std::cout << existaProdus(lst);
//    distrugeLista(lst);
//    std::string read;
//    std::cout << "Dati un text: ";
//    std::cin >> read;
//    auto dict = creazaDictionar();
//    auto it = dict.begin();
//    bool exists = false;
//    while (it != dict.end() && !exists) {
//        if (it->first == read) {
//            exists = true;
//        }
//        it++;
//    }
//    exists ? std::cout << "Exitsa\n" : std::cout << "Nu exista\n";
//    existaInc(dict, read[0]) ? std::cout << "Exista\n" : std::cout << "Nu exista\n";
//    RailCar *pas1 = new PassangerCar("CA", 50);
//    RailCar *pas2 = new PassangerCar("AA", 32);
//    RailCar *pas3 = new PassangerCar("ZA", 40);
//
//    RailCar *rest1 = new RestaurantCar("RA", 20);
//    RailCar *rest2 = new RestaurantCar("PA", 25);
//    Locomotive l = Locomotive(pas1);
//    l.attachRailCar(pas2);
//    l.attachRailCar(pas3);
//    l.attachRailCar(rest1);
//    l.attachRailCar(rest2);
//    printLocomotive(l);
//    Locomotive l1 = removeNotProfitable(l);
//    std::cout << "\n";
//    printLocomotive(l1);
//    Locomotive l2 = revertLoco(l1);
//    std::cout << '\n';
//    printLocomotive(l2);

//    auto melons = createList();
//    std::vector<Fruit*> frts;
//
////
//
//    for (const auto &melon : melons) {
//        insertSorted(frts, melon);
//    }
//    Fruit *watermelon = new Watermelon(12.0, false);
//    insertSorted(frts, watermelon);
//    for (const auto &melon : frts) {
//        std::cout << melon->getDescription() << '\n';
//    }
//    destroyList(frts);
//    auto pizzas1 = createList1();
//    auto pizzas2 = createList2();
//    printList(pizzas1);
//    printList(pizzas2);
//    insertionSort(pizzas1);
//    insertionSort(pizzas2);
//    std::cout << "\n\n";
//    printList(pizzas1);
//    printList(pizzas2);
//    std::cout << "\n\n";
//    auto merged = merge(pizzas1, pizzas2);
//    printList(merged);
//    std::vector<Participant *> parts1 = {new Volunteer("A", "C", 2), new Volunteer("A", "A", 1),
//                                         new Employee("A", "B", "1")};
//    std::vector<Participant *> parts2 = {new Volunteer("A", "C", 2), new Employee("A", "B", "2"),
//    };
//
//    std::vector<ONG> ongs = {ONG(parts1), ONG(parts2)};
//    printList(parts1);
//    printList(parts2);
//    auto sortedParts1 = mergeSortPart(ongs[0]);
//    std::cout << '\n';
//    printList(sortedParts1);
//    std::cout << maxCity(ongs);
//    std::cout << '\n';
//    std::cout << numEmployees(ongs);
    return 0;
}
