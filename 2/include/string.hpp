#ifndef __STRING__
#define __STRING__

#include <istream>
#include <ostream>


class String {
    private:
        int len = 0;
        char* data = nullptr;
    public:
        String(const char* data = nullptr);
        String(const String& other);
        String& operator=(const String& other);
        ~String();

        String operator+(const String& other) const;
        String operator+(const char* literal) const;
        friend String operator+(const char* literal, const String& other);

        String& operator+=(const String& other);
        String& operator+=(const char* literal);

        char operator[](int index) const;
        String operator()(int start, int stop) const;

        bool operator==(const String& other);
        bool operator<(const String& other);
        bool operator>(const String& other);

        friend std::ostream& operator<<(std::ostream& ostream, const String& other);
        friend std::istream& operator>>(std::istream& istream, String& other);
};


#endif
