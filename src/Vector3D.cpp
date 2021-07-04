#include "Vector3D.h"

Vector3D::Vector3D(float x3, float y3, float z3) {
	x = x3;
	y = y3;
	z = z3;
}
void Vector3D::set(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
float Vector3D::operator*(Vector3D op) {
	return (float)(x * op.x + y * op.y + z * op.z);
}

void Vector3D::Pvect(Vector3D a, Vector3D b) {
	this->x = a.y * b.z - a.z * b.y;
	this->y = a.z * b.x * a.x * b.z;
	this->z = a.x * b.y - a.y * b.x;
}

Vector3D Vector3D::operator*(float a) {
	Vector3D resultado;
	resultado.x = x * a;
	resultado.y = y * a;
	resultado.z = z * a;
	return resultado;
}

Vector3D Vector3D::operator+(Vector3D op) {
	Vector3D res;
	res.x = x + op.x;
	res.y = y + op.y;
	res.z = z + op.z;
	return res;
}

Vector3D Vector3D::operator-(Vector3D o) {
	Vector3D r;
	r.x = x - o.x;
	r.y = y - o.y;
	r.z = z - o.z;
	return r;
}
Vector3D Vector3D::unitario() {
	Vector3D un;
	float dom = un.modulo();
	if (dom > 0.0001f) {
		un.x /= dom;
		un.y /= dom;
		un.z /= dom;
	}
	return un;
}

float Vector3D::modulo() {
	return (float)sqrt(x * x + y * y + z * z);
}
Vector3D::~Vector3D() {

}
