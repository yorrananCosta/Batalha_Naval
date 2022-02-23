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

//Uso de registro uso com vetor na chamada
typedef struct{
    string nome;
    int pontos;
} Jogador;

void mostrarDerrota()
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
}

void mostrarVitoria()
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
}

void mostrarTitulo()
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
}

int selecionarDificuldade() 
//Essa função está usando retorno de parâmetros.
{
    int dificuldade = 0;    //para o 'if' de dificuldade
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
                        return 1;
                    break;
                    case 2:
                        return 2;
                    break;
                }
                system("cls");
            }
            else
            {
                system("pause");
            }
        }
}

bool testeContinuar(char resposta)
{
    //teste de continuação:
        if(resposta == 'S')
        {
            return true;
        }
        if(resposta == 'N')
        {
            return false;
        }
}

int main()
{
    Jogador jogador[MEMORIA];
    char linha_capa[DIMENSAO] = {'1', '2', '3', '4', '5', '6', '7', '8'};           //posição da linha na matriz capa
    int linha_atk;                                                                  //variável para linhas a serem atacadas
    int teste_atk;                                                               //conversor de char para int do ataque do jogador
    int dificuldade = 0;                                                            //para o 'if' de dificuldade
    int memo = 0;                                                                   //posição da memória
    int pontos[MEMORIA] = {0};                                                      //pontos armazenados por memoria
    int pontos_computador = 0;                                                      //pontuação do computador
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
        string tabuleiro[DIMENSAO][DIMENSAO] = {""};                               //inicializando tabuleiro de capa
        mostrarTitulo();
        cout << endl;
        cout << "Deseja continuar? Se sim digite 'S',\n";
        cout << "caso contrario digite 'N'\n";
        cin >> resposta;
        continuar = testeContinuar(resposta); 

        system("cls");
        //Armazenamento do nome:
        cin.get();
        cout << "Digite um nickname:" << endl;
        getline(cin, jogador[memo].nome);
        system("cls");
        dificuldade = selecionarDificuldade();
        //Posicionamento do submarinos do jogador
        //São 8 submarinos a serem posicionados
        //Apenas mudará a posição para 0 se o número armazenado na posição for diferente,
        //evitando armazenar mais de duas vezes
        for (int i = 0; i < 4; i++)
        {
            //Mostrar tabuleiro do jogador:
            //Posicionamento de submarinos do jogador
            //Usa as variáveis: aux, linha, auxconv, tabuleiro_jogador
        } 

        
        
        for (int i = 0; i < 3; i++)
        {
            //Mostrar tabuleiro do jogador.
            // Posicionamento dos hidroaviões do jogador:
            //variáveis: aux, linha, aux_conv, tabuleiro_jogador.
        }

        // Posicionamento do Computador:
        // variáveis: aux, linha, auxconv, tabuleiro_jogador.

        // Sorteio de hidroaviao
        // variáveis: aux, linha, auxconv, tabuleiro_jogador. 

        //Partida 
        while (rodada[memo] < 64 && pontos[memo] < 16 && pontos_computador < 16)
        {
            //Tabuleiro do jogador:
            
            // Mostrar Tabuleiro capa
            
            //Sistema similar ao de seleção, com switch e if embutido para a confirmação.
            //Sistema bugado  

           
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
            cout << jogador[memo].nome << " ACERTOU na rodada passada!" << endl;
        }
        else
        {
            cout << jogador[memo].nome << " ERROU na rodada passada!" << endl;
        }

        if ((pontos_computador > pontos[memo]) && (pontos_computador >= 15)) 
        {
            mostrarDerrota();
            break;
        }
        if ((pontos[memo] > pontos_computador) && (pontos[memo] >= 15))
        {
            mostrarVitoria();
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
        cout << "Rodada " << i << " : " <<  jogador[i].nome << ".................pontos: " << pontos[i] << endl;
    }
    system("pause");
    return 0;

}