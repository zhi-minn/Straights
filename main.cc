#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>
#include <stdlib.h>
#include "controller.h"
#include "display.h"
using namespace std;

int main(int argc, char* argv[]) {
    int seed = 42;
    string cmd;
    char inp1, inp2;
    if (argc > 1) {
        seed = stoi(argv[1]);
    }
    shared_ptr<Controller> controller = make_shared<Controller>(seed);
    shared_ptr<Display> display = make_shared<Display>();
    display->setTable(controller->getTable());

    for (int i = 1; i <= 4; i++) {
        cout << "Is Player" << i << " a human (h) or a computer (c)?" << endl;
        cout << ">";
        cin >> inp1;
        controller->addPlayer(inp1, i);
    }
    controller->setGameStatePlayers();
    controller->attachDisplay(display);
    controller->createDeck();

    while (true) {
        controller->roundBegin();
        while (true) {
            controller->playerTurn();
            cout << *display;
            while (cout << ">" && cin >> cmd) {
                try {
                    if (cmd == "play") {
                        cin >> inp1 >> inp2;
                        controller->playCard(inp1, inp2);
                        break;
                    } else if (cmd == "discard") {
                        cin >> inp1 >> inp2;
                        controller->discard(inp1, inp2);
                        break;
                    } else if (cmd == "deck") {
                        controller->printDeck();
                    } else if (cmd == "quit") {
                        exit(0);
                    } else if (cmd == "ragequit") {

                    } else {
                        throw invalid_argument("Invalid command: \"" + cmd + "\"");
                    }
                } catch (invalid_argument &e) {
                    cerr << e.what() << endl;
                }
            }
        }
    }
}