// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include <KP3/toys_group.h>

#include <iostream>
#include <cstring>

ToysGroup::ToysGroup()
    : Toy(), delivery_date_(Date()), price_(1000), counts_(100)
{
#ifdef CONSTRUCTORS
  std::cout << "ToysGroup()" << std::endl;
#endif
}

ToysGroup::ToysGroup(Toy toy,
                     Date delivery_date,
                     int price, int counts)
    : delivery_date_(delivery_date),
      price_(price), counts_(counts)
{
  SetNameOfToy(toy.GetNameOfToy());
  SetManufacturerName(toy.GetManufacturerName());
  SetClassification(toy.GetClassification());

#ifdef CONSTRUCTORS
  std::cout << "ToysGroup(Toy, Date, int, int)" << std::endl;
#endif
}

//Constructor with parameters and Toy class
ToysGroup::ToysGroup(const char *name_of_toy,
                     const char *manufacturer_name,
                     Classififcation classififcation,
                     Date delivery_date,
                     int price, int counts)
    : delivery_date_(delivery_date),
      price_(price), counts_(counts)
{
  SetNameOfToy(name_of_toy);
  SetManufacturerName(manufacturer_name);
  SetClassification(classififcation);

#ifdef CONSTRUCTORS
  std::cout << "ToysGroup(const char *, const char *, Classififcation, Date, int, int)" << std::endl;
#endif
}

ToysGroup::ToysGroup(const ToysGroup &copy)
    : delivery_date_(copy.delivery_date_),
      price_(copy.price_), counts_(copy.counts_)
{
  SetNameOfToy(copy.GetNameOfToy());
  SetManufacturerName(copy.GetManufacturerName());
  SetClassification(copy.GetClassification());

#ifdef CONSTRUCTORS
  std::cout << "ToysGroup(const ToysGroup &copy)" << std::endl;
#endif
}

ToysGroup::~ToysGroup()
{
#ifdef CONSTRUCTORS
  std::cout << "~ToysGroup()" << std::endl;
#endif
}

ToysGroup &ToysGroup::SetToy(const Toy &toy)
{
  SetNameOfToy(toy.GetNameOfToy());
  SetManufacturerName(toy.GetManufacturerName());
  SetClassification(toy.GetClassification());
  return *this;
}

ToysGroup &ToysGroup::SetDeliveryDate(const Date &delivery_date)
{
  delivery_date_ = delivery_date;
  return *this;
}
ToysGroup &ToysGroup::SetPrice(const int price)
{
  price_ = price;
  return *this;
}
ToysGroup &ToysGroup::SetCounts(const int counts)
{
  counts_ = counts;
  return *this;
}

//Getters
Toy ToysGroup::GetToy() const { return Toy(GetNameOfToy(), GetManufacturerName(), GetClassification()); }
Date ToysGroup::GetDeliveryDate() const { return delivery_date_; }
int ToysGroup::GetPrice() const { return price_; }
int ToysGroup::GetCounts() const { return counts_; }

void ToysGroup::Print()
{
  std::cout << "Toy: " << GetToy()
      << " (date: " << GetDeliveryDate() << "), "
      << "counts: " << GetCounts() << ", "
      << "price: " << GetPrice();
}

//Operators
bool ToysGroup::operator==(const ToysGroup &copy)
{

  return (strcmp(GetNameOfToy(), copy.GetNameOfToy()) == 0 &&
          strcmp(GetManufacturerName(), copy.GetManufacturerName()) == 0 &&
          GetClassification() == copy.GetClassification() &&
          delivery_date_ == copy.delivery_date_ &&
          price_ == copy.price_ &&
          counts_ == copy.counts_);
}
bool ToysGroup::operator!=(const ToysGroup &copy)
{
  return !operator==(copy);
}

bool ToysGroup::operator>(const ToysGroup &copy)
{
  return counts_ > copy.counts_;
}

bool ToysGroup::operator<(const ToysGroup &copy)
{
  return counts_ < copy.counts_;
}

ToysGroup ToysGroup::operator+(const ToysGroup &copy)
{
  if (GetToy() == copy.GetToy())
  {
    return ToysGroup(GetToy(), delivery_date_,
                     price_ + copy.GetPrice(),
                     counts_ + copy.GetCounts());
  }
}

std::ostream &operator<<(std::ostream &out, const ToysGroup &copy)
{
  out << "Toy: " << copy.GetToy()
      << " (date: " << copy.GetDeliveryDate() << "), "
      << "counts: " << copy.GetCounts() << ", "
      << "price: " << copy.GetPrice();

  return out;
}

std::istream &operator>>(std::istream &in, ToysGroup &copy)
{
  Toy toy_buff;
  in >> toy_buff;
  copy.SetToy(toy_buff);

  Date date_buff;
  in >> date_buff;
  copy.SetDeliveryDate(date_buff);

  int int_buff;
  std::cout << "Enter price of toys group: ";
  in >> int_buff;
  copy.SetPrice(int_buff);

  std::cout << "Enter counts of toys group: ";
  in >> int_buff;
  copy.SetCounts(int_buff);

  return in;
}