
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
  // const�^�������Ȃ����t�@�����X�̏����l�͍��Ӓl�łȂ���΂Ȃ�܂���
  // ���t�@�����X���Ă͈̂����̂��Ƃ��ȁH
  // �����ύX�̂ł���lvalue(���Ӓl)�ł͂Ȃ�((�ǂ����̃T�C�g���

  // �����@
  // void copy(const int& x)
  // const��t���Ă����悤�B

  return 0;
}