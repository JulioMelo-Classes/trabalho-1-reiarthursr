#include "Forca.hpp"

using namespace std;

int main(int argc, char *argv[]){
    Forca forca(argv[1], argv[2]);//criar forca

    cout<<">>> Lendo arquivos de palavras ["<<argv[1]<<"] e scores ["<<argv[2]<<"], por favor aguarde.."<<endl<<
    "--------------------------------------------------------------------"<<endl;

    //validano arquivos
    auto validade = forca.eh_valido();
    if(validade.first)//se for válido
        cout<<">>> Arquivos OK!"<<endl<<
        "--------------------------------------------------------------------"<<endl;
    else//se não for válido
    {
        cout<<"Erro pelo motivo: "<<validade.second<<endl;
        return EXIT_FAILURE;//fechando o programa
    }

    while(true)
    {
        int opcao;//opção escolhida pelo jogador

        //tela inicial!
        while (true)//só sai da tela inicial quando inicia o jogo
        {
            cout<<"Bem vindo ao Jogo Forca! Por favor escolha uma das opções"<<endl<<
            "1 - Iniciar o jogo"<<endl<<
            "2 - Ver scores anteriores"<<endl<<
            "Sua escolha: ";
            while (cin>>opcao)
            {
                if(opcao==1 || opcao==2) break;
                else cout<<"Opção inválida. Digite uma das opções acima."<<endl<<
                "Sua escolha: ";
            }

            if(opcao==1) break;//sair da tela inicial caso comece o jogo
            else if(opcao==2)//ver scores anteriores
            {
                //fazer tela de scores-----------------------------------------------------------------------
                cout<<"Digite '1' para retornar a tela inicial."<<endl;
                while(cin>>opcao)
                    if(opcao==1) break;
            }
        }
        
        //escolher dificuldade
        cout<<"Vamos iniciar o jogo! Por favor escolha o nível de dificuldade"<<endl<<
        "1 - Fácil"<<endl<<
        "2 - Médio"<<endl<<
        "3 - Difícil"<<endl<<
        "Sua escolha: ";
        while (cin>>opcao)
        {
            if(opcao==1 || opcao==2 || opcao==3) break;
            else cout<<"Opção inválida. Digite uma das opções acima."<<endl<<
            "Sua escolha: ";
        }
    }

    return EXIT_SUCCESS;
}