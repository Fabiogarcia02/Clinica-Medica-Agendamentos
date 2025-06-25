#ifndef CONSULTAS_H_INCLUDED
#define CONSULTAS_H_INCLUDED

typedef struct {
    int idConsulta;
    int idPaciente;
    int idMedico;
    char data[11];
    char hora[6];
} Consulta;

void agendarConsulta();
void consultasPorMedicoOuPaciente();
void exibirRelatorioPresencas();

#endif
