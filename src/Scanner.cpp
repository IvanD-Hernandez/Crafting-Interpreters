
#include "Scanner.h"
#include <string>
#include "TokenTypes.h"
#include "Token.h"

Scanner::Scanner(std::string _Source){

    Source = _Source;

}

std::vector<Token> Scanner::scanTokens(){

    while(!isAtEnd()){
        start = current;
        scanToken();
    }

    tokens.push_back(new Token(EOFS,"",NULL,line));
}

bool Scanner::isAtEnd(){

    return current >= Source.length();

}

void Scanner::scanToken(){

    char c = advance();

    switch(c){
        case '(':
            addToken(LEFT_PAREN);
            break;
        case ')':
            addToken(RIGHT_PAREN);
            break;
        case '{':
            addToken(LEFT_BRACE);
            break;
        case '}':
            addToken(RIGHT_BRACE);
            break;
        case ',':
            addToken(COMMA);
            break;
        case '.':
            addToken(DOT);
            break;
        case '-':
            addToken(MINUS);
            break;
        case '+':
            addToken(PLUS);
            break;
        case ';':
            addToken(SEMICOLON);
            break;
        case '*':
            addToken(STAR);
            break;


    }

}

char Scanner::advance(){
    return Source.at(current++);
}

void Scanner::addToken(TokenType _type){

    addToken(_type, NULL);

}

void Scanner::addToken(TokenType _type,std::string _literal){

    std::string text = Source.substr(start,(current-start+1)); // may be wrong
    tokens.push_back(new Token(_type,text,_literal,line));

}