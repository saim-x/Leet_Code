class Solution {
public:
    string intToBinary(int number) {
        string binary = "";
        while (number > 0) {
            binary = to_string(number % 2) + binary;
            number /= 2;
        }
        return binary == "" ? "0" : binary;
    }
    int occurence(string s) { return std::ranges::count(s, '1'); }
    vector<int> countBits(int n) {
        vector<int> a;
        for (int i = 0; i <= n; i++) {
            a.push_back(occurence(intToBinary(i)));
        }
        return a;
    }
};