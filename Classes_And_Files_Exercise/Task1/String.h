#ifndef String_H
#define String_H

class String {
    char* string;

public:
    String(const char*);
    String(String const& other);
    String& operator=(String const& other);

    ~String();
    String(String&& other);
    String& operator=(String&& other);

    char operator[](const char symbol) const;
    String operator+(const char*) const;
    String operator+(const String& string) const;

    
};







#endif
