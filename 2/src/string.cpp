#include "string.hpp"
#include <cstring>
#include <iostream>
#include <string>


String::String(const char* data){
    if (data == nullptr)
        return;
    this->len = strlen(data);
    this->data = new char[this->len + 1]{0};
    strcpy(this->data, data);
}

String::String(const String& other){
    if (this == &other)
        return;
    this->len = other.len;
    this->data = new char[other.len + 1]{0};
    strcpy(this->data, other.data);
}

String& String::operator=(const String& other){
    if (this != &other){
        delete[] this->data;
        this->len = other.len;
        this->data = new char[other.len + 1]{0};
        strcpy(this->data, other.data);
    }
    return *this;
}

String::~String(){
    delete[] this->data;
}

String String::operator+(const String& other) const {
    String result;
    result.len = this->len + other.len;
    result.data = new char[this->len + other.len + 1]{0};
    strcpy(result.data, this->data);
    strcat(result.data, other.data);
    return result;
}

String String::operator+(const char* literal) const {
    return *this + String(literal);
}

String operator+(const char* literal, const String& other){
    return String(literal) + other;
}

String& String::operator+=(const String& other){
    String tmp = *this + other;
    *this = tmp;
    return *this;
}

String& String::operator+=(const char* literal){
    *this += String(literal);
    return *this;
}

String& String::operator++(){
    for (int i = 0; i < this->len; i++)
        ++this->data[i];
    return *this;
}

String String::operator++(int){
    String result = *this;
    for (int i = 0; i < this->len; i++)
        ++this->data[i];
    return result;
}

char& String::operator[](int index) const {
    return this->data[index];
}

String String::operator()(int start, int end) const {
    String result;
    char* data = new char[end - start + 2]{0};
    strncpy(data, this->data + start, end - start + 1);
    result.data = data;
    result.len = end - start + 2;
    return result;
}

bool String::operator==(const String& other) const {
    return !strcmp(this->data, other.data);
}

bool String::operator!=(const String& other) const {
    return !(*this == other);
}

bool String::operator<(const String& other) const {
    return this->len < other.len;
}

bool String::operator>(const String& other) const {
    return this->len > other.len;
}


std::ostream& operator<<(std::ostream& ostream, const String& other){
    return ostream << "String(" << other.data << ")" << std::endl;
}


std::istream& operator>>(std::istream& istream, String& other){
    istream >> std::ws;
    std::string tmpString;
    std::getline(istream, tmpString);
    other = tmpString.c_str();
    return istream;
}
