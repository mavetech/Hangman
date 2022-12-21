#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void displayHangman(int level){
    
    
    char b[][37] = {
        {' ','+', '-', '-', '-', '+',' ', '|', ' ', ' ', ' ', '|',' ','|', ' ', ' ', ' ', '|',' ',' ', ' ', ' ', ' ', '|',' ',' ', ' ', ' ', ' ', '|',' ', '=','=','=','=','=' },
        {' ','+', '-', '-', '-', '+',' ', '|', ' ', ' ', ' ', '|',' ','O', ' ', ' ', ' ', '|',' ',' ', ' ', ' ', ' ', '|',' ',' ', ' ', ' ', ' ', '|',' ', '=','=','=','=','=' },
        {' ','+', '-', '-', '-', '+',' ', '|', ' ', ' ', ' ', '|',' ','O', ' ', ' ', ' ', '|',' ','|', ' ', ' ', ' ', '|',' ',' ', ' ', ' ', ' ', '|',' ', '=','=','=','=','=' },
        {' ','+', '-', '-', '-', '+',' ', '|', ' ', ' ', ' ', '|',' ','O', ' ', ' ', ' ', '|',' ','|', '\\', ' ', ' ', '|',' ',' ', ' ', ' ', ' ', '|',' ', '=','=','=','=','=' },
        {' ','+', '-', '-', '-', '+',' ', '|', ' ', ' ', ' ', '|',' ','O', ' ', ' ', ' ', '|','/','|', '\\', ' ', ' ', '|',' ',' ', ' ', ' ', ' ', '|',' ', '=','=','=','=','=' },
        {' ','+', '-', '-', '-', '+',' ', '|', ' ', ' ', ' ', '|',' ','O', ' ', ' ', ' ', '|','/','|', '\\', ' ', ' ', '|',' ',' ', '\\', ' ', ' ', '|',' ', '=','=','=','=','='},
        {' ','+', '-', '-', '-', '+',' ', '|', ' ', ' ', ' ', '|',' ','O', ' ', ' ', ' ', '|','/','|', '\\', ' ', ' ', '|','/',' ', '\\', ' ', ' ', '|',' ', '=','=','=','=','='},
    };
    
    for(int i=1;i<37;i++){
        cout<<b[level][i-1];
        if(i%6==0 && i!=0){
            cout<<endl;
        }
    }

}


int main()
{
    srand(time(0));
    int randomIndex = rand()%100+1;
    
    char worldList[100][11]={"climb", "hill", "fear", "fast", "catch", "dizzy", "length", "sight","sketch", "wrath", "rear", "mountain", "town", "river", "school", "float", "breathe", "shiny", "play", "power", "tiger", "lion", "chaos", "dreadful", "amazing", "superior", "inferior", "lost", "fantastic", "frown", "cascade", "proud", "general", "army", "pakistan", "country", "century", "grace", "match", "fate", "green", "orange", "grey", "brown", "black", "white", "blue", "colour", "bitter", "sweet", "grateful", "thankful", "gratitude", "shrink", "time", "playful", "subject", "verb", "adjective", "object", "understand", "language", "english", "laptop", "computer", "science", "politics", "television", "world", "broad", "excercise", "bigotry", "escape", "plan", "gasp", "threat", "malice", "divine", "november", "calendar", "arcade", "knowledge", "small","trench", "weary", "budget", "beach", "shopping", "letter", "print", "sword", "trouser", "drop", "mint", "guide", "tower", "glance", "game", "minute", "flyer"};
    char word[11];
    int sizeOfWord=0;
    for(int i=0;i<11;i++) {
        if(worldList[randomIndex][i]){
            
            word[i] = worldList[randomIndex][i];
            sizeOfWord++;  
        }
    } 
    
    int level=0;
    int success=0;
    int checkRepeat[sizeOfWord]={0};
    char input;
    bool wordExists = false, alreadyInputted = false;
    cout<<"WordSize:"<<sizeOfWord<<endl;
    
    while(level < 7 && success < sizeOfWord) {
        cout<<"Input alphabet: ";
        cin>>input;
        for(int i=0;i<sizeOfWord;i++){
            if(word[i]==input && checkRepeat[i]==0){
               wordExists = true;
               checkRepeat[i] = 1;
               success++;
               cout<<"word:"<<word[i]<<", char:"<<input<<endl;
            }
            else if (word[i]==input && checkRepeat[i]==1){
                alreadyInputted = true;
                cout<<"Already provided"<<endl;
                break;
            }
        }
        if(wordExists==false && alreadyInputted==false) {
            displayHangman(level);
            level++;
        }
        alreadyInputted = false;
        wordExists = false;
    }
    
    if(success>=7) {
        cout<<"Success"<<endl;
    }
    else if(level>=7) {
        cout<<"Not Successful"<<endl;
    }
    
    std::cout<<"Word selected is: ";
    for(int i=0;i<sizeOfWord;i++) {
        std::cout<<word[i];
    } 
    
    return 0;
}
