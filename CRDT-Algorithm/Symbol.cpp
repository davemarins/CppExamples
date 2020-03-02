//
// Created by davide on 18/08/19.
//

#include <bits/stdc++.h> 
#include <string>
#include <vector>
#include "Symbol.h"

using namespace std;

Symbol::Symbol(int client, int counter, char c) {
    Symbol::c = c;
    Symbol::id = to_string(client) + "-" + to_string(counter);
}

void Symbol::setVectorPosition(vector<int> pos) {
    Symbol::pos = pos;
}

char Symbol::getCharacter() {
    return Symbol::c;
}

string Symbol::getCompleteId() {
    return Symbol::id;
}

int Symbol::getIdEditor() {
    stringstream completeID(Symbol::id); 
    string IdEditor;
    getline(completeID, IdEditor, '-');
    stringstream temp(IdEditor);
    int result = 0; 
    temp >> result;
    return result;
}

int Symbol::getIdCharacter() {
    stringstream completeID(Symbol::id); 
    string IdCharacter;
    getline(completeID, IdCharacter, '-');
    getline(completeID, IdCharacter, '-');
    stringstream temp(IdCharacter);
    int result = 0; 
    temp >> result;
    return result;
}

vector<int> Symbol::getFractionalPosition() {
    return Symbol::pos;
}
