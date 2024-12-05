class Solution {
public:
    bool canChange(string start, string target) {

        int sl = start.length();
        int tl = target.length();

        int sp = 0;
        int tp = 0;

        while (sp < sl && tp < tl) {
            if (start[sp] == '_')
                sp++;
            else if (target[tp] == '_')
                tp++;
            else if ((start[sp] == 'L' && target[tp] == 'R') || 
                     (start[sp] == 'R' && target[tp] == 'L'))
                return false;
            else if (start[sp] == 'L' && target[tp] == 'L') {
                if (tp > sp) return false;

                sp++;
                tp++;
            } else if (start[sp] == 'R' && target[tp] == 'R') {
                if (tp < sp) return false;

                sp++;
                tp++;
            }
        }

        while (sp < sl) {
            if (start[sp] != '_') return false;
            sp++;
        }
        while (tp < tl) {
            if (target[tp] != '_') return false;
            tp++;
        }
        return true;
    }
};