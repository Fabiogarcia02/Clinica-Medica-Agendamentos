#include <stdio.h>
#include <string.h>
#include "pacientes.h"

#define MAX_PACIENTES 20

extern Paciente pacientes[MAX_PACIENTES];
extern int totalPacientes;

int cpfExiste(char cpf[]) {
    for (int i = 0; i < totalPacientes; i++)
        if (strcmp(pacientes[i].cpf, cpf) == 0)
            return 1;
    return 0;
}

void cadastrarPaciente() {
    if (totalPacientes >= MAX_PACIENTES) {
        printf("Limite de pacientes atingido.\n");
        return;
    }

    Paciente p;
    p.id = totalPacientes + 1;

    printf("Nome: ");
    scanf(" %[^\n]", p.nome);

    do {
        printf("Idade: ");
        scanf("%d", &p.idade);
        if (p.idade <= 0)
            printf("Idade inválida.\n");
    } while (p.idade <= 0);

    do {
        printf("CPF: ");
        scanf(" %[^\n]", p.cpf);
        if (cpfExiste(p.cpf))
            printf("CPF já cadastrado.\n");
    } while (cpfExiste(p.cpf));

    printf("Plano de Saúde: ");
    scanf(" %[^\n]", p.plano);

    pacientes[totalPacientes++] = p;
    printf("Paciente cadastrado com sucesso!\n");
}

void listarPacientes() {
    printf("\n=== Lista de Pacientes ===\n");
    for (int i = 0; i < totalPacientes; i++) {
        printf("[%d] %s | Idade: %d | CPF: %s | Plano: %s\n",
            pacientes[i].id, pacientes[i].nome, pacientes[i].idade,
            pacientes[i].cpf, pacientes[i].plano);
    }
    printf("Total: %d pacientes\n", totalPacientes);
}
