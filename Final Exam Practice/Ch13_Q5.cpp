#include <iostream>
#include <string>

using namespace std;

class RetailItem{
    private:
        string description;
        int unitsOnHand;
        double price;
    public:
        RetailItem();
    
        //Accessor Functions
        string getDesc() const;
        int getUnits() const;
        double getPrice() const;

        //Mutator Functions
        void setDesc(string);
        void setUnits(int);
        void setPrice(double);
};

//Default Constructor
RetailItem::RetailItem() {
    unitsOnHand = 0;
    price = 0.0;
}

//Accessor Functions
string RetailItem::getDesc() const { return description; }

int RetailItem::getUnits() const { return unitsOnHand; }

double RetailItem::getPrice() const { return price; }

//Mutator Functions
void RetailItem::setDesc(string desc) { description = desc; }

void RetailItem::setUnits(int units) { unitsOnHand = units; }

void RetailItem::setPrice(double price_1) { price = price_1; }

int main(){
    RetailItem Item_1;

    //Item 1
    Item_1.setDesc("Jacket");
    Item_1.setUnits(12);
    Item_1.setPrice(59.95);

    cout << Item_1.getDesc() << endl << Item_1.getUnits() << endl << Item_1.getPrice();

    return 0;
}
