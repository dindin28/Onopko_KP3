#ifndef _KP3_INCLUDE_KP3_TOYS_GROUP_H_
#define _KP3_INCLUDE_KP3_TOYS_GROUP_H_

#include <KP3/toy.h>
#include <KP3/date.h>
#include <KP3/classification.h>

class ToysGroup : public Toy
{
public:
  //Default constructor(with no parameters)
  ToysGroup();

  //Constructor with parameters
  ToysGroup(Toy toy,
            Date delivery_date,
            int price, int counts);

  //Constructor with parameters and Toy class
  ToysGroup(const char *name_of_toy,
            const char *manufacturer_name,
            Classififcation classififcation,
            Date delivery_date,
            int price, int counts);

  //Copy constructor
  ToysGroup(const ToysGroup &copy);

  //Destructor
  ~ToysGroup();

  //Setters
  ToysGroup &SetToy(const Toy &toy);
  ToysGroup &SetDeliveryDate(const Date &date);
  ToysGroup &SetPrice(const int price);
  ToysGroup &SetCounts(const int counts);

  //Getters
  Toy GetToy() const;
  Date GetDeliveryDate() const;
  int GetPrice() const;
  int GetCounts() const;

  //Function for printing class info
  void Print() override;

  //Operators
  bool operator==(const ToysGroup &copy);
  bool operator!=(const ToysGroup &copy);

  bool operator>(const ToysGroup &copy);
  bool operator<(const ToysGroup &copy);


  ToysGroup operator+(const ToysGroup &copy);

  friend std::ostream &operator<<(std::ostream &out, const ToysGroup &copy);
  friend std::istream &operator>>(std::istream &in, ToysGroup &copy);

private:
  Date delivery_date_;
  int price_, counts_;
}; //Class (ToysGroup)

#endif //Header Guard