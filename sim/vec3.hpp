#pragma once

struct vec3{
  double m_x; // Forwards
  double m_y; // Left
  double m_z; // Up

  constexpr vec3(double x, double y, double z)
    : m_x(x), m_y(y), m_z(z) {}
  
  constexpr bool operator==(const vec3 &b) const        // equal check for 2 vectors
    { return (m_x == b.m_x && m_y == b.m_y && m_z == b.m_z); }
  double operator[](const size_t idx) const;  // index for vec's elements

  constexpr vec3 operator+(const vec3 &b) const         // adding 2 vectors
    { return vec3(m_x + b.m_x, m_y + b.m_y, m_z + b.m_z); }
  constexpr vec3 operator-(const vec3 &b) const         // subtracting 2 vectors
    { return vec3(m_x - b.m_x, m_y - b.m_y, m_z - b.m_z); }
  
  vec3 operator*(const double &k) const;      // scalar multiplication => vec * k
  vec3 operator/(const double &k) const;      // scalar divison
  vec3 operator-() const;                     // negation of vector

  // return *this
  vec3& operator+=(const vec3 &b);            // adding one vec to another
  vec3& operator-=(const vec3 &b);            // subtracting one vec to another
  
  vec3& operator*=(const double &k);          // scalar multiplication
  vec3& operator/=(const double &k);          // scalar divison

  double length() const;                      // length of the vec
  constexpr double lengthSquared() const      // length of the vec, squared
    { return (m_x*m_x + m_y*m_y + m_z*m_z); }
  vec3 normalize() const;                     // normalize the vec
};

std::ostream& operator<<(std::ostream& os, const vec3& v);  // clear output
vec3 operator*(const double k, const vec3& v);              // scalar multiplication => k * vec