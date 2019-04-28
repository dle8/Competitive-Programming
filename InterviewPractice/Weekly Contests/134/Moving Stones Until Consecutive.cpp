int min(int a, int b) {
    return (a <= b) ? a : b;
}

int max(int a, int b) {
    return (a >= b) ? a : b;
}

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> res;
        res.push_back(a);
        res.push_back(b);
        res.push_back(c);
        sort(res.begin(), res.end());
        a = res[0]; b = res[1]; c = res[2];
        res.clear();
        // cout << a << " " << b << " " << c << '\n';
        if ((a + 1 == b) && (c - 1 == b)) {
            res.push_back(0);
            res.push_back(0);
        }
        else {
            if (a + 2 == b || b + 2 == c) {
                res.push_back(1);
            }
            else {
                res.push_back(
                    ((a == (b - 1)) ? 0 : 1) + ((c == (b + 1)) ? 0 : 1)
                );
            }
            res.push_back(
                (b - 1 - a) + (c - 1 - b)
            );
        }
        return res;
    }
};
