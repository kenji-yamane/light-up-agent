//
// Created by kenji on 17/09/22.
//

#ifndef LIGHT_UP_AGENT_BOARD_H
#define LIGHT_UP_AGENT_BOARD_H

#include "modeling/Restriction.h"
#include "modeling/Variable.h"

namespace modeling {

class Board {
public:
    Board();
    Board(int size);
    ~Board();

    void printBoard();

private:
    void initializeBoard();
    bool assertViability();

    int size;
    std::vector<std::vector<Variable*> > boardMatrix;
    std::vector<std::vector<Restriction*> > restrictionsMatrix;
};

}

#endif //LIGHT_UP_AGENT_BOARD_H
