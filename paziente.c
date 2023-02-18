#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cartella_clinica.h"
#include "cartelle_cliniche.h"
#include "paziente.h"


int create_paziente(paziente* new_paziente, char nome[], char cognome[], int eta, char contatto[]){//input
    (*new_paziente) = (paziente)malloc(sizeof(struct paziente)); //allocazione di memoria assegnando la quantità di memoria richiesta alla struttura paziente alla variabile new_paziente
                                                                                          
    if ((*new_paziente) == NULL) return 1;
    /*I campi del nuovo paziente vengono impostati chiamando le funzioni set_nome, set_cognome, set_eta e set_contatto passando 
    l'indirizzo della struttura appena creata e i valori specificati come argomenti.*/
    set_nome(*new_paziente, nome); 
    
    set_cognome(*new_paziente, cognome);

    set_eta(*new_paziente, eta);

    set_contatto(*new_paziente, contatto);
        int result = create_cartelle_cliniche(&((*new_paziente)->cci)); //viene richiamata questa funzione per creare una lista di cartelle cliniche per il paziente
    if(result == 1){ 
        free(*new_paziente); //se la creazione non avviene viene liberata la memoria
        *new_paziente = NULL; //impotato a null
         
        return 1; //
    } 

    return 0;//andata a buon fine
}
//recupera il valore del nome
int get_nome(paziente my_paziente, char nome[]){  // verifica che la struttura è stata inizializzata
    if(my_paziente == NULL) return 1; // output 1 se la struttura non è stata inizializzata correttamente
    strcpy(nome, my_paziente->nome); //prosegue
    return 0; // 0 l'operazione è anadata a buon fine
}

int get_cognome(paziente my_paziente, char cognome[]){  //analoga
    if(my_paziente == NULL) return 1; 
    strcpy(cognome, my_paziente->cognome); 
    return 0; 
}

int get_eta(paziente my_paziente, int eta) {//analoga
if(my_paziente == NULL) return 1;
eta = my_paziente->eta;//viene assegnato il valore dell'eta del paziente alla variabile eta
return 0;
}

int get_contatto(paziente my_paziente, char contatto[]){//analoga
if(my_paziente == NULL) return 1;
strcpy(contatto, my_paziente->contatto);
return 0;
}

int get_cartelle_cliniche(paziente my_paziente, cartelle_cliniche** cartelle_cliniche){
    if(my_paziente==NULL) return 1;
    *cartelle_cliniche =&(my_paziente->cci);
 }

//imposta il valore del nome
int set_nome(paziente my_paziente, char nome[]){// verifica che la struttura è stata inizializzata
if(my_paziente == NULL) return 1;// output 1 se la struttura non è stata inizializzata correttamente
strcpy(my_paziente->nome, nome);
return 0;// 0 l'operazione è anadata a buon fine
}


int set_cognome(paziente my_paziente, char cognome[]){
    if(my_paziente == NULL) return 1;
    strcpy(my_paziente->cognome, cognome);
    return 0;
}

int set_contatto(paziente my_paziente, char contatto[]){
    if(my_paziente == NULL) return 1;
    strcpy(my_paziente->contatto, contatto);
    return 0;
}

int set_eta(paziente my_paziente, int eta) {
    if(my_paziente == NULL) return 1;
    my_paziente->eta = eta;
    return 0;
}


int destroy_paziente(paziente* my_paziente){
    if(*my_paziente == NULL) return 1; //verifica che non sia nullo il*
    int result = destroy_cartelle_cliniche(&((*my_paziente)->cci));//proosegue
    if(result == 1)
        return 1;//operazione non andata a buon fine
    free(*my_paziente);
    *my_paziente = NULL;//imposto il puntatore a null
    return 0;
}

int print_paziente(paziente my_paziente){
    if(my_paziente == NULL) return 1;
    printf("%s %s\n", my_paziente->nome, my_paziente->cognome);
    print_cartelle_cliniche(my_paziente->cci);
    return 0;
}







