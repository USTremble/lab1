#ifndef COMPLTREE_H
#define COMPLTREE_H

#include "other.h"

struct TNode {
    int value;
    TNode* right;
    TNode* left;

    TNode(const int val) : value(val), left(nullptr), right(nullptr) {}
};

struct CompleteBinaryTree {
    TNode* root;
    CompleteBinaryTree() : root(nullptr) {}

    void insert(int val);
    string serialize();
    void deserialize(string data);
    bool search(int val);
    int maxDepth();
    int countNodes();
    bool isComplete();
    void printTree();
    void printNode(TNode* node, string prefix, bool isLeft);

    int maxDepth(TNode* node);
    int countNodes(TNode* node);
    bool isCompleteBinaryTree(TNode* node);
};

void CompleteBinaryTree::insert(int val) {
    if (!root) {
        root = new TNode(val);
        return;
    }

    Queue<TNode*> q;
    q.enqueue(root); // добавляем корень

    while (q.size() > 0) {
        TNode* current = q.dequeue();

        if (!current->left) {
            current->left = new TNode(val);
            return;
        } else {
            q.enqueue(current->left); // добавляем в очередь
        }

        if (!current->right) {
            current->right = new TNode(val);
            return;
        } else {
            q.enqueue(current->right);
        }
    }
}

bool CompleteBinaryTree::search(int val) {
    if (!root) {
        return false;
    }

    Queue<TNode*> q;
    q.enqueue(root);

    while (q.size() > 0) {
        TNode* current = q.dequeue();

        if (current->value == val) {
            return true;
        }

        if (current->left) {
            q.enqueue(current->left);
        }
        if (current->right) {
            q.enqueue(current->right);
        }
    }

    return false;
}

int CompleteBinaryTree::maxDepth(TNode* node) {
    if (!node)  {
        return 0;
    }

    int leftDepth = maxDepth(node->left);
    int rightDepth = maxDepth(node->right);

    int deepSubtree;
    if (leftDepth > rightDepth) {
        deepSubtree = leftDepth;
    } else {
        deepSubtree = rightDepth;
    }
    return 1 + deepSubtree;
}

int CompleteBinaryTree::maxDepth() {
    return maxDepth(root);
}

int CompleteBinaryTree::countNodes(TNode* node) {
    if (!node) {
        return 0;
    }

    int leftCount = countNodes(node->left);
    int rightCount = countNodes(node->right);

    int total = 1;
    total += leftCount;
    total += rightCount;
    return total;
}

int CompleteBinaryTree::countNodes() {
    return countNodes(root);
}

bool CompleteBinaryTree::isCompleteBinaryTree(TNode* node) {
    if (!root) {
        return true; // т.к пустое тоже является полным
    }

    int depth = maxDepth(root);
    int totalNodes = countNodes(root);

    int maxNodes = pow(2, depth) - 1; // 2^h - 1, где h - глубина

    if (totalNodes == maxNodes) {
        return true;
    } else {
        return false;
    }
}

bool CompleteBinaryTree::isComplete() {
    return isCompleteBinaryTree(root);
}

string CompleteBinaryTree::serialize() {
    if (!root) {
        return "";
    }

    string result;
    Queue<TNode*> q;
    q.enqueue(root);

    while (q.size() > 0) {
        TNode* current = q.dequeue();

        if (current) {

            if (!result.empty()) {
                result += ',';
            }
            result += to_string(current->value);

            if (current->left) { // добавляем только непустые узлы в очередь
                q.enqueue(current->left);
            }
            if (current->right) {
                q.enqueue(current->right);
            }
        }
    }

    return result;
}

void CompleteBinaryTree::deserialize(string str) {
    if (str.empty()) {
        root = nullptr;
        return;
    }

    Array<string> elements = split(str, ',');
    if (elements.size() == 0) {
        root = nullptr;
        return;
    }

    Queue<TNode*> q;
    root = new TNode(stoi(elements.get(0))); // первый становится корнем
    q.enqueue(root);

    int i = 1;
    while (q.size() > 0 && i < elements.size()) {
        TNode* current = q.dequeue();

        if (i < elements.size()) {
            current->left = new TNode(stoi(elements.get(i)));
            q.enqueue(current->left);
        }
        i++;

        if (i < elements.size()) {
            current->right = new TNode(stoi(elements.get(i)));
            q.enqueue(current->right);
        }
        i++;
    }
}


void CompleteBinaryTree::printNode(TNode* node, string prefix, bool isLeft) {
    if (node == nullptr) {
        return;
    }

    cout << prefix; // текущий узел

    if (isLeft) {
        cout << "|-- ";
    } else {
        cout << "\\-- ";
    }

    cout << node->value << endl; // само значение

    string newPrefix = prefix;
    if (isLeft) {
        newPrefix += "|   ";
    } else {
        newPrefix += "   ";
    }
    printNode(node->left, newPrefix, true);
    printNode(node->right, newPrefix, false);
}

void CompleteBinaryTree::printTree() {
    printNode(root, "", false);
}


#endif // COMPLTREE_H
