// You are given a string s of lowercase English letters and an integer array shifts of the same length.
// Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').
// For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
// Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.
// Return the final string after all such shifts to s are applied.
 
//  s = "abc", shifts = [3,5,9] rpl

#include <iostream> 
#include <vector>
#include <string> 

using namespace std; 

string shiftLetters(string s, vector<int>& shifts){
    int n = s.length();
    int cumlativeShift = 0;

    for (int i = n - 1; i >= 0; i--) { 
        cumlativeShift = (cumlativeShift + shifts[i]) % 26;
        cout << cumlativeShift << endl;
       s[i] = (s[i] - 'a' + cumlativeShift) % 26 + 'a';
    }


    // for (int i = 0; i < s.length(); i++) {
    //     s[i] = s[i] - 'a' + shifts[i] % 26 + 'a';
    // }
    return s;
}

int main() { 
    string s = "abc";
    vector<int> shifts = {3, 5, 9};

    string result = move(shiftLetters(s, shifts));
    cout << "Shifted string " << result << endl;

    return 0;
}