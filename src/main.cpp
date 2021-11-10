#include "Forca.hpp"

using namespace std;

int main(int argc, char *argv[]){
  //imprime todos os argumentos recebidos na execução
  //do programa, para testar, compile e faça
  //./a.out arg1 arg2 arg2
  //o primeiro argumento é sempre o nome 
  //do programa (a.out, neste exemplo)
  for(int i=0; i<argc; i++)
    cout<<"Argumento["<<i<<"]: "<<argv[i]<<endl;
  return 0;
}