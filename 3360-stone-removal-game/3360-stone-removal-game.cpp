class Solution {
public:
    bool canAliceWin(int n) {
        int remove = 10;
        bool turn = true;

        while (n >= remove) {
            n -= remove;
            remove--;
            turn = !turn;
        }

        return !turn;
    }
};