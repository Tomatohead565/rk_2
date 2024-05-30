// Decorator design pattern

#include <iostream>
#include "header.h"

int main() {
  /**
   * This way the client code can support both simple components...
   */
  Drink* simple = new Water;
  std::cout << "Client: I've got a simple component:\n";
  ClientCode(simple);
  std::cout << "\n\n";
  /**
   * ...as well as decorated ones.
   *
   * Note how decorators can wrap not only simple components but the other
   * decorators as well.
   */
  Drink* decorator1 = new Milk(simple);
  Drink* decorator2 = new coffe(decorator1);


  ClientCode(decorator2);


  delete simple;
  delete decorator1;
  delete decorator2;

  return 0;
}
