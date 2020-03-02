#include <iostream>
#include "StringBuffer.h"

using namespace std;

int main() {
    StringBuffer s1("Hello");
    StringBuffer s2("world!");
    s1.append(" ");
    s1.append(s2);
    printf("%s\n", s1.c_str());                     // Hello world!
    s1.set("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");
    s1.append("\n");
    printf("%zu\n", s1.size());                     // 124
    s2.clear();
    for (int i = 0; i < 10; i++) {
        s2.insert(s1, 0);
    }
    printf("%s\n", s2.c_str());                     // Lorem ipsum ... 10 volte
    printf("%zu\n", s2.size());                       // 1240
    StringBuffer s3 = s2;
    printf("%s\n", s3.c_str());                     // Lorem ipsum ... 10 volte
    printf("%zu\n", s3.size());                       // 1240
}