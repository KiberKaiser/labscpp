#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<string> extractWords(const string& text) {
    vector<string> words;
    string word;
    for (char c : text) {
        if (isalpha(c) || isdigit(c)) {
            word += c;
        } else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}

void printWordsWithDigits(const vector<string>& words) {
    cout << "Слова, які містять цифри:" << endl;
    for (const string& word : words) {
        for (char c : word) {
            if (isdigit(c)) {
                cout << word << endl;
                break;
            }
        }
    }
}

int main() {
    string text;
    cout << "Введіть рядок слів, розділених комами і завершення крапкою: ";
    getline(cin, text);

    vector<string> words = extractWords(text);
    printWordsWithDigits(words);

    return 0;
}
