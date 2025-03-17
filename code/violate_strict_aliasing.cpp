int fn(int *i, float *f) {
  (*i)++;
  *f = 3.1415f;
  return *i;
}
// Optimizer assumed that value of '*i' cannot be modified by a write to '*f' 

int main(int argc, char *argv[]) {
  int a = 1;
  return fn(&a, reinterpret_cast<float *>(&a));
}
