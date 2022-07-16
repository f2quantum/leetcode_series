//
// Created by FranklinZQuantum on 2021/8/28.
//


# include <iostream>
# include <string>
# include "vector"

using namespace std;
class CombinationIterator {
public:
    int combinationLength;
    string characters;
    bool finished;

    CombinationIterator(string characters, int combinationLength) {
        this->combinationLength=combinationLength;
        this->characters=characters;
        this->finished= false;
    }

    string next() {

    }

    bool hasNext() {

    }
};
int main() {
    return 0;
}
