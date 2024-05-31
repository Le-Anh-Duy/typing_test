
#include <vector>
#include <string>
#include "color_char.hpp"
using namespace std;

class words_box {
public:
    int current_index, sizeWords;
    words_box() {
        current_index = 0;
        sizeWords = 0;
    };
    ~words_box() {};

    vector <vector <color_char>> words;

    void load_words();
    // add a word in words list
    void add_word(string word);
    // put the inputed word to check with the ans
    void put_word(string word, int index);
    void show_words();
};