#include <cmath>
#include <ostream>

#include "vec3.hpp"

// Operator overloads
vec3  vec3::operator+(const vec3 &b) const{ return {m_x + b.m_x, m_y + b.m_y, m_z + b.m_z}; }
vec3  vec3::operator-(const vec3 &b) const{ return {m_x - b.m_x, m_y - b.m_y, m_z - b.m_z}; }

vec3& vec3::operator-=(const vec3 &b) { m_x -= b.m_x; m_y -= b.m_y; m_z -= b.m_z; return *this; }
vec3& vec3::operator+=(const vec3 &b) { m_x += b.m_x; m_y += b.m_y; m_z += b.m_z; return *this; }
vec3& vec3::operator*=(const double &k) { m_x *= k; m_y *= k; m_z *= k; return *this; }
vec3& vec3::operator/=(const double &k) { 
  if (k == 0) throw "Divsion by Zero!";
  m_x /= k; m_y /= k; m_z /= k; return *this; };

bool   vec3::operator==(const vec3 &b) const{ return (m_x == b.m_x && m_y == b.m_y && m_z == b.m_z); }

vec3   vec3::operator/=(const vec3 &b) const{return vec3(m_x/b.m_x, m_y/b.m_y, m_z/b.m_z); }
double vec3::operator[](const size_t idx) const{ // indexed from 0
  if (idx > 2) 
    throw "incorrect index value - must be between 0 and 2";
  else{
    if (idx == 0) return m_x;
    else if (idx == 1) return m_y;
    else return m_z;
  } 
}

// extra methods
double  vec3::length() const{ return std::sqrt(m_x*m_x + m_y*m_y + m_z*m_z); }
vec3    vec3::normalize() const{ 
  double vecLength = length() != 0 ? length() : throw "Divison by Zero";
  return vec3(m_x / vecLength, m_y / vecLength, m_z / vecLength); 
}

// Misc
std::ostream& operator<<(std::ostream& os, const vec3& v){
  return os << '(' << v.m_x << ' ' << v.m_y << ' ' << v.m_z << ')';
}
