// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include <KP3/toy.h>
#include <KP3/toys_group.h>
#include <KP3/toy_shop.h>

#include <iostream>
#include <iomanip> //setfill, setw

int main()
{
  ToysGroup toys_group1(Toy(), Date(), 10, 1);
  ToysGroup toys_group2;
  std::cout << "toys_group1: " << std::endl
            << toys_group1 << std::endl;
  std::cout << "toys_group2: " << std::endl
            << toys_group2 << std::endl;
  std::cout << std::endl;
  std::cout << "toys_group1 + toys_group2: " << std::endl
            << toys_group1 + toys_group2 << std::endl;
  std::cout << std::endl;
  std::cout << "toys_group1 > toys_group2: " << (toys_group1 > toys_group2) << " -> because counts of toys_group2 is greater" << std::endl;

  std::cout << std::endl;
  //setfill - changes the fill character
  //setw - changes the width of next output field
  std::cout << std::setfill('-') << std::setw(100) << "" << std::endl;
  std::cout << std::endl;

  Toy toy1;
  Toy toy2;
  toy2.SetClassification(kConstructor);
  std::cout << "toy1: " << toy1 << std::endl;
  std::cout << "toy2: " << toy2 << std::endl;
  std::cout << std::endl;
  std::cout << "toy1 == toy2: " << (toy1 == toy2) << std::endl;

  std::cout << std::endl;
  //setfill - changes the fill character
  //setw - changes the width of next output field
  std::cout << std::setfill('-') << std::setw(100) << "" << std::endl;
  std::cout << std::endl;

  ToyShop toy_shop;
  toy_shop.AddToysGroup(toys_group1);
  toy_shop.AddToysGroup(toys_group2);
  toy_shop.Print();
  std::cout << std::endl;
  std::cout << "toy_shop[1]: " << std::endl;
  std::cout << toy_shop[1] << std::endl;

  std::cout << std::endl;
  //setfill - changes the fill character
  //setw - changes the width of next output field
  std::cout << std::setfill('-') << std::setw(100) << "" << std::endl;
  std::cout << std::endl;

  Toy *ptr_on_toys_group = &toys_group1;
  std::cout << "Toy *ptr_on_toys_group = &toys_group1" << std::endl;
  std::cout << "ptr_on_toys_group->Print(): " << std::endl;
  ptr_on_toys_group->Print();
  std::cout << std::endl;
}