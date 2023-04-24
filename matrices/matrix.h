#pragma once
#include <iostream>
#include <vector>
#include <cassert>

void print_matrix(const std::vector<double> & M, int nrows, int ncols);
// computes C = AB

void matmul_naive(const std::vector<double> & A,
                  const std::vector<double> & B,
                  const int nrows, const int ncols,
                  std::vector<double> & C);

double compute_trace(const std::vector<double> & A,
                     const int nrows, const int ncols);

void fill_hilbert(std::vector<double> &A, const int ncols);