class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;
        unordered_map<char, int> mp;
        for (auto i : s1) {
            if (mp.find(i) == mp.end()) {
                mp.insert(make_pair(i, 1));
            } else {

                mp[i]++;
            }
        }
        unordered_map<char, int> mp2;
        for (auto i : s2) {
            if (mp2.find(i) == mp2.end()) {
                mp2.insert(make_pair(i, 1));
            } else {

                mp2[i]++;
            }
        }
        for (auto& it : mp) {
            cout << it.first << ' ' << it.second << '\n';
        }
        for (auto& it : mp2) {
            cout << it.first << ' ' << it.second << '\n';
        }
        if (mp.size() != mp2.size()) {
            return false;
        }
        for (auto& [key, value] : mp) {
            auto it = mp2.find(key);
            if (it == mp2.end() || value != it->second) {
                return false;
            }
        }
        // vector<pair<char, int>> vec1(mp.begin(), mp.end());
        // vector<pair<char, int>> vec2(mp2.begin(), mp2.end());
        // int c = 0;
        // for (auto i = 0; i < vec1.size(); ++i) {
        //     if (vec1[i].first != vec2[i].first) {

        //         if (c >= 2) {

        //             cout << vec1[i].first << "    " << vec2[i].first;
        //             return false;
        //         }
        //         c++;
        //     }
        // }
        bool f = false;
        for (int i = 0; i < s1.size(); ++i) {
            // cout << "\nString is now " << s1 << "-" << s2;

            if (s1[i] != s2[i] && !f) {
                cout << "Swapping " << s1[i] << " and " << s2[i];
                // swap(s2[i], s2[s2.find(s1[i])]);
                auto it = mp2.find(s1[i]);
                cout << "\nYE " << it->first;
                string t1 = s2;
                vector<int> done;
                for (int j = 0; j < it->second; ++j) {
                    int index = t1.find(s1[i]);
                    auto it = find(done.begin(), done.end(), index);
                    string t2= t1;
                    while (it != done.end()) {
                        t2[index]=' ';
                        index = t2.find(s1[i]);
                        it = find(done.begin(), done.end(), index);
                    }
                    cout << "\n\nSwapping this time: " << t1[i] << " "
                         << t1[index] << " second idex is " << index;
                    swap(t1[i], t1[index]);

                    if (t1 == s1)
                        return true;
                    swap(t1[i], t1[index]);
                    done.push_back(index);
                }
                cout << "\nString is now " << s1 << "-" << s2;
                f = true;
            }
            if (s1[i] != s2[i] && f) {
                return false;
            }
        }
        return true;
    }
};