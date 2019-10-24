//
// Created by geo on 3/16/18.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "UserInterface.h"
#include "../utils/UserInterfaceVal.h"
#include "../utils/DynamicVector.h"


/*
 * Function that creates a new user interface
 * :param Service: the service for the UI
 * :return: a new User Interface
 */
UI* createUI(Service* srv){
    UI* ui = (UI*)malloc(sizeof(UI));
    ui->srv = srv;
    return ui;
}

/*
 * Function that destroys all the data from the user interface
 * :param UI: the user interface we want to destroy
 */
void destroyUI(UI* userInterface){
    destroyToDelete(userInterface->srv->undoL);
    destroyUndoL(userInterface->srv->undoL);
    destroyAllSrv(userInterface->srv);
    destroyService(userInterface->srv);
    free(userInterface);
}

/*
 * Function that prints the menu to the user
 * :post: the menu will be printed to the user
 */
void printMenu(){
    printf("\t 0. Pentru a afisa lista de tranzactii\n"
                   "\t 1. Pentru a adauga o noua tranzactie\n"
                   "\t 2. Pentru a modifica o tranzactie existenta\n"
                   "\t 3. Pentru a sterge o tranzactie\n"
                   "\t 4. Pentru a filtra lista dupa tip/suma\n"
                   "\t 5. Pentru a sorta lista dupa zi/suma, crescator/descrescator\n"
                   "\t 6. Pentru a face undo la ultima operatie\n"
                   "\t 7. Pentru a inchide aplicatia! ");

}

/*
 * Function that validates a command
 * :param command: the command
 * :return: 1 if the command is corect, -1 otherwise
 */
int validateCmd(char* command){
    if(validateInteger(command)){
        return 1;
    } else{
        return -1;
    }
}

/*
 * Function that adds data to the program
 * :post: data will be added to the application
 */
void populate(UI* userInterface){
    addTrService(userInterface->srv, 1, 10, "intrare");
    addTrService(userInterface->srv, 12, 120, "intrare");
    addTrService(userInterface->srv, 9, 123, "intrare");
    addTrService(userInterface->srv, 16, 11, "iesire");
    addTrService(userInterface->srv, 1, 16, "iesire");
}

/*
 * Function that prints all the transactions
 * :param ui: user interface
 * :post: transactions will be printed to the screen
 */
void printTrans(UI* ui){
    int i = 0;
    DynamicVector all = getAll(ui->srv->repo);
    for(; i < all.num; i++){
        Transaction* tr = copyTrans(all.elems[i]);
        printf("%d\t Ziua: %d\t Suma: %d\t Tipul: %s\n", i+1, tr->day, tr->sum, tr->type);
        destroyTransaction(tr);
    }
    destroyElems(&all);
}

/*
 * Function that reads a day
 * :param day: will store the value in this variable
 * :return: 1 if we could read the day, 0 otherwise
 */
int readDay(int* day){
    char cmd[10];
    printf("\nDati va rog ziua tranzactiei: ");
    readString(cmd, 9);
    if(!validateInteger(cmd) || !validateDay(getInteger(cmd))){
        printf("\nZiua este gresita!\n");
        return 0;
    }
    else{
        *day = getInteger(cmd);
        return 1;
    }
}

/*
 * Function that reads a sum
 * :param sum: will store the value in this variable
 * :return: 1 if we could read the day, 0 otherwise
 */
int readSum(int* sum){
    char cmd[10];
    printf("\nDati va rog suma tranzactiei: ");
    readString(cmd, 9);
    if(!validateInteger(cmd) || !validateSum(getInteger(cmd))){
        printf("\nSuma este gresita!\n");
        return 0;
    }
    else{
        *sum = getInteger(cmd);
        return 1;
    }
}

/* Function that reads a type
 * :param type: where we'll store the result
 * :return: 1 if we coul read the type, 0 otherwise
 */
int readType(char* type){
    char cmd[10];
    printf("\nDati va rog tipul tranzactiei (intrare/iesire): ");
    readString(cmd, 9);
    if(!validateType(cmd)){
        printf("\nTipul tranzactiei trebuie sa fie intrare sau iesire\n");
        return 0;
    }
    else{
        strcpy(type, cmd);
        return 1;
    }
}

/*
 * Function that adds a new Transaction to the list
 * :param userInterface: user interface
 * :post: the transaction will be added to the list
 */
void addTrans(UI* userInterface){
    int day = 0, sum = 0;
    char type[10];
    if(readDay(&day) && readSum(&sum) && readType(type)) {
        int rez = addTrService(userInterface->srv, day, sum, type);
        if(rez == 0){
            printf("\nTranzactia deja exista in lista!\n");
        }
        else{
            printf("\nTranzactia a fost adaugata cu succes!\n");
        }
        return;
    }
    else{
        addTrans(userInterface);
    }

}

/*
 * Function that edits a Transaction from the list
 * :param userInterface: user interface
 * :post: the transaction will be modified in the list
 */
void modifyTrans(UI* userInterface){
    int day1 = 0, sum1 = 0, day2 = 0, sum2 = 0;
    char type1[10], type2[10];
    printf("\nDatele tranzactiei ce se vrea a fi schimbata: ");
    if(readDay(&day1) && readSum(&sum1) && readType(type1)){
        int rez = searchTrService(userInterface->srv, day1, sum1, type1);
        if(rez == -1){
            printf("\nNu se poate modifica tranzactia, deoarece nu exista!\n");
            return;
        }
        printf("\nDatele tranzactiei noi: ");
        if(readDay(&day2) && readSum(&sum2) && readType(type2)){
            modifyTrService(userInterface->srv, day1, sum1, type1, day2, sum2, type2);
        }
        else{
            printf("\nDate introduse gresit!");
            modifyTrans(userInterface);
        }
    }
    else{
        printf("\nDate introduse gresit!");
        modifyTrans(userInterface);
    }
}

/*
 * Function that delets a Transaction from user interafce
 * :param userInterface: the current user interface
 * :post: the transaction will be deleted
 */
void deleteTrans(UI* userInterface){
    int day = 0, sum = 0;
    char type[10];
    printf("\nDatele tranzactiei de sters: \n");
    if(readDay(&day) && readSum(&sum) && readType(type)) {
        int made = deleteTrService(userInterface->srv, day, sum, type);
        if(made == 0){
            printf("\nNu exista tranzactia in lista!\n");
        }
        else{
            printf("\nTranzactia a fost stearasa cu succes!\n");
        }
        return;
    }
    else{
        deleteTrans(userInterface);
    }
}

/*
 * Function that filters by sum
 * :param userInterface: the current userInterface
 * :post will print all the transactions which meet the requirments
 */
void filterSum(UI* userInterface){
    printf("\t 1. Pentru a filtra dupa sume mai mici decat o suma data: \n"
                   "\t 2. Pentru a filtra dupa sume mai mari decat o suma data: ");
    char type[10];
    printf("\nDati va rog o comanda:");
    readString(type, 9);
    int typeF = validateInteger(type);
    if(typeF == 1){
        typeF = getInteger(type);
        int sumCompare = 0;
        switch (typeF){
            case 1:{
                if(readSum(&sumCompare)){
                    DynamicVector* toPrint = filterBySumL(userInterface->srv, sumCompare);
                    printAllServ(toPrint);
                    destroyVector(toPrint);
                    return;
                }
                break;
            }
            case 2:{
                if(readSum(&sumCompare)){
                    DynamicVector* toPrint = filterBySumH(userInterface->srv, sumCompare);
                    printAllServ(toPrint);
                    destroyVector(toPrint);
                    return;
                }
                break;
            }
            default:{
                break;
            }
        }
    }
    else{
        printf("\nComanda este gresita!\n");
        filterSum(userInterface);
    }
}


/*
 * Function that filters by type
 * :param userInterface: current userInterface
 * :post: will print all transactions
 */
void filterType(UI* userInterface){
    printf("\nDati va rog tipul de filtrare (intrare/iesire): ");
    char type[10];
    readString(type, 9);
    int typeV = validateType(type);
    if(typeV == 1){
        if(strcmp(type, "intrare") == 0) {
            DynamicVector *toPrint = filterByType(userInterface->srv, 1);
            printAllServ(toPrint);
            destroyVector(toPrint);
            return;
        }
        else if(strcmp(type, "iesire") == 0){
            DynamicVector* toPrint = filterByType(userInterface->srv, 0);
            printAllServ(toPrint);
            destroyVector(toPrint);
            return;
        }
        else{
            printf("\nTipul introdus nu este valid!\n");
            filterType(userInterface);
        };

    }
}

/*
 * Function that filters the list of Transaction by type or by sum
 * :param userInterface: the userInterface to filter
 */
void filterTypeSum(UI* userInterface){
    int filterBy = 0;
    char command[10];
    printf("\t 1. Pentru a filtra dupa tip\n"
                   "\t 2. Pentru a filtra dupa suma\n");
    printf("Dati va rog o comanda: ");
    readString(command, 9);
    if(validateCmd(command) == -1){
        printf("\nComanda este gresita!\n");
        filterTypeSum(userInterface);
    }
    filterBy = getInteger(command);
    switch (filterBy){
        case 1:{
            filterType(userInterface);
            break;
        }
        case 2:{
            filterSum(userInterface);
            break;
        }
        default:
            printf("\nComanda este gresita!\n");
            filterTypeSum(userInterface);
            break;
    }
}

/*
 * Function that sorts transactions by day asc/desc
 * :param userInterface: the current user interface
 * :post: will print all transactions sorted by day asc or desc
 */
void sortDay(UI* userInterface){
    char type[10];
    int sortBy = 0;
    printf("\t 1. Pentru a sorta crescator\n"
                   "\t 2. Pentru a sorta descrescator");
    printf("\nDati va rog o comanda:");
    readString(type, 9);
    int typeV = validateInteger(type);
    if(typeV == 1){
        sortBy = getInteger(type);
        if(sortBy == 1){
            DynamicVector* toPrint = sortByDay(userInterface->srv, 1);
            printAllServ(toPrint);
            destroyVector(toPrint);
            return;
        }
        else if(sortBy == 2){
            DynamicVector* toPrint = sortByDay(userInterface->srv, 0);
            printAllServ(toPrint);
            destroyVector(toPrint);
            return;
        }
        else{
            printf("\nComanda introdusa cresit!");
            sortDay(userInterface);
        }
    }
}

/*
 * Function that sorts transactions by sum asc/desc
 * :param userInterface: the current user interface
 * :post: will print all transactions sorted by sum asc or desc
 */
void sortSum(UI* userInterface){
    char type[10];
    int sortBy = 0;
    printf("\t 1. Pentru a sorta crescator\n"
                   "\t 2. Pentru a sorta descrescator");
    printf("\nDati va rog o comanda: ");
    readString(type, 9);
    int typeV = validateInteger(type);
    if(typeV == 1){
        sortBy = getInteger(type);
        if(sortBy == 1){
            DynamicVector* toPrint = sortBySum(userInterface->srv, 1);
            printAllServ(toPrint);
            destroyVector(toPrint);
            return;
        }
        else if(sortBy == 2){
            DynamicVector* toPrint = sortBySum(userInterface->srv, 0);
            printAllServ(toPrint);
            destroyVector(toPrint);
            return;
        }
    }
    else{
        printf("\nComanda introdusa cresit!");
        sortDay(userInterface);
    }
}

/*
 * Function that sorts all Transactions by sum or by day asc/desc
 * :param: the current user interface
 * :post: prints all the transactions sorted
 */
void sortSumDay(UI* userInterface){
    int filterBy = 0;
    char command[10];
    printf("\t 1. Pentru a sorta dupa zi\n"
                   "\t 2. Pentru a sorta dupa suma\n");
    printf("Dati va rog o comanda: ");
    readString(command, 9);
    if(validateCmd(command) == -1){
        printf("\nComanda este gresita!\n");
        sortSumDay(userInterface);
    }
    filterBy = getInteger(command);
    switch (filterBy){
        case 1:{
            sortDay(userInterface);
            break;
        }
        case 2:{
            sortSum(userInterface);
            break;
        }
        default:
            printf("\nComanda este gresita!\n");
            sortSumDay(userInterface);
            break;
    }
}

void makeUndo(UI* userInterface){
    if(userInterface->srv->undoL->undoLst->num > 0) {
        DynamicVector *lst = popServ(userInterface->srv->undoL);
        printAllServ(lst);
        userInterface->srv->repo->transactions = lst;
    }
    else{
        printf("Nu se mai poate face undo!\n");
    }
}

/*
 * Function that coordinates the menu
 * :return: -
 * post: -
 */
void showUI(UI* userInterface){
    char command[10];
    populate(userInterface);
    while(1){
        int cmd = -1;
        printMenu();
        printf("\nDati o comanda: ");
        readString(command, 10);
        if(validateCmd(command) == -1){
            printf("\nComanda este gresita!\n");
            continue;
        }
        cmd = getInteger(command);
        if(cmd == 0){
            printTrans(userInterface);
        }
        else if(cmd == 1){
            addTrans(userInterface);
        }
        else if(cmd == 2){
            modifyTrans(userInterface);
        }
        else if(cmd == 3){
            deleteTrans(userInterface);
        }
        else if(cmd == 4){
            filterTypeSum(userInterface);
        }
        else if(cmd == 5){
            sortSumDay(userInterface);
        }
        else if(cmd == 6){
            makeUndo(userInterface);
        }
        else if(cmd == 7){
            return;
        }
    }
}