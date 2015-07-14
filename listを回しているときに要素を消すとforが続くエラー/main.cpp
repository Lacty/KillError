
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

protected:
  std::string name;
  State state;

public:
  Object() : state(State::Awake) {}

  bool isAwake() { return state == State::Awake ? true : false; }
  bool isActive() { return state == State::Active ? true : false; }
  bool isDead() { return state == State::Dead ? true : false; }

  std::string getName() { return name; }

  virtual void update() {};
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

  std::shared_ptr<Item> item;
  item = std::make_shared<Item>();
  if (item->isActive()) { std::cout << "item init" << std::endl; }

  map.emplace(item->getName(), item);
  list.emplace_back(item);

  {
    auto it = map.find("item");
    std::cout << it->second->getName() << " in map" << std::endl;
  }


  //-------- クソコードはこちら ----------//
  for (auto& it : list) {
    it->update();
    //list.remove_if([](std::weak_ptr<Object> obj) { return obj.lock()->isDead(); });
  }
  //------------------------------------//

  {
    auto it = map.find("item");
    map.erase(it);
  }

  list.remove_if([](std::weak_ptr<Object> obj) { return obj.lock()->isDead(); });

  if (item->isDead()) { std::cout << "item dead" << std::endl; }

}