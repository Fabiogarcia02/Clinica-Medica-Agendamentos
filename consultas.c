#include <stdio.h>
#include <string.h>
#include "consultas.h"
#include "pacientes.h"
#include "medicos.h"

#define MAX_CONSULTAS 50
#define MAX_PACIENTES 20
#define MAX_MEDICOS 10

extern Paciente pacientes[MAX_PACIENTES];
extern Medico medicos[MAX_MEDICOS];
extern Consulta consultas[MAX_CONSULTAS];
extern int presencas[MAX_PACIENTES][MAX_MEDICOS];
extern int totalConsultas;
extern int totalPacientes;
extern int totalMedicos;

int consultaDuplicada(int idMedico, char data[], char hora[]) {
    for (int i = 0; i < totalConsultas; i++) {
        if (consultas[i].idMedico == idMedico &&
            strcmp(consultas[i].data, data) == 0 &&
            strcmp(consultas[i].hora, hora) == 0)
            return 1;
    }
    return 0;
}

void agendarConsulta() {
    if (totalConsultas >= MAX_CONSULTAS) {
        printf("Limite de consultas atingido.\n");
        return;
    }

    Consulta c;
    c.idConsulta = totalConsultas + 1;

    char linha[100];

    for (int i = 0; i < totalPacientes; i++)
        printf("[%d] %s\n", pacientes[i].id, pacientes[i].nome);
    printf("ID do paciente: ");
    fgets(linha, sizeof(linha), stdin);
    sscanf(linha, "%d", &c.idPaciente);

    for (int i = 0; i < totalMedicos; i++)
        printf("[%d] %s\n", medicos[i].id, medicos[i].nome);
    printf("ID do médico: ");
    fgets(linha, sizeof(linha), stdin);
    sscanf(linha, "%d", &c.idMedico);

    printf("Data (DD/MM/AAAA): ");
    fgets(c.data, sizeof(c.data), stdin);
    c.data[strcspn(c.data, "\n")] = '\0'; // remove \n

    printf("Hora (HH:MM): ");
    fgets(c.hora, sizeof(c.hora), stdin);
    c.hora[strcspn(c.hora, "\n")] = '\0';

    if (consultaDuplicada(c.idMedico, c.data, c.hora)) {
        printf("Erro: Médico já tem consulta nesse horário.\n");
        return;
    }

    consultas[totalConsultas++] = c;

    int presenca;
    do {
        printf("O paciente compareceu à consulta? (1 - Sim / 0 - Não): ");
        fgets(linha, sizeof(linha), stdin);
        sscanf(linha, "%d", &presenca);
    } while (presenca != 0 && presenca != 1);

    if (presenca == 1) {
        presencas[c.idPaciente - 1][c.idMedico - 1]++;
    }

    printf("Consulta agendada com sucesso!\n");
}

void consultasPorMedicoOuPaciente() {
    int opcao, id;
    char linha[100];

    printf("1 - Consultas por Médico\n2 - Consultas por Paciente\nEscolha: ");
    fgets(linha, sizeof(linha), stdin);
    sscanf(linha, "%d", &opcao);

    if (opcao == 1) {
        for (int i = 0; i < totalMedicos; i++)
            printf("[%d] %s\n", medicos[i].id, medicos[i].nome);
        printf("ID do médico: ");
        fgets(linha, sizeof(linha), stdin);
        sscanf(linha, "%d", &id);
        printf("Consultas do médico %s:\n", medicos[id - 1].nome);
        for (int i = 0; i < totalConsultas; i++) {
            if (consultas[i].idMedico == id)
                printf("Data: %s Hora: %s | Paciente: %s\n",
                       consultas[i].data, consultas[i].hora,
                       pacientes[consultas[i].idPaciente - 1].nome);
        }
    } else {
        for (int i = 0; i < totalPacientes; i++)
            printf("[%d] %s\n", pacientes[i].id, pacientes[i].nome);
        printf("ID do paciente: ");
        fgets(linha, sizeof(linha), stdin);
        sscanf(linha, "%d", &id);
        printf("Consultas do paciente %s:\n", pacientes[id - 1].nome);
        for (int i = 0; i < totalConsultas; i++) {
            if (consultas[i].idPaciente == id)
                printf("Data: %s Hora: %s | Médico: %s\n",
                       consultas[i].data, consultas[i].hora,
                       medicos[consultas[i].idMedico - 1].nome);
        }
    }
}

void exibirRelatorioPresencas() {
    printf("\nRelatório de Presenças:\n");
    printf("%20s", " ");
    for (int j = 0; j < totalMedicos; j++) {
        printf("| %-12s", medicos[j].nome);
    }
    printf("\n");

    for (int i = 0; i < totalPacientes; i++) {
        printf("%-20s", pacientes[i].nome);
        for (int j = 0; j < totalMedicos; j++) {
            printf("| %-12d", presencas[i][j]);
        }
        printf("\n");
    }
}
