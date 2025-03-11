# Ring Camarada

## Sobre o problema: 

### 

Box é um esporte realmente violento. Para compensar, existe um código de conduta para manter a honra e o companheirismo em alto nível no ringue. Uma das regras mais conhecidas deste código de conduta é evitar bater no oponente abaixo da cintura ou acima do pescoço.

Dadas as alturas da cintura e pescoço de um adversário, e as alturas de um conjunto de socos, calcular quantos desses golpes são justos de acordo com a regra acima.

***Entrada:*** A primeira linha contém três inteiros ***W, N e P,*** representando respectivamente a altura da cintura do adversário, a altura do pescoço e o número de socos lançados ***(1 <= W <= N 200 e 1 <= P <= 100).*** A segunda linha contém ***P*** inteiros ***H1; H2; ... Hp (1 <= Hi <= 200 para i = 1; 2;...; P)*** indicando as alturas dos socos. Todas as alturas são dadas em centímetros.

***Saída:*** Retorne um inteiro representando o número de golpes que são justos, de acordo com o Código de conduta.
  
## Warm-Up

Para compilar o código:

`cd warmup`

`gcc -Wall warmup.c solver/warmup_solver.c -o warmup`

Para executar o código:

`./warmup`

