#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pacientes.h"
#include "medicos.h"
#include "consultas.h"

#define MAX_PACIENTES 20
#define MAX_MEDICOS 10
#define MAX_CONSULTAS 50

Paciente pacientes[MAX_PACIENTES];
Medico medicos[MAX_MEDICOS];
Consulta consultas[MAX_CONSULTAS];
int presencas[MAX_PACIENTES][MAX_MEDICOS] = {0};

int totalPacientes = 0;
int totalMedicos = 0;
int totalConsultas = 0;

int main() {
    int opcao;
    char entrada[100];

    do {
        printf("\n==== MENU CLÍNICA ====\n");
        printf("1. Cadastrar Paciente\n");
        printf("2. Cadastrar Médico\n");
        printf("3. Listar Pacientes\n");
        printf("4. Listar Médicos\n");
        printf("5. Agendar Consulta\n");
        printf("6. Consultas por Médico/Paciente\n");
        printf("7. Relatório de Presenças\n");
        printf("0. Sair\n");
        printf("Escolha: ");

        fgets(entrada, sizeof(entrada), stdin);
        sscanf(entrada, "%d", &opcao);

        switch (opcao) {
            case 1: cadastrarPaciente(); break;
            case 2: cadastrarMedico(); break;
            case 3: listarPacientes(); break;
            case 4: listarMedicos(); break;
            case 5: agendarConsulta(); break;
            case 6: consultasPorMedicoOuPaciente(); break;
            case 7: exibirRelatorioPresencas(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
