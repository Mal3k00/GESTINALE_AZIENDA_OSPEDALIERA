#include <stdio.h>
#include <stdlib.h>
#include "cartella_clinica.h"
#include "cartelle_cliniche.h"
#include "paziente.h"
#include "pazienti.h"




int main(){
    char nome[30],cognome[30],cognome_key[30],nome_key[30], new_cognome[30], new_nome[30];
    char contatto[40], new_contatto[40];
    char terapia[30], nome_dottore[40], terapia_key[30], nome_dottore_key[40], new_terapia[30], new_nome_dottore[30];
    int eta, new_eta;
    int s1, s2;

        pazienti paziente_list;
            create_pazienti(&paziente_list);



printf("\n***************************GESTIONE OSPEDALE****************************\n");
do{
    printf("\nSelezionare l'operazione da eseguire:\n");
     printf(".1)MOSTRA ELENCO PAZIENTI\n.2)AGGIUNGI PAZIENTE\n.3)MODIFICA PAZIENTE\n.4)CANCELLA PAZIENTE\n.5)VISUALIZZA PAZIENTE\n.6)ESCI E SALVA\n\n");
     scanf("%d",&s1);
     switch (s1)
     {
     case 1:
                     printf("\n-----------------------------\n");
                     printf("\n*ELENCO PAZIENTI*\n\n");
                     if (paziente_list!=NULL)
                    print_pazienti(paziente_list);
                    else
                    printf("\n[ELENCO VUOTO]\n\n");
                break;

     case 2:
                
                printf("\n*INSERIMENTO NUOVO PAZIENTE*\n\n");
                printf("\nInserisci nome - cognome - eta - contatto(cellulare o email) :\n");
                printf("\ninserisci nome: ");
                scanf("%s", nome);
                printf("\ninserisci cognome: ");
                scanf("%s", cognome);
                printf("\n inserisci eta: ");
                scanf("%d", &eta);
                printf("\ninserisci contetto: ");
                scanf("%s", contatto);
                
                insert_paziente(&paziente_list, nome, cognome, eta, contatto);
                cartelle_cliniche cartella_list;
                 create_cartelle_cliniche(&cartella_list);
                cartelle_cliniche* pointer_cartelle_cliniche;

                
                break; 
    
    case 3: 

               printf("\n*MODIFICA PAZIENTE*\n\nN.B.Modifica errori ortografici\n");
                printf("\nInserisci nome:\n");
                scanf("%s", nome_key );
                
                printf("\nInserisci cognome:\n");
                scanf("%s", cognome_key);
             
                printf("\nInserisci nuovo nome:\n");
                scanf("%s", new_nome );
              
                printf("\ninserisci nuovo cognome\n");
                scanf("%s", new_cognome);

                printf("\ninserisci eta del paziente:\n");
                scanf("%d", &new_eta);

                printf("\ninserisci contatto del paziente:\n ");
                scanf("%s", new_contatto);
                
                modify_paziente(paziente_list, nome_key, cognome_key, new_nome, new_cognome, new_eta, new_contatto);
                break;

    case 4:
                printf("\n*CANCELLAZIONE PAZIENTE*\n\n");
                printf("\nInserisci nome: \n");
                scanf("%s", nome_key);
                printf("\nInserisci cognome paziente: \n");
                scanf("%s", cognome_key);
                
                
               

               
                delete_paziente(&paziente_list,nome_key, cognome_key);
                printf("\n-----------------------------\n");
                printf("\n*ELENCO pazienti*\n\n");
                print_pazienti(paziente_list);
                break; 
    case 5:
                printf("\n*VISUALIZZARE PAZIENTE*\n");
                
                printf("\nInserisci nome paziente:\n");
                scanf("%s", nome_key);
                printf("\n Inserisi cognome paziente:\n");
                scanf("%s",cognome_key);
                
               
                paziente my_paziente=search_paziente(paziente_list,nome_key,cognome_key);
                print_paziente(my_paziente);  

                                do{
                    printf("\nSelezionare l'operazione da eseguire:\n");
        printf(".1)MOSTRA ELENCO CARTELLE\n.2)AGGIUNGI CARTELLE\n.3)MODIFICA CARTELLE\n.4)CANCELLA CARTELLA\n.5)VISUALIZZA CARTELLA\n.6)ESCI E SALVA\n\n");
        scanf("%d",&s2);
        
      
        switch (s2){
            case 1:
                 
                printf("\n-----------------------------\n");
                printf("\n*ELENCO CARTELLE*\n\n");
              if (cartella_list!=NULL)
                    print_cartelle_cliniche(cartella_list);
              else
                  printf("\n[CARTELLA VUOTA]\n\n");
                break;
            case 2:
                printf("\n*INSERIMENTO NUOVA CARTELLA*\n\n");
                printf("\nInserisci terapia e nome dottore:\n");
                scanf("%s %s", terapia,nome_dottore);
               
            
                insert_cartella(&cartella_list,terapia, nome_dottore);
                printf("\n\n");
                print_paziente(my_paziente);
                print_cartelle_cliniche(my_paziente->cci);


                
                break;
            case 3:
                printf("\n*MODIFICA CARTELLA*\n\nN.B.Modifica errori ortografici\n");
                printf("\nInserisci terapia:\n");
                scanf("%s", terapia_key);
              
                printf("\nInserisci nome dottore:\n");
                scanf("%s", nome_dottore_key);
                
                printf("\nInserisci nuovo terapia:\n");
                scanf("%s", new_terapia);
                
                printf("\ninserisci nuovo nome dottore\n");
                scanf("%s", new_nome_dottore);
                
                modify_cartella(cartella_list,terapia_key,new_terapia,nome_dottore_key,new_nome_dottore);
                break;
            case 4:
                printf("\n*CANCELLAZIONE CARTELLA*\n\n");
                printf("\nInserisci terapia:\n");
                scanf("%s", terapia_key);
                
                printf("\nInserisci nome dottore:\n");
                scanf("%s", nome_dottore_key);
                
                delete_cartella(&cartella_list,terapia_key,nome_dottore_key);
                printf("\n-----------------------------\n");
                printf("\n*ELENCO CARTELLE*\n\n");
                print_cartelle_cliniche(cartella_list);
                break;

                    } 
                    
                   } while (s2 != 5);
                   
                   
                 
     }


}while (s1 != 6);
{
    printf("\n\n\nSALAVATAGGIO\n");
}


}