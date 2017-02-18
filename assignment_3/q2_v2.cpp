#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

//Structures
struct DNAnt{
    int num_1;
    int num_2;
    int num_3;
    int num_4;
    char dna_strand[100];
};

//Function Prototypes
void data2DNA(DNAnt allDNA[], int SIZE);
void countDNAnt(DNAnt allDNA[], int SIZE, int num_a, int num_c, int num_g, int num_t);
void DNAtoRNA(DNAnt allDNA[], int SIZE/*, int num_t*/);

int main() {
    int const SIZE = 80;
    DNAnt allDNA[SIZE];

    int num_a=0, num_c=0, num_g=0, num_t=0;

    //Calling the function
    data2DNA(allDNA,SIZE);
    countDNAnt(allDNA, SIZE, num_a, num_c, num_g, num_t);
    DNAtoRNA(allDNA, SIZE/*, num_t*/);

    system("PAUSE");
    return 0;
}

void data2DNA(DNAnt allDNA[], int SIZE){
    ifstream infile;
    ofstream outfile;

    infile.open("data.txt"); //Opens file data.txt
    outfile.open("DNA.txt"); //Opens DNA.txt for writing

    if(infile.fail()){ //Checks for file opening.
        cout << "ERROR => File Failed to Open.";
    }

    while(!infile.eof()){
        for(int i=0; i<SIZE; i++){
            //Read data from file into array of structures.
            infile >>  allDNA[i].num_1 >> allDNA[i].num_2 >> allDNA[i].num_3 >> allDNA[i].num_4;

            for(int j=0; j<100; j++){ //Assigns data to c-string array
                //num_1
                if(allDNA[i].num_1 == 1){
                    allDNA[i].dna_strand[j] = 'A';
                }
                else if(allDNA[i].num_1 == 2){
                    allDNA[i].dna_strand[j] = 'C';
                }
                else if(allDNA[i].num_1 == 3){
                    allDNA[i].dna_strand[j] = 'G';
                }
                else{
                    allDNA[i].dna_strand[j] = 'T';
                }

                //num_2
                if(allDNA[i].num_2 == 1){
                    allDNA[i].dna_strand[j] = 'A';
                }
                else if(allDNA[i].num_2 == 2){
                    allDNA[i].dna_strand[j] = 'C';
                }
                else if(allDNA[i].num_2 == 3){
                    allDNA[i].dna_strand[j] = 'G';
                }
                else{
                    allDNA[i].dna_strand[j] = 'T';
                }

                //num_3
                if(allDNA[i].num_3 == 1){
                    allDNA[i].dna_strand[j] = 'A';
                }
                else if(allDNA[i].num_3 == 2){
                    allDNA[i].dna_strand[j] = 'C';
                }
                else if(allDNA[i].num_3 == 3){
                    allDNA[i].dna_strand[j] = 'G';
                }
                else{
                    allDNA[i].dna_strand[j] = 'T';
                }

                //num_4
                if(allDNA[i].num_4 == 1){
                    allDNA[i].dna_strand[j] = 'A';
                }
                else if(allDNA[i].num_4 == 2){
                    allDNA[i].dna_strand[j] = 'C';
                }
                else if(allDNA[i].num_4 == 3){
                    allDNA[i].dna_strand[j] = 'G';
                }
                else{
                    allDNA[i].dna_strand[j] = 'T';
                }

                //Write results to a file DNA.txt
                outfile << allDNA[i].dna_strand[j] << " ";
            }
        }
    }

    infile.close();
    outfile.close();
}

void countDNAnt(DNAnt allDNA[], int SIZE, int num_a, int num_c, int num_g, int num_t){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<100; j++){
            if(allDNA[i].dna_strand[j] == 'A'){
                num_a++;
            }
            else  if(allDNA[i].dna_strand[j] == 'C'){
                num_c++;
            }
            else if(allDNA[i].dna_strand[j] == 'G'){
                num_g++;
            }
            else{
                num_t++;
            }
        }
    }
    cout << "A-" << num_a << " C-" <<num_c << " G-" << num_g << " T-" << num_t << endl;
}

void DNAtoRNA(DNAnt allDNA[], int SIZE/*, int num_t*/){
    ofstream outfile;
    outfile.open("RNA.txt");

    for(int i=0; i<SIZE; i++){
        for(int j=0; j<100; j++){
            if(allDNA[i].dna_strand[j] == 'T' /*&& num_t > 25*/){
                allDNA[i].dna_strand[j] = 'U';
            }

            //Write results to a file RNA.txt
            outfile << allDNA[i].dna_strand[j] << " ";
        }
    }
    outfile.close();
}
