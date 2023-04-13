
#include "Scanner.h"
#include <string>
#include "TokenTypes.h"
#include "Token.h"
#include <iostream>

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
        //operators
        case '!':
            addToken(match('=') ? BANG_EQUAL : EQUAL);
            break;
        case '=':
            addToken(match('=') ? EQUAL_EQUAL : EQUAL);
            break;
        case '<':
            addToken(match('=') ? LESS_EQUAL : LESS);
            break;
        case '>':
            addToken(match('=') ? GREATER_EQUAL : GREATER);
            break;
        case '/':
            if(match('/')){
                while(peek() != '\n' && !isAtEnd()) advance();
            }
            else{
                addToken(SLASH);
            }
            break;
        case ' ':
        case '\r':
        case '\t':
            break;
        case '\n':
            line++;
            break;
        case '"':
            string();
            break;
        case 'o':
            if(match('r')){
                addToken(OR);
            }
            break;
        default:
            if(isDigit(c)){
                number();
            }
            else if(isAlpha(c)){
                identifier();
            }
            else{
            // TODO: Update error class
            std::cout << "error" << std::endl;
            break;
            }

    }

}

void Scanner::identifier(){
    while(isAlphaNumeric(peek())) advance();
    std::string text = Source.substr(start,(current-start));
    TokenType type = keywords.at(text);
    if(type == NULL) type = IDENTIFIER;

    addToken(type);
}

void Scanner::number(){
    while (isDigit(peek())) advance();

    if(peek() == '.' && isDigit(peekNext())){
        advance();

        while (isDigit(peek())) advance();
    }
    // TODO: FIX for literals
    addToken(NUMBER,Source.substr(start,(current-start)));
}

void Scanner::string(){
    while(peek() != '"' && !isAtEnd()){
        if(peek() == '\n') line++;
        advance();
    }

    if(isAtEnd()){
        // TODO: Update error class
        std::cout << "error" << std::endl;
    }

    advance();

    std::string value = Source.substr(start+1,(current-start)-1); 

}//   "string"

bool Scanner::match(char _expected){
    if(isAtEnd()) return false;
    if(Source.at(current) != _expected) return false;

    current++;
    return true;
}

char Scanner::peek(){
    if(isAtEnd()) return '\0';
    return Source.at(current);
}

char Scanner::peekNext(){
    if(current + 1 >= Source.length()) return '\0';

    return Source.at(current + 1);
}

bool Scanner::isAlpha(char c){
    return ((c >= 'a' && c <= 'z') ||
            (c >= 'a' && c <= 'z') ||
             c == '_');
}

bool Scanner::isAlphaNumeric(char c){
    return isAlpha(c) || isDigit(c);
}

bool Scanner::isDigit(char c){
    return (c >= '0' && c <= '9');
}

char Scanner::advance(){
    return Source.at(current++);
}

void Scanner::addToken(TokenType _type){

    addToken(_type, NULL);

}

void Scanner::addToken(TokenType _type,std::string _literal){

    std::string text = Source.substr(start,(current-start)); // may be wrong
    tokens.push_back(new Token(_type,text,_literal,line));

}