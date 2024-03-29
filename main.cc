#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>
#include <stdlib.h>
#include <chrono>
#include "controller.h"
#include "display.h"
#include "scoreView.h"
using namespace std;

int main(int argc, char* argv[]) {
    bool forcequit = false;

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    string cmd;
    char inp1, inp2;
    if (argc > 1) {
        seed = stoi(argv[1]);
    }
    shared_ptr<Controller> controller = make_shared<Controller>(seed);
    shared_ptr<Display> display = make_shared<Display>();
    shared_ptr<ScoreView> scoreView = make_shared<ScoreView>();

    controller->makePlayers();
    controller->setGameStatePlayers();
    controller->attachObservers(display, scoreView);
    controller->createDeck();

    while (true) {
        controller->roundBegin();
        while (true) {
            controller->playerTurn();
            if (controller->isComputerTurn()) {
                controller->autoplayComputer();
                controller->nextTurn();
            } else {
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
			    forcequit = true;
                            goto END;
                        } else if (cmd == "ragequit") {
                            controller->ragequit();
                            break;
                        } else {
                            throw invalid_argument("Invalid command: \"" + cmd + "\"");
                        }
                    } catch (invalid_argument &e) {
                        cerr << e.what() << endl;
                    }
                }
            }
            if (controller->roundEnd()) {
                cout << *scoreView;
                controller->tabulateScore();
                controller->roundReset();
                break;
            }
        }
        if (controller->gameEnd()) {
            controller->announceWinners();
            break;
        }
	// Facilitate quit functionality
        END:
	if (forcequit) {
	    break;
	}
    }
}
