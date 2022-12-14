//
// Created by kenji on 18/09/22.
//

#include "ConstraintSatisfaction.h"

#include <iostream>
#include <utility>

namespace decision_making {

ConstraintSatisfaction::ConstraintSatisfaction(modeling::Board initialBoard) :
    nodesVisited(0),
    initialBoard(std::move(initialBoard)) {
}

bool ConstraintSatisfaction::solve() {
    this->initialBoard.interpretRestrictions();
    if (not this->initialBoard.assertViability()) {
        return false;
    }
    auto undefinedVariables = this->initialBoard.getUndefinedVariables();
    if (this->solve(State{undefinedVariables, this->initialBoard})) {
        return true;
    }
    return false;
}

bool ConstraintSatisfaction::solve(const State& s) {
    this->nodesVisited++;
    if (s.undefinedVariables.empty()) {
        this->solution = s.board;
        return s.board.enlightened();
    }

    for (const auto &variable : s.undefinedVariables) {
        auto next = s;
        auto affectedVariables = next.board.lightUp(variable.first, variable.second);
        if (not next.board.assertViability()) {
            continue;
        }
        auto it = next.undefinedVariables.begin();
        while (it != next.undefinedVariables.end()) {
            if (affectedVariables.find(std::pair(it->first, it->second)) != affectedVariables.end()) {
                auto aux = it;
                std::advance(it, 1);
                next.undefinedVariables.erase(aux);
            } else {
                std::advance(it, 1);
            }
        }
        if (this->solve(next)) {
            return true;
        }
    }
    return false;
}

}
