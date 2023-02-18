
#ifndef CARTELLA_CLINICA_H
#define CARTELLA_CLINICA_H

struct cartella_clinica{
    char terapia[30];
    char nome_dottore[40];
};

typedef struct cartella_clinica* cartella_clinica;

int create_cartella_clinica(cartella_clinica* new_cartella_clinica, char terapia[], char nome_dottore[]);

int get_terapia(cartella_clinica my_cartella_clinica, char terapia[]);

int get_nome_dottore(cartella_clinica my_cartella_clinica, char nome_dottore[]);

int set_terapia(cartella_clinica my_cartella_clinica, char terapia[]);

int set_nome_dottore(cartella_clinica my_cartella_clinica, char nome_dottore[]);

int destroy_cartella_clinica(cartella_clinica* cartella_clinica);

int print_cartella_clinica(cartella_clinica my_cartella_clinica);

#endif



