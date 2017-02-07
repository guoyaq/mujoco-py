#ifndef DERIVATIVE_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define DERIVATIVE_H

#include "mujoco.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#ifdef __cplusplus
extern "C" void worker(const mjModel* m, const mjData* dmain, mjData* d, int id);
extern "C" double relnorm(mjtNum* residual, mjtNum* base, int n);
extern "C" void checkderiv(const mjModel* m, mjData* d, mjtNum error[7]);
extern "C" void cmptJac(mjtNum* ptr, mjtNum* accu_ptr, mjModel* m, mjData* dold);
#else
void worker(const mjModel* m, const mjData* dmain, mjData* d, int id);
double relnorm(mjtNum* residual, mjtNum* base, int n);
void checkderiv(const mjModel* m, mjData* d, mjtNum error[7]);
void cmptJac(mjtNum* ptr, mjtNum* accu_ptr, mjModel* m, mjData* dold);
#endif
#endif
