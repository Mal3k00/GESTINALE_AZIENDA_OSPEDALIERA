
#ifndef PAZIENTI_H
#define PAZIENTI_H


struct pazienti{
    paziente paz;
    struct pazienti* next;
};

typedef struct pazienti* pazienti;

int create_pazienti(pazienti* paziente_list);

int insert_paziente(pazienti* paziente_list, char new_nome[], char new_cognome[], int new_eta, char new_contatto[]);

paziente search_paziente(pazienti paziente_list, char nome_key[], char cognome_key[]);

int modify_paziente(pazienti paziente_list, char nome_key[],char cognome_key[], char new_nome[], char new_cognome[], int new_eta, char new_contatto[]);

int delete_paziente(pazienti* paziente_list, char nome_key[], char cognome_key[]);

int destroy_pazienti(pazienti* paziente_list);

void print_pazienti(pazienti paziente_list);

#endif
