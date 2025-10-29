#include <iostream>
#include <string>
using namespace std;

// Build LPS (Longest Prefix Suffix) array
void computeLPS(const string &pattern, int lps[]) {
    int len = 0;
    lps[0] = 0;  // first value always 0
    int i = 1;

    while (i < pattern.length()) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Perform KMP Search
void KMPSearch(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();
    int lps[m];
    computeLPS(pattern, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern
    bool found = false;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            found = true;
            j = lps[j - 1];  // continue searching
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    if (!found)
        cout << "Pattern not found in text." << endl;
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pattern);

    KMPSearch(text, pattern);
    return 0;
}
