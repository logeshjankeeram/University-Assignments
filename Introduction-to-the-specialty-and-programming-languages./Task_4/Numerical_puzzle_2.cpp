#include <iostream>
using namespace std;

int find_numbers_task2()
{
    for (int S = 0; S < 10; ++S)
    {
        for (int E = 0; E < 10; ++E)
        {
            for (int N = 0; N < 10; ++N)
            {
                for (int D = 0; D < 10; ++D)
                {
                    for (int M = 0; M < 10; ++M)
                    {
                        for (int O = 0; O < 10; ++O)
                        {
                            for (int R = 0; R < 10; ++R)
                            {
                                for (int Y = 0; Y < 10; ++Y)
                                {
                                    if (S != E && S != N && S != D && S != M && S != O && S != R && S != Y && E != N && E != D && E != M && E != O && E != R && E != Y &&
                                        N != D && N != M && N != O && N != R && N != Y && D != M && D != O && D != R && D != Y &&

                                        M != O && M != R && M != Y && O != R && O != Y && R != Y)

                                    {
                                        int SEND = S * 1000 + E * 100 + N * 10 + D;
                                        int MORE = M * 1000 + O * 100 + R * 10 + E;
                                        int MONEY = M * 10000 + O * 1000 + N * 100 + E * 10 + Y;

                                        if (SEND + MORE == MONEY)
                                        {
                                            cout << "S: " << S << ", E: " << E << ", N: " << N << ", D: " << D << endl;
                                            cout << "M: " << M << ", O: " << O << ", R: " << R << ", Y: " << Y << endl;
                                            cout << "SEND: " << SEND << ", MORE: " << MORE << ", MONEY: " << MONEY << endl;
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "No solution found." << endl;
    return 0;
}

int main()
{
    find_numbers_task2();
    return 0;
}