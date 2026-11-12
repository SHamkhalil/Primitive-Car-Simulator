#include <cmath>
#include <ostream>
#include <stdexcept>

#include "vec3.hpp"

// Operators
bool  vec3::operator==(const vec3 &b) const{ return (m_x == b.m_x && m_y == b.m_y && m_z == b.m_z); }
vec3& vec3::operator*=(const double &k) { m_x *= k; m_y *= k; m_z *= k; return *this; }
vec3& vec3::operator/=(const double &k) { 
  if (k == 0) std::invalid_argument("Divsion by Zero!");
  return (*this *= 1 / k); 
};
vec3& vec3::operator-() { *this *= -1; return *this; }
vec3& vec3::operator+=(const vec3 &b) { m_x += b.m_x; m_y += b.m_y; m_z += b.m_z; return *this; }
vec3& vec3::operator-=(const vec3 &b) { m_x -= b.m_x; m_y -= b.m_y; m_z -= b.m_z; return *this; }

vec3  vec3::operator+(const vec3 &b) const{ return vec3(m_x + b.m_x, m_y + b.m_y, m_z + b.m_z); }
vec3  vec3::operator-(const vec3 &b) const{ return vec3(m_x - b.m_x, m_y - b.m_y, m_z - b.m_z); }
vec3  vec3::operator*(const double &k) const{ return vec3(k * m_x, k * m_y, k * m_z); }

double vec3::operator[](const size_t idx) const{ // indexed from 0
  if (idx > 2) 
    std::invalid_argument("incorrect index value - must be between 0 and 2");
  else{
    if (idx == 0) return m_x;
    else if (idx == 1) return m_y;
    else return m_z;
  } 
}


// Misc
double  vec3::length() const{ return std::sqrt(m_x*m_x + m_y*m_y + m_z*m_z); }
vec3    vec3::normalize() const{ 
  double vecLength = length();
  if (vecLength <= 10e-9 && vecLength >= -10e-9) return vec3(0, 0, 0); // clamp down to <0, 0, 0>
  return vec3(m_x / vecLength, m_y / vecLength, m_z / vecLength);
}
std::ostream& operator<<(std::ostream& os, const vec3& v) {
  return os << '(' << v.m_x << ' ' << v.m_y << ' ' << v.m_z << ')';
}
