#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

//Function Prototypes
bool verified(char *);
void invalidLength();
void invalidLower();
void invalidUpper();
void invalidDigit();
void invalidAlpha();

int main(){

	const int MAX = 100;
	char password [MAX];

	cout << "\n\n";
	cout << " Enter a password that is:\n\n";
	cout << "\tAtleast 6 characters long \n";
	cout << "\tAtleast 1 uppercase letter \n";
	cout << "\tAtleast 1 lowercase letter \n";
	cout << "\tAtleast 1 numerical digit \n\n\n";
	cout << " Enter Password:  ";
	cin.getline (password, MAX);
	cout << "\n\n\n";
	
	while (!verified(password)){
		cout << "\n\n";
		cout << " Re-enter Password: ";
		cin.getline (password, MAX);
		cout << "\n\n\n";
	}
	cout << "\n\n";
	cout << " The password " << password << " is a valid password! \n\n\n";

	return 0;
}

bool verified(char *pass){
	bool vLength = false;
	bool vUpper = false;
    bool vLower = false;
    bool vDigit = false;
	bool vAlpha = false;
    int length = strlen(pass);

    for(int i = 0; i < length; i++){
		if (length >= 6) vLength = true;			
		if (isdigit(pass[i])) vDigit = true;		
        if(islower(pass[i])) vLower = true;		
        if(isupper(pass[i])) vUpper = true;		
		if(isalpha(pass[i])) vAlpha = true;
    }

	if (vLength == false || vDigit == false || vUpper == false || vLower == false || vAlpha == false){
		cout << "\t\t   ======================== \n";
		cout << "\t\t   !!! Invalid Password !!! \n";
		cout << "\t\t   ======================== \n";
		cout << "\n\n";
		cout << "\t Your password DOES NOT contain the following: \n\n";
	}

	if (vLength == false) invalidLength();
	if (vAlpha == false) invalidAlpha();
	if (vDigit == false) invalidDigit();
	if (vLower == false) invalidLower();	
	if (vUpper == false) invalidUpper();

    return vUpper && vLower && vDigit && vAlpha; 
}

void invalidLength() { cout << "\t\t* Atleast 6 characters long! \n"; }
void invalidLower() { cout << "\t\t* Atleast one lower case letter. \n"; }
void invalidUpper() { cout << "\t\t* Atleast one upper case letter. \n"; }
void invalidDigit() { cout << "\t\t* Atleast one numerical digit. \n"; }
void invalidAlpha() { cout << "\t\t* Atleast one letter. \n"; }