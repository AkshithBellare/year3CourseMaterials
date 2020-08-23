#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> input (3,0);
    cout << "Enter m: ";
    cin >> input[0];
    cout << "Enter a: ";
    cin >> input[1];
    if(input[1] < 0) {
        cout << "INVALID INPUT: a has to be a positive integer\n";
        exit(0);
    }
    cout << "Enter n: ";
    cin >> input[2];

    cout << "f(x) = c(x^" << input[0] << " + " << input[1] << ")" << endl;
    cout << "x = 0...." << input[1] << endl;
    double c = 0.0;

    vector<int> powers(input[2]+1);
    int sum = 0;
    for(int i=0; i<=input[2]; i++) {
        int xPowM = pow(i, input[0]);
        sum += xPowM + input[1];
        cout << "f(x) = " << "c * " << xPowM + input[1] << " for x = " << i << endl;
    }
    
    cout << "Sum of all probabilities for all x values = 1" << endl;

    cout << sum << "*c" << " = 1" << endl;
    cout << "c = " << "1/" << sum << endl;

    c = 1.0/static_cast<double> (sum);

    cout << "c = " << c; 
}