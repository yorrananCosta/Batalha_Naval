//Autor: Yorranan Neves de Almeida Costa
//Função: Jogo de batalha naval humano VS computador
//Data: 01 nov. 2021
//Trabalho de Programação de Computadores I
#include <iostream>
#include <ctime>    //lib para rand e srand 
#include <string>   //para teste ASCII
#include <cstdlib>  //para color
#include <windows.h>//uso do sistema
#include <climits>  //para usar limites de variaveis, ex.: INT_MIN
#define DIMENSAO 8  //tamanho de linhas e colunas
#define MEMORIA 100 //número máximo de rodadas

using namespace std;

int main()
{
    string nome_1;                                                                  //top 1 do ranking
    string nome[MEMORIA];                                                           //nome do jogador
    char linha_jogador[DIMENSAO] = {'1', '2', '3', '4', '5', '6', '7', '8'};        //posição da linha de jogador
    char coluna_jogador[DIMENSAO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};       //posição da coluna de jogador
    char linha_capa[DIMENSAO] = {'1', '2', '3', '4', '5', '6', '7', '8'};           //posição da linha na matriz capa
    char coluna_capa[DIMENSAO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};          //posição da coluna na matriz 
    int linha;                                                                      //variável multípla para linhas
    int linha_atk;                                                                  //variável para linhas a serem atacadas
    int aux_atk_conv;                                                               //conversor de char para int do ataque do jogador
    int aux_conv;                                                                   //conversor do posicionamento do jogador
    int dificuldade = 0;                                                            //para o 'if' de dificuldade
    int memo = 0;                                                                   //posição da memória
    int pontos[MEMORIA] = {0};                                                      //pontos armazenados por memoria
    int pontos_computador = 0;                                                      //pontuação do computador
    int linha_numerica_computador = 0;                                              //linha para matriz computador
    int coluna_numerica_computador = 0;                                             //coluna para matriz computador
    int rodada[MEMORIA] = {0};                                                      //contador de rodadas
    int pontos_def[MEMORIA] = {0};                                                  //conversor de pontos de rodada (não essencial)
    int ataques_computador;                                                         //número de ataques do computador, serve para 
    int top1 = INT_MIN;                                                             //valor minimo para não ter problemas no ranking
    char resposta;                                                                  //resposta S ou N se é desejavel continuar
    char aux;                                                                       //auxiliar de posicionamento
    char aux_atk;                                                                   //auxiliar nos ataques
    bool continuar = true;                                                          //verifica se é preciso continuar o programa e exibir a mensagem
    
    system("color B0");
    //Interface inicial:
    while ((continuar == true) && (memo < MEMORIA))
    {
        ataques_computador = 0;
        bool jogador_1 = false;                                                         //booleano para verificar o jogador com o recorde                                            //booleano para verificar de o humano ganhou
        bool sorteio_verdadeiro = false;                                                //booleano para verificar se o sorteio da casa é válido
        string tabuleiro_jogador[DIMENSAO][DIMENSAO] = {""};                            //inicializando tabuleiro do jogador
        string tabuleiro_computador[DIMENSAO][DIMENSAO] = {""};                         //inicializando tabuleiro do computador
        string tabuleiro_capa[DIMENSAO][DIMENSAO] = {""};                               //inicializando tabuleiro de capa
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
        cout << "Deseja continuar? Se sim digite 'S',\n";
        cout << "caso contrario digite 'N'\n";
        cin >> resposta;

        //teste de continuação:
        if(resposta == 'S')
        {
            continuar = true;
        }
        if(resposta == 'N')
        {
            continuar = false;
            break;
        }

        system("cls");
        //Armazenamento do nome:
        cin.get();
        cout << "Digite um nickname:" << endl;
        getline(cin, nome[memo]);
        system("cls");
        for (int i = 0; i < 1; i++)
        {
            cout << "Selecione o nivel de dificuldade: " << endl;
            cout << "Digite o numero em questao!" << endl;
            cout << "1 - Normal" << endl;
            cout << "2 - Dificil" << endl;
            cin >> dificuldade;
            if (dificuldade == 1 || dificuldade == 2)
            {
                switch (dificuldade)
                {
                    case 1:
                        dificuldade = 1;
                    break;
                    case 2:
                        dificuldade = 2;
                    break;
                }
                system("cls");
            }
            else
            {
                system("pause");
            }
        }
        
        //Posicionamento do submarinos do jogador
        //São 8 submarinos a serem posicionados
        //Apenas mudará a posição para 0 se o número armazenado na posição for diferente,
        //evitando armazenar mais de duas vezes
        for (int i = 0; i < 4; i++)
        {
            //Mostrar tabuleiro do jogador:
            cout << endl;
            cout << endl;
            cout << "   ";
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
                        tabuleiro_jogador[l][c] = " ~ ";
                    }
                    cout << tabuleiro_jogador[l][c]; 
                }  
                cout << endl;
            }
            cout << "Defina as posicoes dos Submarinos (tamanho 1):   " << endl;
            cout << "_________________________________________________________________________________"<< endl;
            cout << "*Representacao dos Submarinos:          S        " << endl;
            cout << "Posicao:" << endl;
            cin >> aux;
            cin >> linha;
            aux_conv = ((int)aux) - 65;
            cout << "int aux:" << aux_conv << endl;
            if (linha >= 1 && linha <= 8)
            {
                if (aux_conv >= 0 && aux_conv <= 7)
                {
                    if (tabuleiro_jogador[linha-1][aux_conv] == " ~ ")
                    {
                        tabuleiro_jogador[linha-1][aux_conv] = " S ";
                    }
                    else
                    {
                        cout << "ERRO" << endl;
                        i--;
                    }
                }
                else
                {
                    cout << "tente novamente!" << endl;
                    i--;
                }
            }
            else
            {
                cout << "tente novamente!" << endl;
                i--;
            }
            system("cls");
        }  

        
        
        for (int i = 0; i < 3; i++)
        {
            cout << endl;
            cout << endl;
            cout << "   ";
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
                        tabuleiro_jogador[l][c] = " ~ ";
                    }
                    
                    cout << tabuleiro_jogador[l][c]; 
                }  
                cout << endl;
            }
            // Posicionamento dos hidroaviões
            cout << "Defina as posicoes dos Hidroavioes (tamanho 4): " << endl;
            cout << "Digite o ponto central do hidroaviao!" << endl;
            cout << "_________________________________________________________________________________"<< endl;
            cout << "*Representacao dos Hidroavioes:       H          " << endl;
            cout << "                                     HHH         " << endl;
            cout << "Posicao:" << endl;
            cin >> aux;
            cin >> linha;
            aux_conv = ((int)aux) - 65;
            if (linha >= 1 && linha <= 8)
            {
                if (aux_conv >= 0 && aux_conv <= 6)
                {
                    if (tabuleiro_jogador[linha - 1][aux_conv] == " ~ " && 
                    tabuleiro_jogador[linha - 1][aux_conv-1] == " ~ " && 
                    tabuleiro_jogador[linha - 1][aux_conv+1] == " ~ ")
                    {
                        tabuleiro_jogador[linha - 1][aux_conv-1] = " H ";
                        tabuleiro_jogador[linha - 1][aux_conv] = " H ";
                        tabuleiro_jogador[linha - 1][aux_conv+1] = " H ";
                        //O segundo 'if' verifica se todas as linhas possíveis estão vagas
                        //A prioridade de inserção é a linha superior
                        if (tabuleiro_jogador[linha - 2][aux_conv] == " ~ ")
                        {
                            tabuleiro_jogador[linha - 2][aux_conv] = " H ";
                        }
                        else
                        {
                            if (tabuleiro_jogador[linha][aux_conv] == " ~ ")
                            {
                                tabuleiro_jogador[linha][aux_conv] = " H ";
                            }
                        }
                    }
                    else
                    {
                        cout << "tente novamente!" << endl;
                        i--;
                    }
                }
                else
                {
                    cout << "tente novamente!" << endl;
                    i--;
                }
            }
            else
            {
                cout << "tente novamente!" << endl;
                i--;
            }
            system("cls");
        }

        // Posicionamento do Computador:
        srand(time(NULL));
    
        //Sorteio de submarino
        for (int i = 0; i < 4; i++)
        {
            linha_numerica_computador  = rand()%8;
            coluna_numerica_computador = rand()%8;
            if (tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador] == "")
            {
                tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador] = " S ";
            }
            else
            {
                i--;
            }
        }
        //Sorteio de hidroaviao
        for (int i = 0; i < 3; i++)
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

        //Partida 
        while (rodada[memo] < 64 && pontos[memo] < 16 && pontos_computador < 16)
        {
            //Tabuleiro do jogador:
            cout << endl;
            cout << "_________________________________________________________________________________"<< endl;
            cout << nome[memo] << ":"<< endl;
            cout << endl;
            cout << endl;
            cout << "   ";
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
                    cout << tabuleiro_jogador[l][c]; 
                }  
                cout << endl;
            }
            // Tabuleiro capa
            cout << "_________________________________________________________________________________"<< endl;
            cout << "Computador:"<< endl;
            cout << endl;
            cout << endl;
            cout << "   ";
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
                        tabuleiro_capa[l][c] = " ~ ";
                    }
                    cout << tabuleiro_capa[l][c];
                }  
                cout << endl;
            }
            cout << endl;
            cout << endl;
            cout << endl;
            //Sistema similar ao de seleção, com switch e if embutido para a confirmação.
            cout << "_________________________________________________________________________________"<< endl;
            cout << " RODADA " << rodada[memo] << endl;
            cout << "_________________________________________________________________________________"<< endl;
            cout << "Qual casa deseja atacar?" << endl;
            cout << "Posicao:" << endl;
            cin >> aux_atk;
            cin >> linha_atk;
            aux_atk_conv = ((int) aux_atk)-65;
            for (int i = 0; i < 1; i++)
            {
                if (linha_atk >= 1 && linha_atk <= 8)
                {
                    if (aux_atk_conv >= 0 && aux_atk_conv <= 7)
                    {
                        if (tabuleiro_computador[linha_atk - 1][aux_atk_conv] == ""||
                        tabuleiro_capa[linha_atk - 1][aux_atk_conv] == " * " ||
                        tabuleiro_capa[linha_atk - 1][aux_atk_conv] == " S " ||
                        tabuleiro_capa[linha_atk - 1][aux_atk_conv] == " H ")
                        {
                            tabuleiro_capa[linha_atk-1][aux_atk_conv] = tabuleiro_computador[linha_atk-1][aux_atk_conv];
                            jogador_1 = true;
                            pontos[memo]++;
                            i--;
                        }
                        else
                        {
                            tabuleiro_capa[linha_atk - 1][aux_atk_conv] = " * ";
                            jogador_1 = false;
                        }
                    }
                }
            }
            if (dificuldade == 2)
            {
                ataques_computador = 0;
                while (sorteio_verdadeiro == false || ataques_computador < 2)
                {
                    linha_numerica_computador  = rand()%8;
                    coluna_numerica_computador = rand()%8;
                    if (tabuleiro_jogador[linha_numerica_computador][coluna_numerica_computador] == " S " || tabuleiro_jogador[linha_numerica_computador][coluna_numerica_computador] == " H " )
                    {
                        sorteio_verdadeiro = true;
                        if (sorteio_verdadeiro == true || ataques_computador == 1)
                        {
                            tabuleiro_jogador[linha_numerica_computador][coluna_numerica_computador] = " @ ";
                            ataques_computador++;
                        }
                        pontos_computador++;
                    }
                    else
                    {
                        tabuleiro_jogador[linha_numerica_computador][coluna_numerica_computador] = " * ";
                    }
                    ataques_computador++;
                }
            }
            else
            {
                linha_numerica_computador  = rand()%8;
                coluna_numerica_computador = rand()%8;
                if ((tabuleiro_jogador[linha_numerica_computador][coluna_numerica_computador] == " S " )
                || (tabuleiro_jogador[linha_numerica_computador][coluna_numerica_computador] == " H " ))
                {
                    tabuleiro_jogador[linha_numerica_computador][coluna_numerica_computador] = " @ ";
                    pontos_computador++;
                }
                else
                {
                    tabuleiro_jogador[linha_numerica_computador][coluna_numerica_computador] = " * ";
                }
            }
            rodada[memo]++;
            pontos_def[memo] = pontos[memo];
        system("cls");
        cout << "_________________________________________________________________________________"<< endl;
        cout << "rodada:" << rodada[memo] << endl;
        cout << "pontos:" << pontos_def[memo] << endl;
        if (dificuldade == 1)
        {
            cout << "dificuldade: normal" << endl;
        }
        else
        {
            cout << "dificuldade: dificil" << endl;
        }
    }
    //Checando acertos do jogador:
        if (jogador_1 == true)
        {
            cout << nome[memo] << " ACERTOU na rodada passada!" << endl;
        }
        else
        {
            cout << nome[memo] << " ERROU na rodada passada!" << endl;
        }

        if ((pontos_computador > pontos[memo]) && (pontos_computador >= 15)) 
        {
            cout << "_________________________________________________________________________________"<< endl;
            cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
            cout << "MN0OOO000XNMMN0OOOOO0NN0OOO00KXWMMX0OOO000KXWMMMWXOxxxOXWMN0OOOOOOO0XN0OOOO0XMMM" << endl;
            cout << "Mk'    ...,xNO'     .kk'    ...:0Wx.     ...lKMKl.     .oKx.       .dx.    .oNMM" << endl;
            cout << "Mk.   ;,   'Ok.   ,coKk.   ;,   cXd   .;c'   oNl   'l.   oOo:.   .:okc      ;KMM" << endl;
            cout << "Mk.  .xd.  .kk.  .xWWMk.  .do   :Xd   .xKc   lK:   :O;   cNMX:   ;XMK;  ..  .OMM" << endl;
            cout << "Mk.  .xd.  .kk.   .,lKk.   ..  'kNd    ...  ;OX;   :O;   cNMX:   ;XMO.  ,:   oWM" << endl;
            cout << "Mk.  .xd.  .kk.   .'cKk.   '.  'kNd   .,;.  ;OX;   :O;   cNMX:   ;XWd.  cd.  :XM" << endl;
            cout << "Mk.  .xd.  .kk.  .dNWWk.  .xd   :Xd   .kXc   lK:   :O;   cNMX:   ;XNc   ',   '0M" << endl;
            cout << "Mk.  .lc   .kk.   ckkKx.  .xd.  ;Kd   'kXl   cXc   ,x,   lWMX;   ;XK,    .   .xM" << endl;
            cout << "Mk.        :Kk.      lx.  .xd.  ;Kd   'kXl   cNO,   .   ;0MMX:   ;Xk.   lO,   cN" << endl;
            cout << "MXdoooooodkXMXxoooooo0KxoodKKdookNKdooxXW0ooo0WMXklcccokXMMMWOoooOWKdoodKWOoookN" << endl;
            cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
            break;
        }
        if ((pontos[memo] > pontos_computador) && (pontos[memo] >= 15))
        {
            cout << "_________________________________________________________________________________"<< endl;
            cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
            cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
            cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKo;;ckNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
            cout << "MMWNNNNWMWWNNNWWNNNNWWNNNNNNNNNNWMMWXl.,cxXWMMMWNNNNWWWMMMMWNNNNWMMWWNNNNNWMMMMM" << endl;
            cout << "MMO;'''oNK:'''lx:'''dO:'''''''';OWOc'.....,l0WNo''''',,:dXM0:'''dNM0:''''':0MMMM" << endl;
            cout << "MM0'   ,0x.   :d.   cx,.      ..xx.   ''    ,0X;    ..   cNk.   cNWd.     .dWMMM" << endl;
            cout << "MMX:   .ko    ox.   cXK0l    :0KXc   .kd.   .dX:   .xl   '0k.   cNNc   .   cNMMM" << endl;
            cout << "MMWo   .l:   .kk.   cNMMd.   lWMNc   .kd.    dX;   .l;   ;Kk.   cNK,  .;.  '0MMM" << endl;
            cout << "MMMO.   ;,   ,0k.   cNMMd.   lWMN:   .kd..   oK:        ,kWk.   cNk.  .o,  .xMMM" << endl;
            cout << "MMMK;   ..   cNk.   cNMMd.   lWMNc   .kd..   oK;   .c,  .cXk.   cXd   'd;   lNMM" << endl;
            cout << "MMMWl        dWk.   cNMMd.   lWMNc   .kd..   dX;   .Oo   '0k.   cK:    .    ,KMM" << endl;
            cout << "MMMMk.      .OMk.   cNMMd.   lWMWo   .lc.   .xX;   'Oo   '0k.   cO,   .,.   .kMM" << endl;
            cout << "MMMMK,      ,KMk.   cNMMd.   oWMMKc.       .oXX:   'Oo   '0k.   cd.   :Xx.   oWM" << endl;
            cout << "MMMMW0dddddd0WMXkddd0WMMKxddxKWMMMW0xollloxKWMWOdddkXKxddkNXkddd0Kxddd0WXxddd0WM" << endl;
            cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
            break;
        }
        memo++;    
    }
    cout << "_________________________________________________________________________________"<< endl;
    for (int i = 0; i < memo; i++)
    {
        cout << "_________________________________________________________________________________"<< endl;
        cout << "Sua pontuacao = " << pontos_def[i] << endl;
        cout << "rodada:" << rodada[i] << endl;
    }
    for (int i = 0; i < memo; i++)
    {
        if(pontos[i] > top1)
        {
            top1 = pontos[i];
            nome_1 = nome[i];
        }
    }
    for (int i = 0; i < memo; i++)
    {
        cout << "Rodada " << i << " : " <<  nome[i] << ".................pontos: " << pontos[i] << endl;
    }
    cout << "Recorde: " << nome_1 << " pontos: " << top1 << endl;
    system("pause");
    return 0;

}