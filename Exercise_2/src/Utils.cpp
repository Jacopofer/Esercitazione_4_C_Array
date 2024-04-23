#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "string"
#include "iomanip"

using namespace std;

bool ImportData(const string& inputFilePath, size_t& n, double& S, double*& w, double*& r)
{
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr << "Apertura del file fallita" << endl;
        return false;
    }

    string line;

    // S
    getline(file, line);
    line.erase(0,2);

    istringstream convertS;
    convertS.str(line);
    convertS >> S;

    // n = lunghezza degli array w e r
    getline(file, line);
    line.erase(0,2);

    istringstream convertn;
    convertn.str(line);
    convertn >> n;

    getline(file, line);

    istringstream convertw;
    istringstream convertr;
    w = new double[n];
    r = new double[n];

    unsigned int i = 0;

    while (!file.eof())
    {
        getline(file,line);
        size_t posSeparatore = line.find(';');
        string splitLine_w = line.substr(0, posSeparatore);
        string splitLine_r = line.substr(posSeparatore+1);

        convertw.str(splitLine_w);
        convertr.str(splitLine_r);

        convertw >> w[i];
        convertr >> r[i];

        i++;
        convertw.clear();
        convertr.clear();
    }

    file.close();

    return true;
}



string ArrayToString(const size_t& n, const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}


double RateOfReturn(const size_t& n, const double* const& w,const double* const& r)
{
    double rateOfReturn = 0;
    for (unsigned int i=0; i < n; i++)
        rateOfReturn += w[i] * r[i];

    return rateOfReturn;
}


bool ExportResult(const string& outputFilePath, const size_t& n, const double* const& w, const double* const& r,
                  const double& S, const double& rateOfReturn, const double& finalValue)
{
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr << "Apertura del file fallita" << endl;
        return false;
    }

    file << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    file << "w = " << ArrayToString(n,w) << endl;
    file << "r = " << ArrayToString(n,r) << endl;
    file << "Rate of return of the portfolio: " << setprecision(4) << rateOfReturn << endl;
    file << "V: " << fixed << setprecision(2) << finalValue << endl;

    file.close();
    return true;
}
