// Transform.cpp: implementation of the Transform class.


#include "Transform.h"
//#include <iostream>
//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
  // YOUR CODE FOR HW1 HERE

  // You will change this return call
//  std::cout<<"degrees" << degrees<<std::endl;
  mat3 I(1.0);
  mat3 m = cos(degrees * pi/180.0)*I;
  m = m + (1-cos(degrees * pi / 180.0)) * glm::outerProduct(axis,axis); 
  m = m + sin(degrees * pi/180.0) * mat3(0,axis[2],-axis[1],-axis[2],0,axis[0],axis[1],-axis[0],0);
  return m;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE
  eye =Transform::rotate(degrees,up)*eye; 
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE 
  vec3 w = glm::normalize(eye);
  vec3 u = glm::normalize(glm::cross(up,w));
  eye =Transform::rotate(-degrees,u)*eye; 
  up =Transform::rotate(-degrees,u)*up; 
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR HW1 HERE

  // You will change this return call
  vec3 w = glm::normalize(eye);
  vec3 u = glm::normalize(glm::cross(up,w));
  vec3 v = glm::cross(w,u);
  mat4 R = mat4(u[0],v[0],w[0],0,u[1],v[1],w[1],0,u[2],v[2],w[2],0,0,0,0,1);
  mat4 T = mat4(1,0,0,0,0,1,0,0,0,0,1,0,-eye.x,-eye.y,-eye.z,1);
  mat4 M = R*T; 
  return M;
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
