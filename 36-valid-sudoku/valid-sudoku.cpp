class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char, int>> mparr(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (!isdigit(board[i][j])) {
                    continue;
                }
                if (mparr[i].find(board[i][j]) == mparr[i].end()) {
                    mparr[i].insert(make_pair(board[i][j], 1));
                } else {
                    mparr[i][board[i][j]]++;
                }
            }
        }
        vector<unordered_map<char, int>> mparr2(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (!isdigit(board[j][i])) {
                    continue;
                }
                if (mparr2[i].find(board[j][i]) == mparr2[i].end()) {
                    mparr2[i].insert(make_pair(board[j][i], 1));
                } else {
                    mparr2[i][board[j][i]]++;
                }
            }
        }
        for (int i = 0; i < mparr.size(); i++) {
            auto it = mparr[i].begin();
            while (it != mparr[i].end()) {
                cout << it->first << " " << it->second;
                cout << endl;
                ++it;
            }
        }
        for (int i = 0; i < mparr.size(); i++) {
            auto it = mparr[i].begin();
            while (it != mparr[i].end()) {
                if (it->second >= 2) {
                    return false;
                }
                ++it;
            }
        }
        for (int i = 0; i < mparr2.size(); i++) {
            auto it = mparr2[i].begin();
            while (it != mparr2[i].end()) {
                if (it->second >= 2) {
                    return false;
                }
                ++it;
            }
        }
        // 3x3 sub matrices
        vector<vector<char>> sub(3, vector<char>(3, 0));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; ++j) {
                sub[i][j] = board[i][j];
            }
        }
        unordered_map<char, int> mp3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; ++j) {
                if (!isdigit(sub[i][j])) {
                    continue;
                }
                if (mp3.find(sub[i][j]) == mp3.end()) {
                    mp3.insert(make_pair(sub[i][j], 1));
                } else {
                    mp3[sub[i][j]]++;
                }
            }
        }
        for (const auto i : mp3) {
            if (i.second >= 2) {
                return false;
            }
        }
        mp3.clear();

        // second
        for (int i = 3; i < 6; i++) {
            for (int j = 0; j < 3; ++j) {
                sub[i-3][j] = board[i][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; ++j) {
                if (!isdigit(sub[i][j])) {
                    continue;
                }
                if (mp3.find(sub[i][j]) == mp3.end()) {
                    mp3.insert(make_pair(sub[i][j], 1));
                } else {
                    mp3[sub[i][j]]++;
                }
            }
        }
        for (const auto i : mp3) {
            if (i.second >= 2) {
                return false;
            }
        }
        mp3.clear();

        // third
        for (int i = 6; i < 9; i++) {
            for (int j = 0; j < 3; ++j) {
                sub[i-6][j] = board[i][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; ++j) {
                if (!isdigit(sub[i][j])) {
                    continue;
                }
                if (mp3.find(sub[i][j]) == mp3.end()) {
                    mp3.insert(make_pair(sub[i][j], 1));
                } else {
                    mp3[sub[i][j]]++;
                }
            }
        }
        for (const auto i : mp3) {
            if (i.second >= 2) {
                return false;
            }
        }
        mp3.clear();

        // fourth
        for (int i = 0; i < 3; i++) {
            for (int j = 3; j < 6; ++j) {
                sub[i][j-3] = board[i][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; ++j) {
                if (!isdigit(sub[i][j])) {
                    continue;
                }
                if (mp3.find(sub[i][j]) == mp3.end()) {
                    mp3.insert(make_pair(sub[i][j], 1));
                } else {
                    mp3[sub[i][j]]++;
                }
            }
        }
        for (const auto i : mp3) {
            if (i.second >= 2) {
                return false;
            }
        }
        mp3.clear();

        // fifth
        for (int i = 0; i < 3; i++) {
            for (int j = 6; j < 9; ++j) {
                sub[i][j-6] = board[i][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; ++j) {
                if (!isdigit(sub[i][j])) {
                    continue;
                }
                if (mp3.find(sub[i][j]) == mp3.end()) {
                    mp3.insert(make_pair(sub[i][j], 1));
                } else {
                    mp3[sub[i][j]]++;
                }
            }
        }
        for (const auto i : mp3) {
            if (i.second >= 2) {
                return false;
            }
        }
        mp3.clear();

        // sixth
        for (int i = 3; i < 6; i++) {
            for (int j = 3; j < 6; ++j) {
                sub[i-3][j-3] = board[i][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; ++j) {
                if (!isdigit(sub[i][j])) {
                    continue;
                }
                if (mp3.find(sub[i][j]) == mp3.end()) {
                    mp3.insert(make_pair(sub[i][j], 1));
                } else {
                    mp3[sub[i][j]]++;
                }
            }
        }
        for (const auto i : mp3) {
            if (i.second >= 2) {
                return false;
            }
        }
        mp3.clear();

        // seventh
        for (int i = 3; i < 6; i++) {
            for (int j = 6; j < 9; ++j) {
                sub[i-3][j-6] = board[i][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; ++j) {
                if (!isdigit(sub[i][j])) {
                    continue;
                }
                if (mp3.find(sub[i][j]) == mp3.end()) {
                    mp3.insert(make_pair(sub[i][j], 1));
                } else {
                    mp3[sub[i][j]]++;
                }
            }
        }
        for (const auto i : mp3) {
            if (i.second >= 2) {
                return false;
            }
        }
        mp3.clear();

        // eigth
        for (int i = 6; i < 9; i++) {
            for (int j = 6; j < 9; ++j) {
                sub[i-6][j-6] = board[i][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; ++j) {
                if (!isdigit(sub[i][j])) {
                    continue;
                }
                if (mp3.find(sub[i][j]) == mp3.end()) {
                    mp3.insert(make_pair(sub[i][j], 1));
                } else {
                    mp3[sub[i][j]]++;
                }
            }
        }
        for (const auto i : mp3) {
            if (i.second >= 2) {
                return false;
            }
        }
        mp3.clear();

        // last
        for (int i = 6; i < 9; i++) {
            for (int j = 3; j < 6; ++j) {
                sub[i-6][j-3] = board[i][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; ++j) {
                if (!isdigit(sub[i][j])) {
                    continue;
                }
                if (mp3.find(sub[i][j]) == mp3.end()) {
                    mp3.insert(make_pair(sub[i][j], 1));
                } else {
                    mp3[sub[i][j]]++;
                }
            }
        }
        for (const auto i : mp3) {
            if (i.second >= 2) {
                return false;
            }
        }
        mp3.clear();
        return true;
    }
};