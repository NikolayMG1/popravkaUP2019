#include <iostream>
#include <cstring>

bool recursion(char C[3][4] ,char* word,char* buffer,int x,int y,int l){
	
	//std::cout << x << " " << y << '\n';
	buffer[l] = C[x][y];
	buffer[l+1] = '\0';
	//std::cout << buffer[l];
	C[x][y] = '.';

	//std::cout << strcmp(buffer, word);

	if(!strcmp(buffer, word)){
		std::cout << "da brat";
		return true;
	}
	l++;
	//nagore
	if((C[x-1][y] != '.' && word[l-1] == C[x-1][y]) && x < 2 && y < 2 && x >= 0 && y >= 0 && l < 8){
		std::cout << "1";
		return recursion(C, word, buffer ,x - 1, y, l);
	}
	//dolu
	if((word[l] == C[x+1][y] && C[x+1][y] != '.') && x < 2 && y < 2 && x >= 0 && y >= 0 && l < 8){
		std::cout << "2";
		return recursion(C, word, buffer ,x + 1, y,l);
	}
	//dqsno
	if((word[l] == C[x][y+1] && C[y][y+1] != '.') && x < 2 && y < 2 && x >= 0 && y >= 0 && l < 8){
		//std::cout << "3";
		return (recursion(C, word, buffer ,x , y+1,l));
	}
	//lqvo
	if((word[l] == C[x][y-1] && C[x][y-1] != '.') && x < 2 && y < 2 && x >= 0 && y >= 0 && l < 8){
		std::cout << "4";
		return recursion(C, word, buffer ,x , y-1,l);
	}
	return false;
}

bool crossword (char C[3][4], char** words, unsigned n){

    int count = 0;
	int startX;
	int startY;

    for(int i = 0; i < n; i++){
		int l = 0;
		char buffer[10];
		buffer[9] = '\0';
		char firstLetter = words[i][0];
							
		for(int k = 0; k < 3; k++){
			for(int b = 0; b < 3; b++){
				
				if(C[k][b] == firstLetter){
                    
					startX = k;
					startY = b;
					if(recursion(C, words[i], buffer, startX, startY, l)){
						//std::cout << "bonk";
						count++;
					}
					else{
						return false;
					}
				}
			}
		}
    }
	if(count == n){
		return true;
	}
}

int main(){
    
    char C[3][4] = {
		"cat",
		"who",
		"win"
	};
    std::cout << "Enter the numbers of words: ";
    int n;
    std::cin >> n;
	C[0][3] = '0'; 
	C[1][3] = '0'; 
	C[2][3] = '0'; 
    std::cout << "Enter the words: " << '\n';
    char** words = new char*[n];
    for(int i = 0; i < n; i++){
        std::cout << i+1 << ".";
        words[i] = new char[10];
        std::cin >> words[i];
        std::cout << '\n';
    }

    if(crossword (C, words, n)){
		std::cout << "bachka";
	}
	

    for(int i = 0; i < n; i++){
        delete[] words[i];
    }
    delete[] words;
}

