#include<iostream>
using namespace std;

char square[10] = {'0','1','2','3','4','5','6','7','8','9'};
string player_name[2];

int game_win(){
    int i;
    if(square[1] == square[2] && square[2] == square[3]){
        return 1;
    }
    else if(square[4] == square[5] && square[5] == square[6]){
        return 1;
    }
    else if(square[7] == square[8] && square[8] == square[9]){
        return 1;
    }
    else if(square[1] == square[4] && square[4] == square[7]){
        return 1;
    }
    else if(square[2] == square[5] && square[5] == square[8]){
        return 1;
    }
    else if(square[3] == square[6] && square[6] == square[9]){
        return 1;
    }
    else if(square[1] == square[5] && square[5] == square[9]){
        return 1;
    }
    else if(square[3] == square[5] && square[5] == square[7]){
        return 1;
    }
    
    for(i = 1; i <10; i++){
        if(square[i] == ('0' + i)){
            break;
        }
        else if(i == 9){
            return 0;
        }
    }
    
    return -1;
}

void board(){
    system("clear");
    cout<<"####### Tic Tac Toe #######"<<endl<<endl;
    cout<<"******* Made by Rashik *******"<<endl<<endl;
    cout<<player_name[0]<<" : X      "<<player_name[1]<<" : O"<<endl<<endl;

    // drawing the board

    cout<<"     |     |     "<<endl;
    cout<<"  "<<square[1]<<"  |  "<<square[2]<<"  |  "<<square[3]<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<square[4]<<"  |  "<<square[5]<<"  |  "<<square[6]<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<square[7]<<"  |  "<<square[8]<<"  |  "<<square[9]<<endl;
    cout<<"     |     |     "<<endl<<endl;
}

int main(){
    int player = 1, i, choice;
    char mark;

    cout<<"Enter name of player 1: ";
    cin>>player_name[0];
    cout<<"Enter name of player 2: ";
    cin>>player_name[1];

    do{
        board();
        player = (player % 2)? 1 : 2;
        cout<<"Dear "<<player_name[player - 1]<<", enter the number: ";
        cin>>choice;
        mark = (player == 1)? 'X' : 'O';       
        
        if(choice > 9 || choice < 1 || square[choice] == 'X' || square[choice] == 'O'){
            cout<<endl<<"Invalid Move "<<player_name[player - 1]<<" ! Press Enter to Continue the Game";
            player--;
            cin.ignore();
            cin.get();
        }
        else{
            square[choice] = mark;
        }
        
        i = game_win();
        player++;
    }
    while (i == -1);
    board();

    if (i == 1){
        --player;
        cout<<"\aCONGRATULATIONS ! "<<player_name[player - 1]<<" WINS !";
    }
    else{
        cout<<"\aGAME DRAW !";
    }
    
    cin.ignore();
    cin.get();
    return 0;
}