#include "help.h"
#include "menu.h"

int main() {
    string inputStr;

    while (true) {
        getline(cin, inputStr);
        Array<string> splitedStr = split(inputStr, ' ');
        string command = splitedStr.get(0);

        try {
            if (command[0] == 'M') {
                arrayMenu(splitedStr);
            } else if (command[0] == 'S') {
                stackMenu(splitedStr);
            } else if (command[0] == 'Q') {
                queueMenu(splitedStr);
            } else if (command[0] == 'H') {
                hashMenu(splitedStr);
            } else if (command[0] == 'T') {
                treeMenu(splitedStr);
            } else if (command[0] == 'L') {
                slistMenu(splitedStr);
            } else if (command[0] == 'D') {
                dlistMenu(splitedStr);
            }
        }
        catch(const exception& e) {
            cerr << e.what() << '\n';
        }
    }

    return 0;
}