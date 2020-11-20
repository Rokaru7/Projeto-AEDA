
#ifndef PROJETO_AEDA_WORKERS_H
#define PROJETO_AEDA_WORKERS_H

#include <string>
using namespace std;

class Worker {
protected:
    string name;
    int NIF, years, wage;
public:
    /**
     * Creates an object Worker.
     * @param name
     * @param NIF
     * @param wage
     * @param years
     */
    Worker(string n, int N, int w, int y);
    virtual ~Worker(){};
    /**
     * Returns the role of the worker.
     * @return role
     */
    virtual string getRole() {return "";};
    virtual string getShift() {return "";}
    virtual int getFloor() {return 0;}
    virtual int getEvaluation() {return 0;}
    /**
     * Returns the name of the worker.
     * @return name
     */
    string getName() const;
    /**
     * Returns the NIF of the worker.
     * @return NIF
     */
    int getNIF() const;
    /**
     * Returns the wage of the worker.
     * @return wage
     */
    int getWage() const;
    /**
     * Returns the years of work of the worker.
     * @return years
     */
    int getYears() const;
    /**
     * Displays info from the worker in a human friendly way.
     */
    virtual void info() const;
    virtual void info(ostream &o) const;
};

class Reception: public Worker {
public:
    /**
     * Creates an object of the subclass Reception
     * @param name
     * @param NIF
     * @param wage
     * @param year
     */
    Reception(string n, int N, int w, int y);
    string getRole() {return "Reception";}
    void info() const;
    void info(ostream &o) const;
};

class Responsible: public Worker {
    int floor;
public:
    /**
     * Creates an object of the subclass Responsible.
     * @param name
     * @param NIF
     * @param wage
     * @param years
     * @param floor
     */
    Responsible(string n, int N, int w, int y, int f);
    string getRole() {return "Responsible";}
    /**
     * Returns the floor of the Responsible.
     * @return floor
     */
    int getFloor()  {return floor;};
    void info() const;
    void info(ostream &o) const;
};

class Cleaning: public Worker {
    string shift;
public:
    /**
     * Creates an object of the subclass Cleaning
     * @param name
     * @param NIF
     * @param wage
     * @param years
     * @param shift
     */
    Cleaning(string n, int N, int w, int y, string s);
    string getRole() {return "Cleaning";}
    /**
     * Returns the shift of the Cleaning
     * @return shift
     */
    string getShift() {return shift;};
    void info() const;
    void info(ostream &o) const;
};

class Manager: public Worker {
    int evaluation;
public:
    /**
     * Creates an object of the subclass Manager.
     * @param name
     * @param NIF
     * @param wage
     * @param years
     * @param evaluation
     */
    Manager(string n, int N, int w, int y, int e);
    string getRole() {return "Manager";}
    /**
     * Returns the evaluation of the Manager.
     * @return evaluation
     */
    int getEvaluation() {return evaluation;};
    void info() const;
    void info(ostream &o) const;
};

class WorkerDoesNotExist {
    string name;
public:
    /**
     * Exception when the worker does not exist.
     * @param name
     */
    WorkerDoesNotExist(string n) {name = n;}
    string getName() {return name;}
};

#endif //PROJETO_AEDA_WORKERS_H