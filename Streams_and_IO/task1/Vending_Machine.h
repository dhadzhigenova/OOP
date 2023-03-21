#ifndef Vending_Machine_H
#define Vending_Machine_H

struct Inventory {
    unsigned int salty;
    unsigned int sweet;
    unsigned int drinks;

    void changeSalty(int quantity);
    void changeSweets(int quantity);
    void changeDrinks(int quantity);
    void print();

    Inventory();
};

class VendingMachine {
    int id;
    char* address;
    Inventory inventory;
    char** warningMessages;
    int numWarningMsgs;
    int capacity;

public:
    VendingMachine(); 
    VendingMachine(char* address, Inventory inventory); 
    VendingMachine(VendingMachine const& other);
    VendingMachine(VendingMachine&& other); 
    VendingMachine& operator=(VendingMachine const& other);
    ~VendingMachine();

    //include other needed methods
};


class VendingController {
    VendingMachine* vendingMachineList;
    int numMachines;
    int capacity;

public:
    //include big 4-5-6 
    void addVendingMachine(VendingMachine machine);
    void getAddressOfMachine(int machineID);
    void getInventoryOfMachine(int machineID);
    void sellProductInMachine(int machineID, char* product);
    void restockProductInMachine(int machineID, char* product);
    void seeWarningMsgForMachine(int machineID);
};




#endif