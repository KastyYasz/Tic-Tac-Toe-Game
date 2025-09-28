#include <iostream>
#include <cstdlib>  
#include <ctime>


using namespace std;


bool venceu(char t[3][3], char p) {
    // 3 linhas
    if (t[0][0] == p && t[0][1] == p && t[0][2] == p) return true;
    if (t[1][0] == p && t[1][1] == p && t[1][2] == p) return true;
    if (t[2][0] == p && t[2][1] == p && t[2][2] == p) return true;

    // 3 colunas
    if (t[0][0] == p && t[1][0] == p && t[2][0] == p) return true;
    if (t[0][1] == p && t[1][1] == p && t[2][1] == p) return true;
    if (t[0][2] == p && t[1][2] == p && t[2][2] == p) return true;

    // 2 diagonais
    if (t[0][0] == p && t[1][1] == p && t[2][2] == p) return true;
    if (t[0][2] == p && t[1][1] == p && t[2][0] == p) return true;

    return false;
}



int main()
{

    char escolha;
    char jogador;
    char bot;
    char escolhaBot;

    srand(time(0));

    while (true)
    {
        
        cout << "Você quer jogar como 'X' ou 'O': " << endl; 
            cin >> escolha;

        if(escolha == 'O' || escolha == 'o') 
        {
            jogador = 'O';
            break;
        }

        else if(escolha == 'X' || escolha == 'x')
        {
            jogador = 'X';
            break;
        } 

         else cout << "Escolha invalida, tente novamente: " << endl;

    }

        if (jogador == 'X') bot = 'O';
        else if(jogador == 'O') bot = 'X';
            
    


    char tabuleiro[3][3] =
    {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };

    int pos;
    int coutEmpate = 0;

    for (int i = 0; i < 3; i++)
    {
        cout << " " ;

        for (int j = 0; j < 3; j++)
        {
            cout << tabuleiro[i][j];
            if(j < 2) cout << " | ";
        }
        cout << endl;

        if(i < 2) cout << "---+---+---\n";
    }
    while(coutEmpate < 9){
    


        while (true)
        {   
             cout << "Escolha uma posição: " << endl;
                cin >> pos;

            if(pos < 1 || pos > 9)
            {
                cout << "Posição Invalida, tente novamente: " << endl;
                
            }  
            else break;   
        }
    

    int linha  = (pos - 1) / 3; 
    int coluna = (pos - 1) % 3; 

    char esperado = '0' + pos ;

    if(tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == 'O')
    {
        cout << "Este lugar já está ocupado, tente novamente: " << endl;
    }else if (tabuleiro[linha][coluna] != esperado)
    {
        cout << "lugar inconsistente!" << endl;
    }else
    {
        tabuleiro[linha][coluna] = jogador;
    }

    if (venceu(tabuleiro, jogador))
    {
        cout << "jogador venceu!" << endl;
        break;
    }
    

    // vez do bot jogar
    while (true)
    {

        pos = 1 + rand() % 9;

        int linhaBot = (pos - 1) / 3;
        int colunaBot = (pos - 1) % 3;

        char esperadoBot = '0' + pos;

        if(tabuleiro[linhaBot][colunaBot] == 'X' || tabuleiro[linhaBot][colunaBot] == 'O') continue;
        else
        {
            tabuleiro[linhaBot][colunaBot] = bot;
            break;
        }
        
    }
    
     for (int i = 0; i < 3; i++)
    {
        cout << " " ;

        for (int j = 0; j < 3; j++)
        {
            cout << tabuleiro[i][j];
            if(j < 2) cout << " | ";
        }
        cout << endl;

        if(i < 2) cout << "---+---+---\n";
    }

    if(venceu(tabuleiro, bot))
    {
        cout << "bot venceu !!" << endl;
        break;
    }

    coutEmpate += 2;
     
}

    if(coutEmpate == 9) cout << "Deu empate!" << endl;

    cout << "Obrigado por Jogar! " << endl;
    
    






    return 0;
}
