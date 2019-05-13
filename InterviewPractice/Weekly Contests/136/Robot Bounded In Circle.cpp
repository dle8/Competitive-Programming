#define sz(x) int(x.size())
#define fi first
#define se second
#define FOR(i, l, r) for (int i=l; i<=r; i++)

class Solution {
public:
    bool isRobotBounded(string instructions) {
        pair<int, int> cur = {0, 0};
        char direction = 'N';
        instructions += instructions;
        instructions += instructions;
        FOR(i, 0, sz(instructions) - 1) {
            if (instructions[i] == 'G') {
                if (direction == 'N') cur.fi++;
                if (direction == 'S') cur.fi--;
                if (direction == 'W') cur.se--;
                if (direction == 'E') cur.se++;
            }
            else if (instructions[i] == 'L') {
                if (direction == 'N') direction = 'W';
                else if (direction == 'S') direction = 'E';
                else if (direction == 'W') direction = 'S';
                else if (direction == 'E') direction = 'N';
            }
            else if (instructions[i] == 'R') {
                if (direction == 'N') direction = 'E';
                else if (direction == 'S') direction = 'W';
                else if (direction == 'W') direction = 'N';
                else if (direction == 'E') direction = 'S';
            }
        }
        if (cur.fi == 0 && cur.se == 0) return true;
        return false;
    }
};
