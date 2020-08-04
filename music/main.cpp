#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(void)
{
	float k = pow(2.0f, 1.0f / 12.0f);
	vector<pair<int, int> > melody;
	enum N { A0 = 0, As0, B0, C, Cs, D, Ds, E, F, Fs, G, Gs, A, As, B, C2, Cs2, D2, Ds2, E2, F2, Fs2, G2, Gs2, A2, As2, B2, C3 };
	enum T { T16 = 1, T8 = 2, T4 = 4, T2 = 8, T1 = 16 };
	melody.push_back(make_pair(C, T4));
	melody.push_back(make_pair(D, T4));
	melody.push_back(make_pair(E, T4));
	melody.push_back(make_pair(F, T4));
	melody.push_back(make_pair(G, T4));
	melody.push_back(make_pair(A, T4));
	melody.push_back(make_pair(B, T4));
	melody.push_back(make_pair(C2, T4));

	for (pair<int, int> n : melody)
	{
		int freq = 440.0f * pow(k, n.first);
		for (int i = 0; i < n.second * 44100 * 60 / 100 / 4; i++)
		{
			int16_t a = i % (44100 / freq) > (44100 / freq / 2) ? 32000 : -32000;
			cout.write((const char*)&a, sizeof(a));
		}

	}

	return 0;
}
