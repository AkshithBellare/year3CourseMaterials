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
    if(checkNumber(radius) == false) {
        cout << "Please enter a 3 digit positive radius";
        exit(0);
    }
    else {
        if(radius.length() > 3) {
            cout << "Radius has to be a 3 digit positive integer";
            exit(0);
        } else {
            radint = stoi(radius);
            cout << radint << endl;
        }
    }
    ofstream outputFile;
    outputFile.open("output.txt", ios::app);
    outputFile << "\nradius is " << radius;
    for(int i=0; i<=radint; i++) {
        for(int j=0; j<= pow((pow(radint,2)-pow(i,2)), 0.5); j++ ) {
            outputFile << '(' << i << ',' << j << ')' << " ";
            cout << '(' << i << ',' << j << ')' << " ";
            numOfSamplePoints += 1;
        } 
        outputFile << "\n";
        cout << endl;
    }
    outputFile << "Number of sample points = " << numOfSamplePoints << "\n";
    cout << "Number of Sample points = " << numOfSamplePoints << endl;
}
