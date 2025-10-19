#include <stdio.h>

typedef struct {
  float x, y, z;
} Vec3;

void read_data(Vec3 *v) {
  printf("Geben Sie die Komponenten des Vektors (x, y, z) ein: ");
  scanf("%f %f %f", &v->x, &v->y, &v->z);
}

void show_data(Vec3 v) {
  printf("Vektor: (%.2f, %.2f, %.2f)\n", v.x, v.y, v.z);
}

void add(Vec3 *res, Vec3 a, Vec3 b) {
  res->x = a.x + b.x;
  res->y = a.y + b.y;
  res->z = a.z + b.z;
}

void sub(Vec3 *res, Vec3 a, Vec3 b) {
  res->x = a.x - b.x;
  res->y = a.y - b.y;
  res->z = a.z - b.z;
}

float skalar(Vec3 a, Vec3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

void cross(Vec3 *c, Vec3 a, Vec3 b) {
  c->x = a.y * b.z - a.z * b.y;
  c->y = a.z * b.x - a.x * b.z;
  c->z = a.x * b.y - a.y * b.x;
}

int main() {
  Vec3 v1, v2, result;
  float skalar_result;

  printf("Vektor 1:\n");
  read_data(&v1);
  printf("vektor 2:\n");
  read_data(&v2);

  printf("\nEingelessene Vektoren:\n");
  show_data(v1);
  show_data(v2);

  add(&result, v1, v2);
  printf("\nVektoraddition:\n");
  show_data(result);

  sub(&result, v1, v2);
  printf("\nVektor subtraktion:\n");
  show_data(result);

  skalar_result = skalar(v1, v2);
  printf("\nSkalarprodukt: %.2f\n", skalar_result);

  cross(&result, v1, v2);
  printf("\nKreuzprodukt:\n");
  show_data(result);

  return 0;
}
