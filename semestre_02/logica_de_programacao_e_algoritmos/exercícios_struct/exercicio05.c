#include <stdio.h>
#include <string.h>

#define MAX_PACIENTES 15
#define MAX_CONSULTAS 30

// definicao da struct data
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

// definicao da struct paciente
typedef struct {
    int codigo;
    char nome[100];
    char telefone[25];
} Paciente;

// definicao da struct consulta
typedef struct {
    Paciente paciente;
    Data data;
    char descricao[200];
} Consulta;

// funcao para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// funcao para buscar o indice de um paciente pelo codigo
int buscarPaciente(Paciente pacientes[], int total, int codigo) {
    for (int i = 0; i < total; i++) {
        if (pacientes[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

int main() {
    Paciente pacientes[MAX_PACIENTES];
    Consulta consultas[MAX_CONSULTAS];
    int totalPacientes = 0, totalConsultas = 0;
    int opcao;

    do {
        printf("\nCLINICA MEDICA\n");
        printf("1. Cadastrar paciente (%d/%d)\n", totalPacientes, MAX_PACIENTES);
        printf("2. Registrar consulta (%d/%d)\n", totalConsultas, MAX_CONSULTAS);
        printf("3. Pesquisar consultas por codigo do paciente\n");
        printf("4. Listar consultas por data\n");
        printf("5. Estatisticas de atendimento por paciente\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        //cadastrar um paciente
        if (opcao == 1) {
            if (totalPacientes >= MAX_PACIENTES) {
                printf("Limite de pacientes atingido!\n");
                continue;
            }
            int cod;
            printf("Codigo do paciente: ");
            scanf("%d", &cod);
            limparBuffer();

            if (buscarPaciente(pacientes, totalPacientes, cod) != -1) {
                printf("Codigo ja cadastrado!\n");
                continue;
            }

            pacientes[totalPacientes].codigo = cod;
            printf("Nome do paciente: ");
            fgets(pacientes[totalPacientes].nome, sizeof(pacientes[totalPacientes].nome), stdin);
            pacientes[totalPacientes].nome[strcspn(pacientes[totalPacientes].nome, "\n")] = '\0';

            printf("Telefone: ");
            fgets(pacientes[totalPacientes].telefone, sizeof(pacientes[totalPacientes].telefone), stdin);
            pacientes[totalPacientes].telefone[strcspn(pacientes[totalPacientes].telefone, "\n")] = '\0';

            totalPacientes++;
            printf("Paciente cadastrado com sucesso!\n");

            //registrar uma consulta
        } else if (opcao == 2) {
            if (totalConsultas >= MAX_CONSULTAS) {
                printf("Limite de consultas atingido!\n");
                continue;
            }
            if (totalPacientes == 0) {
                printf("Cadastre um paciente primeiro.\n");
                continue;
            }

            int cod;
            printf("Codigo do paciente: ");
            scanf("%d", &cod);
            limparBuffer();

            int idx = buscarPaciente(pacientes, totalPacientes, cod);
            if (idx == -1) {
                printf("Paciente nao encontrado!\n");
                continue;
            }

            consultas[totalConsultas].paciente = pacientes[idx];

            printf("Data da consulta (DD MM AAAA): ");
            scanf("%d %d %d", &consultas[totalConsultas].data.dia,
                  &consultas[totalConsultas].data.mes,
                  &consultas[totalConsultas].data.ano);
            limparBuffer();

            printf("Descricao do atendimento: ");
            fgets(consultas[totalConsultas].descricao, sizeof(consultas[totalConsultas].descricao), stdin);
            consultas[totalConsultas].descricao[strcspn(consultas[totalConsultas].descricao, "\n")] = '\0';

            totalConsultas++;
            printf("Consulta registrada!\n");

        //gerar relatorio de consultas por paciente
        } else if (opcao == 3) {
            int cod, encontradas = 0;
            printf("Codigo do paciente: ");
            scanf("%d", &cod);

            printf("\n--- Consultas do Paciente (Cod: %d) ---\n", cod);
            for (int i = 0; i < totalConsultas; i++) {
                if (consultas[i].paciente.codigo == cod) {
                    printf("Data: %02d/%02d/%04d | Descricao: %s\n",
                           consultas[i].data.dia, consultas[i].data.mes,
                           consultas[i].data.ano, consultas[i].descricao);
                    encontradas++;
                }
            }
            if (encontradas == 0) {
                printf("Nenhuma consulta encontrada para este paciente.\n");
            }

            //gerar relatorio de consultas por data
        } else if (opcao == 4) {
            Data d;
            int encontradas = 0;
            printf("Informe a data (DD MM AAAA): ");
            scanf("%d %d %d", &d.dia, &d.mes, &d.ano);

            printf("\n--- Consultas em %02d/%02d/%04d ---\n", d.dia, d.mes, d.ano);
            for (int i = 0; i < totalConsultas; i++) {
                if (consultas[i].data.dia == d.dia &&
                    consultas[i].data.mes == d.mes &&
                    consultas[i].data.ano == d.ano) {
                    printf("Paciente: %s (Cod: %d) | Descricao: %s\n",
                           consultas[i].paciente.nome, consultas[i].paciente.codigo,
                           consultas[i].descricao);
                    encontradas++;
                }
            }
            if (encontradas == 0) {
                printf("Nenhuma consulta registrada nesta data.\n");
            }

            //estatisticas de atendimento por paciente
        } else if (opcao == 5) {
            if (totalPacientes == 0) {
                printf("Nenhum paciente cadastrado.\n");
                continue;
            }

            int maxAtendimentos = -1;
            int idxMaisAtendido = 0;

            printf("\nCONTAGEM DE CONSULTAS POR PACIENTE\n");
            for (int i = 0; i < totalPacientes; i++) {
                int contagem = 0;
                for (int j = 0; j < totalConsultas; j++) {
                    if (consultas[j].paciente.codigo == pacientes[i].codigo) {
                        contagem++;
                    }
                }
                printf("Cod: %d | %-20s | Consultas: %d\n",
                       pacientes[i].codigo, pacientes[i].nome, contagem);

                if (contagem > maxAtendimentos) {
                    maxAtendimentos = contagem;
                    idxMaisAtendido = i;
                }
            }

            if (totalConsultas > 0) {
                printf("\nPaciente com maior numero de atendimentos: %s (%d consultas)\n",
                       pacientes[idxMaisAtendido].nome, maxAtendimentos);
            } else {
                printf("\nNenhuma consulta registrada ainda.\n");
            }
        }
    } while (opcao != 0);

    return 0;
}