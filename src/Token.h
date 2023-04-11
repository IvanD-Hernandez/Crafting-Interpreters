#ifndef TOKENC_H
#define TOKENC_H

#include "TokenTypes.h"
#include <string>

class Token{
    public:
    Token(TokenType _Type, std::string _lexeme, std::string _literal, int _line);
    std::string toString();

    private:
    TokenType type;
    std::string lexeme;
    //TODO: Object Literal
    std::string literal;
    int line;
};


#endif