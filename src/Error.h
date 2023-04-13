#ifndef ERROR_H
#define ERROR_H

#include <string>

class Error{
    public:
        Error();
        void new_Error(int line,std::string message);
        static bool hadError;
    private:
        void report(int line,std::string where, std::string message);   


};





#endif