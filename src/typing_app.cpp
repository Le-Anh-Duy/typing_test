#pragma once
#include "typing_app.hpp"
#include <limits>
#include <cstring>
#include <random>
#include <time.h>
#include <fstream>
#include <time.h>

int curX = 0, curY = 0;

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle( STD_OUTPUT_HANDLE ),
        coord
    );
}

int wherex()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD                      result;
    if (!GetConsoleScreenBufferInfo(
            GetStdHandle( STD_OUTPUT_HANDLE ),
            &csbi
            ))
        return -1;
    return result.X;
}

int wherey()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD                      result;
    if (!GetConsoleScreenBufferInfo(
            GetStdHandle( STD_OUTPUT_HANDLE ),
            &csbi
            ))
        return -1;
    return result.Y;
}

string keyboard_get(app* myApp) {
    string ans = "";
    while (true) {
        char ch = _getch();
        if (ch == 8) {
            cout << "\b \b";
            if (ans.size()) ans.pop_back();
            continue;
        }

        if (ch == -32) { // function key
            continue;
        }

        if (!myApp->getRunning()) {
            myApp->setRunning();
            myApp->setCounter();
        }

        if (ch == ' ') {
            return ans;
        } else
            ans += ch;

        cout << ch;
    }
    return ans;
}

bool app::getRunning() {
    return isRunning;
}


void app::setCounter() {
    enlapsedTime = clock();
}

void app::setRunning() {
    isRunning = true;
}

app::app() {
    isRunning = false;
    writen_words = 0;
    wordsBox = new words_box();
}

app::~app() {
    delete wordsBox;
}


std::fstream& GotoLine(std::fstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}

vector <string> getQuote() {
    srand(time(NULL));

    int idx = rand() % 99 + 1;
    fstream file("quotes.txt");

    GotoLine(file, idx);
    string line;
    getline(file, line);

    vector <string> res;

    string tmp = "";

    for (char ch: line) {
        if (ch == '~') break;
        if (ch == ' ') {
            res.push_back(tmp);
            tmp = "";
        } else
            tmp += ch;
    }

    file.close();

    return res;
}

void app::run() {
    system("cls");
    gotoxy(curX, curY);

    // wordsBox->add_word("test");
    // wordsBox->add_word("test");
    // wordsBox->add_word("test");
    // wordsBox->add_word("test");
    // wordsBox->add_word("hello");

    vector <string> quote = getQuote();
    for (string word: quote)
        wordsBox->add_word(word);

    wordsBox->show_words();

    int totalCorrect = 0;

    for (int i = 0; i < wordsBox->words.size(); i ++) {
        gotoxy(curX, curY);

        for (auto &ch: wordsBox->words[i])
            ch.colorCode = YELLOW;
        wordsBox->show_words();
        cout << "Type here: ";
        string type = keyboard_get(this);

        totalCorrect += wordsBox->put_word(type, i);
        system("cls");
        wordsBox->show_words();
    }

    clock_t timePassed = clock() - enlapsedTime;
    float second =  (float) timePassed / CLOCKS_PER_SEC;

    int wpm = (float) totalCorrect / 5.0 / second  * 60.0;

    cout << '\n' << wpm << " WPM" << '\n';

}