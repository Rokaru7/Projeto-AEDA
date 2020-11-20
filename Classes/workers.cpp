
#include "workers.h"
#include <iostream>

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

void Worker::info() const {
    return Worker::info(cout);
}

void Worker::info(ostream &o) const {
    o << "Name: " << name << "  NIF: " << NIF << "  Wage: " << wage << "  Years of work: " << years;
}

string Worker::getName() const {
    return name;
}

Reception::Reception(string n, int N, int w, int y) : Worker(n, N, w, y) {}

void Reception::info() const {
    return Reception::info(cout);
}

void Reception::info(ostream &o) const {
    o << "Reception    ";
    Worker::info();
    o << endl;
}

Responsible::Responsible(string n, int N, int w, int y, int f) : Worker(n, N, w, y) {
    floor = f;
}

void Responsible::info() const {
    return Responsible::info(cout);
}

void Responsible::info(ostream &o) const {
    o << "Responsible  ";
    Worker::info();
    o << endl;
}

Cleaning::Cleaning(string n, int N, int w, int y, string s) : Worker(n, N, w, y) {
    shift = s;
}

/*string Cleaning::getShift() const {
    return shift;
}*/

void Cleaning::info() const {
    return Cleaning::info(cout);
}

void Cleaning::info(ostream &o) const {
    o << "Cleaning     ";
    Worker::info();
    o << "  Shift: " << shift;
    o << endl;
}


Manager::Manager(string n, int N, int w, int y, int e) : Worker(n, N, w, y) {
    evaluation = e;
}

void Manager::info() const {
    return Manager::info(cout);
}

void Manager::info(ostream &o) const {
    o << "Manager      ";
    Worker::info();
    o << "  Evaluation: " << evaluation;
    o << endl;
}
