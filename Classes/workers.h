
#ifndef PROJETO_AEDA_WORKERS_H
#define PROJETO_AEDA_WORKERS_H

#include <string>
using namespace std;

class Worker {
protected:
    string name;
    int NIF, years, wage;
public:
    Worker(string n, int N, int w, int y);
    virtual ~Worker(){};
    virtual string getRole() {return "";};
    virtual string getShift() {return "";}
    virtual int getFloor() {return 0;}
    virtual int getEvaluation() {return 0;}
    string getName() const;
    int getNIF() const;
    int getWage() const;
    int getYears() const;
    virtual void info() const;
    virtual void info(ostream &o) const;
};

class Reception: public Worker {
public:
    Reception(string n, int N, int w, int y);
    string getRole() {return "Reception";}
    void info() const;
    void info(ostream &o) const;
};

class Responsible: public Worker {
    int floor;
public:
    Responsible(string n, int N, int w, int y, int f);
    string getRole() {return "Responsible";}
    int getFloor()  {return floor;};
    void info() const;
    void info(ostream &o) const;
};

class Cleaning: public Worker {
    string shift;
public:
    Cleaning(string n, int N, int w, int y, string s);
    string getRole() {return "Cleaning";}
    string getShift() {return shift;};
    void info() const;
    void info(ostream &o) const;
};

class Manager: public Worker {
    int evaluation;
public:
    Manager(string n, int N, int w, int y, int e);
    string getRole() {return "Manager";}
    int getEvaluation() {return evaluation;};
    void info() const;
    void info(ostream &o) const;
};

class WorkerDoesNotExist {
    string name;
public:
    WorkerDoesNotExist(string n) {name = n;}
    string getName() {return name;}
};

#endif //PROJETO_AEDA_WORKERS_H