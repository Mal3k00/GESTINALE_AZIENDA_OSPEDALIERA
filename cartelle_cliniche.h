
#ifndef CARTELLE_CLINICHE_H
#define CARTELLE_CLINICHE_H
#include "cartella_clinica.h"

struct cartelle_cliniche{
    cartella_clinica cc;
    struct cartelle_cliniche* next;
};

typedef struct cartelle_cliniche* cartelle_cliniche;

int create_cartelle_cliniche(cartelle_cliniche* cartella_list);

int insert_cartella(cartelle_cliniche* cartella_list, char new_terapia[], char new_nome_dottore[]);

cartella_clinica search_cartella(cartelle_cliniche cartella_list, char terapia_key[],char nome_dottore_key[]);

int modify_cartella(cartelle_cliniche cartella_list, char terapia_key[], char new_terapia[],char nome_dottore_key[], char new_nome_dottore[]);

int delete_cartella(cartelle_cliniche* cartella_list, char terapia_key[], char nome_dottore_key[]);

int destroy_cartelle_cliniche(cartelle_cliniche* cartella_list);

void print_cartelle_cliniche(cartelle_cliniche cartella_list);

#endif
