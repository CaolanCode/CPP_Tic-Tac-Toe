/*
    Tic-Tac-Toe
 */

#include <iostream>
using namespace std;

void createBoard(char (&fullBoard)[11][11]);
void printBoard(char (&fullBoard)[11][11]);
void updateBoard(char (&fullBoard)[11][11], char (&choices)[9]);

int main()
{
    char fullBoard[11][11];
    char choices[] = {'1','2','3','4','5','6','7','8','9'};
    
    createBoard(fullBoard);
    updateBoard(fullBoard, choices);
    printBoard(fullBoard);
    
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
