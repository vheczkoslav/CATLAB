#include <iostream>
#include <string>
#include <unordered_map>
#include <regex>
#include <vector>

using namespace std;

typedef enum tokenType{
    VARDEC,
    VARDEF,
    OPERATOR,
    SCALAR,
    VECTOR,
    MATRIX,
    INT,
    FLOAT,
    LONG,
};

template <typename T> class Scalar{

};

template <typename T> class Vector{

};

template <typename T> class Matrix{

};

struct Maps {
    std::unordered_map<std::string, tokenType> dataTypeMap;
    std::unordered_map<std::string, int> intMap;
    std::unordered_map<std::string, float> floatMap;
    std::unordered_map<std::string, long> longMap;
};

int vardec(string &token, char c, std::vector<std::regex> RegExes){
    string s(1, c);
    if(token.length() == 0){
        if(!regex_search(s, RegExes[0])){
            return -1;
        }
        else{
            token += c;
        }
    }
    else{
        if(!regex_search(s, RegExes[1])){
            return -1;
        }
        else{
            token += c;
        }
    }
    return 0;
}

int printVal(string &varToken){
    string normalizedToken;
    int len = varToken.length();
    if(len == 0){
        return -2;
    }
    for(int i = 0; i < len; i++){
        if(varToken[i] == ' ') continue;
        else { normalizedToken += varToken[i]; }
    }
    return 0;
}

int lexer(string &tokensLine){
    std::vector<std::regex> RegExes = {
        std::regex("[A-Za-z]"),       
        std::regex("[A-Za-z0-9]")       
    };
    int len = tokensLine.length();
    tokenType dataType = INT;
    tokenType currentExpected = VARDEC;
    string currentToken = "";
    int col = 0;
    for(int i = 0; i < len; i++){
        if(tokensLine[i] == ' ') { continue; }
        if(currentExpected == VARDEC){
            if(tokensLine[i] == '='){
                currentExpected = VARDEF;
                continue;
            }
            if(vardec(currentToken, tokensLine[i], std::vector<std::regex>{RegExes[0], RegExes[1]}) == -1) { cout << "Incorrect var name format!" << endl; break; }
        }
        if(currentExpected = VARDEF){

        }
        if(i == len - 1 && currentExpected == VARDEC){
            int response = 1;
            response = printVal(currentToken);
            switch(response){
                case 0:

                    break;
                case -1:

                    break;
                case -2:
                cout << "No variable name provided!" << endl;
                    break;
            }
        }
        col++;
    }
    return 0;
}

int main(){
    string currentTokens;
    
    while(true){
        getline(cin, currentTokens); 
        if (currentTokens.empty()) continue; 
        if(lexer(currentTokens) == 1) exit(-1);
    }
    return 0; 
}