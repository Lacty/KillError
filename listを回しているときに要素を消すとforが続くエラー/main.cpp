
#include <iostream>
#include <map>
#include <list>
#include <memory>
#include <string>


class Object {
public:
  enum class State {
    Awake,
    Active,
    Dead
  };

  Object() : state(State::Awake) {}

  // ? :�@�Ō��Ȃ��Ă������B�s���Ȃ�()�ň͂����B
  bool isAwake() { return state == State::Awake; }
  bool isActive() { return state == State::Active; }
  bool isDead() { return state == State::Dead; }

  std::string getName() { return name; }

  virtual void update() {};

// public -> protected -> public�ƃA�N�Z�X���Z�q���ς���Ă����̂ŏC��
protected:
	std::string name;
	State state;

};

class Item : public Object {
private:

public:
  Item() {
    name = "item";
    state = State::Active;
  };

  void update() { state = State::Dead; }
};

int main() {
  std::map<std::string, std::shared_ptr<Object>> map;
  std::list<std::shared_ptr<Object>> list;

  std::shared_ptr<Item> item = std::make_shared<Item>();

  if (item->isActive())
  {
	  std::cout << "item init" << std::endl;
  }

  map.emplace(item->getName(), item);
  list.emplace_back(item);

  {
    auto it = map.find("item");
    std::cout << it->second->getName() << " in map" << std::endl;
  }

  std::cout << "list size : " << list.size() << std::endl;
  std::cout << "for each Start !" << std::endl;
  for (auto& it : list) {
    it->update();
  }

  std::cout << "for each End !" << std::endl;

  //for each �����̓����ŌĂ΂Ȃ����B
  list.remove_if([](std::weak_ptr<Object> obj) { return obj.lock()->isDead(); });
 
  std::cout << "list size : " << list.size() << std::endl;


  {
    auto it = map.find("item");
    map.erase(it);
  }

  if (item->isDead()) { std::cout << "item dead" << std::endl; }

}