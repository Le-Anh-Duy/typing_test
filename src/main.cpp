#include "typing_app.hpp"

using namespace std;

int main() {
    app* myApp = new app();
    myApp->run();
    delete myApp;
    return 0;
}