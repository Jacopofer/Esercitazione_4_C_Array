#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

int main()
{
    double* w = nullptr;
    double* r = nullptr;
    string inputFileName = "./data.csv";
    size_t n = 0;
    double S = 0;

    if (!ImportData(inputFileName, n, S, w, r))
    {
        cerr<< "Errore nell'importazione dei dati"<< endl;
        return -1;
    }
    else {
        cout << "Importazione dei dati andata a buon fine" << endl;
        cout << "S = "<< fixed << setprecision(2) << S << ", n = " << n << ", w = " << ArrayToString(n,w) << ", r = " << ArrayToString(n,r)<<endl;
    }

    double rateOfReturn = RateOfReturn(n,w,r);
    double V = (1 + rateOfReturn)*S;

    cout << "Rate of return of the portfolio: " << setprecision(4) << rateOfReturn << endl;
    cout << "Final value of the portfolio: " << fixed << setprecision(2) << V << endl;

    string outputFileName = "./result.txt";
    if (!ExportResult(outputFileName, n, w, r, S, rateOfReturn, V))
    {
        cerr<< "Errore nell'esportazione dei dati"<< endl;
        return -1;
    }
    else
        cout<< "Esportazione dei dati andata a buon fine"<< endl;

    delete[] w;
    delete[] r;

    return 0;
}

