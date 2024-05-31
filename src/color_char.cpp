#include "color_char.hpp"

void changeColor(int desiredColor){
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

void color_char::write() {
    changeColor(colorCode);
    cout << ch;
    changeColor(WHITE);
}