#include <iostream>
#include <vector>
#include <typeinfo>
#include <map>
#include <random>
#include <time.h>

void PrintHelp(std::string program){
    std::cout<< "Usage:" <<program<< "[options]  length\n";
    std::cout<< "-h\t help\n";
    std::cout<< "-n\t numbers\n";
    std::cout<< "-l\t letters\n";
    std::cout<< "-s\t symbols\n";
}

int main(int argc, char* args[])
{

if(argc < 3){
    PrintHelp(args[0]);
    return 0;
}

std::srand(static_cast<unsigned>(time(NULL)));

const int NUMS = 1,LETTERS = 2,SYMBOLS = 3,HELP = 4;

char nums[] = {'1','2','3','4','5','6','7','8','9','0'};
char letters [] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char symbols [] = {'!','@','#','&','(',')','-','[','{','}',']',':',';','\'',',','?','/','*','`','~','$','^','+','=','<','>','"'};
std::vector<char> allChars;

std::map <std::string, int> mapping;
mapping["-n"] =NUMS;
mapping["-l"] =LETTERS;
mapping["-s"] =SYMBOLS;
mapping["-h"] =HELP;

bool addedNums,addedLetters,addedSymbols = false;

    for(int i = 1; i < argc-1 ; i++){
    switch(mapping[args[i]]){
        case NUMS:
        if(!addedNums){
            for(char e : nums){
                allChars.push_back(e);
            }
            addedNums = true;
        }
        break;
        case LETTERS:
        if(!addedLetters){
            for(char e : letters){
                allChars.push_back(e);
            }
            addedLetters = true;
        }
        break;
        case SYMBOLS:
        if(!addedSymbols){
            for(char e : symbols){
                allChars.push_back(e);
            }
            addedSymbols = true;
        }
        break;
        case HELP:
            PrintHelp(args[0]);
            return 0;
        }
    }
    int n = atoi(args[argc-1]);
    std::cout<< n <<std::endl;

    for(char e : allChars){
    std::cout<<e<<", ";
    }

    char *password = new char(n);
    int allCharsLength = allChars.size();

    for(int i = 0; i < n; i++){
    int r = rand()%allCharsLength;
    password[i] = allChars[r];
    }

    std::cout<<password<<std::endl;

    return 0;
}
