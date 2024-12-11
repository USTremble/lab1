#ifndef HELP_H
#define HELP_H

#include "tree.h"
#include "other.h"

Array<string> readArray(string name) {
    Array<string> array;

    ifstream file(FILENAME);

    if (!file.is_open()) {
        throw runtime_error("Error opening file");
    }

    string line;
    
    bool isArray = false;
    while (getline(file, line)) {
        if (line == "Array") {
            isArray = true;
        }  else if (line == "" && isArray) {
            break;
        } else if (isArray) {
            Array<string> splittedLine = split(line, ' ');

            if (splittedLine.size() != 2) {
                continue;
            }

            if (splittedLine.get(0) == name) {
                array = split(splittedLine.get(1), ','); // делим по запятым второй аргумент
                return array;
            }
        }
    }

    file.close();

    return array;
}

Queue<string> readQueue(string name) {
    Queue<string> queue;

    ifstream file(FILENAME);

    if (!file.is_open()) {
        throw runtime_error("Error opening file");
    }

    string line;
    
    bool isQueue = false;
    while (getline(file, line)) {
        if (line == "Queue") {
            isQueue = true;
        }  else if (line == "" && isQueue) {
            break;
        } else if (isQueue) {
            Array<string> splittedLine = split(line, ' ');

            if (splittedLine.size() != 2) {
                continue;
            }

            if (splittedLine.get(0) == name) {
                Array<string> array = split(splittedLine.get(1), ',');

                for (int i = 0; i < array.size(); i++) {
                    queue.enqueue(array.get(i));
                }
                return queue;
            }
        }
    }

    file.close();

    return queue;
}

Stack<string> readStack(string name) {
    Stack<string> stack;

    ifstream file(FILENAME);

    if (!file.is_open()) {
        throw runtime_error("Error opening file");
    }

    string line;
    
    bool isStack = false;
    while (getline(file, line)) {
        if (line == "Stack") {
            isStack = true;
        }  else if (line == "" && isStack) {
            break;
        } else if (isStack) {
            Array<string> splittedLine = split(line, ' ');

            if (splittedLine.size() != 2) {
                continue;
            }

            if (splittedLine.get(0) == name) {
                Array<string> array = split(splittedLine.get(1), ','); 
                array.reverse();

                for (int i = 0; i < array.size(); i++) {
                    stack.push(array.get(i));
                }
                return stack;
            }
        }
    }

    file.close();

    return stack;
}

Dlist<string> readDlist(string name) {
    Dlist<string> dlist;

    ifstream file(FILENAME);

    if (!file.is_open()) {
        throw runtime_error("Error opening file");
    }

    string line;
    
    bool isDList = false;
    while (getline(file, line)) {
        if (line == "Dlist") {
            isDList = true;
        } else if (line == "" && isDList) {
            break;
        } else if (isDList) {
            Array<string> splittedLine = split(line, ' ');

            if (splittedLine.size() != 2) {
                continue;
            }

            if (splittedLine.get(0) == name) {
                Array<string> array = split(splittedLine.get(1), ',');

                for (int i = 0; i < array.size(); i++) {
                    dlist.pushBack(array.get(i));
                }
                return dlist;
            }
        }
    }

    file.close();

    return dlist;
}

SList<string> readSlist(string name) {
    SList<string> slist;

    ifstream file(FILENAME);

    if (!file.is_open()) {
        throw runtime_error("Error opening file");
    }

    string line;
    
    bool isSList = false;
    while (getline(file, line)) {
        if (line == "Slist") {
            isSList = true;
        } else if (line == "" && isSList) {
            break;
        } else if (isSList) {
            Array<string> splittedLine = split(line, ' ');

            if (splittedLine.size() != 2) {
                continue;
            }

            if (splittedLine.get(0) == name) {
                Array<string> array = split(splittedLine.get(1), ',');

                for (int i = 0; i < array.size(); i++) {
                    slist.pushBack(array.get(i));
                }
                return slist;
            }
        }
    }

    file.close();

    return slist;
}

HashTable<string> readHashTable(string name) {
    HashTable<string> table;

    ifstream file(FILENAME);

    if (!file.is_open()) {
        throw runtime_error("Error opening file");
    }

    string line;
    
    bool isTable = false;
    while (getline(file, line)) {
        if (line == "HashTable") {
            isTable = true;
        } else if (line == "" && isTable) {
            break;
        } else if (isTable) {
            Array<string> splittedLine = split(line, ' ');

            if (splittedLine.size() != 2) {
                continue;
            }

            if (splittedLine.get(0) == name) {
                Array<string> array = split(splittedLine.get(1), ';'); 
                if (array.size() == 1 && array.get(0) == "") { 
                    array.remove(0);
                } else {
                    for (int i = 0; i < array.size(); i++) {
                        Array<string> keyval = split(array.get(i), ',');
                        if (keyval.size() != 2) {
                            throw runtime_error("invalid HashTable format");
                        }
                        string key = keyval.get(0);
                        string value = keyval.get(1);
                        table.put(key, value);
                    }
                }
                
                return table;
            }
        }
    }

    file.close();

    return table;
}

CompleteBinaryTree readTree(string name) {
    CompleteBinaryTree tree;

    ifstream file(FILENAME);

    if (!file.is_open()) {
        throw runtime_error("Error opening file");
    }

    string line;
    bool isTree = false;

    while (getline(file, line)) {
        if (line == "Tree") {
            isTree = true;
        }  else if (line == "" && isTree) {
            break;
        } else if (isTree) {
            Array<string> splittedLine = split(line, ' ');

            if (splittedLine.size() != 2) {
                continue;
            }

            if (splittedLine.get(0) == name) {
                tree.deserialize(splittedLine.get(1));
                return tree;
            }
        }
    }

    file.close();

    return tree;
}


void writeToFile(string section, string name, string writeline) {
    ifstream file(FILENAME);

    if (!file.is_open()) {
        throw runtime_error("Error opening file");
    }
    Array<string> fileLines;  
    string line; 
    bool isCorrectSection = false; 
    bool foundSection = false;

    while (getline(file, line)) {
        if (line == section) {
            isCorrectSection = true;
        } else if (isCorrectSection && line == "") {
            isCorrectSection = false;
            if (!foundSection) {
                fileLines.pushBack(writeline);
            }
        }

        if (isCorrectSection) {
            Array<string> splittedLine = split(line, ' ');

            if (splittedLine.size() == 2 && splittedLine.get(0) == name) {
                line = writeline;
                foundSection = true;
            }
        }

        fileLines.pushBack(line);  //сохраняем строку
    }

    file.close(); 

    ofstream outFile(FILENAME); //перезаписываем содержимое файла
    if (!outFile.is_open()) {
        throw runtime_error("Error opening file for writing");
    }

    for (int i = 0; i < fileLines.size(); i++) {
        outFile << fileLines.get(i) << endl;
    }

    outFile.close();
}

void checkArgumentCount(Array<string>& parameters, int expected) {
    if (parameters.size() != expected) {
        throw runtime_error("Incorrect count of arguments");
    }
}

int parseIndex(const string& parameter) {
    try {
        return stoi(parameter);
    } catch (const invalid_argument&) {
        throw runtime_error("Argument should be a number");
    }
}

void validateElement(const string& element) {
    if (element.find(",") != string::npos) {
        throw runtime_error("',' shouldn't be in the element");
    }
}

void saveTree(const string& name, CompleteBinaryTree& tree) {
    writeToFile("Tree", name, name + " " + tree.serialize()); 
}

void saveHash(const string& name, HashTable<string>& table) {
    writeToFile("HashTable", name, name + " " + table.join());
}

void saveQueue(const string& name, Queue<string>& queue) {
    writeToFile("Queue", name, name + " " + queue.data().join(','));
}

void saveSlist(const string& name, SList<string>& slist) {
    writeToFile("Slist", name, name + " " + slist.join(','));
}

void saveStack(const string& name,  Stack<string>& stack) {
    writeToFile("Stack", name, name + " " + stack.data().join(','));
}

void saveArray(const string& name, Array<string>& array) { 
    writeToFile("Array", name, name + " " + join(array, ','));
}

void saveDlist(const string& name, Dlist<string>& dlist) { 
    writeToFile("Dlist", name, name + " " + dlist.join(','));
}

#endif