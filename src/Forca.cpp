#include "Forca.hpp"

Forca::Forca( std::string palavras, std::string scores )
{
    m_arquivo_palavras = palavras;
    m_arquivo_scores = scores;
}

std::pair<bool, std::string> Forca::eh_valido()
{
    std::string linha;//linha lida pelo arquivo
    std::vector<std::string> linhas;
    std::vector<std::string> var_linha;//variáveis que estão na linha
    std::pair<bool, std::string> retorno = {true, ""};

    //abrindo arquivo de palavras
    std::ifstream arquivo_pala;
    arquivo_pala.open(m_arquivo_palavras);
    if(arquivo_pala.is_open())
    {
        while (getline(arquivo_pala, linha))
            linhas.push_back(linha);
        for (size_t i = 0; i < linhas.size(); i++)
        {
            linha = linhas[i];

            if(i < linhas.size()-1) linha.erase(linha.size()-1);
            var_linha = dividir_linha(linha, '	');//dividindo linha

            if (var_linha[0].find_first_not_of("abcçdefghijklmnopqrstuvwxyzABCÇDEFGHIJKLMNOPQRSTUVWXYZ-")
            != std::string::npos)
            {
                retorno={false, "A palavra da linha possui caracteres inválidos: <"+linha+">"};
                break;
            }

            if(var_linha.size()<2)
            {
                retorno={false, "A linha não possui frequência: <"+linha+">"};
                break;
            }
            
            if(var_linha.size()>2)
            {
                retorno={false, "A linha possui mais de 2 variáveis: <"+linha+">"};
                break;
            }

            if(!isNumber(var_linha[1]))
            {
                retorno={false, "A frequência da linha não é um número: <"+linha+">"};
                break;
            }

            if(var_linha[0].size() < 4)
            {
                retorno={false, "Palavra com tamanho menor do que 4 na linha: <"+linha+">"};
                break;
            }
        }
    }
    else retorno={false, "Arquivo de palavras não abriu: "+m_arquivo_palavras};

    arquivo_pala.close();//fechar arquivo
    if(!retorno.first) return retorno;//se der erro, retorna erro

    linhas.clear();

    //abrindo arquivo de scores
    std::ifstream arquivo_sco;
    arquivo_sco.open(m_arquivo_scores);
    if(arquivo_sco.is_open())
    {
        while (getline(arquivo_sco, linha))
            linhas.push_back(linha);
        for (size_t i = 0; i < linhas.size(); i++)
        {
            linha = linhas[i];

            if(i < linhas.size()-1) linha.erase(linha.size()-1);
            var_linha = dividir_linha(linha, ';');//dividindo linha

            if(var_linha.size()<4)
            {
                return {false, "A linha possui menos de 3 ';': <"+linha+">"};
                break;
            }
            
            if(var_linha.size()>4)
            {
                return {false, "A linha possui mais de 3 ';': <"+linha+">"};
                break;
            }

            if(var_linha[0] == "")
            {
                return {false, "Campo 'nível de dificuldade' vazio na linha: <"+linha+">"};
                break;
            }

            if(var_linha[1] == "")
            {
                return {false, "Campo 'nome' vazio na linha: <"+linha+">"};
                break;
            }
            
            if(var_linha[3] == "")
            {
                return {false, "Campo 'pontuação' vazio na linha: <"+linha+">"};
                break;
            }
        }
    }
    else return {false, "Arquivo de scores não abriu: "+m_arquivo_scores};

    arquivo_sco.close();//fechar arquivo
    if(!retorno.first) return retorno;//se der erro, retorna erro

    return retorno;
}

void Forca::carrega_arquivos()
{
    std::string linha;//linha lida pelo arquivo
    std::vector<std::string> linhas;
    std::vector<std::string> var_linha;//variáveis que estão na linha
    std::pair<bool, std::string> retorno = {true, ""};

    //abrindo arquivo de palavras
    std::ifstream arquivo_pala;
    arquivo_pala.open(m_arquivo_palavras);
    if(arquivo_pala.is_open())
    {
        while (getline(arquivo_pala, linha))
            linhas.push_back(linha);
        for (size_t i = 0; i < linhas.size(); i++)
        {
            linha = linhas[i];

            if(i < linhas.size()-1) linha.erase(linha.size()-1);
            var_linha = dividir_linha(linha, '	');//dividindo linha

            m_palavras.push_back({ var_linha[0], stoi(var_linha[1]) });//armazenando no vetor de palavras
        }
    }
    else std::cout<<"Erro ao abrir arquivo de palavras["<<m_arquivo_palavras<<"]"<<std::endl;
    arquivo_pala.close();//fechar arquivo

    linhas.clear();

    //abrindo arquivo de scores
    SCORE score;//armazenar um score temporariamente
    std::ifstream arquivo_sco;
    arquivo_sco.open(m_arquivo_scores);

    if(arquivo_sco.is_open())
    {
        while (getline(arquivo_sco, linha))
            linhas.push_back(linha);
        for (size_t i = 0; i < linhas.size(); i++)
        {
            linha = linhas[i];

            if(i < linhas.size()-1) linha.erase(linha.size()-1);
            var_linha = dividir_linha(linha, ';');//dividindo linha

            score.dificuldade = var_linha[0];
            score.nome = var_linha[1];
            score.palavras_acertadas = dividir_linha(var_linha[2], ',');
            score.pontuacao = stoi(var_linha[3]);

            m_scores.push_back(score);//armazenando no vetor
        }
    }
    else std::cout<<"Erro ao abrir arquivo de scores["<<m_arquivo_scores<<"]"<<std::endl;
    arquivo_sco.close();//fechar arquivo

    calc_frequencia_media();
    //criar sub-vetores de palavras
}

void Forca::set_dificuldade(Forca::Dificuldade d)
{
    this->d = d;
}

std::string Forca::proxima_palavra()
{
    switch (d)
    {
    case FACIL:
        /* code */
        break;

    case MEDIO:
        /* code */
        break;

    case DIFICIL:
        /* code */
        break;
    
    default:
        std::cout<<"Erro: Dificuldade inválida"<<std::endl;
        return "";
        break;
    }
    return "";
}

std::string Forca::get_palavra_atual()
{
    return m_palavra_atual;
}

bool Forca::palpite(std::string palpite)
{
    if(m_palavra_atual.find_first_of(palpite) != std::string::npos)//se pertencer
        return true;
    else
    {
        m_tentativas_restantes--;
        return false;
    }
}

bool Forca::game_over()
{
    if(m_tentativas_restantes <= 0) return true;//acabou as tentativas
    else return false;//ainda possui tentativas
}

void Forca::set_tentativas_restantes(int tentativas)
{
    m_tentativas_restantes = tentativas;
}

int Forca::get_tentativas_restantes()
{
    return m_tentativas_restantes;
}

void Forca::imprimir_scores()
{
    for (auto it = m_scores.begin(); it != m_scores.end(); it++)
    {
        std::cout<<"Jogador: ["<<it->nome<<"] Dificuldade: ["<<it->dificuldade<<
        "] Pontuação: ["<<it->pontuacao<<"]"<<std::endl<<"Palavras acertadas: [";
        for (auto it2=it->palavras_acertadas.begin(); it2!=it->palavras_acertadas.end(); it2++)
        {
            std::cout<<*it2;
            if(it2 != it->palavras_acertadas.end()-1) std::cout<<", ";
        }
        std::cout<<"]"<<std::endl<<
        "--------------------------------------------------------------------"<<std::endl;
    }
}

void Forca::calc_frequencia_media()
{
    size_t soma_frequencia=0;//soma das frequências
    for (auto it = m_palavras.begin(); it != m_palavras.end(); it++)//soma todas as frequências
        soma_frequencia += it->second;//soma uma frequência ao total

    m_frequencia_media = soma_frequencia/m_palavras.size();//calculando frequência média
}

std::vector<std::string> Forca::dividir_linha(std::string linha, char delimiter)
{
    std::vector<std::string> result;
	std::string rest = linha, block;
	size_t operator_position = rest.find_first_of(delimiter);
	while (operator_position != std::string::npos) {
		block = rest.substr(0, operator_position);
		rest = rest.substr(operator_position + 1);
		operator_position = rest.find_first_of(delimiter);
        if(block[0] == ' ') block.erase(0, 1);
		result.push_back(block);
	}
	
	if (rest.length() > 0)
    {
        if(rest[0] == ' ') rest.erase(0, 1);
		result.push_back(rest);
    }

	return result;
}

bool Forca::isNumber(const std::string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}