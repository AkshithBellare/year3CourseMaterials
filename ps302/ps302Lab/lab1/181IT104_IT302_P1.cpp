#include <iostream>
#include<string>
#include <math.h>
#include <fstream>
using namespace std;

bool checkNumber(string str) {
    for(int i=0; i<str.length(); i++) {
        if(isdigit(str[i]) == false) {
            return false;
        }
    }
    return true;
}

int main()
{
    int numOfSamplePoints = 0;
    string radius = "";
    int radint;
    cout << "Enter the radius:";
    cin >> radius;

    unsigned int fileSeq;
    ifstream seqFileIn;
    ofstream seqFileOut;
    seqFileIn.open("sequenceFile.txt", ios::in);

    if(seqFileIn.is_open()) {
        seqFileIn >> fileSeq;
        fileSeq++;
    }
    else fileSeq = 1;
    ofstream outputFile;
    string fileName = "181IT104_IT302_P1_Output_TC" + to_string(fileSeq) + ".txt";
    seqFileOut.open("sequenceFile.txt", ios::out);
    outputFile.open(fileName, ios::app);
    //if not a number exit
    if(checkNumber(radius) == false) {
        outputFile << "You entered an invalid radius: " << radius <<  " | Please enter a 3 digit positve integer radius" << endl;
        outputFile << "________________________________________________________" << endl;
        seqFileOut << fileSeq;
        seqFileOut.close();
        cout << "Please enter a 3 digit positive integer radius" << endl;
        exit(0);
    }
    else {
        //remove all leading zeros.
        radius.erase(0, radius.find_first_not_of('0'));
        if(radius.length() > 3) {
            outputFile << "The radius was too large: " << radius << " | Please enter a 3 digit integer positive radius" << endl;
            outputFile << "________________________________________________________" << endl;
            seqFileOut << fileSeq;
            seqFileOut.close();
            cout << "Please enter a 3 digit positive integer radius" << endl;
            exit(0);
        } else {
            radint = stoi(radius);
            cout << radint << endl;
        }
    }
    outputFile << "\nRadius is " << radius << endl;
    for(int i=0; i<=radint; i++) {
        //consider reflection along x=y : decreases number of comparisons.
        for(int j=0; j<=i && j*j < radint*radint - i*i; j++ ) {
            outputFile << '(' << i << ',' << j << ')' << " ";
            cout << '(' << i << ',' << j << ')' << " ";
            if(i!=j) {
                cout << "| " <<  '(' << j << ',' << i << ')' << " ";
                outputFile << '(' << j << ',' << i << ')' << " ";
                numOfSamplePoints += 1;
            }

            numOfSamplePoints += 1;
        } 
        outputFile << "\n";
        cout << endl;
    }
    outputFile << "Number of sample points = " << numOfSamplePoints << "\n";
    outputFile << "________________________________________________________" << endl;
    outputFile.close();
    seqFileOut << fileSeq;
    cout << "Number of Sample points = " << numOfSamplePoints << endl;
}
