//Muzalfa bibi
//SU91-BIETM-F23-008
#include<iostream>
using namespace std;
char table[3][3] = { { '1','2','3' },{ '4','5','6' },{ '7','8','9' } };
char turn = 'x';
int row, column;
bool draw = false;
void display() {
    system("cls");
    cout << "   *** TIC TAC TOE GAME ***\n";
    cout << "\tPlary 1 [x]\n\tPlary 2 [O]\n";
    cout << "\t\t\t ************************************" << endl;
    cout << "\t\t\t |       TIC TAC TOE GAME            |" << endl;
    cout << "\t\t\t ************************************" << endl;
    cout << "\t\t\t |            |           |          |" << endl;
    cout << "\t\t\t |      " << table[0][0] << "     |     " << table[0][1] << "     |   " << table[0][2] << "      |" << endl;
    cout << "\t\t\t |____________|___________|__________|" << endl;
    cout << "\t\t\t |            |           |          |" << endl;
    cout << "\t\t\t |      " << table[1][0] << "     |     " << table[1][1] << "     |   " << table[1][2] << "      |" << endl;
    cout << "\t\t\t |____________|___________|__________|" << endl;
    cout << "\t\t\t |            |           |          |" << endl;
    cout << "\t\t\t |      " << table[2][0] << "     |     " << table[2][1] << "     |   " << table[2][2] << "      |" << endl;
    cout << "\t\t\t |____________|___________|__________|" << endl;
}
void player_turn() {
    int choice;
    if (turn == 'x')
        cout << "\n\tplayer 1 turn[x]:";
    else
        cout << "\n\tplayer 2 turn[O]:";
    cin >> choice;
    switch (choice) {
    case 1: row = 0; column = 0; break;
    case 2: row = 0; column = 1; break;
    case 3: row = 0; column = 2; break;
    case 4: row = 1; column = 0; break;
    case 5: row = 1; column = 1; break;
    case 6: row = 1; column = 2; break;
    case 7: row = 2; column = 0; break;
    case 8: row = 2; column = 1; break;
    case 9: row = 2; column = 2; break;
    default:
        cout << "You Enter a Wrong Choice";
        break;
    }
    if (turn == 'x' && table[row][column] != 'x' && table[row][column] != 'o') {
        table[row][column] = 'x';
        turn = 'o';
    }
    else if (turn == 'o' && table[row][column] != 'x' && table[row][column] != 'o') {
        table[row][column] = 'o';
        turn = 'x';
    }
    else {
        cout << "***Box Already Filed***\n***Please Try Again***";
        player_turn();
    }
    display();
}
bool gameover() {
    for (int i = 0; i < 3; i++)
         if (table[i][0] == table[i][1] && table[i][0] == table[i][2] || table[0][i] == table[1][i] && table[0][i] == table[2][i])
            return false;
    if (table[0][0] == table[1][1] && table[0][0] == table[2][2] || table[0][2] == table[1][1] && table[0][2] == table[2][0])
        return false;
    for (int i = 0; i < 3; i++)
         for (int j = 0; j < 3; j++)
             if (table[i][j] != 'x' && table[i][j] != 'o')
                return true;
    draw = true;
    return false;
}
int main() {
    char again = 0;
    do {
        cout << "\n*** The Symbol 'X' is player 1 *** \n*** The Symbol 'O' is player 2 ***" << endl;
        cout << "*** Select your symbol *** \n Start your game : ";
        cin >> turn;
        while (gameover()) {
            display();
            player_turn();
            display();
            gameover();
        }
        if (turn == 'x' && draw == false)
            cout << "\n\t ***player.2 [O] :***\n\t *** WINS THE GAME***\n\t   ***CONGRATULATIONS***\n";
        else if (turn == 'o' && draw == false)
            cout << "\n\t ***player.1 [X] :***\n\t *** WINS THE GAME***\n\t   ***CONGRATULATIONS***\n";
        else
            cout << "***GAME IS NOT SUCCESSFUL***\n";
        cout << "\n*** Select 'y' if you play again game ***\n";
        cout << "*** Select 'n' if you not play again game ***\n";
        cin >> again;
        if (again == 'y' || again == 'Y')
            turn = 'x';
        draw = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                table[i][j] = '1' + i * 3 + j;
            }
        }
    } while (again == 'y' || again == 'Y');
    return 0;
}

