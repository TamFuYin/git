#include "testlib.h"
#include <bits/stdc++.h>
#include <cstring>

#define ull unsigned long long
void readOthers(InStream &s) { while (!s.seekEof()) s.readToken(); }
const int N(5035), M(N * N);
const ull B(19260817);
struct edge { int x, y; };
int n, K, type;

int main(int argc, char* argv[])
{
	registerTestlibCmd(argc, argv);
	int n=inf.readInt(),q=inf.readInt();
	while(q--){
		double T1=ouf.readReal(),T2=ans.readReal();
		if(fabs(T2-T1)<=1e-5||fabs((T2-T1)/T2)<=1e-5);
		else quitf(_wa, "Wrong Answer!");
	}
	quitf(_ok, "Accepted!");
	return 0;
}
