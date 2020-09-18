#include<bits/stdc++.h>
using namespace std;

int makeEqualLength(string &s1, string &s2) {
   int len1 = s1.size(); 
   int len2 = s2.size();
   if(len1 < len2) {
       for(int i=0; i<len2-len1; i++) {
          s1 = '0' + s1;
       }
       return len2;
   }
   else if(len1 > len2) {
       for(int i=0; i<len1-len2; i++) {
           s2 = '0' + s2;
       }
       return len1;
   }
   return len1;
}

string onesComplement(string num) {
    string result = "";
    int n = num.size();
    for(int i=0; i<n; i++) {
        if(num[i] == '0') {
            result += '1' ;
        }
        else {
            result += '0';
        }
    }
    return result;
}

string addBitStrings(string first, string second) {
   string result; 

   int length = makeEqualLength(first, second);
   int carry = 0;

   for(int i = length - 1; i>=0; i--) {
       int firstBit = first.at(i) - '0';
       int secondBit = second.at(i) - '0';

       int sum = (firstBit ^ secondBit ^ carry)  + '0'; //adding '0' to get the ascii value of sum

       result = (char)sum + result;

       carry = (firstBit&secondBit) | (secondBit&carry) | (firstBit&carry);
   }

   if(carry) result = '1' + result;

   return result;
}

string twosComplement(string num) {
   string onesComp = onesComplement(num);
   string res = addBitStrings(onesComp, "1");
   return res;
}

string subtractBitStrings(string num1, string num2) {
    string res;
    if(num1 == "0" && num2 == "0") {
        return "0";
    }
    if(num1 == "1" && num2 == "0") {
        return "0";
   } else if(num2 =="1" && num1=="0") {
       return "0";
   }
    string twosNum2 = twosComplement(num2);
    int len = makeEqualLength(num1, twosNum2); 
    int carry = 0;
    for(int i=len-1; i>=0; i--) {
        int bit1 = num1.at(i) - '0';
        int bit2 = twosNum2.at(i) - '0';
        int sum = bit1 ^ bit2 ^ carry; 

        if(sum == 0) {
            res = "0" + res;
        } else res = "1" + res;

        carry = bit1&bit2 | bit2&carry | bit1&carry;
    }
    if(carry == 1) {
        return res;
    } else {
        res = "-" + addBitStrings(onesComplement(res),"1");
    }
    return res; 
}


string makeshift(string num, int step) {
    for(int i=0; i<step; i++) {
        num = num + '0';
    }
    return num;
}

string multiplySingleBit(string a, string b) {
    return ((a[0] - '0')*(b[0] - '0') == 0)? "0":"1";
}

string multiply(string x, string y) {
    int len = makeEqualLength(x, y);

    if(len == 0) {
        return 0;
    }
    if(len == 1) return multiplySingleBit(x, y);

    int first_half = len / 2;
    int second_half = len - first_half;

    string xl = x.substr(0,first_half);
    string xr = x.substr(first_half,second_half);

    string yl = y.substr(0, first_half);
    string yr = y.substr(first_half, second_half);

    string p1 = multiply(xl,yl);
    string p2 = multiply(xr,yr);
    string p3 = multiply(addBitStrings(xl, xr), addBitStrings(yl, yr));

    string comp1 = makeshift(p1, 2*second_half);
    string comp2 = makeshift(subtractBitStrings(p3,addBitStrings(p1,p2)), second_half);
    string comp3 = p2;

    return addBitStrings(comp1,addBitStrings(comp1,comp2));
}

int main() {
    string num1 = "1100";
    string num2 = "1010";
    cout << multiply("10", "01") << endl;
    cout << subtractBitStrings("1","1") << endl;
}