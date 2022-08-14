#include <iostream>
#include <cstring>

void encode (char* s1,char* r1, char* s2, char* r2){
    for(int i = 0; i < strlen(s1);i++){
        
    }
}

int main(){
    char alphabet[27];
    int n = 97;
    for(int i = 0; i < 26; i++){
        alphabet[i] = n++;
    }
    alphabet[26] = '1';
    alphabet[27] = '\0';
    
    char s1[64] = "hello";
    char r1[64];
    char s2[64] = "love";
    char r2[64];
    
    encode(s1,r1,s2,r2);
}