#ifndef MENU_H
#define MENU_H

#include "help.h"

void arrayMenu(Array<string> parameters) { 
    string command = parameters.get(0);
    string name = parameters.get(1);
    Array<string> arr = readArray(name);

    if (command == "MPUSH") { 
        checkArgumentCount(parameters, 3);
        string element = parameters.get(2);
        validateElement(element);

        arr.pushBack(element);
        saveArray(name, arr);
    } else if (command == "MLEN") { 
        checkArgumentCount(parameters, 2);

        cout << arr.size() << endl;
    } else if (command == "MSET") { 
        checkArgumentCount(parameters, 4);
        int index = parseIndex(parameters.get(2));
        string val = parameters.get(3);

        arr.set(index, val);
        saveArray(name, arr);
    } else if (command == "MDEL") { 
        checkArgumentCount(parameters, 3);
        int index = parseIndex(parameters.get(2));

        arr.remove(index);
        saveArray(name, arr);
    } else if (command == "MGET") {
        checkArgumentCount(parameters, 3);
        int index = parseIndex(parameters.get(2));

        cout << arr.get(index) << endl;
    } else if (command == "MPRINT"){
        checkArgumentCount(parameters, 2);
        cout << arr;
    } else {
        throw runtime_error("Unknown for array command");
    }
}

void hashMenu(Array<string> parameters) { 
    string command = parameters.get(0);
    string name = parameters.get(1);
    HashTable<string> table = readHashTable(name);

    if (command == "HPUSH") {
        checkArgumentCount(parameters, 4);
        string key = parameters.get(2);
        string value = parameters.get(3);

        table.put(key, value);
        saveHash(name, table);
    } else if (command == "HDEL") {
        checkArgumentCount(parameters, 3);
        string key = parameters.get(2);

        table.remove(key);
        saveHash(name, table);
    } else if (command == "HGET") {
        checkArgumentCount(parameters, 3);
        string key = parameters.get(2);

        cout << table.get(key) << endl;
        saveHash(name, table);
    } else if (command == "HPRINT") {
        checkArgumentCount(parameters, 2);

        cout << table << endl;
    } else {
        throw runtime_error("Unknown for hashTable command");
    }
}

void queueMenu(Array<string> parameters) { 
    string command = parameters.get(0);
    string name = parameters.get(1);
    Queue<string> queue = readQueue(name);

    if (command == "QPUSH") {
        checkArgumentCount(parameters, 3);
        string element = parameters.get(2);
        validateElement(element);

        queue.enqueue(element);
        saveQueue(name, queue);
    } else if (command == "QPOP") { 
        checkArgumentCount(parameters, 2);

        cout << "Popped: " << queue.dequeue() << endl;
        saveQueue(name, queue);
    } else if (command == "QPRINT") {
        checkArgumentCount(parameters, 2);

        cout << queue << endl;
    } else {
        throw runtime_error("Unknown for queue command");
    }
}

void stackMenu(Array<string> parameters) {
    string command = parameters.get(0);
    string name = parameters.get(1);
    Stack<string> stack = readStack(name);

    if (command == "SPUSH") {
        checkArgumentCount(parameters, 3);
        string element = parameters.get(2);
        validateElement(element);

        stack.push(element);
        saveStack(name, stack);
    } else if (command == "SPOP") {
        checkArgumentCount(parameters, 2);

        cout << "Popped: " << stack.pop() << endl;
        saveStack(name, stack);
    } else if (command == "SPRINT") {
        checkArgumentCount(parameters, 2);

        cout << stack << endl;
    } else {
        throw runtime_error("Unknown for stack command");
    }
}

void slistMenu(Array<string> parameters) {  
    string command = parameters.get(0);
    string name = parameters.get(1);
    SList<string> slist = readSlist(name);

    if (command == "LPUSHBACK") {
        checkArgumentCount(parameters, 3);
        string element = parameters.get(2);
        validateElement(element);

        slist.pushBack(element);
        saveSlist(name, slist);
    } else if (command == "LPUSHFORWARD") {
        checkArgumentCount(parameters, 3);
        string element = parameters.get(2);

        slist.pushForward(element);
        saveSlist(name, slist);
    } else if (command == "LDELBACK") {
        checkArgumentCount(parameters, 2);

        slist.removeBack();
        saveSlist(name, slist);
    } else if (command == "LDELFORWARD") {
        checkArgumentCount(parameters, 2);

        slist.removeForward();
        saveSlist(name, slist);
    } else if (command == "LDELVALUE") {
        checkArgumentCount(parameters, 3);
        string element = parameters.get(2);

        slist.removeValue(element);
        saveSlist(name, slist);
    } else if (command == "LGET") {
        checkArgumentCount(parameters, 3);
        int index = parseIndex(parameters.get(2));

        cout << slist.get(index) << endl;
    } else if (command == "LFINDBYVALUE") {
        checkArgumentCount(parameters, 3);
        string element = parameters.get(2);

        int index = slist.findByValue(parameters.get(2));
        if (index != -1) {
            cout << index << endl;
        } else {
            throw runtime_error("Element not found");
        }
    } else if (command == "LPRINT") {
        checkArgumentCount(parameters, 2);

        cout << slist << endl;
    } else {
        throw runtime_error("Unknown for slist command");
    }
}

void dlistMenu(Array<string> parameters) {  
    string command = parameters.get(0);
    string name = parameters.get(1);
    Dlist<string> dlist = readDlist(name);

    if (command == "DPUSHBACK") {
        checkArgumentCount(parameters, 3);
        string element = parameters.get(2);
        validateElement(element);

        dlist.pushBack(element);
        saveDlist(name, dlist);
    } else if (command == "DPUSHFORWARD") {
        checkArgumentCount(parameters, 3);
        string element = parameters.get(2);
        validateElement(element);

        dlist.pushForward(element);
        saveDlist(name, dlist);
    } else if (command == "DDELBACK") {
        checkArgumentCount(parameters, 2);

        dlist.removeBack();
        saveDlist(name, dlist);
    } else if (command == "DDELFORWARD") {
        checkArgumentCount(parameters, 2);

        dlist.removeForward();
        saveDlist(name, dlist);
    } else if (command == "DDELVALUE") {
        checkArgumentCount(parameters, 3);
        string element = parameters.get(2);

        dlist.removeValue(element);
        saveDlist(name, dlist);
    } else if (command == "DGET") {
        checkArgumentCount(parameters, 3);
        int index = parseIndex(parameters.get(2));

        cout << dlist.get(index) << endl;
    } else if (command == "DFINDBYVALUE") {
        checkArgumentCount(parameters, 3);
        string element = parameters.get(2);

        int index = dlist.findByValue(element);

        if (index != -1) {
            cout << index << endl;
        } else {
            throw runtime_error("Element not found");
        }
    } else if (command == "DPRINT") {
        checkArgumentCount(parameters, 2);

        cout << dlist << endl;
    } else {
        throw runtime_error("Unknown for dlist command");
    }
}

void treeMenu(Array<string> parameters) { 
    string command = parameters.get(0);
    string name = parameters.get(1);
    CompleteBinaryTree tree = readTree(name);

    if (command == "TPUSH") {
        checkArgumentCount(parameters, 3);
        string element = parameters.get(2);
        validateElement(element);

        if (!isInteger(element)) {
            cerr << "Value must be an integer" << endl;
            return;
        }

        tree.insert(stoi(element));
        saveTree(name, tree);
    } else if (command == "TFIND") {
        checkArgumentCount(parameters, 3);
        int element = stoi(parameters.get(2));

        if(tree.search(element)){
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    } else if (command == "TCHECK") {
        checkArgumentCount(parameters, 2);

        if (tree.isComplete()) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    } else if (command == "TPRINT") {
        checkArgumentCount(parameters, 2);

        tree.printTree();
    }else {
        throw runtime_error("Unknown for tree command");
    }
}

#endif