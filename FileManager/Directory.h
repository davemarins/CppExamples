//
// Created by Davide on 2019-07-21.
//

#ifndef ES2_DIRECTORY_H
#define ES2_DIRECTORY_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Base.h"
#include "File.h"

using namespace std;

class Directory : public Base, public enable_shared_from_this<Directory> {
private:
    vector<shared_ptr<Base>> children;
    weak_ptr<Directory> parent;
    weak_ptr<Directory> self;
protected:
    Directory();
    Directory(string name);
public:
    static shared_ptr<Directory> getRoot();
    shared_ptr<Directory> addDirectory(string nome);
    shared_ptr<File> addFile(string name, uintmax_t size);
    shared_ptr<Base> get(string name);
    shared_ptr<Directory> getDir(string name);
    shared_ptr<File> getFile(string name);
    void remove(string nome);
    int mType() const override;
    void ls(int indent = 0) const override;
    ~Directory();
};

#endif //ES2_DIRECTORY_H
