#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cartella_clinica.h"
#include "cartelle_cliniche.h"

//creo la lista vuota
int create_cartelle_cliniche(cartelle_cliniche* cartella_list){ //prende in input cartelle_cliniche
    *cartella_list = NULL; //viene inizializzato a null
    return 0; // ok
} 

int insert_cartella(cartelle_cliniche* cartella_list, char new_terapia[], char new_nome_dottore[]){ //input
    cartelle_cliniche new_cartella_clinica; //varibile della struttura
    new_cartella_clinica = (cartelle_cliniche)malloc(sizeof(struct cartelle_cliniche)); //allocazione memoria
    if(new_cartella_clinica == NULL) return 1; //se l'operazione non è riuscita restituisce 1
    int result = create_cartella_clinica(&(new_cartella_clinica->cc), new_terapia, new_nome_dottore); //richiamo la funzione c.c.c per inizializzare i dati 
    if(result == 1) return 1; //operazione non riuscita

   new_cartella_clinica->next = *cartella_list;//prosegue, la nuova cartella clinica viene inserita in testa
    *cartella_list = new_cartella_clinica;
    return 0; //operazione riuscita
}

cartella_clinica search_cartella(cartelle_cliniche cartella_list, char terapia_key[], char nome_dottore_key[]){//input
    while(cartella_list != NULL){
        char terapia[30];
        char nome_dottore[40];
        get_terapia(cartella_list->cc, terapia);//per ogni cartella clinica nella lista
        get_nome_dottore(cartella_list->cc, nome_dottore);//vengono estratte le informazioni relative alla terapia e al nome del medico tramite le funzioni "get_terapia" e "get_nome_dottore".
        if(strcmp(terapia_key, terapia) == 0 || strcmp(nome_dottore_key, nome_dottore) == 0)//vengono confrontate queste informazioni con le chiavi di ricerca fornite 
            return cartella_list->cc; //se una delle due corrisponde, la cartella clinica corrispondente viene ritornata dalla funzione.
        cartella_list = cartella_list->next;//se nessuna cartella clinica corrisponde alle chiavi di ricerca, il ciclo continua fino a quando non si è scorso l'intera lista.
    } 
    return 0;//se non è stata trovata alcuna cartella restituisce 0
}

int modify_cartella(cartelle_cliniche cartella_list, char terapia_key[], char new_terapia[],char nome_dottore_key[], char new_nome_dottore[]){//input
    cartella_clinica cartella_key = search_cartella(cartella_list, terapia_key, nome_dottore_key);//chiamo la funzione cerca per cercare l'elemento
    if(cartella_key == NULL) return 1; //1 se non viene trovato
    //se viene trovata la cartella clinica, vengono inizializzati due valori a 0, per registrare l'esito della modifica della terapia e del nome del medico.
    int result1 = 0;
    int result2 = 0;
    if(new_terapia[0] != '\0')//Se la stringa new_terapia non è vuota viene chiamata la funzione set_terapia per modificare la terapia nella cartella clinica corrispondente. Il risultato viene registrato in "result1".
        result1 = set_terapia(cartella_key, new_terapia);//set_terapia per modificare la terapia nella cartella clinica corrispondente il risultato viene registrato in result1
    if(new_nome_dottore[0] != '\0') //analogo
        result2 = set_nome_dottore(cartella_key, new_nome_dottore);
    if (result1 && result2) return 1; //Se entrambi i risultati sono uguali a 1, la funzione ritorna 1, indicando che c'è stato un errore 
    return 0;// 0 ope. andata a buon fine
}

int delete_cartella(cartelle_cliniche* cartella_list, char terapia_key[], char nome_dottore_key[]){ //input
  cartelle_cliniche r = *cartella_list;//puntatori inizializzati alla testa della lista
  cartelle_cliniche q = *cartella_list;
  char terapia[30];
  char nome_dottore[40];
  get_terapia(q->cc, terapia);//gt per ottenere la terapia, viene salvata nella stringa
  get_nome_dottore(q->cc, nome_dottore);//analogo

  while ((q != NULL) && (strcmp(terapia, terapia_key) !=0 || strcmp(nome_dottore, nome_dottore_key) != 0)){//continua finché non si trova la cartella clinica da eliminare o si arriva alla fine della lista
    r = q; 
    q = q->next; //la funzione avanza
    get_terapia(q->cc, terapia);
    get_nome_dottore(q->cc, nome_dottore);
  }

  if (q == NULL) //non è stato trovato nessun elemento
    return 1;
    /*se q non è diventato NULL la funzione verifica se la cartella clinica da eliminare è la prima 
    nella lista (if (q == *cartella_list))*/ 
  if (q==*cartella_list)
    (*cartella_list) = (*cartella_list)->next; //se è vero, la testa della lista viene spostata al prossimo elemento ((*cartella_list) = (*cartella_list)->next;). Altrimenti, se la cartella clinica da eliminare non è la prima nella lista, allora viene collegato il puntatore del predecessore (r) alla cartella clinica successiva (r->next = q->next) per saltare la cartella clinica da eliminare*/
  else
    r->next = q->next; // se la cartella clinica da eliminare non è la prima nella lista, allora viene collegato il puntatore del predecessore (r) alla cartella clinica successiva (r->next = q->next) per saltare la cartella clinica da eliminare*/
  destroy_cartella_clinica(&(q->cc)); //per distruggere l'oggetto
   
  free(q); //per liberare memoria
  
  return 0;
}



int destroy_cartelle_cliniche(cartelle_cliniche* cartella_list){
    while(*cartella_list != NULL){
        cartelle_cliniche p = *cartella_list; //ad ogni iterazione la variabile p viene impostata sull'indirizzo della lista
        destroy_cartella_clinica(&(p->cc)); //viene chiamata per eliminare i dati
        *cartella_list = (*cartella_list)->next;//L'indirizzo della prossima cartella clinica nella lista viene impostato come nuovo valore della lista.
        free(p);
    }
    
}
//per stampare l'intera lista
void print_cartelle_cliniche(cartelle_cliniche cartella_list){
    while(cartella_list != NULL){
        print_cartella_clinica(cartella_list->cc);//in ogni iterazione,  print_cartella_clinica viene chiamata 
        cartella_list = cartella_list->next; //l'indirizzo della prossima cartella clinica nella lista viene impostato come nuovo valore della lista.
    }
}



