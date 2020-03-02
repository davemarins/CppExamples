//
// Created by davide on 18/08/19.
//

#include "Message.h"
#include "Symbol.h"
#include <bits/stdc++.h> 
#include <string>
#include <vector>

Message::Message(int _siteId, char value, string id, vector<int> pos, Operation op): 
_siteId(_siteId), value(value), id(id), pos(pos), op(op) {}

int Message::getIdClient() const {
    return Message::_siteId;
}

char Message::getValue() const {
    return Message::value;
}

enum Operation Message::getTypeMessage() const {
    return Message::op;
}

vector<int> Message::getPosition() const{
    return Message::pos;
}

string Message::getId() const{
    return Message::id;
}

int Message::getIdCharacter() const{
    stringstream completeID(Message::id);
    string IdCharacter;
    getline(completeID, IdCharacter, '-');
    getline(completeID, IdCharacter, '-');
    stringstream temp(IdCharacter);
    int result = 0; 
    temp >> result;
    return result;
}

Symbol Message::generateSymbol() const {
    return Symbol(Message::_siteId, Message::getIdCharacter(), Message::value);
}
