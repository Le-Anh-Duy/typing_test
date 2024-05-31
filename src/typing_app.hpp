#include <iostream>
#include "words_box.hpp"
#include <string>

using namespace std;

class app {
public:
    int writen_words;
    words_box* wordsBox;
    app();
    ~app();

    void run();
};