#include"GameScene.h"
#include"Vector3.h"

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

Matrix4x4 MakeRotateXMatrix(float radian);

Matrix4x4 MakeRotateYMatrix(float radian) ;
   

Matrix4x4 MakeRotateZMatrix(float radian) ;

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) ;

Vector3& operator+=(Vector3& lhv,const Vector3& rhv);

float EaseInOut(float start,float end,float time);
float Lerp(float start,float end,float time);
Vector3 Lerp(const Vector3& v1,const Vector3& v2,float t);