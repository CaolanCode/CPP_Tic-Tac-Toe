/*
    Tic-Tac-Toe
 */

#include <iostream>
#include <ctype.h>
using std::cout;
using std::endl;
using std::cin;

void createBoard(char (&fullBoard)[11][11]);
void printBoard(char (&fullBoard)[11][11]);
void updateBoard(char (&fullBoard)[11][11], char (&choices)[9]);
void checkWinner(char (&choices)[9], bool &winner);
void getChoice(int &pick, char (&choices)[9], char &player);
void changePlayer(char &player);
void checkReplay(char &playGame);
void resetBoard(char (&choices)[9], char &player);

int main()
{
    char fullBoard[11][11];
    char choices[] = {'1','2','3','4','5','6','7','8','9'};
    bool winner = false;
    int pick;
    char player = 'O';
    int counter = 0;
    char playGame = 'Y';
    createBoard(fullBoard);
    
    while(playGame == 'Y')
    {
        changePlayer(player);
        updateBoard(fullBoard, choices);
        printBoard(fullBoard);
        getChoice(pick, choices, player);
        checkWinner(choices, winner);
        counter++;
        if(winner)
        {
            updateBoard(fullBoard, choices);
            printBoard(fullBoard);
            cout << "\nPlayer " << player << " wins!\n";
            checkReplay(playGame);
            if(playGame == 'Y') resetBoard(choices, player);
                
        }
        else if(counter == 9)
        {
            updateBoard(fullBoard, choices);
            printBoard(fullBoard);
            cout << "\nResult is a draw!\n";
            checkReplay(playGame);
            if(playGame == 'Y') resetBoard(choices, player);
        }
    }
    
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

void checkWinner(char (&choices)[9], bool &winner)
{
    if(choices[0] == choices[1] && choices[1] == choices[2] && choices[0] != ' ') winner = true;
    else if(choices[3] == choices[4] && choices[4] == choices[5] && choices[3] != ' ') winner = true;
    else if(choices[6] == choices[7] && choices[7] == choices[8] && choices[6] != ' ') winner = true;
    else if(choices[0] == choices[3] && choices[3] == choices[6] && choices[6] != ' ') winner = true;
    else if(choices[1] == choices[4] && choices[4] == choices[7] && choices[1] != ' ') winner = true;
    else if(choices[2] == choices[5] && choices[5] == choices[8] && choices[2] != ' ') winner = true;
    else if(choices[0] == choices[4] && choices[4] == choices[8] && choices[8] != ' ') winner = true;
    else if(choices[2] == choices[4] && choices[4] == choices[6] && choices[2] != ' ') winner = true;
    
}

void getChoice(int &pick, char (&choices)[9], char &player)
{
    cout << "\nPlayer " << player << ".\n";
    do
    {
        cout << "Choose the position between 1-9: ";
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

void checkReplay(char &playGame)
{
    char choice;
    do
    {
        cout << "Do you want to play again? (Y/N): ";
        cin >> choice;
    }while(choice != 'Y' && choice != 'N');
    
    playGame = toupper(choice);
}

void resetBoard(char (&choices)[9], char &player)
{
    int number = 49; // 1 decimal
    for(int i = 0; i < 9; i++)
    {
        choices[i] = char(number);
        number++;
    }
    player = 'O';
}

