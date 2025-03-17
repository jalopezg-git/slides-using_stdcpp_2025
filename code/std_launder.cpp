#include <iostream>
#include <new>

int main(int argc, char *argv[]) {
  struct MyStruct {
    const float f;
    const int &i_ref;
  };

  int i = 0x11, j = 0x22;
  MyStruct obj{12.34f, i};

  MyStruct *p = &obj;
  std::cout << "f=" << p->f << " i_ref=" << p->i_ref << std::endl;

  new (static_cast<void*>(p)) MyStruct{3.1415f, j};

  std::cout << p->i_ref << std::endl; // ????
  std::cout << std::launder(p)->i_ref << std::endl; // OK
}
