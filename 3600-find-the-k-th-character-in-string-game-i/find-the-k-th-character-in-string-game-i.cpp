class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        for (int i = 0; word.length() < k; i++) {
            string temp = "";
            for (char c : word) {
                char ch = (c + 1);
                temp += ch;
                cout << ch;
            }
            word+= temp;
        }
        cout << endl << word;
        return word[k - 1];
    }
};