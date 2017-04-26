#include <iostream>

using namespace std;

class PayRoll{
private:
    double pay_rate, gross_pay;
    int hours;
public:
    PayRoll() {
        pay_rate = 0;
        hours = 0;
        gross_pay = 0;
    }

    PayRoll(int pay, int h, double total){
        pay_rate = pay;
        hours = h;
        gross_pay = total;
    }

    void setPay(double pay) { pay_rate = pay; }
    void setHours(int h) { hours = h; }
    void setGrossPayment(double total) { gross_pay = total;}

    double getPay() const { return pay_rate;}
    int getHours() const { return hours;}
    double getGrossPayment() const { return pay_rate * hours;}
};

int main(){
    const int SIZE = 7;
    PayRoll employees[SIZE];

    int pay, h;
    double total;

    for (int i=0; i<SIZE; i++){
        cout << "Enter Pay Rate: " << endl;
        cin >> pay;
        cout << "Enter Hours Worked per Week: " << endl;
        cin >> h;

        //total = pay * h;

        employees[i].setPay(pay);
        employees[i].setHours(h);
        //employees[i].setGrossPayment(total);

        employees[i].getPay();
        employees[i].getHours();

        cout << "Weekly pay for employee " << i << " is " << employees[i].getGrossPayment() << endl;
    }

    return 0;
}
