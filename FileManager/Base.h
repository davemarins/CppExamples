//
// Created by Davide on 2019-07-21.
//

#ifndef ES2_BASE_H
#define ES2_BASE_H

#include <string>

using namespace std;

enum Type {
    Directory = 0,
    File = 1
};

class Base {
private:
    string name;
    Type type;
protected:
    Base();
public:
    string getName() const;
    void setName(string name);
    ~Base();
    Type getType();
    void setType(Type t);
    virtual int mType() const = 0;
    virtual void ls(int indent = 0) const = 0;
};


#endif //ES2_BASE_H
