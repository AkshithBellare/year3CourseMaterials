#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Result {
    public:
        int i_ind;
        int j_ind;
        int max_sum;

        Result(int i, int j, int s): i_ind{i}, j_ind{j}, max_sum{s} {}
        Result() {}
};

Result max(Result A, Result B) {
    if(A.max_sum > B.max_sum) {
        return A;
    }
    return B;
}

Result max(Result A, Result B, Result C) {
    return max(max(A,B), C);
}

Result maximumSubarrayNaive(vector<int> inp) {
    Result result = Result();
    int n = static_cast<int> (inp.size());
    result.i_ind = 0;
    result.j_ind = 0; 
    result.max_sum = INT_MIN;
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += inp[j];
            if(sum > result.max_sum) {
                result.max_sum = sum;
                result.i_ind = i;
                result.j_ind = j;
            }
        }
    }
    return result;
}

void printResult(Result result) {
    cout << "The maximum sum is = " << result.max_sum << endl;
    cout << "starting index = " << result.i_ind << endl;
    cout << "ending index = " << result.j_ind << endl;
}

Result maximumSubarrayCrossing(vector<int> inp, int l, int m, int r) {
    Result l_result = Result();
        l_result.i_ind = m;
        l_result.j_ind = m;
        l_result.max_sum = INT_MIN;

    Result r_result = Result();
        r_result.i_ind = m;
        r_result.j_ind = m;
        r_result.max_sum = INT_MIN;

    Result lr_result = Result();

    int sum = 0;
    for(int i=m; i>=l; i--) {
        sum += inp[i];
        if (sum > l_result.max_sum) {
            l_result.max_sum = sum;
            l_result.i_ind = i;
        }
    }

    sum = 0;
    for(int i=m+1; i<=r; i++) {
        sum += inp[i];
        if (sum > r_result.max_sum) {
            r_result.max_sum = sum;
            r_result.j_ind = i;
        }
    }

    lr_result.max_sum = l_result.max_sum + r_result.max_sum;
    lr_result.i_ind = l_result.i_ind;
    lr_result.j_ind = r_result.j_ind;

    return max(l_result, r_result, lr_result);
}

Result maximumSubarrayDC(vector<int> inp, int l, int r) {
    Result result = Result();
    if(l == r) {
        result.i_ind = l;
        result.j_ind = r;
        result.max_sum = inp[l];
        return result;
    }
    int m = (l+r)/2;

    return max(maximumSubarrayDC(inp,l,m), maximumSubarrayDC(inp,m+1,r), maximumSubarrayCrossing(inp,l,m,r));
}

int main() {
   vector<int> inp{10, 2, 3, -2, 20, -10};
   int n = static_cast<int> (inp.size());

   Result result = maximumSubarrayNaive(inp);
   printResult(result);

   result = maximumSubarrayDC(inp,0,n-1);
   printResult(result);
}
