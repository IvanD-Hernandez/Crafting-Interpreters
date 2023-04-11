#ifndef SCANNER_H
#define SCANNER_H

#include "TokenTypes.h"
#include "Token.h"
#include <string>
#include <vector>

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


};


#endif