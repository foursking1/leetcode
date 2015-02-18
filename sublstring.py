import unittest

def subconcat (S, L):
    """Substring with Concatenation of All Words.
    http://oj.leetcode.com/problems/substring-with-concatenation-of-all-words/
    """
    ret = []
    len0 = len(L[0])
    lenL = len(L)
    cntL = defaultdict(int)
    for x in L:
        cntL[x] += 1
    for i in xrange(len(S) - lenL * len0 + 1):
        cntLtmp = cntL.copy()
        for j in xrange(lenL):
            s = S[i+j*len0: i+(j+1)*len0]
            if s not in cntLtmp or cntLtmp[s] == 0:
                break
            cntLtmp[s] -= 1
        else:  # i.e., no break
            ret.append(i)
    return ret

class Test (unittest.TestCase):
    """Accepted."""
    def test (self):
        tcases = {
            ('barfoothefoobarman', '["foo", "bar"]'): [0, 9],  # barfoo, foobar
            ('axy01bb01xy', '["01", "xy"]'): [1, 7],  # xy01,01xy
            ('axy01bb01xy', '["0", "1", "x", "y"]'): [1, 7],  # xy01,01xy
            ('axy01bb01xy', '["0"]'): [3, 7],
        }
        for inp, out in tcases.iteritems():
            self.assertListEqual(subconcat(inp[0], eval(inp[1])), out)

if __name__ == '__main__':
    unittest.main()