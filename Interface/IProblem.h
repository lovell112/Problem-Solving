//
// Created by HP on 30/09/2025.
//

#ifndef PROBLEMS_IPROBLEM_H
#define PROBLEMS_IPROBLEM_H

class IProblem {
public:
    IProblem() = default;
    virtual ~IProblem() = default;
    virtual void run() = 0;
};

#endif //PROBLEMS_IPROBLEM_H