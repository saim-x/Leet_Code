class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<int> gr;
        int a, b;
        int used = 0;
        a = arrays[0][0];
        for (int i = 1; i < arrays.size(); i++) {
            if (arrays[i][0] < a) {
                a = arrays[i][0];
                used = i;
            }
        }
        cout << used;
        for (int i = 0; i < arrays.size(); i++) {
            if (i != used) {
                b = arrays[i][arrays[i].size() - 1];
                break;
            }
        }

        for (int i = 1; i < arrays.size(); i++) {
            if (arrays[i][arrays[i].size() - 1] > b && i != used) {
                b = arrays[i][arrays[i].size() - 1];
            }
        }

        cout << "a: " << a;
        cout << "b: " << b;

        gr.push_back(abs(a - b));

        used = 0;
        b = arrays[0].back();
        for (int i = 1; i < arrays.size(); i++) {
            if (arrays[i].back() > b) {
                b = arrays[i].back();
                used = i;
            }
        }
        cout << used;
        for (int i = 0; i < arrays.size(); i++) {
            if (i != used) {
                a = arrays[i][0];
                break;
            }
        }

        for (int i = 1; i < arrays.size(); i++) {
            if (arrays[i][0] < a && i != used) {
                a = arrays[i][0];
            }
        }

        cout << "a: " << a;
        cout << "b: " << b;
        gr.push_back(abs(a-b));


        sort(gr.begin(), gr.end());
        return gr.back();

    }
};