//
// Created by pedro on 17/11/2020.
//

#include "workers.h"

Worker::Worker(string n, int N, int w, int y) {
    name = n; NIF = N; wage = w; years = y;
}

int Worker::getNIF() const {
    return NIF;
}

int Worker::getWage() const {
    return wage;
}

int Worker::getYears() const {
    return years;
}

Reception::Reception(string n, int N, int w, int y) : Worker(n, N, w, y) {}

Responsible::Responsible(string n, int N, int w, int y, int f) : Worker(n, N, w, y) {
    floor = f;
}

int Responsible::getFloor() const {
    return floor;
}

Cleaning::Cleaning(string n, int N, int w, int y, string s) : Worker(n, N, w, y) {
    shift = s;
}

string Cleaning::getShift() const {
    return shift;
}


Manager::Manager(string n, int N, int w, int y, int e) : Worker(n, N, w, y) {
    evaluation = e;
}

int Manager::getEvaluation() const {
    return evaluation;
}
