#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cartella_clinica.h"


//la funzione crea una nuova struttura cartella_clinica e la inizializza con gli argomentti della struttura
int create_cartella_clinica(cartella_clinica* new_cartella_clinica, char terapia[], char nome_dottore[]){
    (*new_cartella_clinica) = (cartella_clinica)malloc(sizeof(struct cartella_clinica)); //allocazione di memoria per la nuova struttura
  //il risultato viene assegnato alla variabile puntatore new_cartella_clinica                                                                                        
    if ((*new_cartella_clinica) == NULL) return 1;// se non ce abbastanza memoria dis. output 1
      strcpy((*new_cartella_clinica)->terapia, terapia);//in caso contrario prosegue vengono copiati gli argomenti nelle variabili
    set_terapia(*new_cartella_clinica, terapia);  
      strcpy((*new_cartella_clinica)->nome_dottore, nome_dottore);
    set_nome_dottore(*new_cartella_clinica, nome_dottore);
    return 0; //restituisce 0 l'operazione è andata a buon fine
}
//recupera il valore della terapia
int get_terapia(cartella_clinica my_cartella_clinica, char terapia[]){// verifica che la struttura è stata inizializzata 
    if(my_cartella_clinica == NULL) return 1; // output 1 se la struttura non è stata inizializzata correttamente
    strcpy(terapia, my_cartella_clinica->terapia); //prosegue
    return 0; // 0 l'operazione è anadata a buon fine
}

int get_nome_dottore(cartella_clinica my_cartella_clinica, char nome_dottore[]){ //analoga
    if(my_cartella_clinica == NULL) return 1;
    strcpy(nome_dottore, my_cartella_clinica->nome_dottore);
    return 0;
}
//imposta il valore della terapia
int set_terapia(cartella_clinica my_cartella_clinica, char terapia[]){ // verifica che la struttura è stata inizializzata
    if(my_cartella_clinica == NULL) return 1; // output 1 se la struttura non è stata inizializzata correttamente
    strcpy(my_cartella_clinica->terapia, terapia);//prosegue
    return 0;// 0 l'operazione è anadata a buon fine
}

int set_nome_dottore(cartella_clinica my_cartella_clinica, char nome_dottore[]){//analoga
    if(my_cartella_clinica == NULL) return 1;
    strcpy(my_cartella_clinica->nome_dottore, nome_dottore);
    return 0;
}
//liberare memoria
int destroy_cartella_clinica(cartella_clinica* my_cartella_clinica){
    if(*my_cartella_clinica == NULL) return 1; // verifica che la struttura passata come argomento non sia nulla 
    free(*my_cartella_clinica);//prosegue, libera la memoria utilizzata dalla struttura
    *my_cartella_clinica = NULL; //imposta il puntatore a null
    return 0; //ouput 0 ope. andata a buon  fine
}

int print_cartella_clinica(cartella_clinica my_cartella_clinica){
    if(my_cartella_clinica == NULL) return 1;// verifica che l'ogggetto non sia nullo 
    else printf("%s  %s\n", my_cartella_clinica->terapia, my_cartella_clinica->nome_dottore); // prosegue
    return 0; //operazione andata a buon fine
}

