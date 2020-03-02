//
// Created by Davide on 2019-07-21.
//

#include "Base.h"
#include "File.h"

File::File() {}

File::~File() {}

File::File(string name, uintmax_t size) {
    File::setType(Type::File);
    File::setName(name);
    File::size = size;
}

uintmax_t File::getSize() const {
    return File::size;
}

void File::setSize(uintmax_t size) {
    File::size = size;
}

int File::mType() const {
    return Type::File;
}

void File::ls(int indent) const {
    cout << " " << File::getName() << " " << File::getSize() << endl;
}
