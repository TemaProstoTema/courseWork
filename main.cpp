#include <iostream>
#include <iomanip>//?
#include<ctime>
#include <cstdlib>

int board[4][4];
int score;
int dirLine[]={1,0,-1,0};//передвижение для строки
int dirColumn[]={0,1,0,-1};//передвижение для столбца

std::pair<int,int> generateNum(){
    int engaged = 1;
    int line , column;
    while(engaged!=0){
         line  = rand() %4;//how work
         column = rand() %4;
        if (board[line][column] == 0){
            engaged = 0;
        }
    }
    return std::make_pair(line,column);
}

void addPiece(){
    std::pair<int,int> position = generateNum();
    board[position.first][position.second] = 2;//?
}

void resetGame(){
    for(int i =0; i<4; ++i){
        for(int j =0; j<4;++j){
        board[i][j]=0;
        }
    }
    addPiece();
}

void gameBoard(){
    //system("cls");
    for(int i =0; i<4;i++){
        for(int j =0; j<4;j++) {

            if (board[i][j] == 0) {
                std::cout <<std::setw(4)<<"_";
            } else {
                std::cout <<std::setw(4)<< board[i][j];
            }
        }
        std::cout << std::endl;

    }
    std::cout<<"n: новая игра "<<"w: вверх "<<"s: вниз"<<"a: влево"<<"d: вправо"<<"q: выход\n";
    std::cout<<"Счёт: "<<score<<std::endl;
}

bool possibilityMove(int line, int column, int nextLine, int nextColumn){
    if(nextLine<0||nextColumn<0||nextLine>=4||nextColumn>=4||board[line][column] != board[nextLine][nextColumn] && board[nextLine][nextColumn]!=0){
        return false;
    }else{
        return true;
    }
}

void move(int dir) {
    int startLine = 0, startColumn = 0, lineStep = 1, columnStep = 1;
    if (dir == 0) {
        startLine = 3;
        lineStep = -1;
    }
    if (dir == 1) {//right
        startColumn = 3;
        columnStep = -1;
    }
    int movePossible, canAddPiece =0;//?
    do {


        movePossible = 0;

        for (int i = startLine; i >= 0 && i < 4; i += lineStep) {
            for (int j = startColumn; j >= 0 && j < 4; j += columnStep) {
                int nextI = i + dirLine[dir];
                int nextJ = j + dirColumn[dir];
                //std::cout<<i<<" "<<j<<" "<<nextI<<" "<<nextJ<<std::endl;
                if (board[i][j]!=0 && possibilityMove(i, j, nextI, nextJ)) {
                    board[nextI][nextJ] += board[i][j];
                    if(board[nextI][nextJ]>2){
                        score += board[nextI][nextJ];
                    }
                    //если происходит сложение, то score = sum


                    board[i][j] = 0;
                    movePossible = canAddPiece =1;//?

                }
            }
        }

}while(movePossible== true);
    if(canAddPiece== true){
        addPiece();
    }
}

int main() {
    srand(time(0));//?
    char commandToDir[128];
    commandToDir['s']=0;
    commandToDir['d']=1;
    commandToDir['w']=2;
    commandToDir['a']=3;
    resetGame();
    while(true){
    gameBoard();
    char command;
    std::cin>>command;
    if(command == 'q'){
        resetGame();
        }
    if(command == 'w' ){//up

        }
    if(command == 's'){//down

        }
    if(command == 'a'){//left

    }
    if(command == 'd'){//right

    }
    if(command == 'q'){
        break;

    }
    else{
        int curDir = commandToDir[command];
        //std::cout<<curDir<<"\n";
        move(curDir);
        }
    }
    return 0;
}
