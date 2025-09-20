#include "richest.h"
#include <bits/stdc++.h>
using namespace std;
static int N, T, S, r, t, s;
static vector<int> W;
vector<int> ask(vector<int> i, vector<int> j) {
    ++t;
    if (t > T)
        throw string("Too many queries");
    if (i.size() != j.size())
        throw string("Invalid query: i and j must have the same size");
    int m = i.size();
    s += m;
    if (s > S)
        throw string("Too many total elements in queries");
    vector<int> res(m);
    for (int k = 0; k < m; k++) {
        if (i[k] < 0 || i[k] >= N || j[k] < 0 || j[k] >= N)
            throw string("Invalid query: index out of bounds");
        res[k] = W[i[k]] > W[j[k]] ? i[k] : j[k];
    }
    return res;
}

constexpr int Sub2_score = 85;

int main() {
    int R;
    cin >> N >> T >> S >> R;
    if (N <= 0 || T < 0 || S < 0 || R < 0) {
        cerr << "Invalid input for N, T, S or R" << endl;
        return 1;
    }
    mt19937_64 rng(R);
    W.resize(N);
    bool hasWrong = false;
    int maxt = 0, maxs = 0;
    for (int _ = 0; _ < 10; _++) {
        iota(W.begin(), W.end(), 0);
        shuffle(W.begin(), W.end(), rng);
        int answer = max_element(W.begin(), W.end()) - W.begin();
        try {
            r = -1; t = 0; s = 0;
            r = richest(N, T, S);
            if (r != answer)
                throw string("Wrong Answer");
            cout << r << ' ' << t << ' ' << s << " Correct (pretest)" << endl;
        } catch (const string& msg) {
            hasWrong = true;
            cout << r << ' ' << t << ' ' << s << ' ' << msg << endl;
        }
        maxt = max(maxt, t);
        maxs = max(maxs, s);
    }
    if (N == 1000 && T == 1 && S == 499500) {
        if (hasWrong) {
            cout << "Wrong Case 1, score: 0 / " << (100 - Sub2_score) << endl;
        } else {
            cout << "Correct (pretest) Case 1, score: " << (100 - Sub2_score) << " / " << (100 - Sub2_score) << endl;
        }
    } else if (N == 1000000 && T == 20 && S == 2000000) {
        if (hasWrong) {
            cout << "Wrong Case 2, score: 0 / " << Sub2_score << endl;
        } else {
            double ft = 1;
            if (maxt > 8)
                ft -= sqrt(maxt - 8) / 4;
            double gs = 1;
            if (maxs > 1099944) {
            	if (maxs < 1100044)
            		gs -= log10(maxs - 1099943) / 6;
            	else
            		gs -= 1.0 / 3 + pow(maxs - 1100043, 1.0 / 2) / 1500;
			}
            cout
                << (ft * gs >= 1 ? "Correct" : "Partially correct")
                << " (pretest) Case 2, score: "
                << to_string(int(Sub2_score * ft * gs))
                << " / " << Sub2_score;
        }
    } else {
        if (hasWrong) {
            cout << "Wrong" << endl;
        } else {
            cout << "Correct" << endl;
        }
    }
}
