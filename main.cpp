#include <iostream>
#include <string>
#include <unordered_map>
#include <regex>
#include <vector>

using namespace std;

enum TokenType
{
    Integer = 11, // or literal
    Float = 12,
    Long = 13,
    Delimiter = 20, // ; for Vector and Matrixes
    Identifier = 30,
    Operator = 41,
    Equals = 42,
    OpenBracket = 51,
    CloseBracket = 52,
    OpenCurly = 53,
    CloseCurly = 54,
    Invalid = 99
};

string tokenTypeIdToString(TokenType tt){
    switch(tt){
        case 11:
            return "Integer";
        case 12:
            return "Float";
        case 13:
            return "Float";
        case 20:
            return "Delimiter";
        case 30:
            return "Identifier";
        case 41:
            return "Operator";
        case 42:
            return "Equals";
        case 51:
            return "Open Bracket";
        case 52:
            return "Closed Bracket";
        case 53:
            return "Open Curly";
        case 54:
            return "Closed Curly";
        case 99:
            return "Invalid";
        default:
            return "Something went really wrong";                 
    }
}

typedef TokenType DataType;

struct Token
{
    std::string value;
    TokenType type;
};

template <typename T> class Scalar{

};

template <typename T> class Vector{

};

template <typename T> class Matrix{

};

struct{
    std::unordered_map<std::string, DataType> dataTypeMap;
    std::unordered_map<std::string, int> intMap;
    std::unordered_map<std::string, float> floatMap;
    std::unordered_map<std::string, long> longMap;
}Maps;

struct{
    std::regex varName = std::regex("^[A-Za-z][A-Za-z0-9]*$");
    std::regex operators = std::regex("^(\\/=|\\+=|\\-=|\\*=|\\/|\\+|\\-|\\*)$");
    std::regex longFloatRegex = std::regex("^[0-9]+\\.[0-9]+L;$");
    std::regex floatRegex = std::regex("^[0-9]+\\.[0-9]+;$");
    std::regex integerRegex = std::regex("^[0-9]+;$");

}RegExes;

std::string shift(std::vector<std::string> &src)
{
    std::string current = src.front();
    src.erase(src.begin());
    return current;
}

std::vector<std::string> splitString(const std::string &sourceCode) {
    std::vector<std::string> words;
    std::string word;

    for (char ch : sourceCode) {
        if (ch != ' ') {
            word += ch;
        }
        else if(ch == '[' || ch == ']' || ch == '{' || ch == '}'){
            words.push_back(word);
            word.clear();
        }
        else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
        else{}
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}

std::vector<Token> tokenize(std::string &sourceCode) {
    std::vector<Token> tokens;
    std::vector<std::string> src = splitString(sourceCode);

    while (!src.empty()) {
        if(src.front() == "="){
            tokens.push_back({shift(src), TokenType::Equals});
        }
        if (src.front() == "[") {
            tokens.push_back({shift(src), TokenType::OpenBracket});
        }
        else if (src.front() == "]") {
            tokens.push_back({shift(src), TokenType::CloseBracket});
        }
        else if (src.front() == "{") {
            tokens.push_back({shift(src), TokenType::OpenCurly});
        }
        else if (src.front() == "}") {
            tokens.push_back({shift(src), TokenType::CloseCurly});
        }
        else if(src.front() == ";"){
            tokens.push_back({shift(src), TokenType::Delimiter});
        }
        else if(regex_search(src.front(), RegExes.operators)){
            tokens.push_back({shift(src), TokenType::Operator});
        }
        else if(regex_search(src.front(), RegExes.varName)){
            tokens.push_back({shift(src), TokenType::Identifier});
        }
        else if(regex_search(src.front(), RegExes.longFloatRegex)){
            tokens.push_back({shift(src), TokenType::Long});
        }
        else if(regex_search(src.front(), RegExes.floatRegex)){
            tokens.push_back({shift(src), TokenType::Float});
        }
        else if(regex_search(src.front(), RegExes.integerRegex)){
            tokens.push_back({shift(src), TokenType::Integer});
        }
        else{
            tokens.push_back({shift(src), TokenType::Invalid});
        }
    }

    return tokens;
}

int main(){
    std::string currentLine;
    while(true){
        getline(cin, currentLine);
        std::vector<Token> tokens = tokenize(currentLine);
        for(int i = 0; i < tokens.size(); i++){
            cout << "Token value: " << tokens[i].value << ", type: " << tokenTypeIdToString(tokens[i].type) << endl;
        }
    }
    return 0; 
}
