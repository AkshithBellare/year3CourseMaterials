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

string onesComplement(string num) {
    int len = num.size();
    string res = "";
    for(int i=0; i<len; ++i) {
        if(num.at(i) == '0') {
            res = res +  "1";
        } else res = res + "0";
    }
    return res;
}

string twoComplement(string num) {
   string onesComp = onesComplement(num);
   string res = addTwoBitStrings(onesComp, "1");
   return res;
}

string subtractTwoStrings(string num1, string num2) {
    string res;
    string twosNum2 = twoComplement(num2);
    cout << "twos complement of num2: " << twosNum2 << endl;
    int len = makeEqual(num1, twosNum2); 
    cout << "len = " << len << endl;
    int carry = 0;
    for(int i=len-1; i>=0; i--) {
        int bit1 = num1.at(i) - '0';
        int bit2 = twosNum2.at(i) - '0';
        int sum = bit1 ^ bit2 ^ carry; 

        cout << "bit1: " << bit1 << endl;
        cout << "bit2:" << bit2 << endl;
        cout << "sum: " << sum << endl;

        if(sum == 0) {
            res = "0" + res;
        } else res = "1" + res;

        carry = bit1&bit2 | bit2&carry | bit1&carry;
        cout << "carry: " << carry << endl;
        cout << "res: " << res << endl << endl;
    }
    cout << "result till now: " << res << endl;
    cout << "carry is : " << carry << endl;

    if(carry == 1) {
        return res;
    } else {
        res = "-" + addTwoBitStrings(onesComplement(res),"1");
    }
    return res;
}

int main() {
    cout << subtractTwoStrings("1001", "1010") << endl;
    return 0;
}