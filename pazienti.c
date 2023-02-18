#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cartella_clinica.h"
#include "cartelle_cliniche.h"
#include "paziente.h"
#include "pazienti.h"


//creo la lista vuota
int create_pazienti(pazienti* paziente_list){//prende in input cartelle_cliniche
    *paziente_list = NULL;//viene inizializzato a null
    return 0;// ok
}

int insert_paziente(pazienti* paziente_list, char new_nome[], char new_cognome[], int new_eta, char new_contatto[]){//input
    pazienti new_paziente;//varibile della struttura
    new_paziente = (pazienti)malloc(sizeof(struct pazienti));//allocazione memoria
    if(new_paziente == NULL) return 1;//se l'operazione non è riuscita restituisce 1
    int result = create_paziente(&(new_paziente->paz), new_nome, new_cognome, new_eta, new_contatto);//richiamo la funzione c.c.c per inizializzare i dati 
    if(result == 1){//operazione non riuscita
        free(new_paziente);
        return 1;
    }
    new_paziente->next = *paziente_list;//prosegue, il nuoco viene inserito in testa
    *paziente_list = new_paziente;
    return 0;
}


paziente search_paziente(pazienti paziente_list, char nome_key[], char cognome_key[]){
    while(paziente_list != NULL){
        char cognome[30];
        char nome[30];
        get_nome(paziente_list->paz, nome);
        get_cognome(paziente_list->paz, cognome);
        if(strcmp(nome_key, nome) == 0 && strcmp(cognome_key, cognome) == 0)
         
            return paziente_list->paz;
        paziente_list = paziente_list->next;
    }

}

int modify_paziente(pazienti paziente_list, char nome_key[],char cognome_key[], char new_nome[], char new_cognome[], int new_eta, char new_contatto[]) {//input
    paziente paziente_key = search_paziente(paziente_list, cognome_key, nome_key);//chiamo la funzione cerca per cercare l'elemento
   //se viene trovato il paziente, vengono inizializzati i valori a 0, per registrare l'esito della modifica della terapia e del nome del medico.
    int result1 = 0;
    int result2 = 0;
    int result3 = 0;
    int result4 = 0;
      if(paziente_key == NULL) return 1;//1 se non viene trovato
    if(new_nome[0] != '\0')//Se la stringa new_nome non è vuota viene chiamata la funzione set_nome per modificare il nome del paziente corrispondente il risultato viene registrato in result1.
        result1 = set_nome(paziente_key, new_nome);//set_nme per modificare il nome del pazientw corrispondente il risultato viene registrato in result1
    if(new_cognome[0] != '\0')
        result2 = set_cognome(paziente_key, new_cognome);
    if(new_eta >= 0)
        result3 = set_eta(paziente_key, new_eta);
    if(new_contatto[0] != '\0')
        result4 = set_contatto(paziente_key, new_contatto);
    if (result1 && result2 && result3 && result4) return 1;
    return 0;
}

int delete_paziente(pazienti* paziente_list, char nome_key[], char cognome_key[]){
  pazienti r = *paziente_list;//puntatori inizializzati alla testa della lista
  pazienti q = *paziente_list;
  char nome[30];
  char cognome[30];
  
  get_nome(q->paz, nome);//gt per ottenere la terapia, viene salvata nella stringa
  get_cognome(q->paz, cognome);
  

  while ((q != NULL) && (strcmp(nome, nome_key) !=0 || strcmp(cognome, cognome_key) != 0)){//continua finché non si trova il paziente da eliminare o si arriva alla fine della lista
    r = q;
    q = q->next;
    get_nome(q->paz, nome);
    get_cognome(q->paz, cognome);
  }

  if (q == NULL) return 1;//non è stato trovato nessun elemento
   /*se q non è diventato NULL la funzione verifica se il paziente da eliminare è la prima 
    nella lista (if (q == *paziente_list))*/
  if (q==*paziente_list)
    (*paziente_list) = (*paziente_list)->next;
  else
    r->next = q->next;// se il paziente da eliminare non è il prima nella lista, allora viene collegato il puntatore del predecessore (r) al paziente successivo (r->next = q->next) per saltare il paziente da eliminare*/
  destroy_paziente(&(q->paz));//per distruggere l'oggetto
  
  free(q);//libero memoria
  return 0;
}



int destroy_pazienti(pazienti* paziente_list){
    while(*paziente_list != NULL){
        pazienti p = *paziente_list;//ad ogni iterazione la variabile p viene impostata sull'indirizzo della lista
        destroy_paziente(&(p->paz));//viene chiamata per eliminare i dati
        *paziente_list = (*paziente_list)->next;//L'indirizzo della prossima cartella clinica nella lista viene impostato come nuovo valore della lista.
        free(p);
    }

}

void print_pazienti(pazienti paziente_list){
    while(paziente_list != NULL){
        print_paziente(paziente_list->paz);//in ogni iterazione,  print_cartella_clinica viene chiamata 
        paziente_list = paziente_list->next;//l'indirizzo della prossima cartella clinica nella lista viene impostato come nuovo valore della lista.
    }
}

/*

void save_pazienti(pazienti* paziente_list, char* pazienti) {
    FILE* file = fopen(pazienti, "wb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    pazienti* current = paziente_list;
    while (current != NULL) {
        fwrite(current, sizeof(pazienti), 1, file);
        current = current->next;
    }

    fclose(file);
}





void load_pazienti(pazienti** paziente_list, char* pazienti) {
    FILE* file = fopen(pazienti, "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    pazienti* current = NULL;
    while (1) {
        pazienti* new_paziente = (pazienti*)malloc(sizeof(pazienti));
        size_t read = fread(new_paziente, sizeof(pazienti), 1, file);
        if (read != 1) {
            free(new_paziente);
            break;
        }

        new_paziente->next = NULL;
        if (*paziente_list == NULL) {
            *paziente_list = new_paziente;
        } else {
            current->next = new_paziente;
        }
        current = new_paziente;
    }

    fclose(file);
}

pazienti* search_paziente(pazienti* paziente_list, char* name) {
    pazienti* current = paziente_list;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

*/

