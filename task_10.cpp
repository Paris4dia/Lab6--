#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <thread>
#include <cctype>
using namespace std;

string text;

void readFile() {
    ifstream file("text.txt");
    char c;

    while (file.get(c)) {
        text += c;
    }

    file.close();
}

void countWords() {
    string word;
    int count = 0;
    stringstream input(text);

    while (input >> word)
        count++;

    cout << "Слів: " << count << endl;
}

void countCharacters() {
    cout << "Символів: " << text.length() << endl;
}

void countPunctuation() {
    int count = 0;

    for (char c : text) {
        if (ispunct(c))
            count++;
    }

    cout << "Знаків пунктуації: " << count << endl;
}

int main() {
    thread producer(readFile);
    producer.join();

    thread t1(countWords);
    thread t2(countCharacters);
    thread t3(countPunctuation);

    t1.join();
    t2.join();
    t3.join();
}
