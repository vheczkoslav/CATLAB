#include <vector>
#include <string>

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

typedef TokenType DataType;

struct Token
{
    string value;
    TokenType type;
};

class ASTNode { /* Base class */
    Token val;
    ASTNode* left = nullptr;
    ASTNode* right = nullptr;
public:
    ASTNode(Token val) : val{val}{
        
    };
};
class AssignmentNode : public ASTNode { /* Left = Right */ };
class BinaryOpNode : public ASTNode { /* Left op Right */ };

string parser(vector<Token> tokenizedStream){
    if(tokenizedStream.front().type != TokenType::Identifier){
        
    }
    else{
        return "Every statement must always begin with identifier!";
    }
};

void parseStatement(vector<Token> tokenizedStream, int currentIndex){

}