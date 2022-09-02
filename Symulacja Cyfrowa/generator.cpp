#include "generator.h"
#include <cmath>

UniformGenerator::UniformGenerator(int kernel) : kernel_(kernel)
{
    // empty
}

UniformGenerator::~UniformGenerator()
{

}

double UniformGenerator::Rand()
{
    int h = kernel_ / kQ;
    kernel_ = kA * (kernel_ - kQ * h) - kR * h;
    if (kernel_ < 0)
        kernel_ = kernel_ + static_cast<int>(kM);
    return kernel_ / kM;
}

double UniformGenerator::Range_rand(double min_value, double max_value)
{
    return (Rand() * (max_value - min_value)) + min_value;
}

double UniformGenerator::Exponential(double intensity)
{
    return -log(Rand()) / intensity;
}