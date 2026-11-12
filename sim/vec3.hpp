#pragma once

struct vec3{
  double m_x; // Forwards
  double m_y; // Left
  double m_z; // Up

  vec3(double x, double y, double z)
    : m_x(x), m_y(y), m_z(z) {}
  
  // return new Object vec3
  vec3 operator+(const vec3 &b) const; // adding 2 vectors 
  vec3 operator-(const vec3 &b) const; // subtracting 2 vectors
  
  // return *this
  vec3& operator+=(const vec3 &b); // adding 2 vectors
  vec3& operator-=(const vec3 &b); // subtracting 2 vectors
  
  vec3 operator/=(const vec3 &b) const; // pairwise vector element divison
  vec3 operator*=(const double &k) const; // scalar multiplication
  bool operator==(const vec3 &b) const; // equal check for 2 vectors
  double operator[](const size_t idx) const;

  double length() const;
  vec3 normalize() const;
};

std::ostream& operator<<(std::ostream& os, const vec3& v);