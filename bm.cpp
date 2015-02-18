#include <iostream>
#include <vector>
#include <Algorithm>

using namespace std;

#define ASIZE 256

//bad character
void preBmBc(char *S, int m, int bmBc[]) {
	for( int i = 0; i < ASIZE; i ++) {
		bmBc[i] = m;
	}

	for(int i = 0; i < m ; i ++ ) {
		bmBc[S[i]] = m - i - 1;
	}
}

int BMsearch(char *buf, int blen, char *ptrn, int plen) {
	int bindex = plen;
	int *bmBc = new int[ASIZE];
	preBmBc(ptrn, plen, bmBc);

	if( plen == 0)
		return 1;

	while( bindex <= blen ) {
		int pindex = plen;
		int shift;

		while( buf[--bindex] == ptrn[--pindex] ){
			cout << "once" << endl;
			if( bindex < 0)
				return 0;

			if( pindex == 0)
			{
				return 1;
			}
		} 
		cout << pindex << endl;
		cout << ptrn[pindex] << endl;
		shift = bmBc[buf[bindex]] + 1;
		bindex += shift;

		cout << "bindex:" << buf[bindex] << endl;
		//break;
	}

	return 0;

}


int main(int argc, char const *argv[])
{	
	char *s = "abcdefghijk";
	char *p = "gai";
	cout << BMsearch(s,11,p,3);
	return 0;
}