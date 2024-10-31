#include <iostream>
#include <string>
#include <unordered_map>
#include <regex>
#include <vector>

using namespace std;

typedef enum{
    VARDEC,
    VARDEF,
    OPERATOR,
    SCALAR,
    VECTOR,
    MATRIX,
    INT,
    FLOAT,
    LONG,
}tokenType;

template <typename T> class Scalar{

};

template <typename T> class Vector{

};

template <typename T> class Matrix{

};

struct{
    std::unordered_map<std::string, tokenType> dataTypeMap;
    std::unordered_map<std::string, int> intMap;
    std::unordered_map<std::string, float> floatMap;
    std::unordered_map<std::string, long> longMap;
}Maps;

struct{
    std::regex varNameFirstLetter = std::regex("[A-Za-z]"); 
    std::regex varNameNonFirstLetter = std::regex("[A-Za-z0-9]");
    std::regex operators = std::regex("^(\\/=|\\+=|\\-=|\\*=|=)$");
}RegExes;

void savevar(){}

int vardec(string &token, char c){
    string s(1, c);
    if(token.length() == 0){
        if(regex_search(s, RegExes.operators)){
            cout << "You must declare var before assigning value!" << endl;
            return -1;
        }
        if(!regex_search(s, RegExes.varNameFirstLetter)){
            cout << "Incorrect var name format!" << endl;
            return -2;
        }
        else{
            token += c;
        }
    }
    else{
        if(!regex_search(s, RegExes.operators)){
            return -3;
        }
        if(!regex_search(s, RegExes.varNameNonFirstLetter)){
            cout << "Incorrect var name format or operation!" << endl;
            return -2;
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
        return -1;
    }
    for(int i = 0; i < len; i++){
        if(varToken[i] == ' ') continue;
        else { normalizedToken += varToken[i]; }
    }
    auto it = Maps.dataTypeMap.find(normalizedToken);
    if (it == Maps.dataTypeMap.end()) {
        return -2;
    }

    switch (it->second) {
        case tokenType::INT:
            std::cout << Maps.intMap[normalizedToken] << std::endl;
            break;
        case tokenType::FLOAT:
            std::cout << Maps.floatMap[normalizedToken] << std::endl;
            break;
        case tokenType::LONG:
            std::cout << Maps.longMap[normalizedToken] << std::endl;
            break;
        default:
            return -3;
    }
    return 0;
}

int lexer(string &tokensLine){
    int len = tokensLine.length();
    tokenType dataType = INT;
    tokenType currentExpected = VARDEC;
    string currentToken = "";
    int col = 0;
    for(int i = 0; i < len; i++){
        //if(tokensLine[i] == ' ') { continue; }
        if(currentExpected == VARDEC){
            if(vardec(currentToken, tokensLine[i]) == -3){
                savevar(currentToken)
            };
        }
        if(currentExpected = VARDEF){

        }
        if(i == len - 1 && currentExpected == VARDEC){
            int response = 1;
            response = printVal(currentToken);
            switch(response){
                case -1:

                    break;
                case -2:

                    break;
                case -3:

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