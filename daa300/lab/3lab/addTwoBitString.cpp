#include<iostream>
#include<string>
using namespace std;

int makeEqual(string &num1, string &num2) {
    int len1 = num1.size();
    int len2 = num2.size();

    int i;

    if(len1 > len2) {
        for(i=0; i<len1- len2; ++i)  {
            num2 = '0' + num2;
        }
        return len1;
    }

    if(len2 > len1) {
        for(i=0; i<len2-len1; ++i) {
            num1 = '0' + num1;
        }
        return len2;
    }

    return len1;
}

string addTwoBitStrings(string num1, string num2) {
    string res = "";
    int len = makeEqual(num1,num2);
    int carry = 0;
    for(int i=len-1; i>=0; --i) {
        int bit1 = num1.at(i) - '0';
        int bit2 = num2.at(i) - '0';
        int sum = bit1 ^ bit2 ^ carry;
        if(sum == 0) {
            res = "0" + res;
        } else res = "1" + res;
        carry= bit1&carry | bit2&carry | bit1&bit2;
    }
    if(carry == 1) {
        res = "1" + res;
    }
    return res;
}

void printTwoNumbers(string &num1, string &num2) {
    cout << "First  number = " << num1 << endl;
    cout << "Second number = " << num2 << endl;
}

int main() {
    string num1 = "1100";
    string num2 = "1111";
    printTwoNumbers(num1,num2);
    cout << addTwoBitStrings(num1,num2);
}


