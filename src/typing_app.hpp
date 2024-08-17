#include <iostream>
#include "words_box.hpp"
#include <string>
#include <ctime>
using namespace std;

class app {
private:
    clock_t enlapsedTime;
    bool isRunning;

public:
    int writen_words;
    words_box* wordsBox;

    void setRunning();
    void setCounter();
    bool getRunning();
    app();
    ~app();

    void run();


};