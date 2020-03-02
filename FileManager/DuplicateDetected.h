//
// Created by Davide on 2019-08-17.
//

#ifndef ES2_DUPLICATEDETECTED_H
#define ES2_DUPLICATEDETECTED_H

#include <stdexcept>

using namespace std;

class DuplicateDetected: logic_error {
public:
    DuplicateDetected(): logic_error("Duplicate detected") {}
};

#endif //ES2_DUPLICATEDETECTED_H
