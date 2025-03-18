int fn(int *i, float *f) {
  (*i)++;
  *f = 3.1415f;
  return *i;
}
// Optimizer assumes value of '*i' can't be changed by assigning '*f' 

int main(int argc, char *argv[]) {
  int a = 1;
  return fn(&a, reinterpret_cast<float *>(&a));
}
