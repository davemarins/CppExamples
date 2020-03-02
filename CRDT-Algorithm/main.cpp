#include <iostream>
#include "NetworkServer.h"
#include "SharedEditor.h"

using namespace std;

int main(int argc, char *argv[]) {
    NetworkServer network;
    SharedEditor ed1(network);
    SharedEditor ed2(network);
    ed1.localInsert(0, 'c');
    ed1.localInsert(1, 'a');
    ed1.localInsert(2, 't');
    network.dispatchMessages();
    cout << "ed1: " << ed1.to_string() << endl; // ed1: cat
    cout << "ed2: " << ed2.to_string() << endl; // ed2: cat
    ed1.localInsert(1, 'h');
    ed2.localErase(1);
    network.dispatchMessages();
    cout << "ed1: " << ed1.to_string() << endl; // ed1: cht
    cout << "ed2: " << ed2.to_string() << endl; // ed2: cht
    return 0;
}
