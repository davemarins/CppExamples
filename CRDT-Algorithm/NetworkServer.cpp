//
// Created by davide on 18/08/19.
//

#include <algorithm>
#include "NetworkServer.h"

NetworkServer::NetworkServer() {}

int NetworkServer::connect(SharedEditor *sharedEditor) {
    int size = NetworkServer::editors.size();
    NetworkServer::editors.push_back(sharedEditor);
    return size;
}

void NetworkServer::disconnect(SharedEditor *sharedEditor) {
    auto it = find(NetworkServer::editors.begin(), NetworkServer::editors.end(), sharedEditor);
    NetworkServer::editors.erase(it);
}

void NetworkServer::send(const Message &m) {
    NetworkServer::messages.push(m);
}

void NetworkServer::dispatchMessages() {
    while(NetworkServer::messages.size() != 0) {
        for(SharedEditor *e: NetworkServer::editors)
            e->process(NetworkServer::messages.front());
        NetworkServer::messages.pop();
    }
}
