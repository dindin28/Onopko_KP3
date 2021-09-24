#ifndef _KP3_INCLUDE_KP3_TOY_SHOP_H_
#define _KP3_INCLUDE_KP3_TOY_SHOP_H_

#include <KP3/toys_group.h>

class ToyShop
{
public:
  //Default constructor(with no parameters)
  ToyShop();

  //Constructor with parameters
  ToyShop(int store_serial_number);

  //Copy constructor
  ToyShop(const ToyShop &copy);

  //operator=
  ToyShop &operator=(const ToyShop &copy);

  //Destructor
  ~ToyShop();

  //Setters
  ToyShop &SetStoreSerialNumber(const int store_serial_number);
  ToyShop &SetNewPointer(const ToysGroup *pointer, const size_t size);

  //Getters
  int GetShopsCount() const;
  int GetStoreSerialNumber() const;
  int GetSize() const;

  //Function for printing class info
  void Print();
  void PrintShortly();

  //Other functions
  void AddToysGroup(const ToysGroup value);
  bool SellToy(const Toy value); //return if there is toy in shop

  ToysGroup &operator[](const int index);

private:
  static int shops_count_;
  int store_serial_number_;
  ToysGroup *pointer_;
  size_t size_;
}; //Class (ToysGroup)

#endif //Header Guard