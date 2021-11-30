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

# Avaliação

## Código | Funcionalidades
1. Classe forca 10/10

2. Interface textual 10/10

3. Execução completa do jogo 13/15

4. Validação dos arquivos de texto 5/5

5. Arquivos de teste de validação dos casos de erro 5/5

6. Arquivos de teste de validação dos níveis de dificuldade 5/5

7. Observações gerais
- Você poderia ter modularizado o main em funções ou criado outra classe para exibir
a interface, ainda assim ficou muito bom o código.

## Código | Boas práticas

1. Documentação do código e readme 10/10

2. Organização e indentação 5/10

3. Compilação automatizada 5/5

