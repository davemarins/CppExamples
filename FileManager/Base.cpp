//
// Created by Davide on 2019-07-21.
//

#include "Base.h"

Base::Base() {}

Base::~Base() {}

string Base::getName() const {
    return Base::name;
}

void Base::setName(string name) {
    Base::name = name;
}

Type Base::getType() {
    return Base::type;
}

void Base::setType(Type t) {
    Base::type = t;
}