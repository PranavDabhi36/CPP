#include <iostream>
#include <string>
#include <vector>

using namespace std;

int isAlnum(char c) {
    return (c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9');
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') return c + 32;
    return c;
}

int findWord(vector<string>& words, string word) {
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == word) return i;
    }
    return -1;
}

int main() {
    cout << "Enter a sentence:\n";
    string text;
    getline(cin, text);

    vector<string> words;
    vector<int> counts;
    string word = "";

    for (int i = 0; i <= text.length(); i++) {
        char c = (i < text.length()) ? text[i] : ' ';
        if (isAlnum(c)) {
            word += toLower(c);
        } else if (word != "") {
            int index = findWord(words, word);
            if (index == -1) {
                words.push_back(word);
                counts.push_back(1);
            } else {
                counts[index]++;
            }
            word = "";
        }
    }

    cout << "\nWord Frequency:\n";
    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << " : " << counts[i] << "\n";
    }

    return 0;
}