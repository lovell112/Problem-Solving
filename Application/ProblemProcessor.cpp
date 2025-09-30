//
// Created by HP on 30/09/2025.
//

#include "ProblemProcessor.h"

void ProblemProcessor::process(IProblem* problem) {
    problem->run();
    delete problem;
}
