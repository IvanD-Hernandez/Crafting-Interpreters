
#include <string>
#include "Token.h"

Token::Token(TokenType _type, std::string _lexeme, std::string _literal, int _line){
    type = _type;
    lexeme = _lexeme;
    literal = _literal;
    line = _line;
};

std::string Token::toString(){
    return type + " " + lexeme + " " + literal; 
};