#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <algorithm>
 
//! A classe Forca.
/*! É a classe onde se pode criar um jogo da forca.
* \author Arthur Soares Ramalho.
* \since 15/11/2021
* \version 1.0
*/

class Forca {
    public:
        //! Enumeração Dificuldade.
        /*! indica a dificuldade do jogo */
        enum Dificuldade{
            FACIL, MEDIO, DIFICIL
        };

        struct SCORE
        {
            std::string dificuldade;
            std::string nome;
            std::vector<std::string> palavras_acertadas;
            int pontuacao;
        };//!< armazena um score!
    private:
        std::vector<SCORE> m_scores; //!< scores dos jogadores!

        std::vector<std::string> m_palavras_acertadas; //!< palavras que o jogador acertou!
       
        std::vector< std::pair<std::string, int> > m_palavras; //!< palavras e sua ocorrência no Corpus
 
        std::string m_arquivo_scores; //!< nome do arquivo contendo os scores
 
        std::string m_arquivo_palavras; //!< nome do arquivo contendo as palavras
 
        Dificuldade d = Dificuldade::FACIL; //!< dificuldade do jogo
 
        std::string m_palavra_atual; //!< palavra sendo testada atualmente
 
        int m_tentativas_restantes = 6; //!< tentativas restantes

        int m_cont_medio = 2; //!< contador de partidas para dificuldade média!

        int m_frequencia_media; //!< frequência média das palavras
   
    public:
        /**
         * Cria a classe Forca
         * O construtor pode ou não validar os arquivos de entrada, no entanto, mesmo com 
         * os arquivos inválidos o objeto deve ser construído. Para o caso de arquivos de palavras
         * ou scores inválidos, use o método eh_valido.
         * @param palavras o arquivo que contém as palavras
         * @param scores o nome do arquivo que contém os scores
         * @see eh_valido
         */
        Forca( std::string palavras, std::string scores );
       
 
        /**
         * Valida os arquivos de entrada de acordo com as especificações.
         * Ao validar os arquivos, no caso de arquivos inválidos, este método deve retornar a 
         * razão correspondente de acordo com as especificações.
         * @return {T,""} se os arquivos estiverem válidos, {F,"razão"} caso contrário.
         */
        std::pair<bool, std::string> eh_valido();
 
        /**
         * Carrega os arquivos de scores e palavras preenchendo **ao menos** a estrutura m_palavras
         */
        void carrega_arquivos();
 
        /**
         * Modifica a dificuldade do jogo.
         * De acordo com a dificuldade configurada, o método proxima_palavra retornará palavras
         * diferentes.
         * @param d a dificuldade desejada
         * @see proxima_palavra
         */
        void set_dificuldade(Dificuldade d);
 
        /**
         * Retorna a próxima palavra de acordo com a dificuldade atual.
         * Este método deve atualizar o atributo m_palavra_atual e retornar a palavra um texto no formato
         * "_ _ _ _ ... _" dependendo do tamanho de m_palavra_atual. O método também deve sortear as 
         * letras que devem aparecer dependendo do nível de dificuldade.
         * @return a próxima palavra do conjunto de palavras disponível de acordo com a dificuldade atual.
         */
        std::string proxima_palavra();
 
        /**
         * Retorna a palavra atual que está sendo jogada.
         * @return o valor do atributo m_palavra_atual.
         */
        std::string get_palavra_atual();
 
        /**
         * Testa se uma letra pertence á palavra atual, retorna T se a letra pertence.
         * Este método testa se uma letra pertence à palavra atual e retorna True caso pertença. 
         * Caso contrário, o método deve atualizar o atributo m_tentativas_restantes, decrementando 
         * em 1, e retornar False.
         * @param palpite uma letra, que deve ser testada se pertence à palavra.
         * @return T se a palpite pertence à palavra, F caso contrário.
         */
        bool palpite(std::string palpite);
 
        /**
         * Em caso de Game Over este método deve retornar T.
         * @return T caso o m_tentativas_restantes do jogo esteja igual a 0, F caso contrário.
         */
        bool game_over();
 
        /**
         * Atualiza o número de tentativas restantes.
         * Este método é útil no caso do jogador escolher continuar o jogo.
         * @param tentativas atualiza o valor da variável m_tentativas_restantes.
         */
        void set_tentativas_restantes(int tentativas);
 
        /**
         * Retorna a quantidade de tentativas restantes.
         * @return a quantidade de tentativas restantes.
         */
        int get_tentativas_restantes();

        /**
         * Este método imprime todos os scores dos jogadores na tela.
         * É usado quando o jogador pede para ver os scores anteriores!
         */
        void imprimir_scores();

        /**
         * Este método calcula e seta a frequancia_media!
         */
        void calc_frequencia_media();

        /**
         * Este método imprime o boneco da forca com base nas m_tentivas_restantes.
         * É usado na hora de imprimir a tela do jogo da forca!
         */
        void imprimir_boneco();

        /**
         * Este método salva o score do jogador atual no arquivo de scores.
         * É usado assim que o jogo acaba!
         * @param nome nome do jogador a ser salvo no arquivo de scores.
         * @param pontos a pontuação que o jogador fez durante o jogo. também irá ser salvo no arquivo.
         */
        void salvar_score(std::string nome, int pontos);

        /**
         * Este método serve para adicionar letras na string da palavra incompleta, retornando os pontos recebidos.
         * É usado quando o jogador acerta algum palpite, calculando e retornando os pontos que ele ganhou!
         * @param palavra_incompleta é a palavra a ser adicionado as letras.
         * @param letra é a letra que será adicionado a palavra, somente nos espaços vazios "_".
         * @return quantidadee de pontos ganhos, baseado na quantidade de letras adicionadas.
         */
        int adicionar_letra(std::string* palavra_incompleta, char letra);

        /**
         * Este método adiciona a m_palavra_atual no vetor m_palavras_acertadas.
         * É usado quando o jogador acerta a palavra atual!
         */
        void add_palavra_acertada();

        /**
         * Este método limpa o vetor m_palavras_acertadas.
         * É útil quando necessário resetar o jogo!
         */
        void clear_palavras_acertadas();

        /**
         * Este método serve para dividir uma linha em várias partes com base num delimitador.
         * Serve para ler os arquivos de forma fácil, dividindo as variáves nescessárias!
         * @param linha é a linha a ser dividida.
         * @param delimiter é a divisão entre cada parte. ele não entrará em nenhuma das strings do retorno.
         * @return retorna o vetor de string onde contem cada parte da string que foi dividida.
         */
        std::vector<std::string> dividir_linha(std::string linha, char delimiter);

        /**
         * Este método serve para verificar se uma string é um número.
         * É útil para verificar se algumas das variáveis contidas nos arquivos são váliddas ou não!
         * @param str a string a ser verificada se é um número ou não.
         * @return T se a string recebida for um número e F caso contrário.
         */
        bool isNumber(const std::string& str);

};
