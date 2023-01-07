/*
    Tic-Tac-Toe
 */

#include <iostream>
using namespace std;

void createBoard(char (&fullBoard)[11][11]);
void printBoard(char (&fullBoard)[11][11]);
void updateBoard(char (&fullBoard)[11][11], char (&choices)[9]);
void checkWinner(char (&choices)[9]);
void getChoice(int &pick, char (&choices)[9], char &player);
void changePlayer(char &player);

int main()
{
    char fullBoard[11][11];
    char choices[] = {'1','2','3','4','5','6','7','8','9'};
    bool winner = false;
    int pick;
    char player = 'X';
    createBoard(fullBoard);
    
    do
    {
        updateBoard(fullBoard, choices);
        printBoard(fullBoard);
        getChoice(pick, choices, player);
        changePlayer(player);
        
    }while(!winner);
    
    return 0;
}

void createBoard(char (&fullBoard)[11][11])
{
    for(int i = 0; i < 11; i++)
    {
        for(int j = 0; j < 11; j++)
        {
            if((i == 3 || i == 7) && (j != 3 || j != 7)) fullBoard[i][j] = '-';
            else if(j == 3 || j == 7) fullBoard[i][j] = '|';
            else fullBoard[i][j] = ' ';
        }
    }
}

void printBoard(char (&fullBoard)[11][11])
{
    for(int i = 0; i < 11; i++)
    {
        for(int j = 0; j < 11; j++)
        {
            cout << fullBoard[i][j];
        }
        cout << endl;
    }
}

void updateBoard(char (&fullBoard)[11][11], char (&choices)[9])
{
    int k = 0;
    for(int i = 1; i < 10; i += 4)
    {
        for(int j = 1; j < 10; j += 4)
        {
            fullBoard[i][j] = choices[k];
            k++;
        }
    }
}

void checkWinner(char (&choices)[9])
{
    if(choices[0] == choices[1] && choices[1] == choices[2] && choices[0] != ' ') cout << choices[0] << " is the winner!";
    else if(choices[3] == choices[4] && choices[4] == choices[5] && choices[3] != ' ') cout << choices[3] << " is the winner!";
    else if(choices[6] == choices[7] && choices[7] == choices[8] && choices[6] != ' ') cout << choices[6] << " is the winner!";
    else if(choices[0] == choices[3] && choices[3] == choices[6] && choices[6] != ' ') cout << choices[6] << " is the winner!";
    else if(choices[1] == choices[4] && choices[4] == choices[7] && choices[1] != ' ') cout << choices[1] << " is the winner!";
    else if(choices[2] == choices[5] && choices[5] == choices[8] && choices[2] != ' ') cout << choices[2] << " is the winner!";
    else if(choices[0] == choices[4] && choices[4] == choices[8] && choices[8] != ' ') cout << choices[8] << " is the winner!";
    else if(choices[2] == choices[4] && choices[4] == choices[6] && choices[2] != ' ') cout << choices[2] << " is the winner!";
    
}

void getChoice(int &pick, char (&choices)[9], char &player)
{
    do
    {
        cout << "\nChoose the position between 1-9: ";
        cin >> pick;
        if(pick < 1 || pick > 9) cout << "\nIncorrect choice\n";
        else choices[pick-1] = player;
    }while(pick < 1 || pick > 9);
}

void changePlayer(char &player)
{
    if(player == 'X') player = 'O';
    else player = 'X';
}
