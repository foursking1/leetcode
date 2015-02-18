#include <iostream>
#include <vector>
#include <Algorithm>
#include <string>
#include <set>

using namespace std;


class Solution {
public:
    bool isMatch2(const char *s, const char *p) {
        int i, j;
        int m = strlen(s);
        int n = strlen(p);

        /**
         * b[i + 1][j + 1]: if s[0..i] matches p[0..j]
         * if p[j] != '*'
         * b[i + 1][j + 1] = b[i][j] && s[i] == p[j]
         * if p[j] == '*', denote p[j - 1] with x,
         * then b[i + 1][j + 1] is true iff any of the following is true
         * 1) "x*" repeats 0 time and matches empty: b[i + 1][j -1]
         * 2) "x*" repeats 1 time and matches x: b[i + 1][j]
         * 3) "x*" repeats >= 2 times and matches "x*x": s[i] == x && b[i][j + 1]
         * '.' matches any single character
         */
        bool b[m + 1][n + 1];
        b[0][0] = true;
        for (i = 0; i < m; i++) {
            b[i + 1][0] = false;
        }
        // p[0..j - 2, j - 1, j] matches empty iff p[j] is '*' and p[0..j - 2] matches empty
        for (j = 0; j < n; j++) {
            b[0][j + 1] = j > 0 && '*' == p[j] && b[0][j - 1];
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (p[j] != '*') {
                    b[i + 1][j + 1] = b[i][j] && ('.' == p[j] || s[i] == p[j]);
                } else {
                    b[i + 1][j + 1] = b[i + 1][j - 1] && j > 0 || b[i + 1][j] ||
                                b[i][j + 1] && j > 0 && ('.' == p[j - 1] || s[i] == p[j - 1]);
                }
            }
        }
        return b[m][n];
    }
    bool isMatch(const char *s, const char *p) {
        struct State {
            bool accept_[256];
            State* out_, *out1_;
            State() : out_(NULL), out1_(NULL) {
                for(int i = 0; i < 256; ++i) {
                    accept_[i] = false;
                }
            }

            void setAccept(int c) {
                if(c != '.') {
                    accept_[c] = true;
                } else {
                    for(int i = 0; i < 255; ++i) {
                        accept_[i] = true;
                    }
                }
            }

            void setEnd() {
                accept_[255] = true;
            }

            bool isEnd() {
                State* s = this;
                do {
                    if(s->accept_[255]) {
                        return true;
                    }
                    s = s->out1_;
                } while(s != NULL);
                return false;
            }

            void transfer(const char c, set<State*>& t) {
                State* s = this;
                do {
                    if(s->accept_[c]) {
                        t.insert(s->out_);
                    }
                    s = s->out1_;
                } while(s != NULL);
            }
        };

        struct Automata {
            Automata(const char* p) : s_(NULL) {
                State** ps = &s_, *lastState = s_;
                for(; *p; ++p) {
                    if('*' == *p) {
                        lastState->out_ = lastState;
                        ps = &(lastState->out1_);
                    } else {
                        *ps = new State;
                        State* t = *ps;
                        t->setAccept(*p);
                        lastState = *ps;
                        ps = &(t->out_);
                    }
                }
                *ps = new State;
                (*ps)->setEnd();
            }

            bool isMatch(const char* s) {
                set<State*> current, next;
                if(s_) {
                    next.insert(s_);
                }
                for(; *s; ++s) {
                    current = next;
                    next.clear();
                    for(set<State*>::iterator it = current.begin(); it != current.end(); ++it) {
                        (*it)->transfer(*s, next);
                    }
                }
                for(set<State*>::iterator it = next.begin(); it != next.end(); ++it) {
                    State* t = *it;
                    if(t->isEnd()) {
                        return true;
                    }
                }
                return false;

            }

            State* s_;
        };

        Automata a(p);
        return a.isMatch(s);
    }
};



int main(int argc, char const *argv[])
{	
	const char *s = "a";
	const char *reg = "d*";
	Solution *sol = new Solution();
	cout << sol->isMatch2(s,reg);

	return 0;
}