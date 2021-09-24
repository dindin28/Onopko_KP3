// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include <KP3/toy_shop.h>

#include <iostream>

int ToyShop::shops_count_ = 0;

//Default constructor(with no parameters)
ToyShop::ToyShop()
    : store_serial_number_(shops_count_ + 1), size_(0), pointer_(nullptr)
{
  shops_count_++;

#ifdef CONSTRUCTORS
  std::cout << "ToyShop()" << std::endl;
#endif
}

//Constructor with parameters
ToyShop::ToyShop(int store_serial_number)
    : store_serial_number_(store_serial_number), size_(0), pointer_(nullptr)
{
  shops_count_++;

#ifdef CONSTRUCTORS
  std::cout << "ToyShop(int store_serial_number)" << std::endl;
#endif
}

//Copy constructor
ToyShop::ToyShop(const ToyShop &copy)
    : size_(copy.size_), store_serial_number_(copy.store_serial_number_)
{
  pointer_ = new ToysGroup[size_];
  for (int i = 0; i < size_; i++)
  {
    pointer_[i] = copy.pointer_[i];
  }

  shops_count_++;

#ifdef CONSTRUCTORS
  std::cout << "ToyShop(const ToyShop &copy)" << std::endl;
#endif
}

//operator=
ToyShop &ToyShop::operator=(const ToyShop &copy)
{
  if (this != &copy) //Protection from leak of memory
  {
    if (size_ != 0)
    {
      delete[] pointer_;
    }

    pointer_ = new ToysGroup[copy.size_];
    for (int i = 0; i < copy.size_; i++)
    {
      pointer_[i] = copy.pointer_[i];
    } //For loop(i < copy.size_)

    size_ = copy.size_;
    store_serial_number_ = copy.store_serial_number_;
  } //Condition (this != &copy)

  return *this;
}

//Destructor
ToyShop::~ToyShop()
{
  if (size_ != 0)
  {
    delete[] pointer_;
  }

#ifdef CONSTRUCTORS
  std::cout << "~ToyShop()" << std::endl;
#endif
}

//Setters
ToyShop &ToyShop::SetStoreSerialNumber(const int store_serial_number)
{
  store_serial_number_ = store_serial_number;

  return *this;
}

ToyShop &ToyShop::SetNewPointer(const ToysGroup *pointer, const size_t size)
{
  if (size_ > 0)
  {
    delete[] pointer_;
  }
  pointer_ = new ToysGroup[size];
  for (int i = 0; i < size; i++)
  {
    pointer_[i] = pointer[i];
  }
  size_ = size;

  return *this;
}

//Getters
int ToyShop::GetShopsCount() const { return shops_count_; }
int ToyShop::GetStoreSerialNumber() const { return store_serial_number_; }
int ToyShop::GetSize() const { return size_; }

//Function for printing class info
void ToyShop::Print()
{
  std::cout << "Shop #" << store_serial_number_ << std::endl;
  if (size_ > 0)
  {
    std::cout << "Toys group:" << std::endl;
    for (int i = 0; i < size_; i++)
    {
      std::cout << i + 1 << ") ";
      pointer_[i].Print();
      std::cout << std::endl;
    }
  }
}
void ToyShop::PrintShortly()
{
  std::cout << "Serial number: " << store_serial_number_;
  int sum = 0;
  for (int i = 0; i < size_; i++)
  {
    sum += pointer_[i].GetCounts();
  }
  std::cout << " ,toys: " << sum << std::endl;
}

//Other functions
void ToyShop::AddToysGroup(const ToysGroup value)
{
  if (size_ != 0)
  {
    ToysGroup *new_pointer = new ToysGroup[size_ + 1];
    for (int i = 0; i < size_; i++)
    {
      new_pointer[i] = pointer_[i];
    }
    new_pointer[size_] = value;
    delete[] pointer_;
    pointer_ = new_pointer;
  }
  else
  {
    pointer_ = new ToysGroup[1];
    pointer_[0] = value;
  }
  ++size_;
}

//return if there is toy in shop
bool ToyShop::SellToy(const Toy value)
{
  bool is_valid_to_sell = false;
  for (int i = 0; i < size_ && is_valid_to_sell == false; i++)
  {
    if (pointer_[i].GetToy() == value)
    {
      is_valid_to_sell = true;
      if (pointer_[i].GetCounts() - 1 > 0)
      {
        pointer_[i].SetCounts(pointer_[i].GetCounts() - 1);
      }
      else
      {
        if (size_ != 1)
        {
          ToysGroup *new_pointer = new ToysGroup[size_ - 1];
          for (int j = 0, k = 0; j < size_; j++)
          {
            if (j != i)
            {
              new_pointer[k] = pointer_[j];
              k++;
            } //Condition (j != i)
          }   //for loop (j < size_)
          delete[] pointer_;
          pointer_ = new_pointer;
        }
        else
        {
          delete[] pointer_;
        }
        --size_;
      } //Condition (pointer_[i].GetCounts() - 1 > 0)
    }   //Condition (pointer_[i].GetToy() == value)
  }     //for loop (i < size_ && is_valid_to_sell == false)
  return is_valid_to_sell;
}

//Operators
ToysGroup &ToyShop::operator[](const int index)
{
  return pointer_[index];
}