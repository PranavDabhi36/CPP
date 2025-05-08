#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string fileName;
    cout << "Enter the file name: ";
    cin >> fileName;

    ifstream file(fileName);
    if (!file) {
        cout << "Error: Unable to open file " << fileName << endl;
        return 1;
    }

    string line;
    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;

    while (getline(file, line)) {
        lineCount++;
        charCount += line.length();

        // Count words by detecting transitions between spaces and non-spaces
        bool inWord = false;
        for (char ch : line) {
            if (ch != ' ' && ch != '\t') {
                if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            } else {
                inWord = false;
            }
        }
    }

    cout << "Total Lines: " << lineCount << endl;
    cout << "Total Words: " << wordCount << endl;
    cout << "Total Characters (including spaces and punctuation): " << charCount << endl;

    file.close();
    return 0;
}