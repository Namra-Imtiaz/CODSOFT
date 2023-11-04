#include<iostream>
#include <windows.h>
using namespace std;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int turn1;
int row,column;
char turn='X';
bool draw=false;

void display_board(){
    system("cls");
    cout<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"\t\ttik tak toe game"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"\tPlayer1[X]";
    cout<<"\t\tPlayer2[O]"<<endl;
    cout<<"\t\t     |     |     "<<endl;
    
    for (int i = 0; i < 3; i++) {
        cout << "\t\t  ";
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') {
                SetConsoleTextAttribute(h, 9);  // Set color for X (e.g., yellow)
            } else if (board[i][j] == 'O') {
                SetConsoleTextAttribute(h, 4);  // Set color for O (e.g., red)
            }

            cout << board[i][j];

            SetConsoleTextAttribute(h, 15);  // Reset text color to white
            if (j < 2) {
                cout << "  |  ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "\t\t_____|_____|_____" << endl;
            cout << "\t\t     |     |     " << endl;
        }
    }
}

void player_turn(){
    if(turn=='X')
        cout<<"\tPlayer1[X] turn:";
    //cin>>turn1;    
    if(turn=='O')
        cout<<"\tPlayer2[O] turn:";
    cin>>turn1;   
    
    switch(turn1){
        case 1:
        row=0;
        column=0;
        break;
        case 2:
        row=0;
        column=1;
        break;
        case 3:
        row=0;
        column=2;
        break;
        case 4:
        row=1;
        column=0;
        break;
        case 5:
        row=1;
        column=1;
        break;
        case 6:
        row=1;
        column=2;
        break;
        case 7:
        row=2;
        column=0;
        break;
        case 8:
        row=2;
        column=1;
        break;
        case 9:
        row=2;
        column=2;
        break;
        default:
        SetConsoleTextAttribute(h, 4); // Set color to red for error message
        cout<<"\tERROR!"<<endl;
        cout<<"\tInvalid Input"<<endl;
        SetConsoleTextAttribute(h, 15);  // Reset text color to white
        break;
    }
    if(turn=='X' && board[row][column]!='X' && board[row][column]!='O'){
        board[row][column]='X';
        turn='O';
    }
    else if(turn=='O' && board[row][column]!='X' && board[row][column]!='O'){
        board[row][column]='O';
        turn='X';
    }
    else{
        SetConsoleTextAttribute(h, 4); // Set color to red for error message
        cout<<"\tERROR!"<<endl;
        cout<<"\tBox already filled!Please try again"<<endl;
        SetConsoleTextAttribute(h, 15);  // Reset text color to white
        player_turn();
    }
    display_board();
}

bool game_over(){
    // check win
    for(int i=0;i<3;i++)
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[1][i] && board[0][i]==board[2][i])
        return false; 
    
    if(board[0][0]==board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] && board[0][2]==board[2][0]){
        return false;
    }
    
    //if there is any box not filled
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    if(board[i][j]!='X' && board[i][j]!='O')
    return true;
    
    //DRAW
    draw=true;
    return false;
}
void reset_board(){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j] = '0' + i*3 + j + 1;
    draw = false;
}

int main(){
	char play_again;
	do {
        reset_board();
    while(game_over()){
        display_board();
        player_turn();
    }
    cout<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    if(turn=='X' && draw==false){
        SetConsoleTextAttribute(h, 4); // Set color for the winning message
        cout<<"\t\tPlayer2[O] WINNER :)"<<endl;
        SetConsoleTextAttribute(h, 15);  // Reset text color to white
    }
    else if(turn=='O' && draw==false){
        SetConsoleTextAttribute(h, 9); // Set color for the winning message
        cout<<"\t\tPlayer1[X] WINNER :)"<<endl;
        SetConsoleTextAttribute(h, 15);  // Reset text color to white
    }
    else{
        SetConsoleTextAttribute(h, 15); // Set color for the draw message
        cout<<"\t\tGAME DRAW  !"<<endl;
        SetConsoleTextAttribute(h, 15);  // Reset text color to white
    }
    cout << "\nPlay Again? (Y/N): ";
        cin >> play_again;
    } while (play_again == 'Y' || play_again == 'y');
    return 0;
}

