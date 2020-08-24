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

    ofstream outputFile;
    outputFile.open("output.txt");
    string result_str = "";
    result_str +=  "f(x) = c(x^" + to_string(input[0]) + " + " + to_string(input[1]) + ")" + "\n";
    result_str += "x = 0...." + to_string(input[1]) + "\n";
    double c = 0.0;

    vector<int> powers(input[2]+1);
    int sum = 0;
    for(int i=0; i<=input[2]; i++) {
        int xPowM = pow(i, input[0]);
        sum += xPowM + input[1];
        result_str += "f(" + to_string(i) + ") = c * " + to_string(xPowM + input[1]) + "\n";
    }
    result_str += "Sum of all probabilities for all x values = 1\n";

    result_str += to_string(sum) + "*c" + " = 1\n" ;
    result_str += "c = 1/" + to_string(sum) + "\n";

    c = 1.0/static_cast<double> (sum);

    result_str += "c = " + to_string(c) + "\n"; 

    outputFile << result_str;
    cout << result_str;
}