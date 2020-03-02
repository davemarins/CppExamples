//
// Created by davide on 18/08/19.
//

#ifndef ES3_NETWORKSERVER_H
#define ES3_NETWORKSERVER_H

#include <memory>
#include <queue>
#include <vector>
#include "Message.h"
#include "SharedEditor.h"

using namespace std;

class NetworkServer {
private:
    vector<SharedEditor *> editors;
    queue<Message> messages;
public:
    NetworkServer();
    int connect(SharedEditor *sharedEditor);
    void disconnect(SharedEditor *sharedEditor);
    void send(const Message &m);
    void dispatchMessages();
};

#endif //ES3_NETWORKSERVER_H
