#ifndef LINDATUPLE_H
#define LINDATUPLE_H

#include <iostream>

class LindaTuple
{
public:
    LindaTuple();
};

class LindaTupleElement
{
    enum class Type
    {
        Integer = 'i',
        Float   = 'f',
        String  = 's'
    };

    union Content
    {
        char* string_data;
        int int_data;
        float float_data;
    };

    Type    type;
    size_t  size;
    Content content;
public:
    LindaTupleElement(std::string string_data);
    LindaTupleElement(float float_data);
    LindaTupleElement(int int_data);

    LindaTupleElement();
    LindaTupleElement(const LindaTupleElement& element);
};

#endif // LINDATUPLE_H
