#include <iostream>

using namespace std;

class Inventory{
    private:
        int itemNumber, quantity;
        double cost, totalCost;
    public:
        Inventory();
        Inventory(int, double, int, double);

        //Setter Functions
        void setItemNumber(int);
        void setQuantity(int);
        void setCost(double);
        void setTotalCost(double);

        //Accessor Functions
        int getItemNumber()const;
        int getQuantity() const;
        double getCost() const;
        double getTotalCost() const;
};

Inventory::Inventory() {
    itemNumber = 0;
    quantity = 0;
    cost = 0.0;
    totalCost = 0.0;
}

Inventory::Inventory(int num, double cost_1 , int quan, double total) {
    itemNumber = num;
    cost = cost_1;
    quantity = quan;
    totalCost = total;

    setTotalCost(total);
}

//Setter Functions
void Inventory::setItemNumber(int num) { itemNumber = num;}
void Inventory::setQuantity(int quan) { quantity = quan;}
void Inventory::setCost(double cost_1) { cost = cost_1;}
void Inventory::setTotalCost(double total) { totalCost = total;}

//Accessor Functions
int Inventory::getItemNumber() const { return  itemNumber;}
int Inventory::getQuantity() const { return quantity;}
double Inventory::getCost() const { return cost;}
double Inventory::getTotalCost() const { return totalCost;}

int main(){

    int num, quan;
    double cost_1, total;

    cout << "What is the item number?" << endl;
    cin >> num;

    cout << "What is the quantity?" << endl;
    cin >> quan;

    cout << "What is the cost?" << endl;
    cin >> cost_1;

    Inventory Item_1;

    if (num>0 && quan>0 && cost_1>0){
        Item_1.setItemNumber(num);
        Item_1.setQuantity(quan);
        Item_1.setCost(cost_1);

        total = quan * cost_1;

        Item_1.setTotalCost(total);

        cout << Item_1.getTotalCost() << endl;
    }

    return 0;
}
