//
// Created by Davide on 2019-07-21.
//

#include <iostream>
#include "Directory.h"
#include "DuplicateDetected.h"
#include "OperationDenied.h"

Directory::Directory() {}

Directory::~Directory() {}

Directory::Directory(string name) {
    Directory::setName(name);
    vector<shared_ptr<Base>> children;
    Directory::children = children;
    Directory::setType(Type::Directory);
}

shared_ptr<Directory> Directory::getRoot() {
    shared_ptr<Directory> root(new Directory("/"));
    root->self = root;
    root->parent = root;
    return root;
}

int Directory::mType() const {
    return Type::Directory;
}

void Directory::ls(int indent) const
{
    cout << "[+] " << Directory::getName() << endl;
    for(shared_ptr<Base> index: Directory::children) {
        cout << "	";
        index->ls();
    }
    return;
}

shared_ptr<Directory> Directory::addDirectory(string nome)
{
    try {
        for(shared_ptr<Base> index: Directory::children)
            if (index->getName() == nome) throw DuplicateDetected();
        shared_ptr<Directory> temp(new Directory(nome));
        temp->self = temp;
        temp->parent = shared_from_this();
        Directory::children.push_back(temp);
        return temp;
    }
    catch (DuplicateDetected &e) {
        cout << e.what() << endl;
        return nullptr;
    }
}

shared_ptr<File> Directory::addFile(string nome, uintmax_t size)
{
    try
    {
        for(shared_ptr<Base> index: Directory::children)
            if(index->getName() == nome) throw DuplicateDetected();
        shared_ptr<File> temp(new File(nome, size));
        Directory::children.push_back(temp);
        return temp;
    } catch (DuplicateDetected &e) {
        cout << e.what() << endl;
        return nullptr;
    }
}

shared_ptr<Base> Directory::get(string name)
{
    if (name == "..") return Directory::parent.lock();
    if (name == ".") return Directory::self.lock();
    for(shared_ptr<Base> index: Directory::children)
        if (index->getName() == name)
            return i;
    return nullptr;
}

shared_ptr<Directory> Directory::getDir(string name)
{
    if(name == "..") return Directory::parent.lock();
    if(name == ".") return Directory::self.lock();
    for(shared_ptr<Base> index: Directory::children)
        if (index->getName() == name && i->getType() == Directory)
            return dynamic_pointer_cast<Directory>(i);
    return nullptr;
}

shared_ptr<File> Directory::getFile(string name)
{
    for(shared_ptr<Base> index: Directory::children)
        if (index->getName() == name && index->getType() == File)
            return dynamic_pointer_cast<File>(index);
    return nullptr;
}

void Directory::remove(string nome)
{
    try {
        if(nome == ".." || nome == ".") throw OperationDenied();
        for(int i = 0; i < Directory::children.size(); i++)
            if (Directory::children[i]->getName() == nome) {
                Directory::children.erase(Directory::children.begin() + i);
                return;
            }
    } catch (OperationDenied &e) {
        cout << e.what() << endl;
    }
}

