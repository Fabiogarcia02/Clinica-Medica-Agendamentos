#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED

typedef struct {
    int id;
    char nome[50];
    int idade;
    char cpf[15];
    char plano[30];
} Paciente;

int cpfExiste(char cpf[]);
void cadastrarPaciente();
void listarPacientes();

#endif
