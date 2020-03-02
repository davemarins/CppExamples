//
// Created by davide on 18/08/19.
//

#ifndef ES3_SYMBOL_H
#define ES3_SYMBOL_H

#include <string>
#include <vector>

using namespace std;

class Symbol {
private:
    string id;
    vector<int> pos;
    char c;
public:
    Symbol(int client, int counter, char c);
    vector<int> getFractionalPosition();
    void setVectorPosition(vector<int> pos);
    int getIdEditor();
    int getIdCharacter();
    char getCharacter();
    string getCompleteId();
};

#endif //ES3_SYMBOL_H
