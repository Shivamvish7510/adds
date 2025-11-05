#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct Node {
    unordered_map<char, Node*> children;
};

Node* bruteForceSuffixTrie(const string& T) {
    Node* root = new Node();
    int n = T.length();
    for (int i = n - 1; i >= 0; i--) {
        Node* node = root;
        int j = i;
        while (j < n && node->children.find(T[j]) != node->children.end()) {
            node = node->children[T[j]];
            j++;
        }
        for (int k = j; k < n; k++) {
            Node* newNode = new Node();
            node->children[T[k]] = newNode;
            node = newNode;
        }
    }
    return root;
}

bool search(Node* root, const string& pattern) {
    Node* node = root;
    for (char ch : pattern) {
        if (node->children.find(ch) == node->children.end()) return false;
        node = node->children[ch];
    }
    return true;
}

int main() {
    string text = "casca";
    Node* root = bruteForceSuffixTrie(text);
    cout << "Suffix Trie built for text: " << text << endl;
    cout << "Searching 'as'  -> " << (search(root, "as") ? "Found" : "Not Found") << endl;
    cout << "Searching 'sca' -> " << (search(root, "sca") ? "Found" : "Not Found") << endl;
    cout << "Searching 'xyz' -> " << (search(root, "xyz") ? "Found" : "Not Found") << endl;
    return 0;
}
