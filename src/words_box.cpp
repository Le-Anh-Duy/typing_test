#include "words_box.hpp"

void words_box::load_words() {}

void words_box::add_word(string word) {
    vector <color_char> ans;
    for (char ch: word)
        ans.push_back(color_char(ch, WHITE));
    words.push_back(ans);
}

int words_box::put_word(string word, int index) {
    while (word.size() < words[index].size()) word += ' ';

    int correct = 0;

    for (int i = 0; i < words[index].size(); i ++) {
        if (words[index][i].ch != word[i]) {
            words[index][i].colorCode = RED;
        } else {
            words[index][i].colorCode = GREEN;
            correct ++;
        }
    }
    current_index ++;

    return correct;
}

void words_box::show_words() {
    for (auto &word: words) {
        for (color_char &ch: word) {
            ch.write();
            sizeWords ++;
        }
        cout << ' ';
    }
    cout << '\n';
}