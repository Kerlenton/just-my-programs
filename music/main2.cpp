#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(void)
{
    float k = pow(2.0f, 1.0f / 12.0f);
    vector<pair<int, int> > melody;
	
    enum N { A0 = 0, As0, B0, C, Cs, D, Ds, E, F, Fs, G, Gs, A, As, B, C2, Cs2, D2, Ds2, E2, F2, Fs2, G2, Gs2, A2, As2, B2, C3, Cs3, D3, Ds3, E3, F3, Fs3, G3, Gs3, A3 };
    enum T { T16 = 1, T8 = 2, T4 = 4, T2 = 8, T1 = 16 };
	
    melody.push_back(make_pair(A, T8));
    melody.push_back(make_pair(A2, T8));
    melody.push_back(make_pair(A, T8));
    melody.push_back(make_pair(A2, T8));
    melody.push_back(make_pair(F, T8));
    melody.push_back(make_pair(F2, T8));
    melody.push_back(make_pair(F, T8));
    melody.push_back(make_pair(F2, T8));
    melody.push_back(make_pair(C2, T8));
    melody.push_back(make_pair(C3, T8));
    melody.push_back(make_pair(C2, T8));
    melody.push_back(make_pair(C3, T8));
    melody.push_back(make_pair(E, T8));
    melody.push_back(make_pair(E2, T8));
    melody.push_back(make_pair(E, T8));

    for (pair<int, int> n : melody)
    {
            int freq = 440.0f * pow(k, n.first);
            for (int i = 0; i < n.second * 44100 * 60 / 100 / 4; i++)
            {
                    int16_t a = i % (44100 / freq) > (44100 / freq / 2) ? 1000 : -1000;
                    cout.write((const char*)&a, sizeof(a));
            }

    }

    int freq1 = 440.0f * pow(k, E2);
    int freq2 = 440.0f * pow(k, B2);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, C3);
	freq2 = 440.0f * pow(k, A);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }


    freq1 = 440.0f * pow(k, C3);
	freq2 = 440.0f * pow(k, A2);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, C3);
	freq2 = 440.0f * pow(k, A);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, A3);
	freq2 = 440.0f * pow(k, A2);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, F);
	freq2 = 440.0f * pow(k, A3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, F2);
	freq2 = 440.0f * pow(k, A3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, F);
	freq2 = 440.0f * pow(k, A3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, F2);
	freq2 = 440.0f * pow(k, A3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, G3);
	freq2 = 440.0f * pow(k, C2);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }


    freq1 = 440.0f * pow(k, C3);
	freq2 = 440.0f * pow(k, F3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, C2);
	freq2 = 440.0f * pow(k, E3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }


    freq1 = 440.0f * pow(k, C3);
	freq2 = 440.0f * pow(k, D3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, E3);
	freq2 = 440.0f * pow(k, E);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, E3);
	freq2 = 440.0f * pow(k, E2);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, E3);
	freq2 = 440.0f * pow(k, E);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, E3);
	freq2 = 440.0f * pow(k, E2);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, A);
	freq2 = 440.0f * pow(k, C3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, A2);
	freq2 = 440.0f * pow(k, C3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, A);
	freq2 = 440.0f * pow(k, C3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, A2);
	freq2 = 440.0f * pow(k, C3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, F);
	freq2 = 440.0f * pow(k, A3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, F2);
	freq2 = 440.0f * pow(k, A3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, F);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, F2);
	freq2 = 440.0f * pow(k, A3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, C2);
	freq2 = 440.0f * pow(k, G3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }


    freq1 = 440.0f * pow(k, C3);
	freq2 = 440.0f * pow(k, G3);

    for (int i = 0; i < 1 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, C3);
	freq2 = 440.0f * pow(k, F3);

    for (int i = 0; i < 1 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, C2);
	freq2 = 440.0f * pow(k, E3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, C3);
	freq2 = 440.0f * pow(k, D3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }



    freq1 = 440.0f * pow(k, E);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        cout.write((const char *)&a1, sizeof(a1));
    }


    freq1 = 440.0f * pow(k, E2);
	freq2 = 440.0f * pow(k, E3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, E);
	freq2 = 440.0f * pow(k, E3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, E2);
	freq2 = 440.0f * pow(k, D3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, A);
	freq2 = 440.0f * pow(k, C3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, A2);
	freq2 = 440.0f * pow(k, C3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, A);
	freq2 = 440.0f * pow(k, C3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, A2);
	freq2 = 440.0f * pow(k, A3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, F);
	freq2 = 440.0f * pow(k, A3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, F2);
	freq2 = 440.0f * pow(k, A3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, F);
	freq2 = 440.0f * pow(k, A3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, F2);
	freq2 = 440.0f * pow(k, G3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, C2);
	freq2 = 440.0f * pow(k, G3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, C3);
	freq2 = 440.0f * pow(k, F3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, C2);
	freq2 = 440.0f * pow(k, E3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }

    freq1 = 440.0f * pow(k, C3);
	freq2 = 440.0f * pow(k, D3);

    for (int i = 0; i < 2 * 44100 * 60 / 100 / 4; i++)
    {

        int16_t a1 = i % (44100 / freq1) > (44100 / freq1 / 2) ? 1000 : -1000;
        int16_t a2 = i % (44100 / freq2) > (44100 / freq2 / 2) ? 1000 : -1000;
        a1 += a2;
        cout.write((const char *)&a1, sizeof(a1));
    }



	return 0;
}
