//
// Created by Davide on 2019-07-21.
//

#include <iostream>
#include "Directory.h"
#include "File.h"

using namespace std;

int main() {
    shared_ptr<Directory> root = Directory::getRoot();
    auto alfa = root->addDirectory("alfa");
    alfa->addDirectory("beta")->addFile("beta1", 100);
    alfa->getDir("beta")->addFile("beta2", 200);
    alfa->getDir("..")->ls();
    alfa->remove("beta");
    root->ls();
}