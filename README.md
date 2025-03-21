# Ring Camarada

## Sobre o problema

Box é um esporte realmente violento. Para compensar, existe um código de conduta para manter a honra e o companheirismo em alto nível no ringue. Uma das regras mais conhecidas deste código de conduta é evitar bater no oponente abaixo da cintura ou acima do pescoço.

Dadas as alturas da cintura e pescoço de um adversário, e as alturas de um conjunto de socos, calcular quantos desses golpes são justos de acordo com a regra acima.

### Entrada

A primeira linha contém três inteiros **W, N e P**, representando respectivamente a altura da cintura do adversário, a altura do pescoço e o número de socos lançados **(1 <= W <= N <= 200 e 1 <= P <= 100)**. A segunda linha contém **P** inteiros **H1, H2, ..., Hp** **(1 <= Hi <= 200 para i = 1, 2, ..., P)** indicando as alturas dos socos. Todas as alturas são dadas em centímetros.

### Saída

Retorne um inteiro representando o número de golpes que são justos, de acordo com o Código de conduta.

## Modelagem do Problema

### Variáveis

- `W`: Altura da cintura do adversário.
- `N`: Altura do pescoço do adversário.
- `P`: Número de socos lançados.
- `H`: Lista de alturas dos socos.

### Funções/Procedimentos

- `solve_warmup(FILE* ptr_in_file, char* file_name, const char* warmup_instance)`: Função principal que resolve o problema.
- `check_warmup_solution(FILE* ptr_in_file, char* file_name, const char* warmup_instance)`: Função que verifica a solução gerada.

### Estruturas

- Arquivos de entrada e saída organizados em diretórios específicos.
- Funções de leitura e escrita de arquivos.

## Solução

### Algoritmo

1. Ler os valores de `W`, `N` e `P` do arquivo de entrada.
2. Ler as alturas dos socos.
3. Contar quantos socos estão dentro do intervalo [W, N].
4. Escrever o resultado no arquivo de saída.

### Código

```c
void solve_warmup(FILE* ptr_in_file, char* file_name, const char* warmup_instance) {
    FILE *fwsolptr;
    int W, N, P;
    int golpes_justos_atingidos = 0;

    // Lê a primeira linha do arquivo de entrada
    fscanf(ptr_in_file, "%d %d %d", &W, &N, &P);

    // Lê as alturas dos socos e conta os golpes justos
    for (int i = 0; i < P; i++) {
        int altura_do_soco;
        fscanf(ptr_in_file, "%d", &altura_do_soco);
        if (altura_do_soco >= W && altura_do_soco <= N) {
            golpes_justos_atingidos++;
        }
    }

    // Escreve o resultado no arquivo de solução
    fwsolptr = fopen(SOLUTION_FILE, "w");
    if (fwsolptr == NULL) {
        printf("File '%s' can't be opened\n", SOLUTION_FILE);
        exit(1);
    }
    fprintf(fwsolptr, "%d\n", golpes_justos_atingidos);
    fclose(fwsolptr);
}
```


### Execução
#### Compilação
Para compilar o código, execute os comandos:

```bash
cd warmup
gcc -Wall warmup.c solver/warmup_solver.c -o warmup
```
### Execução
Para executar o código após compilar, execute o comando:
```bash
./warmup
```

### Desempenho
#### Testes

O programa foi testado utilizando as instâncias de entrada localizadas em ``` ring-camarada/input/```. O desempenho foi avaliado com base no número de instâncias de testes com sucesso e com falha.

Instâncias de testes com sucesso: **51** \
Instâncias de testes com falha: **0**


