#include <iostream>
#include <new>

int main(int argc, char *argv[]) {
  struct MyStruct {
    const float f;
  };

  MyStruct obj{12.34f};

  MyStruct *p = &obj;
  std::cout << "f=" << p->f << std::endl;

  new (static_cast<void*>(p)) MyStruct{3.1415f};

  std::cout << p->f << std::endl; // ????
  std::cout << std::launder(p)->f << std::endl; // OK
}
