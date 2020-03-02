//
// Created by davide on 18/08/19.
//

#ifndef ES3_SHAREDEDITOR_H
#define ES3_SHAREDEDITOR_H

#include <string>
#include <vector>
#include "NetworkServer.h"
#include "Symbol.h"

using namespace std;

class SharedEditor {
private:
    NetworkServer &_server;
    vector<Symbol> _symbols;
    int _counter;
    int _siteId;
public:
    SharedEditor(NetworkServer _server);
    void localInsert(int index, char value);
    void localErase(int index);
    void process(const Message &m);
    string to_string();
};

#endif //ES3_SHAREDEDITOR_H
