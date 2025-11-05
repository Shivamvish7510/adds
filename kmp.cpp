#include <iostream>
#include <vector>
using namespace std;

// Function to create LPS (Longest Prefix Suffix) array
void computeLPS(string pat, vector<int> &lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while(i < pat.length()) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Search function
void KMPsearch(string text, string pat) {
    int n = text.length();
    int m = pat.length();

    vector<int> lps(m);
    computeLPS(pat, lps);

    int i = 0, j = 0;
    while(i < n) {
        if(text[i] == pat[j]) {
            i++;
            j++;
        }

        if(j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if(i < n && text[i] != pat[j]) {
            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    string text, pattern;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter pattern: ";
    getline(cin, pattern);

    KMPsearch(text, pattern);

    return 0;
}
