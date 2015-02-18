#include <iostream>
#include <vector>
#include <Algorithm>
#include <queue>

using namespace std;

class ACAutomaton
{
public:
	static const int MAX_N = 10000 * 50 + 5;
	static const int CLD_NUM = 26;

	int n;
	int id['z'+1];
	int fail[MAX_N];
	int tag[MAX_N];
	int tire[MAX_N][CLD_NUM];

	void init() 
	{
		for (int i = 0; i < CLD_NUM; i++)
			id['a' + i] = i;
	}

	void reset()
	{
		memset(trie[0], -1, sizeof(trie[0]));
		tag[0] = 0;
		n = 1;
	}

	void add(char *s)
	{
		int p = 0;
		while( *s)
		{
			int i = id[*s];
			if( -1 == tire[p][i])
			{
				memset(trie[n], -1 , sizeof(trie[n]));
				tag[n] = 0;
				trie[p][i] = n++;
			}
			p = tire[p][i];
			s++;
		}
		tag[p]++;
	}

	void construct() 
	{
		queue<int> Q;
		fail[0] = 0;
		for( int i = 0; i < CLD_NUM; i++)
		{
			if( -1 != trie[0][i]) 
			{
				fail[trie[0][i]] = 0;
				Q.push(tire[0][i]);
			}
		}

		while(!Q.empty()) 
		{
			int u = Q.front();
			Q.pop();
			for(int i = 0; i < CLD_NUM; i++ )
			{
				int &v = trie[u][i];
				
			}
		}
	}
}

int main(int argc, char const *argv[])
{	
	return 0;
}