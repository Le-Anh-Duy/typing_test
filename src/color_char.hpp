#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

#define RED 12
#define WHITE 7
#define GREEN 2
#define YELLOW 6

struct color_char {
    char ch;
    int colorCode;
    color_char(char ch, int code): ch(ch), colorCode(code) {};
    void write();
};
