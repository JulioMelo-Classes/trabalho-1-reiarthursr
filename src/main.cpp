#include "Forca.hpp"

using namespace std;

int main(int argc, char *argv[]){
    cout<<">>> Lendo arquivos de palavras ["<<argv[1]<<"] e scores ["<<argv[2]<<"], por favor aguarde.."<<endl<<
    "--------------------------------------------------------------------"<<endl;
    Forca forca(argv[1], argv[2]);//!< criar forca

    

    //! validano arquivos
    auto validade = forca.eh_valido();
    if(validade.first)//! se for válido
        cout<<">>> Arquivos OK!"<<endl<<
        "--------------------------------------------------------------------"<<endl;
    else//! se não for válido
    {
        cout<<"Erro pelo motivo: "<<validade.second<<endl;
        return EXIT_FAILURE;//! fechando o programa
    }

    //! gerando semente
    auto seed = time(0);
    srand(seed);

    while(true)
    {
        forca.carrega_arquivos();//! carregar os arquivos
        int opcao;//!< opção escolhida pelo jogador

        //! tela inicial!
        while (true)//! só sai da tela inicial quando inicia o jogo
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

            if(opcao==1) break;//! sair da tela inicial caso comece o jogo
            else if(opcao==2)//! ver scores anteriores
            {
                //! fazer tela de scores
                forca.imprimir_scores();

                cout<<"Digite '1' para retornar a tela inicial."<<endl;
                while(cin>>opcao)
                    if(opcao==1) break;
            }
        }
        
        //! escolher dificuldade
        cout<<"Vamos iniciar o jogo! Por favor escolha o nível de dificuldade"<<endl<<
        "1 - Fácil"<<endl<<
        "2 - Médio"<<endl<<
        "3 - Difícil"<<endl<<
        "Sua escolha: ";
        while (cin>>opcao)
        {
            if(opcao>=1 && opcao<=3)//! setando dificuldade
            {
                if(opcao==1)
                {
                    forca.set_dificuldade(Forca::Dificuldade::FACIL);
                    cout<<"Iniciando o Jogo no nível Fácil, será que você conhece essa palavra?"<<endl;
                }
                else if(opcao==2)
                {
                    forca.set_dificuldade(Forca::Dificuldade::MEDIO);
                    cout<<"Iniciando o Jogo no nível Médio, será que você conhece essa palavra?"<<endl;
                }
                else 
                {
                    forca.set_dificuldade(Forca::Dificuldade::DIFICIL);
                    cout<<"Iniciando o Jogo no nível Difícil, será que você conhece essa palavra?"<<endl;
                }
                break;
            }
            else cout<<"Opção inválida. Digite uma das opções acima."<<endl<<
                "Sua escolha: ";
        }

        //! jogo
        int pontos = 0;//!< pontos que o jogador marcou
        forca.clear_palavras_acertadas();//! resetar palavras acertadas
        while (true)
        {
            //! resetando para tentar outra palavra
            forca.set_tentativas_restantes(6);
            string palavra_incompleta = forca.proxima_palavra();//!< algo como "_ _ _ _ ... _"
            string letras_palpitadas = palavra_incompleta;//!< letras que o jogador já palpitou

            if(palavra_incompleta == "")//! se acabar as palavras
            {
                cout<<"Acabaram as palavras dessa dificuldade!"<<endl;
                break;
            }

            //! adivinhando uma palavra
            while (true)
            {
                forca.imprimir_boneco();
                cout<<palavra_incompleta<<endl<<
                "Pontos: "<<pontos<<endl<<
                "Palpite: ";
                char palpite;//!< letra palpitada pelo jogador
                while (cin>>palpite)
                {
                    palpite = toupper(palpite);//! deixar em maiúsculo
                    if(letras_palpitadas.find_first_of(palpite) != string::npos)
                        cout<<"Essa letra já foi palpitada. Digite outro palpite."<<endl<<"Palpite: ";
                    else
                    {
                        //! adicionando a palpite ao vetor de letras palpitadas
                        letras_palpitadas += palpite;

                        if(forca.palpite({palpite}))//! se palpite estiver na palavra
                        {
                            cout<<"Muito bem! A palavra contém a letra "<<palpite<<"!"<<endl;
                            //! adiciona as letras e adiciona pontos com base na quantidade de letras adicionadas
                            pontos += forca.adicionar_letra(&palavra_incompleta, palpite);
                        }
                        else
                        {
                            cout<<"Meh, não achei a letra "<<palpite<<"! :<"<<endl;
                            pontos--;
                        }

                        break;
                    }
                }

                //! se acabar as tentativas
                if(forca.game_over())
                {
                    cout<<"O jogo acabou, a palavra era "<<forca.get_palavra_atual()<<"!"<<endl;
                    break;
                }
                //! se descobriu todas as letras
                if(palavra_incompleta.find_first_of('_') == std::string::npos)
                {
                    cout<<"Você venceu, a palavra era "<<forca.get_palavra_atual()<<"!"<<endl;
                    forca.add_palavra_acertada();//! adicionar ao vetor de palavras acertadas
                    pontos += 2;
                    if(forca.get_tentativas_restantes() == 6)//! se não errar nenhuma vez
                        pontos++;
                    break;
                }
            }
            
            if(forca.game_over()) break;//! se acabar as tentativas

            //! escolher se deve continuar
            cout<<"Deseja continuar?"<<endl<<
            "1 - Continuar"<<endl<<
            "2 - Parar"<<endl<<
            "Sua escolha: ";
            while (cin>>opcao)
            {
                if(opcao==1 || opcao==2) break;
                else cout<<"Opção inválida. Digite uma das opções acima."<<endl<<
                    "Sua escolha: ";
            }
            if(opcao==2) break;//! caso jogador escolha parar
        }
        
        //! salvar score no arquivo
        string nome;
        cout<<"Digite seu nome: ";
        cin>>nome;
        forca.salvar_score(nome, pontos);
    }

    return EXIT_SUCCESS;
}