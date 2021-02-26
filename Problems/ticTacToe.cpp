#include <iostream>
using namespace std;


bool isGameWon(int gameboard[][3], int length){
    //Vertical check 
    int sum = 0;
    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++){
            if(gameboard[i][j] != 0 && gameboard[i][j] == gameboard[i][0]){
                sum++;
            }
        }
        if(sum == length){
            cout << "Gamw Won Vertically" << endl;
            return true;
        }else{
            sum = 0;
        }
    }

    //Horizontal Check
    sum = 0;
    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++){
            if((gameboard[j][i] != 0) && (gameboard[j][i] == gameboard[0][i])){
                sum++;
            }
        }
        if(sum == length){
            cout << "Gamw Won Vertically" << endl;
            return true;
        }else{
            sum = 0;
        }
    }
    
    // "\" Diagnol Check
    sum = 0;
    for(int i=0; i<length; i++){
        if(gameboard[i][i] != 0 && gameboard[i][i] == gameboard[0][0]){
            sum++;
        }
    }
    if(sum == length){
        cout << "Gamw Won Diagnolly 1" << endl;
        return true;
    }
    
    // "/" Diagnol Check
    sum = 0;
    for(int i=0; i<length; i++){
        if(gameboard[i][length-i-1] != 0 && gameboard[i][length-i-1] == gameboard[0][length-1]){
            sum++;
        }
    }
    if(sum == length){
        cout << "Gamw Won Diagnolly 2" << endl;
        return true;
    }

    return false;

}

bool gamePlay(int gameboard[][3], int row, int coloumn, int player, int length){

    try{
        gameboard[row][coloumn] = player;
        cout << "  0 1 2" << endl;

        for(int i=0; i<length; i++){
            cout << i << " ";
            for(int j=0; j<length; j++){
                cout << gameboard[i][j] << " ";
            }
            cout<< endl;
        }

        bool gameWon = isGameWon(gameboard, length);

        return gameWon;
    }
    catch(exception e){
        cout << "Error occoured: " << e.what();
        //return false;
    }
    
}


int main(){
    int count = 0;
    cout << "  0 1 2" << endl;
    int gameBoard[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    int length = sizeof(gameBoard)/sizeof(gameBoard[0]);

    for(int i=0; i < length; i++){
        cout << i << " ";
        for (int j=0; j < length; j++){
            cout << gameBoard[i][j] << " ";
        }
        cout << endl;
    }

    bool gameWon = false;
    int player = 2;
    int row, coloumn;
    while(!gameWon){

        if (player == 2){
            player = 1;
        }
        else{
            player = 2;
        }
        cout << "Player: "<<player << endl;
        cout << "Enter your choice of row: ";
        cin >> row ;
        cout << "Enter your choice of coloumn: ";
        cin >> coloumn;

        gameWon = gamePlay(gameBoard, row, coloumn, player, length);
        count++;
        if(count>9){
            gameWon = true;
        }

    }

    return 0;
}
