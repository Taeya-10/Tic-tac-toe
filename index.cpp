#include <iostream>
using namespace std;

char marker;
int player_turn;
char matrix[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void play_board()
{
    cout << " " << matrix[0][0] << " | " << matrix[0][1] << " | " << matrix[0][2] << endl;
    cout << "----------" << endl;
    cout << " " << matrix[1][0] << " | " << matrix[1][1] << " | " << matrix[1][2] << endl;
    cout << "----------" << endl;
    cout << " " << matrix[2][0] << " | " << matrix[2][1] << " | " << matrix[2][2] << endl;
}

bool pointing(int slot)
{
    int row = (slot / 3);
    int column;
    if (slot % 3 == 0)
    {
        row = row - 1;
        column = 2;
    }
    else
    {
        column = (slot % 3) - 1;
    }
    // cout << row << "," << column;
    if (matrix[row][column] != 'x' && matrix[row][column] != 'o')
    {
        matrix[row][column] = marker;
        return true;
    }
    else
    {
        return false;
    }
}
char result()
{
    for (int i = 0; i < 3; i++)
    {
        //row
        if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2])
            return player_turn;
        if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i])
            return player_turn;
    }
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
        return player_turn;
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
        return player_turn;
    return 0;
}

void swap_marker_player()
{
    if (marker == 'x')
    {
        marker = 'o';
    }
    else
        (marker = 'x');

    if (player_turn == 1)
    {
        player_turn = 2;
    }
    else
        (player_turn = 1);
}

void players()
{

    cout << "player_1 choose your marker ";
    char player_1;
    cin >> player_1;

    player_turn = 1;
    marker = player_1;
    play_board();

    int winner;

    for (int i = 0; i < 9; i++)
    {
        cout << "its player " << player_turn << "'s turn mark your slot" << endl;
        int slot;
        cin >> slot;
        if (slot < 1 || slot > 9)
        {
            cout << "the slot is invalid! try another slot";
            i--;
            continue;
        }

        if (!pointing(slot))
        {
            cout << "the slot is occupied! try another slot";
            i--;
            continue;
        }

        play_board();
        winner = result();
        if (winner == 1)
        {
            cout << "player 1 is the winner congrulations!" << endl;
            break;
        }
        if (winner == 2)
        {
            cout << "player 2 is the winner congrulations!" << endl;
            break;
        }

        swap_marker_player();
        //play_board();
    }
    if (winner == 0)
    {
        cout << "its a tie match!";
    }
}

int main()
{
    //play_board();
    //cout << "\n";
    //pointing(1);
    //pointing(5);
    //pointing(9);
    //player_turn = 1;
    //
    //play_board();
    //cout << result() << endl;
    players();
}