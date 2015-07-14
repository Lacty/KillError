
#include <iostream>


class Test01 {
private:

  int x;

public:

  Test01() :
  x(10) {}

  int getX() {
    return x;
  }
};

class Test02 {
private:

  int x;

public:

  Test02() :
  x(0) {}

  void copy(int& x) {
    this->x = x;
  }
};

int main(){
  Test01 test01;
  Test02 test02;

  test02.copy(const test01.getX()); // err

  // initial value of reference to non_const must be an lvalue
  // const型をもたないリファレンスの初期値は左辺値でなければなりません
  // リファレンスってのは引数のことかな？
  // 代入や変更のできるlvalue(左辺値)ではない((どこかのサイトより

  // 解決法
  // void copy(const int& x)
  // constを付けてあげよう。

  return 0;
}