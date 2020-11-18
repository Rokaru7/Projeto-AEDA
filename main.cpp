#include <iostream>
#include "Classes/hotel.h"


int main() {
    hotel h;
    string name, shift;
    int NIF, wage, years, floor, evaluation, price, quality;

    while(true){
        int input;
        cout << "1 - Client    2 - Room    3 - Worker    4 - Manager    0 - Close" << endl;
        cin >> input;
        if (input == 0) break;
        else if (input == 1){}
        else if (input == 2){}
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
                            h.addWorker(c);
                        }
                        else if (input == 2){
                            cout << "Name    NIF    Wage    Years of service    Evaluation" << endl;
                            cin >> name >> NIF >> wage >> years >> evaluation;
                            Manager *m = new Manager(name, NIF, wage, years, evaluation);
                            h.addWorker(m);
                        }
                        else if (input == 3){
                            cout << "Name    NIF    Wage    Years of service" << endl;
                            cin >> name >> NIF >> wage >> years;
                            Reception *r = new Reception(name, NIF, wage, years);
                            h.addWorker(r);
                        }
                        else if (input == 4){
                            cout << "Name    NIF    Wage    Years of service    Shift" << endl;
                            cin >> name >> NIF >> wage >> years >> floor;
                            Responsible *r1 = new Responsible(name, NIF, wage, years, floor);
                            h.addWorker(r1);
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
                    string input_str;
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
                            h.addProvider(p);
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
                            h.getProviders()[pos]->addProduct(p1);
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
