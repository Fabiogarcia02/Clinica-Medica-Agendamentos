#ifndef MEDICOS_H_INCLUDED
#define MEDICOS_H_INCLUDED


typedef struct {
    int id;
    char nome[50];
    char crm[20];
    char especialidade[30];
    char turno[10];
} Medico;

int crmExiste(char crm[]);
void cadastrarMedico();
void listarMedicos();

#endif
