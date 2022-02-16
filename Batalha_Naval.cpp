#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib> 
#define DIMENSAO 8
#define MEMORIA 100

using namespace std;

int main()
{
    string nome[MEMORIA];
    string tabuleiro_jogador[DIMENSAO][DIMENSAO] = {""};
    string tabuleiro_computador[DIMENSAO][DIMENSAO] = {""};
    string tabuleiro_capa[DIMENSAO][DIMENSAO] = {""}; 
    char linha_jogador[DIMENSAO] = {'1', '2', '3', '4', '5', '6', '7', '8'};
    char coluna_jogador[DIMENSAO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char linha_capa[DIMENSAO] = {'1', '2', '3', '4', '5', '6', '7', '8'};
    char coluna_capa[DIMENSAO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char linha_computador[DIMENSAO] = {'1', '2', '3', '4', '5', '6', '7', '8'};
    char coluna_computador[DIMENSAO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int linha;
    int linha_atk;
    int dificuldade;
    int memo = 0;
    int linha_numerica_computador = 0;
    int coluna_numerica_computador = 0;
    int pontos[MEMORIA] = {0};
    char resposta;
    char aux;
    char aux_atk;
    bool continuar = true;

    //Interface inicial:
    while ((continuar == true) && (memo < MEMORIA))
    {
        cout << "MMMMMMMMMMMMMMNk;.    .,xNMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMWd. .;lo:.  lNMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMX:  ;KMMX:  ,KMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMWx.  ,cc;. .dNMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMWOc.    .:kNMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMN0kkkkx;    ,xkkkk0NMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMO'                .kMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMKc,,,,,.    .',,,,:0MMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMWWWWWNo    cXWWWWWMMMMMMMMMMM" << endl;
        cout << "MMMMMXKWMMMMMMMMWo    cNMMMMMMMMWKXWMMMM" << endl;
        cout << "MMMNx'.c0WMMMMMMWo    cNMMMMMMWKl..oXMMM" << endl;
        cout << "MW0;    .dNMMMMMWo    cNMMMMMNx'    ,OWM" << endl;
        cout << "MWOl'   .oXMMMMMWo    cNMMMMMNd.   .ckNM" << endl;
        cout << "MMMMO.  .dNMMMMMWo    cNMMMMMWk.  .xWMMM" << endl;
        cout << "MMMMWx.  .c0WMMMWo    cNMMMWKl.  .oNMMMM" << endl;
        cout << "MMMMMWk,   .:xKNWo    cNWKkc.   'xNMMMMM" << endl;
        cout << "MMMMMMMXx,    .';.    .;,.    'oKMMMMMMM" << endl;
        cout << "MMMMMMMMMNOo;.            .,lkXMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMWXOxo,    'oxOXWMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMXo;,lKMMMMMMMMMMMMMMMMM" << endl;
        cout << "MMMMMMMMMMMMMMMMMMWWWWMMMMMMMMMMMMMMMMMM" << endl;
        cout << "________________________________________" << endl;
        cout << "        B A T A L H A   N A V A L       " << endl;
        cout << "________________________________________" << endl;
        cout << endl;
        cout << "Deseja continuar? Se sim digite 's',\n";
        cout << "caso contrario digite 'n'\n";
        cin >> resposta;

        //teste de continuação:
        if(resposta == 's')
        {
            continuar = true;
        }
        else
        {
            continuar = false;
            break;
        }

        //Armazenamento do nome:
        cin.get();
        cout << "Digite um nickname:" << endl;
        getline(cin, nome[memo]);
        for (int i = 0; i < 1; i++)
        {
            cout << "Selecione o nivel de dificuldade: " << endl;
            cout << "Digite o numero em questao!" << endl;
            cout << "1 - Facil" << endl;
            cout << "2 - Normal" << endl;
            cout << "3 - Dificil" << endl;
            cout << "4 - Lunatico" << endl;
            cin >> dificuldade;
            switch (dificuldade)
            {
                case 1:
                    dificuldade = 64;
                    break;
                case 2:
                    dificuldade = 46;
                    break;
                case 3:
                    dificuldade = 24;
                    break;
                case 4:
                    dificuldade = 10;
                    break;
                default:
                    cout << "inválido! tente novamente." << endl;
                    i--;
                    break;
                
            }
        }
        cout << endl;
        cout << endl;
        //Posicionamento do submarinos do jogador
        //São 8 submarinos a serem posicionados
        //Apenas mudará a posição para 0 se o número armazenado na posição for diferente,
        //evitando armazenar mais de duas vezes
        cout << "Defina as posicoes dos Submarinos (tamanho 1):   " << endl;
        cout << "_________________________________________________" << endl;
        cout << "*Representacao dos Submarinos:          S        " << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << "Posicao:" << endl;
            cin >> aux;
            cin >> linha; 
            switch (aux)
            {
            case 'A':
                if (tabuleiro_jogador[linha-1][0] == "")
                {
                    tabuleiro_jogador[linha-1][0] = " S ";
                }
                break;
            case 'B':
                if (tabuleiro_jogador[linha-1][1] == "")
                {
                    tabuleiro_jogador[linha-1][1] = " S ";
                }
                break;
            case 'C':
                if (tabuleiro_jogador[linha-1][2] == "")
                {
                    tabuleiro_jogador[linha-1][2] = " S ";
                }
                break;
            case 'D':
                if (tabuleiro_jogador[linha-1][3] == "")
                {
                    tabuleiro_jogador[linha-1][3] = " S ";
                }
                break;
            case 'E':
                if (tabuleiro_jogador[linha-1][4] == "")
                {
                    tabuleiro_jogador[linha-1][4] = " S ";
                }
                break;
            case 'F':
                if (tabuleiro_jogador[linha-1][5] == "")
                {
                    tabuleiro_jogador[linha-1][5] = " S ";
                }
                break;
            case 'G':
                if (tabuleiro_jogador[linha-1][6] == "")
                {
                    tabuleiro_jogador[linha-1][6] = " S ";
                }
                break;
            case 'H':
                if (tabuleiro_jogador[linha-1][7] == "")
                {
                    tabuleiro_jogador[linha-1][7] = " S ";
                }
                break;
            
            default:
                cout << "ERRO" << endl;
                i--;
                break;
            }
        }  
       

        // Posicionamento dos hidroaviões
        cout << "Defina as posicoes dos Hidroavioes (tamanho 4): " << endl;
        cout << "Digite o ponto central do hidroaviao!" << endl;
        cout << "_________________________________________________" << endl;
        cout << "*Representação dos Hidroavioes:       H          " << endl;
        cout << "                                       HHH         " << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << "Posicao:" << endl;
            cin >> aux;
            cin >> linha;
            if (linha != 1 && linha != 8)
            {
                switch (aux)
                {
                //Apenas pode haver entrada em colunas 
                case 'B':
                    // O 'if' testa se todas as colunas necessárias estão livres
                    if (tabuleiro_jogador[linha-1][1] == "" && tabuleiro_jogador[linha-1][0] == "" && tabuleiro_jogador[linha-1][2] == "")
                    {
                        tabuleiro_jogador[linha-1][0] = " H ";
                        tabuleiro_jogador[linha-1][1] = " H ";
                        tabuleiro_jogador[linha-1][2] = " H ";
                        //O segundo 'if' verifica se todas as linhas possíveis estão vagas
                        //A prioridade de inserção é a linha superior
                        if (tabuleiro_jogador[linha-2][1] == "")
                        {
                            tabuleiro_jogador[linha-2][1] = " H ";
        
                        }
                        else
                        {
                            if (tabuleiro_jogador[linha][1] == "")
                            {
                                tabuleiro_jogador[linha][1] = " H ";
            
                            }
                        } 
                    }
                    break;
                case 'C':
                    if (tabuleiro_jogador[linha-1][2] == "" && tabuleiro_jogador[linha-1][1] == "" && tabuleiro_jogador[linha-1][3] == "")
                    {
                        tabuleiro_jogador[linha-1][1] = " H ";
                        tabuleiro_jogador[linha-1][2] = " H ";
                        tabuleiro_jogador[linha-1][3] = " H ";
                        if (tabuleiro_jogador[linha-2][2] == "")
                        {
                            tabuleiro_jogador[linha-2][2] = " H ";
        
                        }
                        else
                        {
                            if (tabuleiro_jogador[linha][2] == "")
                            {
                                tabuleiro_jogador[linha][2] = " H ";
            
                            }
                        } 
                    }
                    break;
                case 'D':
                    if (tabuleiro_jogador[linha-1][3] == "" && tabuleiro_jogador[linha-1][2] == "" && tabuleiro_jogador[linha-1][4] == "")
                    {
                        tabuleiro_jogador[linha-1][2] = " H ";
                        tabuleiro_jogador[linha-1][3] = " H ";
                        tabuleiro_jogador[linha-1][4] = " H ";
                        if (tabuleiro_jogador[linha-2][2] == "")
                        {
                            tabuleiro_jogador[linha-2][2] = " H ";
        
                        }
                        else
                        {
                            if (tabuleiro_jogador[linha][2] == "")
                            {
                                tabuleiro_jogador[linha][2] = " H ";
            
                            }
                        } 
                    }
                    break;
                case 'E':
                    if ((tabuleiro_jogador[linha-1][4] == "") && (tabuleiro_jogador[linha-1][3] == "") && (tabuleiro_jogador[linha-1][5] == ""))
                    {
                        tabuleiro_jogador[linha-1][3] = " H ";
                        tabuleiro_jogador[linha-1][4] = " H ";
                        tabuleiro_jogador[linha-1][5] = " H ";
                        if (tabuleiro_jogador[linha-2][4] == "")
                        {
                            tabuleiro_jogador[linha-2][4] = " H ";
        
                        }
                        else
                        {
                            if (tabuleiro_jogador[linha][4] == "")
                            {
                                tabuleiro_jogador[linha][4] = " H ";
            
                            }
                        } 
                    }
                    break;
                case 'F':
                    if ((tabuleiro_jogador[linha-1][5] == "") && (tabuleiro_jogador[linha-1][4] == "") && (tabuleiro_jogador[linha-1][6] == ""))
                    {
                        tabuleiro_jogador[linha-1][4] = " H ";
                        tabuleiro_jogador[linha-1][5] = " H ";
                        tabuleiro_jogador[linha-1][6] = " H ";
                        if (tabuleiro_jogador[linha-2][5] == "")
                        {
                            tabuleiro_jogador[linha-2][5] = " H ";
        
                        }
                        else
                        {
                            if (tabuleiro_jogador[linha][5] == "")
                            {
                                tabuleiro_jogador[linha][5] = " H ";
            
                            }
                        } 
                    }
                    break;
                case 'G':
                    if ((tabuleiro_jogador[linha-1][6] == "") && (tabuleiro_jogador[linha-1][5] == "") && (tabuleiro_jogador[linha-1][7] == ""))
                    {
                        tabuleiro_jogador[linha-1][5] = " H ";
                        tabuleiro_jogador[linha-1][6] = " H ";
                        tabuleiro_jogador[linha-1][7] = " H ";
                        if (tabuleiro_jogador[linha-2][6] == "")
                        {
                            tabuleiro_jogador[linha-2][6] = " H ";
        
                        }
                        else
                        {
                            if (tabuleiro_jogador[linha][6] == "")
                            {
                                tabuleiro_jogador[linha][6] = " H ";
            
                            }
                        } 
                    }
                    break;
                
                default:
                    i--;
                    break;
                }
            }
        }

        // Posicionamento do Computador:
        srand(time(NULL));
        //Sorteio de submarino
        for (int i = 0; i < 2; i++)
        {
            linha_numerica_computador  = rand()%8;
            coluna_numerica_computador = rand()%8;
            if (tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador] == "")
            {
                tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador] = " S ";
                cout << linha_numerica_computador << "  " << coluna_numerica_computador << endl;
            }
            else
            {
                i--;
            }
        }
        //SOrteio de hidroaviao
        for (int i = 0; i < 2; i++)
        {
            linha_numerica_computador  = rand()%8;
            coluna_numerica_computador = rand()%8;
            if (tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador] == "" &&
                tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador-1] == "" &&
                tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador+1] == "" &&
                tabuleiro_computador[linha_numerica_computador+1][coluna_numerica_computador] == "") 
            {
                tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador] = " H ";
                tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador-1] = " H ";
                tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador+1] = " H ";
                tabuleiro_computador[linha_numerica_computador+1][coluna_numerica_computador] = " H ";
            }
            else
            {
                if (tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador] == "" &&
                tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador-1] == "" &&
                tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador+1] == "" &&
                tabuleiro_computador[linha_numerica_computador-1][coluna_numerica_computador] == "") 
                {
                    tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador] = " H ";
                    tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador-1] = " H ";
                    tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador+1] = " H ";
                    tabuleiro_computador[linha_numerica_computador-1][coluna_numerica_computador] = " H ";
                } 
                else
                {
                    i--;
                }
            }
        }
        
        cout << nome[memo] << ":"<< endl;
        cout << endl;
        cout << endl;
        cout << "   ";

        //Tabuleiro do jogador:
        for (int i = 0; i < DIMENSAO; i++)
        {
            cout << coluna_jogador[i] << "  ";
        }
        cout << endl;
        
        for (int l = 0; l < DIMENSAO; l++)
        {
            cout << linha_jogador[l] << " ";  
            for(int c = 0; c < DIMENSAO; c++)
            {
                if (tabuleiro_jogador[l][c] == "")
                {
                    cout << tabuleiro_jogador[l][c]  << " ~ ";
                }
                else
                {
                    cout << tabuleiro_jogador[l][c];
                }
            }  
            cout << endl;
        }

        cout << "___________" << endl;
        cout << "Computador:"<< endl;
        cout << endl;
        cout << endl;
        cout << "   ";

        // Tabuleiro capa
        for (int i = 0; i < DIMENSAO; i++)
        {
            cout << coluna_capa[i] << "  ";
        }
        cout << endl;
        
        for (int l = 0; l < DIMENSAO; l++)
        {
            cout << linha_capa[l] << " ";  
            for(int c = 0; c < DIMENSAO; c++)
            {
                if (tabuleiro_capa[l][c] == "")
                {
                    cout << tabuleiro_capa[l][c]  << " ~ ";
                }
                else
                {
                    cout << tabuleiro_capa[l][c];
                }
            }  
            cout << endl;
        }
        cout << endl;
        cout << endl;
        cout << endl;

        //Partida
        cout << "------VS------" << endl;
        cout << "Qual casa deseja atacar?" << endl;
        for (int i = 0; i < dificuldade; i++)
        {
            cout << "posicao: " << endl;
            //Sistema similar ao de seleção, com switch e if embutido para a confirmação.
            //!Pode ter problema com o case onde a entrada é o " ~ ".
            cin >> aux_atk;
            cin >> linha_atk;
            switch (aux_atk)
            {
            case 'A':
                if (tabuleiro_computador[linha-1][0] != "")
                {
                    tabuleiro_capa[linha-1][0] = " @ ";
                    pontos[MEMORIA]++;
                    cout << "pontos: " << pontos[MEMORIA] << endl;
                }
                else
                {
                    cout << "Errou... F total" << endl;
                    cout << "pontos: " << pontos[MEMORIA] << endl;
                }
                break;

             case 'B':
                if (tabuleiro_computador[linha-1][1] != "")
                {
                    tabuleiro_capa[linha-1][1] = " @ ";
                    pontos[MEMORIA]++;
                    cout << "pontos: " << pontos[MEMORIA] << endl;
                }
                else
                {
                    cout << "Errou... F total" << endl;
                    cout << "pontos: " << pontos[MEMORIA] << endl;
                }
                break;

             case 'C':
                if (tabuleiro_computador[linha-1][2] != "")
                {
                    tabuleiro_capa[linha-1][2] = " @ ";
                    pontos[MEMORIA]++;
                    cout << "pontos: " << pontos[MEMORIA] << endl;
                }
                else
                {
                    cout << "Errou... F total" << endl;
                    cout << "pontos: " << pontos[MEMORIA] << endl;
                }
                break;
             case 'D':
                if (tabuleiro_computador[linha-1][3] != "")
                {
                    tabuleiro_capa[linha-1][3] = " @ ";
                    pontos[MEMORIA]++;
                    cout << "pontos: " << pontos[MEMORIA] << endl;
                }
                else
                {
                    cout << "Errou... F total" << endl;
                    cout << "pontos: " << pontos[MEMORIA] << endl;
                }
                break;
             case 'E':
                if (tabuleiro_computador[linha-1][4] != "")
                {
                    tabuleiro_capa[linha-1][4] = " @ ";
                    pontos[MEMORIA]++;
                    cout << "pontos: " << pontos[MEMORIA] << endl;
                }
                else
                {
                    cout << "Errou... F total" << endl;
                    cout << "pontos: " << pontos[MEMORIA] << endl;
                }
                break;
             case 'F':
                if (tabuleiro_computador[linha-1][5] != "")
                {
                    tabuleiro_capa[linha-1][5] = " @ ";
                    pontos[MEMORIA]++;
                    cout << "pontos: " << pontos[MEMORIA] << endl;
                }
                else
                {
                    cout << "Errou... F total" << endl;
                    cout << "pontos: " << pontos[MEMORIA] << endl;
                }
                break;
             case 'G':
                if (tabuleiro_computador[linha-1][6] != "")
                {
                    tabuleiro_capa[linha-1][6] = " @ ";
                    pontos[MEMORIA]++;
                    cout << "pontos: " << pontos[MEMORIA] << endl;
                }
                else
                {
                    cout << "Errou... F total" << endl;
                    cout << "pontos: " << pontos[MEMORIA] << endl;
                }
                break;
             case 'H':
                if (tabuleiro_computador[linha-1][7] != "")
                {
                    tabuleiro_capa[linha-1][7] = " @ ";
                    pontos[MEMORIA]++;
                    cout << "pontos: " << pontos[MEMORIA] << endl;
                }
                else
                {
                    cout << "Errou... F total" << endl;
                    cout << "pontos: " << pontos[MEMORIA] << endl;
                }
                break;
            
            default:
                    cout << "POSIÇÃO INVÁLIDA! Tente novamente" << endl;
                    i--;
                break;
            }
        }
        memo++;
    }
    cout << "_______________________________________" << endl;
    cout << "Sua pontuação = " << pontos[MEMORIA] << endl;
    return 0;

}
