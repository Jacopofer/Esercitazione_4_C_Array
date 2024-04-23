#pragma once

#include "iostream"

using namespace std;


bool ImportData(const string& inputFilePath, size_t& n, double& S, double*& w, double*& r);

string ArrayToString(const size_t& n, const double* const& v);

double RateOfReturn(const size_t& n, const double* const& w,const double* const& r);

bool ExportResult(const string& outputFilePath, const size_t& n, const double* const& w, const double* const& r,
                  const double& S, const double& rateOfReturn, const double& finalValue);
