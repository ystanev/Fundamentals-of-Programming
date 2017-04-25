#include <iostream>
#include <cmath>

using namespace std;

class Mortgage{
private:
    double loanAmount, interestRate;
    int years;

public:
    //Accessor Functions
    /*double getAmount() const;
    double getRate() const;
    int getYears() const;*/

    //Mutator Functions
    void setAmount(double);
    void setRate(double);
    void setYears(int);

    //Calculations
    double calculateTerm();
    double calculatePayment();
};

//Accessor Functions
/*double Mortgage::getAmount() const {
    return loanAmount;
}

double Mortgage::getRate() const {
    return interestRate;
}

int Mortgage::getYears() const {
    return years;
}*/

//Mutator Functions
void Mortgage::setAmount(double amt) {
    loanAmount = amt;
}

void Mortgage::setRate(double rate) {
    interestRate = rate;
}

void Mortgage::setYears(int years_1) {
    years = years_1;
}

//Calculations
double Mortgage::calculateTerm() {
    return pow( ( 1 + (interestRate/12) ), (12 * years) );
}

double Mortgage::calculatePayment() {
    return ( loanAmount * (interestRate/12) * calculateTerm() ) / ( calculateTerm() - 1 );
}

int main(){

    double amt, rate;
    int years_1;

    cout << "Enter the loan amount: ";
    cin >> amt;

    while (amt < 0){
        cout << "Loan ammount can't be negative." << endl;
        cout << "Enter the loan amount: ";
        cin >> amt;
    }

    cout << "Enter interest rate: ";
    cin >> rate;
    cout << "Enter the loan period: ";
    cin >> years_1;

    Mortgage morg1;

    morg1.setAmount(amt);
    morg1.setRate(rate);
    morg1.setYears(years_1);

    cout << "You monthly payment is: " << morg1.calculatePayment() << endl
        << "Your total amount paid is: " << morg1.calculateTerm() << endl;
    return 0;
}
