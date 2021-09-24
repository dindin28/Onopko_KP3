// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include <KP3/toy.h>

#include <cstring>
#include <iostream>
#include <string>

//Con
Toy::Toy()
    : classififcation_(kSoftToy)
{
  const char *name_of_toy = "Bunny";
  const char *manufacturer_name = "BuchaInc";

  name_of_toy_ = new char[strlen(name_of_toy) + 1];
  strcpy(name_of_toy_, name_of_toy);

  manufacturer_name_ = new char[strlen(manufacturer_name) + 1];
  strcpy(manufacturer_name_, manufacturer_name);

#ifdef CONSTRUCTORS
  std::cout << "Toy()" << std::endl;
#endif
}

Toy::Toy(const char *name_of_toy, const char *manufacturer_name, Classififcation classififcation)
    : classififcation_(classififcation)
{
  name_of_toy_ = new char[strlen(name_of_toy) + 1];
  strcpy(name_of_toy_, name_of_toy);

  manufacturer_name_ = new char[strlen(manufacturer_name) + 1];
  strcpy(manufacturer_name_, manufacturer_name);

#ifdef CONSTRUCTORS
  std::cout << "Toy(const char *, const char *, Classififcation)" << std::endl;
#endif
}

Toy::Toy(const Toy &copy)
    : classififcation_(copy.classififcation_)
{
  name_of_toy_ = new char[strlen(copy.name_of_toy_) + 1];
  strcpy(name_of_toy_, copy.name_of_toy_);

  manufacturer_name_ = new char[strlen(copy.manufacturer_name_) + 1];
  strcpy(manufacturer_name_, copy.manufacturer_name_);

#ifdef CONSTRUCTORS
  std::cout << "Toy(const Toy &copy)" << std::endl;
#endif
}

Toy &Toy::operator=(const Toy &copy)
{
  if (this != &copy) //Protect from leak of memory when this == &copy
  {
    //Copy name_of_toy_
    if (strlen(name_of_toy_) != 0)
    {
      delete[] name_of_toy_;
    }
    name_of_toy_ = new char[strlen(copy.name_of_toy_) + 1];
    strcpy(name_of_toy_, copy.name_of_toy_);

    //Copy manufacturer_name_
    if (strlen(manufacturer_name_) != 0)
    {
      delete[] manufacturer_name_;
    }
    manufacturer_name_ = new char[strlen(copy.manufacturer_name_) + 1];
    strcpy(manufacturer_name_, copy.manufacturer_name_);

    //Copy classififcation_
    classififcation_ = copy.classififcation_;
  }

  return *this;
}

Toy::~Toy()
{
  if (strlen(name_of_toy_) != 0)
  {
    delete[] name_of_toy_;
  }
  if (strlen(manufacturer_name_) != 0)
  {
    delete[] manufacturer_name_;
  }

#ifdef CONSTRUCTORS
  std::cout << "~Toy()" << std::endl;
#endif
}

//Setters
Toy &Toy::SetNameOfToy(const char *name_of_toy)
{
  if (strlen(name_of_toy_) != 0)
  {
    delete[] name_of_toy_;
  }
  name_of_toy_ = new char[strlen(name_of_toy) + 1];
  strcpy(name_of_toy_, name_of_toy);

  return *this;
}

Toy &Toy::SetManufacturerName(const char *manufacturer_name)
{
  if (strlen(manufacturer_name_) != 0)
  {
    delete[] manufacturer_name_;
  }
  manufacturer_name_ = new char[strlen(manufacturer_name) + 1];
  strcpy(manufacturer_name_, manufacturer_name);

  return *this;
}

Toy &Toy::SetClassification(Classififcation classififcation)
{
  classififcation_ = classififcation;

  return *this;
}

//Getters
const char *Toy::GetNameOfToy() const { return name_of_toy_; }
const char *Toy::GetManufacturerName() const { return manufacturer_name_; }
Classififcation Toy::GetClassification() const { return classififcation_; }

void Toy::Print()
{
  std::cout << "Toy name: " << name_of_toy_ << std::endl;
  std::cout << "Manufacturer name: " << manufacturer_name_ << std::endl;
  std::cout << "Classification: ";
  switch (classififcation_)
  {
  case (kSoftToy):
  {
    std::cout << "Soft toy";
    break;
  }
  case (kDoll):
  {
    std::cout << "Doll";
    break;
  }
  case (kTechnicalModel):
  {
    std::cout << "Technical model";
    break;
  }
  case (kConstructor):
  {
    std::cout << "Constructor";
    break;
  }
  } //Switch (classififcation_)
  std::cout << std::endl;
}

//Operators
bool Toy::operator==(const Toy &copy)
{
  return (strcmp(name_of_toy_, copy.name_of_toy_) == 0 &&
          strcmp(manufacturer_name_, copy.manufacturer_name_) == 0 &&
          classififcation_ == copy.classififcation_);
}
bool Toy::operator!=(const Toy &copy)
{
  return !operator==(copy);
}

std::ostream &operator<<(std::ostream &out, const Toy &copy)
{
  out << copy.GetNameOfToy() << " (" << copy.GetManufacturerName() << ", ";
  switch (copy.GetClassification())
  {
  case (kSoftToy):
  {
    out << "Soft toy";
    break;
  }
  case (kDoll):
  {
    out << "Doll";
    break;
  }
  case (kTechnicalModel):
  {
    out << "Technical model";
    break;
  }
  case (kConstructor):
  {
    out << "Constructor";
    break;
  }
  } //Switch (classififcation_)
  out << ")";

  return out;
}

std::istream &operator>>(std::istream &in, Toy &copy)
{
  std::string str_buff;
  std::cout << "Enter toy`s name: ";
  in >> str_buff;
  copy.SetNameOfToy(str_buff.c_str());

  std::cout << "Enter manufacturer`s name: ";
  in >> str_buff;
  copy.SetManufacturerName(str_buff.c_str());

  int int_buff;
  std::cout << "1 - Soft toy" << std::endl;
  std::cout << "2 - Doll" << std::endl;
  std::cout << "3 - Technical Model" << std::endl;
  std::cout << "4 - Constructor" << std::endl;
  std::cout << "Enter classification: " << std::endl;
  in >> int_buff;
  switch (int_buff)
  {
  case (kSoftToy):
  {
    copy.SetClassification(kSoftToy);
    break;
  }
  case (kDoll):
  {
    copy.SetClassification(kDoll);
    break;
  }
  case (kTechnicalModel):
  {
    copy.SetClassification(kTechnicalModel);
    break;
  }
  case (kConstructor):
  {
    copy.SetClassification(kConstructor);
    break;
  }
  } //Switch (int_buff)

  return in;
}