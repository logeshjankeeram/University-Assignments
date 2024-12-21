#include <iostream>
using namespace std;

int find_numbers_task1()
{
    for (int O = 0; O < 10; ++O)
    {
        for (int A = 0; A < 10; ++A)
        {
            for (int H = 0; H < 10; ++H)
            {
                int OHOHO = O * 10000 + H * 1000 + O * 100 + H * 10 + O;
                int AHAHA = A * 10000 + H * 1000 + A * 100 + H * 10 + A;
                int AHAHAH = A * 100000 + H * 10000 + A * 1000 + H * 100 + A * 10 + H;

                if (OHOHO + AHAHA == AHAHAH)
                {
                    cout << "O: " << O << ", A: " << A << ", H: " << H << endl;
                    cout << "OHOHO: " << OHOHO << ", AHAHA: " << AHAHA << ", AHAHAH: " << AHAHAH << endl;
                    return 1;
                }
            }
        }
    }
    return 0;
}