#include <iostream>
#include <cstring>
using namespace std;

//spoils every character in a string
int main() {
    string s = "Hello World";

    int num = s.length();

    char chars[num+1];
    strcpy(chars, s.c_str());

    for (int i = 0; i < num; i++) {
        cout << "||" << chars[i] << "||";
    }
    cout << endl;

    return 0;
}