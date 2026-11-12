#pragma once

struct vec3{
  double m_x; // Forwards
  double m_y; // Left
  double m_z; // Up

  vec3(double x, double y, double z)
    : m_x(x), m_y(y), m_z(z) {}
  
  bool operator==(const vec3 &b) const; // equal check for 2 vectors
  double operator[](const size_t idx) const;

  vec3 operator+(const vec3 &b) const; // adding 2 vectors 
  vec3 operator-(const vec3 &b) const; // subtracting 2 vectors
  vec3 operator*(const double &k) const;

  vec3& operator-(); // negation of vector

  // return *this
  vec3& operator+=(const vec3 &b); // adding one vec to another
  vec3& operator-=(const vec3 &b); // subtracting one vec to another
  
  vec3& operator*=(const double &k); // scalar multiplication
  vec3& operator/=(const double &k); // scalar divison

  double length() const;
  vec3 normalize() const;
};

std::ostream& operator<<(std::ostream& os, const vec3& v);