#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void runFile(std::string path);
void runPrompt();
void run(std::string* pByteString);
void error(int line,std::string message);
void report(int line,std::string where, std::string message);
static bool hadError = false;

int main(int argc, char* argv[]){

    if (argc > 2){
        std::cout << "Usage: main.cpp [script]" << std::endl;
        exit(1);
    }
    else if(argc == 2){
        runFile(argv[0]);
    }
    else{
        runPrompt();
    }

}

void runFile(std::string path){
    std::string ByteString;
    std::string * pByteString = &ByteString;
    std::vector<unsigned char> bytes;
    std::ifstream file;
    file.open(path,std::ios::in);

    if(!file){
        std::cout << "ERROR" << std::endl;
    }
    else{
        while(true){
            unsigned char byte;
            file >> byte;
            if(file.eof()){
                break;
            }
            bytes.push_back(byte);
        }

        for(unsigned char iterator : bytes){
            ByteString.push_back(iterator);
        }
        run(pByteString);

        if(hadError){
            exit(65);
        }

    }

}

void runPrompt(){
    std::string line;
    while(true){
        std::cout << "> ";
        std::cin >> line;
        //TODO:
        // Never empty, detects \n as not empty
        if(line.empty()){
            break;
        }
        run(&line);
        hadError = false;

        line.clear();
    }

}

void run(std::string* pByteString){
    for(unsigned char i : *pByteString){
        std::cout << i;
    }

}

void error(int line,std::string message){

    report(line,"",message);

}

void report(int line,std::string where, std::string message){

    std::cout << "[line " << line << "] Error" << where << ": " << message << std::endl;
    hadError= true;
}