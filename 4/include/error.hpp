#ifndef __ERROR_H__
#define __ERROR_H__

#include <exception>
#include <string>

using String = std::string;


class ArrayError : public std::exception {
    private:
        String message;
    public:
        explicit ArrayError(String message) : message(message) {}
        const char* what() const noexcept override {return message.c_str();}
};


#endif
