//
// Created by kenji on 17/09/22.
//

#include "Variable.h"

namespace modeling {

std::map<Domain, char> Variable::domainToAscii = std::map<Domain, char>{
    {Domain::EMPTY, ' '},
    {Domain::IMPOSSIBLE, 'X'},
    {Domain::LIGHT_BULB, 'L'},
    {Domain::UNDEFINED, '?'},
};

Variable::Variable() {
    this->value = Domain::UNDEFINED;
}

char Variable::prettyDomain() const {
    return Variable::domainToAscii[this->value];
}

std::list<Variable>::iterator eraseVariable(
        std::list<Variable> &variables, std::list<Variable>::iterator it
) {
    auto aux = it;
    std::advance(it, 1);
    variables.erase(aux);
    return it;
}

}
