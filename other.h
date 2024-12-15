#ifndef OTHER_H
#define OTHER_H

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "arr.h"
#include "hashtable.h"
#include "queue.h"
#include "stack.h"
#include "slist.h"
#include "dlist.h"
#include "tree.h"

const string FILENAME = "file.data";

using namespace std;

Array<string> split(string str, char delimiter) {
    Array<string> arr;
    int prevDel = -1;

    for (int i = 0; i < str.size(); i++) {
        if(str[i] == delimiter) {
            arr.pushBack(str.substr(prevDel + 1, i - 1 - prevDel));
            prevDel = i;
        }
    }
    arr.pushBack(str.substr(prevDel + 1, str.size() - prevDel));

    return arr;
}

string join(Array<string>& array, char delimiter) {
    string result;
    for (int i = 0; i < array.size(); i++) {
        result += array.get(i);
        if (i < array.size() - 1) {
            result += delimiter;
        }
    }
    return result;
}

bool isInteger(const string& str) {
    try {
        stoi(str);
        return true;
    } catch (...) {
        return false;
    }
}

#endif //OTHER_H
