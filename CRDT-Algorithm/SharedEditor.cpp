//
// Created by davide on 18/08/19.
//

#include "Message.h"
#include "SharedEditor.h"
#include "Symbol.h"
#include <algorithm>
#include <exception>
#include <string>
#include <vector>

using namespace std;

SharedEditor::SharedEditor(NetworkServer _server): _server(_server) {
    SharedEditor::_siteId = SharedEditor::_server.connect(this);
    SharedEditor::_counter = 0;
    SharedEditor::_symbols.reserve(256);
}

void SharedEditor::localInsert(int index, char value) {
    Symbol s(SharedEditor::_siteId, SharedEditor::_counter++, value);
    vector<int> fractional_position;
    try {
        // exception of out of bound or nullptr
        Symbol ifPresent = SharedEditor::_symbols.at(index);
        if(ifPresent.getCompleteId().empty()) {
            fractional_position.assign(2, index);
        } else {
            fractional_position[0] = index - 1;
            fractional_position[1] = index;
        }
    } catch(exception &e) {
        // never inserted or delete operation
        fractional_position.assign(2, index);
    }
    s.setVectorPosition(fractional_position);
    // local insert
    SharedEditor::_symbols.insert(SharedEditor::_symbols.begin() + index, s);
    Message m(SharedEditor::_siteId, value, s.getCompleteId(), fractional_position, Operation::Insert);
    SharedEditor::_server.send(m);
}

void SharedEditor::localErase(int index) {
    char empty;
    vector<int> fractional_position;
    fractional_position.assign(2, index);
    for(int i = 0; i < SharedEditor::_symbols.size(); i++) {
        if(SharedEditor::_symbols[i].getFractionalPosition() == fractional_position) {
            // local delete
            SharedEditor::_symbols.erase(SharedEditor::_symbols.begin() + i);
            Message m(SharedEditor::_siteId, empty, nullptr, fractional_position, Operation::Delete);
            SharedEditor::_server.send(m);
            break;
        }
    }
}

void SharedEditor::process(const Message &m) {
    bool found = false;
    for(Symbol s: SharedEditor::_symbols)
        if((m.getTypeMessage() == Operation::Delete && s.getFractionalPosition() == m.getPosition())
        || (m.getTypeMessage() == Operation::Insert && s.getCharacter() == m.getValue() && s.getFractionalPosition() == m.getPosition()))
            found = true;
    if(!found) {
        if(m.getTypeMessage() == Operation::Delete) {
            SharedEditor::_symbols.erase(SharedEditor::_symbols.begin() + m.getPosition()[1]);
        } else if(m.getTypeMessage() == Operation::Insert) {
            SharedEditor::_symbols.insert(SharedEditor::_symbols.begin() + m.getPosition()[1], m.generateSymbol());
        }
    }
}

string SharedEditor::to_string() {
    string result = "";
    for(int i = 0; i < SharedEditor::_symbols.size(); i++)
        result += SharedEditor::_symbols[i].getCharacter();
    return result;
}
