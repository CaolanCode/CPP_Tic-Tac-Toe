/*
    Tic-Tac-Toe
 */
#include <iostream>
using namespace std;

class TicTacToe
{
    char marker;
public:
    TicTacToe(char m)
    {
        cout << "In constructor\n";
        //setName(n);
        marker = m;
        cout << marker << endl;
    }
    char get_marker() { return marker;}
};
int main() {
    TicTacToe playerX('X');
    TicTacToe playerY('O');
    
    cout << playerX.get_marker() << endl;
    cout << playerY.get_marker() << endl;
    
    return 0;
}
