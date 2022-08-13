#include <iostream>
#include <cstring>

const int HEIGHT = 5;
const int WIDTH = 6;
bool test(char matrix[][6],const int n, int x,int y){
    
    std::cout << '\n' << "------------------" ;
    std::cout << "[" << x << "][" << y << "]" << '\n';
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            std::cout << i << "|" << matrix[i][j] << "|" << j << '\t';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    if(x == n || y == n || x < 0 || y < 0 || matrix[x][y] == '*' || matrix[x][y] == '.'){
        std::cout << "Stop" << '\n';
        return false;
    }
    if(matrix[x][y] == '$'){
        //std::cout << "namereno" << std::endl;
        return true;
    }
    //minato
    matrix[x][y] = '.';
    //nagore
    if(test(matrix, n , x - 1, y)){
        return true;
    }
    //nadolu
    if(test(matrix, n , x + 1, y)){
        return true;
    }
    //dqsno
    if(test(matrix, n , x    , y+1)){
        return true;
    }
    //lqvo
    if(test(matrix, n , x    , y-1)){
        return true;
    }
    return false;
}


void labyrinth(){
    char matrix[HEIGHT][WIDTH] = {"* ** ", "     ", " ***$", "    *", "  ** "};
    
    int startX = 4;
    int startY = 1;




    if(test(matrix, 5, startX, startY)){
        std::cout << "namerihme go" << '\n';
    }
    else{
        std::cout << "ne";
    }
    
    
}


int main(){
    labyrinth();
}
