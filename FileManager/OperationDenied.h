//
// Created by Davide on 2019-08-17.
//

#ifndef ES2_OPERATIONDENIED_H
#define ES2_OPERATIONDENIED_H

#include <stdexcept>

using namespace std;

class OperationDenied: public logic_error {
public:
    OperationDenied(): logic_error("Operation denied") {}
};

#endif //ES2_OPERATIONDENIED_H
