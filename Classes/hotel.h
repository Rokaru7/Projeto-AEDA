//
// Created by pedro on 17/11/2020.
//

#ifndef PROJETO_AEDA_HOTEL_H
#define PROJETO_AEDA_HOTEL_H

#include <vector>
#include "workers.h"
using namespace std;

class hotel {
    vector<Worker *> workers;
public:
    vector<Worker *> getWorkers();
};


#endif //PROJETO_AEDA_HOTEL_H
