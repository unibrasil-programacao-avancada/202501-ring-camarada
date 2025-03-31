#include "../include/warmup_solver.h"

const char OUTPUT_DIR[] = "output/";
const char SOLUTION_FILE[] = "solution.txt";

void solve_warmup(FILE* ptr_in_file, char* file_name, const char* warmup_instance) {

    FILE *fwsolptr;
    char out_file[100];

    out_file[0] = '\0';
    strcat(out_file, warmup_instance);
    strcat(out_file, OUTPUT_DIR);
    strcat(out_file, file_name);

    // Creating solution file
    fwsolptr = fopen(SOLUTION_FILE, "w");
    if (fwsolptr == NULL) {
        printf("File '%s' can't be opened\n", SOLUTION_FILE);
        exit(1);
    }

    // Declara��o de vari�veis para armazenar as informa��es do problema
    int W, N, P; // W (cintura), N (pesco�o), P (n�mero de socos)
    int golpes_justos_atingidos = 0;  // Contador de golpes justos

    // L� a primeira linha do arquivo de entrada, que cont�m W, N e P
    fscanf(ptr_in_file, "%d %d %d", &W, &N, &P);

    // L� as alturas dos socos e conta quantos s�o "golpes justos"
    // Um golpe � considerado justo se sua altura estiver entre W (m�nimo) e N (m�ximo)
    for (int i = 0; i < P; i++) {
        int altura_do_soco;

        // L� a altura do soco a partir do arquivo de entrada
        fscanf(ptr_in_file, "%d", &altura_do_soco);

        // Verifica se a altura do soco est� dentro do intervalo de altura considerado justo
        if (altura_do_soco >= W && altura_do_soco <= N) {
            golpes_justos_atingidos++;  // Se for justo, incrementa o contador
        }
    }

    // Escreve o n�mero de golpes justos atingidos no arquivo de solu��o
    fprintf(fwsolptr, "%d\n", golpes_justos_atingidos);

    // Fecha o arquivo de solu��o ap�s gravar o resultado
    fclose(fwsolptr);
}

int check_warmup_solution(const char* file_name, const char* warmup_instance) {

    FILE *fanswer, *fsolution;
    char answer_line[100], solution_line[100], answer_file[100];
    int is_correct = 1;

    answer_file[0] = '\0';
    strcat(answer_file, warmup_instance);
    strcat(answer_file, OUTPUT_DIR);
    strcat(answer_file, file_name);

    // Opening answer file
    fanswer = fopen(answer_file, "r");
    if (fanswer == NULL) {
        printf("File '%s' can't be opened\n", answer_file);
        exit(1);
    }

    // Opening solution file
    fsolution = fopen(SOLUTION_FILE, "r");
    if (fsolution == NULL) {
        printf("File '%s' can't be opened\n", SOLUTION_FILE);
        exit(1);
    }

    // Reading from the answer file and comparing with the solution file
    while (fgets(answer_line, 100, fanswer)) {

        fgets(solution_line, 100, fsolution);

        if (strcmp(answer_line, solution_line)) {
            is_correct = 0;
            break;
        }
    }

    fclose(fanswer);
    fclose(fsolution);

    return is_correct;
}
