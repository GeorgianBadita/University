//
// Created by geo on 3/20/18.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "UI.h"

int validateCommand(int* cmds, int nrcmds, long nr);

void uiAdaugaFotbalist(UI* ui);

UI* creeazaUI(Service* s){
    UI* ui = (UI*)malloc(sizeof(UI));
    ui->s = s;
    return ui;
}
void printMeniu(){
    printf("Meniu:\n");
    printf("1.Adauga Fotbalist \n");
    printf("0.Exit\n");
}

void executeCommand(UI* ui,int nr){
    switch(nr){
        case 1:
            uiAdaugaFotbalist(ui);
            break;
        case 2:
            break;
        case 0:
            return;
    }
}

void uiAdaugaFotbalist(UI* ui) {
    char idbuff[50];
    long id;
    char nume[50];
    char echipa[50];
    char valbuff[50];
    double valoare;
    printf("Introduceti id:\n");
    scanf("%s",idbuff);
    char** fin;
    id = strtol(idbuff,fin,10);
    if (fin==NULL){
        printf("Introduceti nume:\n");
        scanf("%s",nume);
        printf("Introduceti echipa:\n");
        scanf("%s",echipa);
        printf("Introduceti valoare:\n");
        scanf("%s",valbuff);
        valoare = strtod(valbuff,fin);
        if (fin == NULL){
            int val = adaugaFotbalist(ui->s,id,nume,echipa,valoare);
        }else{
            printf("Invalid value!\n");
        }
    }else{
        printf("Invalid id!\n");
    }

}

int validateCommand(int* cmds, int nrcmds, long nr) {
    int i=0;
    for(;i<nrcmds;i++)
        if (nr==cmds[i])
            return 1;
    return 0;
}

void run(UI* ui){
    char cmd[20];
    int cmds[3]={0,1,2};
    int nrcmds = 3;
    long nr;
    while(1){
        printMeniu();
        scanf("%s",cmd);
        char* fin;
        nr=strtol(cmd,&fin,10);
        if (*fin==NULL){
            if (validateCommand(cmds,nrcmds,nr)>0){
                executeCommand(ui,nr);
            }else{
                printf("Inacceptable command!!!!\n");
            }

        }else{
            printf("Invalid command!!!!\n");
        }
    }
}



void distrugeUI(UI* ui ){
    distrugeService(ui->s);
    free(ui);
}