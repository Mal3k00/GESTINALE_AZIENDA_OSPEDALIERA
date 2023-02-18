
#ifndef PAZIENTE_H
#define PAZIENTE_H
#include "cartelle_cliniche.h"



struct paziente{
    char nome[30];
    char cognome[30];
    int eta;
    char contatto[40]; //email o cellulare
    cartelle_cliniche cci;
};

typedef struct paziente* paziente;

int create_paziente(paziente* new_paziente, char nome[], char cognome[], int eta, char contatto[]);


int get_nome(paziente my_paziente, char nome[]);

int get_cognome(paziente my_paziente, char cognome[]);

int get_eta(paziente my_paziente, int eta);

int get_contatto(paziente my_paziente, char contatto[]);

int get_cartelle_cliniche(paziente my_paziente, cartelle_cliniche** cartelle_cliniche);

int set_nome(paziente my_paziente, char nome[]);

int set_cognome(paziente my_paziente, char cognome[]);

int set_eta(paziente my_paziente, int eta);

int set_contatto(paziente my_paziente, char contatto[]);

int destroy_paziente(paziente* my_paziente);

int print_paziente(paziente my_paziente);

#endif
