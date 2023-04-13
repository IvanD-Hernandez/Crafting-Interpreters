#ifndef SCANNER_H
#define SCANNER_H

#include "TokenTypes.h"
#include "Token.h"
#include <string>
#include <vector>
#include <map>

class Scanner {
    public:
        Scanner(std::string _Source);
        std::vector<Token> scanTokens();

    private:
        std::string Source;
        std::vector<Token*> tokens; //???

        int start = 0;
        int current = 0;
        int line = 1;
        bool isAtEnd();
        void scanToken();
        char advance();
        void addToken(TokenType _type);
        void addToken(TokenType _type,std::string _literal); //TODO UPdate to object
        bool match(char _expected);
        char peek();
        void string();
        bool isDigit(char c);
        void number();
        char peekNext();
        void identifier();
        bool isAlpha(char c);
        bool isAlphaNumeric(char c);

        const std::map<std::string,TokenType> keywords = {
            {"and",AND},
            {"class",CLASS},
            {"else",ELSE},
            {"false",FALSE},
            {"for",FOR},
            {"fun",FUN},
            {"if",IF},
            {"nil",NIL},
            {"or",OR},
            {"print",PRINT},
            {"return",RETURN},
            {"super",SUPER},
            {"this",THIS},
            {"true",TRUE},
            {"var",VAR},
            {"while",WHILE}
        };

};


#endif