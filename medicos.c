#include <stdio.h>
#include <string.h>
#include "medicos.h"

#define MAX_MEDICOS 10

extern Medico medicos[MAX_MEDICOS];
extern int totalMedicos;

int crmExiste(char crm[]) {
    for (int i = 0; i < totalMedicos; i++)
        if (strcmp(medicos[i].crm, crm) == 0)
            return 1;
    return 0;
}

void cadastrarMedico() {
    if (totalMedicos >= MAX_MEDICOS) {
        printf("Limite de médicos atingido.\n");
        return;
    }

    Medico m;
    m.id = totalMedicos + 1;

    printf("Nome: ");
    scanf(" %[^\n]", m.nome);

    do {
        printf("CRM: ");
        scanf(" %[^\n]", m.crm);
        if (crmExiste(m.crm))
            printf("CRM já cadastrado.\n");
    } while (crmExiste(m.crm));

    printf("Especialidade: ");
    scanf(" %[^\n]", m.especialidade);

    printf("Disponibilidade (manhã/tarde): ");
    scanf(" %[^\n]", m.turno);

    medicos[totalMedicos++] = m;
    printf("Médico cadastrado com sucesso!\n");
}

void listarMedicos() {
    printf("\n=== Lista de Médicos ===\n");
    for (int i = 0; i < totalMedicos; i++) {
        printf("[%d] Dr(a). %s | CRM: %s | Esp: %s | Turno: %s\n",
            medicos[i].id, medicos[i].nome, medicos[i].crm,
            medicos[i].especialidade, medicos[i].turno);
    }
    printf("Total: %d médicos\n", totalMedicos);
}
