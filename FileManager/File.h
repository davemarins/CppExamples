//
// Created by Davide on 2019-07-21.
//

#ifndef ES2_FILE_H
#define ES2_FILE_H

#include "Base.h"
#include <iostream>

using namespace std;

class File: public Base{
private:
    uintmax_t size;
public:
    File();
    ~File();
    File(string name, uintmax_t size);
    uintmax_t getSize() const;
    void setSize(uintmax_t size);
    int mType() const override;
    void ls(int indent = 0) const override;
};

#endif //ES2_FILE_H
