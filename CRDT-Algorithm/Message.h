//
// Created by davide on 18/08/19.
//

#ifndef ES3_MESSAGE_H
#define ES3_MESSAGE_H

#include "Symbol.h"

using namespace std;

enum Operation {
    Insert = 0,
    Delete = 1
};

class Message {
private:
    int _siteId;
    char value;
    string id;
    vector<int> pos;
    Operation op;
    int getIdCharacter() const;
public:
    Message(int _siteId, char value, string id, vector<int> pos, Operation op);
    int getIdClient() const;
    char getValue() const;
    enum Operation getTypeMessage() const;
    vector<int> getPosition() const;
    string getId() const;
    Symbol generateSymbol() const;
};

#endif //ES3_MESSAGE_H
