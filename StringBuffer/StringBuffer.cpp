//
// Created by Davide on 2019-07-21.
//

#include <iostream>
#include "StringBuffer.h"

using namespace std;

// printf("New size: %d\nNew #blocks: %d\nNew string: %s\n", StringBuffer::length, StringBuffer::n_blocks, StringBuffer::string);

StringBuffer::StringBuffer()
{
    StringBuffer::n_blocks = 1;
    StringBuffer::length = 0;
    StringBuffer::string = new char[StringBuffer::n_blocks*LEN];
}

StringBuffer::StringBuffer(const char *string)
{
    int size = 0;
    for(int i = 0; string[i] != '\0'; i++, size++);
    StringBuffer::length = size;
    StringBuffer::n_blocks = ((size + 1)/LEN) + 1;
    StringBuffer::string = new char[StringBuffer::n_blocks*LEN];
    for(int i = 0; i < StringBuffer::length; i++) {
        StringBuffer::string[i] = string[i];
    }
    StringBuffer::string[StringBuffer::length] = '\0';
}

StringBuffer::StringBuffer(const StringBuffer &sb)
{
    StringBuffer::length = sb.length;
    StringBuffer::n_blocks = sb.n_blocks;
    StringBuffer::string = new char[StringBuffer::n_blocks*LEN];
    for(int i = 0; i < sb.length; i++) {
        StringBuffer::string[i] = sb.string[i];
    }
    StringBuffer::string[StringBuffer::length] = '\0';
}

StringBuffer::~StringBuffer()
{
    StringBuffer::n_blocks = 0;
    StringBuffer::length = 0;
    delete[] StringBuffer::string;
    printf("Oggetto distrutto\n");
}

StringBuffer &StringBuffer::operator=(const StringBuffer &sb)
{
    if(StringBuffer::n_blocks >= sb.n_blocks) {
        for(int i = 0; i < sb.length; i++) {
            StringBuffer::string[i] = sb.string[i];
        }
        StringBuffer::string[sb.length] = '\0';
        StringBuffer::length = sb.length;
    } else {
        StringBuffer::n_blocks = ((sb.length + 1)/LEN) + 1;
        char *new_string = new char[StringBuffer::n_blocks*LEN];
        delete[] StringBuffer::string;
        for(int i = 0; i < sb.length; i++) {
            new_string[i] = sb.string[i];
        }
        new_string[sb.length] = '\0';
        StringBuffer::length = sb.length;
        StringBuffer::string = new_string;
    }
}

void StringBuffer::append(const char *string)
{
    int size = 0;
    for (int i = 0; string[i] != '\0'; i++, size++);
    if (((StringBuffer::length + size + 1) / LEN) + 1 > StringBuffer::n_blocks) {
        StringBuffer::n_blocks = ((StringBuffer::length + size + 1) / LEN) + 1;
        char *new_string = new char[StringBuffer::n_blocks*LEN];
        for(int i = 0; i < StringBuffer::length; i++) {
            new_string[i] = StringBuffer::string[i];
        }
        delete[] StringBuffer::string;
        for (int i = 0, j = StringBuffer::length; i < size; i++, j++) {
            new_string[j] = string[i];
        }
        StringBuffer::length += size;
        new_string[StringBuffer::length] = '\0';
        StringBuffer::string = new_string;
    } else {
        for (int i = 0, j = StringBuffer::length; i < size; i++, j++) {
            StringBuffer::string[j] = string[i];
        }
        StringBuffer::length += size;
        StringBuffer::string[StringBuffer::length] = '\0';
    }
}

void StringBuffer::append(const StringBuffer &sb)
{
    if (((StringBuffer::length + sb.length + 1) / LEN) + 1 > StringBuffer::n_blocks) {
        StringBuffer::n_blocks = ((StringBuffer::length + sb.length + 1) / LEN) + 1;
        char *new_string = new char[StringBuffer::n_blocks*LEN];
        for(int i = 0; i < StringBuffer::length; i++) {
            new_string[i] = StringBuffer::string[i];
        }
        delete[] StringBuffer::string;
        for (int i = 0, j = StringBuffer::length; i < sb.length; i++, j++) {
            new_string[j] = sb.string[i];
        }
        StringBuffer::length += sb.length;
        new_string[StringBuffer::length] = '\0';
        StringBuffer::string = new_string;
    } else {
        for (int i = 0, j = StringBuffer::length; i < sb.length; i++, j++) {
            StringBuffer::string[j] = sb.string[i];
        }
        StringBuffer::length += sb.length;
        StringBuffer::string[StringBuffer::length] = '\0';
    }
}

const char *StringBuffer::c_str()
{
    return StringBuffer::string;
}

size_t StringBuffer::size()
{
    return StringBuffer::length;
}

size_t StringBuffer::capacity()
{
    return StringBuffer::n_blocks;
}

void StringBuffer::clear()
{
    delete[] StringBuffer::string;
    StringBuffer::string = new char[StringBuffer::n_blocks*LEN];
    StringBuffer::string[0] = '\0';
    StringBuffer::length = 0;
}

void StringBuffer::set(const char *string)
{
    int size = 0;
    for(int i = 0; string[i] != '\0'; i++, size++);
    if (((size + 1) / LEN) + 1 > StringBuffer::n_blocks) {
        StringBuffer::n_blocks = ((StringBuffer::length + size + 1) / LEN) + 1;
        delete[] StringBuffer::string;
        StringBuffer::string = new char[StringBuffer::n_blocks*LEN];
    }
    for (int i = 0; i < size; i++) {
        StringBuffer::string[i] = string[i];
    }
    StringBuffer::length = size;
    StringBuffer::string[StringBuffer::length] = '\0';
}

void StringBuffer::set(const StringBuffer &sb)
{
    if (StringBuffer::n_blocks < sb.n_blocks) {
        StringBuffer::n_blocks = sb.n_blocks;
        delete[] StringBuffer::string;
        StringBuffer::string = new char[StringBuffer::n_blocks*LEN];
    }
    for (int i = 0; i < sb.length; i++) {
        StringBuffer::string[i] = sb.string[i];
    }
    StringBuffer::length = sb.length;
    StringBuffer::string[StringBuffer::length] = '\0';
}

void StringBuffer::insert(const char *string, size_t pos)
{
    int size = 0;
    for(int i = 0; string[i] != '\0'; i++, size++);
    if((((StringBuffer::length + size + 1)/LEN) + 1) > StringBuffer::n_blocks) {
        StringBuffer::n_blocks = ((StringBuffer::length + size + 1)/LEN) + 1;
        char *new_string = new char[StringBuffer::n_blocks*LEN];
        for(int i = 0; i < pos; i++) {
            new_string[i] = StringBuffer::string[i];
        }
        for(int i = pos, j = 0; j < size; i++, j++) {
            new_string[i] = string[j];
        }
        for(int i = pos + size, j = pos; j < StringBuffer::length; i++, j++) {
            new_string[i] = StringBuffer::string[j];
        }
        delete[] StringBuffer::string;
        StringBuffer::string = new_string;
        StringBuffer::length += size;
        StringBuffer::string[StringBuffer::length] = '\0';
    } else {
        for(int i = pos, j = 0; j < size; i++, j++) {
            StringBuffer::string[i] = string[j];
        }
        for(int i = pos + size, j = pos; j < StringBuffer::length; i++, j++) {
            StringBuffer::string[i] = StringBuffer::string[j];
        }
        StringBuffer::length += size;
        StringBuffer::string[StringBuffer::length] = '\0';
    }
}

void StringBuffer::insert(const StringBuffer &sb, size_t pos)
{
    if((((StringBuffer::length + sb.length + 1)/LEN) + 1) > StringBuffer::n_blocks) {
        StringBuffer::n_blocks = ((StringBuffer::length + sb.length + 1)/LEN) + 1;
        char *new_string = new char[StringBuffer::n_blocks*LEN];
        for(int i = 0; i < pos; i++) {
            new_string[i] = StringBuffer::string[i];
        }
        for(int i = pos, j = 0; j < sb.length; i++, j++) {
            new_string[i] = sb.string[j];
        }
        for(int i = pos + sb.length, j = pos; j < StringBuffer::length; i++, j++) {
            new_string[i] = StringBuffer::string[j];
        }
        delete[] StringBuffer::string;
        StringBuffer::string = new_string;
        StringBuffer::length += sb.length;
        StringBuffer::string[StringBuffer::length] = '\0';
    } else {
        for(int i = pos, j = 0; j < sb.length; i++, j++) {
            StringBuffer::string[i] = sb.string[j];
        }
        for(int i = pos + sb.length, j = pos; j < StringBuffer::length; i++, j++) {
            StringBuffer::string[i] = StringBuffer::string[j];
        }
        StringBuffer::length += sb.length;
        StringBuffer::string[StringBuffer::length] = '\0';
    }
}