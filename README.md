# Trabalho-1
Repositório contendo as especificações do Trabalho 1 da disciplina de LP1

## Compilando

use comando ```make``` dentro do diretório "/build".

## Executando

Use o comando ```./program ../data/nome_do_arquivo_de_palavras.txt ../data/nome_do_arquivo_de_scores.txt``` dentro do diretório "/build".

EX:
```
./program ../data/palavras.txt ../data/scores.txt
```

## Executanto testes

Teste de níveis de dificuldade: Use o comando ```./program ../data/dif_palavras.txt ../data/scores.txt``` dentro do diretório "/build".

Teste de casos de erros: Use os comando ```./program ../data/err_palavras_N.txt ../data/scores.txt``` e 
```./program ../data/palavras.txt ../data/err_scores_N.txt``` dentro do diretório "/build", trocando "N" pelo número do teste.

Todos os testes de erro:
```
./program ../data/err_palavras_1.txt ../data/scores.txt
./program ../data/err_palavras_2.txt ../data/scores.txt
./program ../data/err_palavras_3.txt ../data/scores.txt

./program ../data/palavras.txt ../data/err_scores_1.txt
./program ../data/palavras.txt ../data/err_scores_2.txt
./program ../data/palavras.txt ../data/err_scores_3.txt
./program ../data/palavras.txt ../data/err_scores_4.txt
```

## Limitações e funcionalidades não implementadas

O programa não possui nenhuma limitação de funcionalidade aparente e nem funcionalidades não implementadas.