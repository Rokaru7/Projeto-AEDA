#include <iostream>
#include <fstream>
#include "Classes/hotel.h"


int main() {
    hotel h;
    string name, shift, type;
    int NIF, wage, years, floor, evaluation, price, quality, guests, number, capacity;
    bool free;

    ifstream data("data.txt");
    string word;
    while ( data >> word ){
        if (word == "Client"){
            for (int i = 0; i != 4; i++){
                data >> word;
                if (i == 0) name = word;
                else if (i == 1) NIF = stoi(word);
                else if (i == 2) years = stoi(word);
                else guests = stoi(word);
            }
            Clients *c = new Clients(name, NIF, years, guests);
            h.addClient(c, false);
        }
        else if (word == "Room"){
            for (int i = 0; i != 6; i++){
                data >> word;
                if (i == 0) name = word;
                else if (i == 1) floor = stoi(word);
                else if (i == 2) number = stoi(word);
                else if (i == 3) price = stoi(word);
                else if (i == 4) capacity = stoi(word);
                else free = stoi(word);
            }
            Room *r = new Room(name, floor, number, price, capacity, free);
            h.addRoom(r, false);
        }
        else if (word == "Cleaning"){
            for (int i = 0; i != 5; i++){
                data >> word;
                if (i == 0) name = word;
                else if (i == 1) NIF = stoi(word);
                else if (i == 2) wage = stoi(word);
                else if (i == 3) years = stoi(word);
                else shift = word;
            }
            Cleaning *c = new Cleaning(name, NIF, wage, years, shift);
            h.addWorker(c, false);
        }
        else if (word == "Reception"){
            for (int i = 0; i != 4; i++){
                data >> word;
                if (i == 0) name = word;
                else if (i == 1) NIF = stoi(word);
                else if (i == 2) wage = stoi(word);
                else years = stoi(word);
            }
            Reception *r = new Reception(name, NIF, wage, years);
            h.addWorker(r, false);
        }
        else if (word == "Responsible"){
            for (int i = 0; i != 5; i++){
                data >> word;
                if (i == 0) name = word;
                else if (i == 1) NIF = stoi(word);
                else if (i == 2) wage = stoi(word);
                else if (i == 3) years = stoi(word);
                else floor = stoi(word);
            }
            Responsible *r1 = new Responsible(name, NIF, wage, years, floor);
            h.addWorker(r1, false);
        }
        else if (word == "Manager"){
            for (int i = 0; i != 5; i++){
                data >> word;
                if (i == 0) name = word;
                else if (i == 1) NIF = stoi(word);
                else if (i == 2) wage = stoi(word);
                else if (i == 3) years = stoi(word);
                else evaluation = stoi(word);
            }
            Manager *m = new Manager(name, NIF, wage, years, evaluation);
            h.addWorker(m, false);
        }
        else if (word == "Provider"){
            data >> word;
            name = word;
            Provider *P = new Provider(name);
            h.addProvider(P, false);
        }
        else if (word == "Product"){
            for (int i = 0; i != 4; i++){
                data >> word;
                if (i == 0) name = word;
                else if (i == 1) type = word;
                else if (i == 2) price = stoi(word);
                else if (i == 3) quality = stoi(word);
            }
            Product *p = new Product(type, price, quality);
            h.getProviders()[h.getProviderpos(name)]->addProduct(p, false);
        }
        else {
            name = word;
            data >> word;
            floor = stoi(word);
            data >> word;
            number = stoi(word);
            int pos_cl = h.getClientspos(name);
            int pos = h.getRoompos(floor, number);
            h.getRooms()[pos]->enter();
            h.getClients()[pos_cl]->addRoom(h.getRooms()[pos]);
            h.addIncome(h.getRooms()[pos]->getPrice());
        }
    }
    data.close();

    while(true){
        int input;
        string input_str;
        cout << "1 - Client    2 - Room    3 - Worker    4 - Manager    0 - Close" << endl;
        cin >> input;
        if (input == 0) break;
        else if (input == 1){
            while(true){
                cout << "1 - Add Client    2 - Remove Client    3 - List of Clients    0 - Go back" << endl;
                cin >> input;
                if (input == 0) break;
                else if (input == 1){
                    cout << "Name    NIF    Number of guests" << endl;
                    cin >> name >> NIF >> guests;
                    Clients *c = new Clients(name, NIF, 0, guests);
                    h.addClient(c, true);
                }
                else if (input == 2){
                    cout << "Name: " << endl;
                    cin >> name;
                    int pos = h.getClientspos(name);
                    cout << "Are you sure u want to remove (yes or no) :" << endl;
                    h.getClients()[pos]->info();
                    cin >> input_str;
                    if (input_str == "yes") h.removeClient(pos);
                }
                else if (input == 3){
                    h.listClients();
                }
                else cout << "Invalid input" << endl;
            }
        }
        else if (input == 2){
            while (true){
                cout << "1 - Add Room    2 - Remove Room    3 - List free rooms    4 - List all rooms    0 - Go back" << endl;
                cout << "5 - Enter Room    6 - Leave Room" << endl;
                cin >> input;
                if (input == 0) break;
                else if (input == 1){
                    cout << "Type of the room (suite, withview, withoutview): " << endl;
                    cin >> name;
                    if (name != "suite" && name != "withview" && name != "withoutview"){
                        cout << "Invalid type" << endl;
                        break;
                    }
                    cout << "Floor   Number of the room   Capacity   Price" << endl;
                    cin >> floor >> number >> capacity >> price;
                    Room *r = new Room(name, floor, number, price, capacity, true);
                    h.addRoom(r, true);
                }
                else if (input == 2){
                    cout << "Floor   Number" << endl;
                    cin >> floor >> number;
                    int pos = h.getRoompos(floor, number);
                    cout << "Are you sure u want to remove (yes or no) :" << endl;
                    h.getRooms()[pos]->info();
                    cin >> input_str;
                    if (input_str == "yes") h.removeRoom(pos);
                }
                else if (input == 3){
                    h.listfreeRooms();
                }
                else if (input == 4){
                    h.listRooms();
                }
                else if (input == 5){
                    cout << "Name of the Client: " << endl;
                    cin >> name;
                    int pos_cl = h.getClientspos(name);
                    cout << "Number of Rooms: " << endl;
                    int it;
                    cin >> it;
                    vector<int> positions;
                    int totalspots = 0;
                    for (int i = 0; i != it; i++){
                        cout << "Floor   Number of the room" << endl;
                        cin >> floor >> number;
                        int pos = h.getRoompos(floor, number);
                        if (!h.getRooms()[pos]->getFree()) {
                            cout << "Room is occupied" << endl;
                            break;
                        }
                        positions.push_back(pos);
                        totalspots += h.getRooms()[pos]->getCapacity();
                    }
                    if (totalspots >= h.getClients()[pos_cl]->getReservation()){
                        for (int i = 0; i != positions.size(); i++){

                            ofstream data;
                            data.open ("data.txt", fstream::app);
                            data << h.getClients()[pos_cl]->getName() << " " << floor << " " << number << endl;
                            data.close();

                            h.getRooms()[positions[i]]->enter();
                            h.getClients()[pos_cl]->addRoom(h.getRooms()[positions[i]]);
                            h.addIncome(h.getRooms()[positions[i]]->getPrice());
                        }
                    }
                    else {
                        cout << "Not enought capacity for all guests" << endl;
                        continue;
                    }
                }
                else if (input == 6){
                    cout << "Name of the Client: " << endl;
                    cin >> name;
                    int pos_cl = h.getClientspos(name);
                    for (int i = 0; i != h.getClients()[pos_cl]->getRooms().size(); i++){
                        h.eraseLine((name + " " + to_string(h.getClients()[pos_cl]->getRooms()[i]->getFloor()) + " " + to_string(h.getClients()[pos_cl]->getRooms()[i]->getNumber())));
                        h.getClients()[pos_cl]->getRooms()[i]->leave();
                        h.removeIncome(h.getClients()[pos_cl]->getRooms()[i]->getPrice());
                    }
                }
                else cout << "Invalid input" << endl;
            }
        }
        else if (input == 3){
            while(true){
                cout << "1 - Add Worker    2 - Remove Worker    0 - Go back" << endl;
                cin >> input;
                if (input == 0) break;
                else if (input == 1){
                    while (true){
                        cout << "1 - Cleaning    2 - Manager    3 - Reception    4 - Responsible    0 - Go back" << endl;
                        cin >> input;
                        if (input == 0) break;
                        else if (input == 1){
                            cout << "Name    NIF    Wage    Years of service    Shift" << endl;
                            cin >> name >> NIF >> wage >> years >> shift;
                            Cleaning *c = new Cleaning(name, NIF, wage, years, shift);
                            h.addWorker(c, true);
                        }
                        else if (input == 2){
                            cout << "Name    NIF    Wage    Years of service    Evaluation" << endl;
                            cin >> name >> NIF >> wage >> years >> evaluation;
                            Manager *m = new Manager(name, NIF, wage, years, evaluation);
                            h.addWorker(m, true);
                        }
                        else if (input == 3){
                            cout << "Name    NIF    Wage    Years of service" << endl;
                            cin >> name >> NIF >> wage >> years;
                            Reception *r = new Reception(name, NIF, wage, years);
                            h.addWorker(r, true);
                        }
                        else if (input == 4){
                            cout << "Name    NIF    Wage    Years of service    Shift" << endl;
                            cin >> name >> NIF >> wage >> years >> floor;
                            Responsible *r1 = new Responsible(name, NIF, wage, years, floor);
                            h.addWorker(r1, true);
                        }
                        else cout << "Invalid input" << endl;
                    }
                }
                else if (input == 2){
                    cout << "Name: " << endl;
                    cin >> name;
                    int pos = h.getWorkerpos(name);
                    cout << "Are you sure u want to remove (yes or no) :" << endl;
                    h.getWorkers()[pos]->info();
                    cin >> input_str;
                    if (input_str == "yes") h.removeWorker(pos);
                }
                else cout << "Invalid input" << endl;
            }
        }
        else if (input == 4){
            while (true) {
                cout << "1 - Clients/Workers information    2 - Providers/Products     3 - Accounting    0 - Go back"
                     << endl;
                cin >> input;
                if (input == 0) break;
                else if (input == 1){
                    cout << "1 - Filter new Clients    2 - Sort Workers by wage    3 - Search Workers by Wage" << endl;
                    cout << "4 - Sort Workers by Role    5 - Search Workers by Role" << endl;
                    cin >> input;
                    if (input == 1){
                        h.filterClients();
                    }
                    else if (input == 2){
                        h.sortbyWage();
                    }
                    else if (input == 3){
                        cout << "Enter the desired wage: " << endl;
                        cin >> input;
                        h.searchbyWage(input);
                    }
                    else if (input == 4){
                        h.sortbyRole();
                    }
                    else if (input == 5){
                        cout << "Enter the desired Role: " << endl;
                        cin >> input_str;
                        h.searchbyRole(input_str);
                    }
                    else cout << "Invalid input" << endl;
                }
                else if (input == 2){
                    cout << "1 - Providers    2 - Products    0 - Go back" << endl;
                    cin >> input;
                    if (input == 0) continue;
                    else if (input == 1){
                        cout << "1 - Add Provider    2 - Remove Provider    3 - List Providers    0 - Go back" << endl;
                        cin >> input;
                        if (input == 0) continue;
                        else if (input == 1){
                            cout << "Name of the provider: " << endl;
                            cin >> name;
                            Provider *p = new Provider(name);
                            h.addProvider(p, true);
                        }
                        else if (input == 2){
                            cout << "Name: " << endl;
                            cin >> name;
                            int pos = h.getProviderpos(name);
                            cout << "Are you sure u want to remove " << name << " (yes or no) :" << endl;
                            string input_str;
                            cin >> input_str;
                            if (input_str == "yes") h.removeProvider(pos);
                        }
                        else if (input == 3){
                            h.listProviders();
                        }
                        else cout << "Invalid input" << endl;
                    }
                    else if (input == 2){
                        cout << "1 - Add Product    2 - Remove Product    3 - Buy Product    4 - List Products    0 - Go back" << endl;
                        cin >> input;
                        if (input == 0) continue;
                        else if (input == 1){
                            cout << "Name of the provider: " << endl;
                            cin >> name;
                            int pos = h.getProviderpos(name);
                            cout << "Type of the Product    Price    Quality" << endl;
                            cin >> name >> price >> quality;
                            Product *p1 = new Product(name, price, quality);
                            h.getProviders()[pos]->addProduct(p1, true);
                        }
                        else if (input == 2){
                            cout << "Name of the provider: " << endl;
                            cin >> name;
                            int pos = h.getProviderpos(name);
                            cout << "Type of the product: " << endl;
                            cin >> name;
                            h.getProviders()[pos]->removeProduct(h.getProviders()[pos]->getProductpos(name));
                        }
                        else if (input == 3){
                            cout << "Type of the product: " << endl;
                            cin >> name;
                            h.chooseProducts(name);
                        }
                        else if (input == 4){
                            h.listProducts();
                        }
                        else cout << "Invalid input" << endl;
                    }
                    else cout << "Invalid input" << endl;
                }
                else if (input == 3){
                    cout << "Income: " << h.getIncome() << "    Costs: " << (h.getTotalProducts()+h.getTotalWorkers()) << "    Profit: " <<
                    (h.getIncome() - (h.getTotalProducts()+h.getTotalWorkers())) << endl;
                }
                else cout << "Invalid input" << endl;
            }
        }
        else cout << "Invalid input" << endl;

    }
    return 0;
}
