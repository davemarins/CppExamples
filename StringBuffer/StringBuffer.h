//
// Created by Davide on 2019-07-21.
//

#ifndef ES1_STRINGBUFFER_H
#define ES1_STRINGBUFFER_H


#define LEN 100

class StringBuffer {
private:
    char *string;
    int length;
    int n_blocks;
public:
    StringBuffer();
    StringBuffer(const char *string);
    StringBuffer(const StringBuffer &sb);
    ~StringBuffer();
    StringBuffer &operator=(const StringBuffer &sb);
    void append(const char *string);
    void append(const StringBuffer &sb);
    const char *c_str();
    size_t size();
    size_t capacity();
    void clear();
    void insert(const char *string, size_t pos);
    void insert(const StringBuffer &sb, size_t pos);
    void set(const char* string);
    void set(const StringBuffer &sb);
};


#endif //ES1_STRINGBUFFER_H
