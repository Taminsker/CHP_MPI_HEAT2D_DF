#include "operators.h"

double operator| (const std::vector<double> &x, const std::vector<double> &y)
{
  if (x.size () != y.size ())
  {
    return -1.;
  }

  double ps = 0;

  for (int i = 0; i < x.size (); ++i)
  {
    ps += x [i] * y [i];
  }

  return ps;
}


std::vector<double> operator+ (const std::vector<double> &x, const std::vector<double> &y)
{
  if (x.size () != y.size ())
  {
    return std::vector<double> (1, -1.);
  }

  std::vector<double> vec = x;

  for (int i = 0; i < x.size (); ++i)
  {
    vec [i] += y [i];
  }

  return vec;
}


std::vector<double> operator- (const std::vector<double> &x, const std::vector<double> &y)
{
  if (x.size () != y.size ())
  {
    return std::vector<double> (1, -1.);
  }

  std::vector<double> vec = x;

  for (int i = 0; i < x.size (); ++i)
  {
    vec [i] -=  y [i];
  }

  return vec;
}


void operator+= (std::vector<double> &x, const std::vector<double> &y)
{
  if (x.size () != y.size ())
  {
    return;
  }

  for (int i = 0; i < x.size (); ++i)
  {
    x [i] += y [i];
  }
}


void operator-= (std::vector<double> &x, const std::vector<double> &y)
{
  if (x.size () != y.size ())
  {
    return;
  }

  for (int i = 0; i < x.size (); ++i)
  {
    x [i] -= y [i];
  }

  return;
}


std::vector<double> operator* (double k, std::vector<double> x)
{
  for (int i = 0; i < x.size (); ++i)
  {
    x [i] *= k;
  }

  return x;
}


std::vector<double> operator* (std::vector<double> x, double k)
{
  for (int i = 0; i < x.size (); ++i)
  {
    x [i] *= k;
  }

  return x;
}

void print (std::vector<double> a)
{
  for (int i = 0; i < a.size(); i++)
  {
    printf("%f, ", a [i]);
  }
  printf("\n");
}
