/**
 * @brief assign2
 * @author Clayton Moeck
 */

#include <iostream>

using namespace std;

int main()
{ 
  double orderCost;
  int shippingMethod;

  cout << "Please type in the cost of the order: ";
  cin >> orderCost;
  if (orderCost <= 0)
  {
    cout << "Bad Input";
    return 0;
  }

  cout << "Now please type in the shipping method: 1- Drone Delivery. 2 - 2-Day Delivery. And 3 - Standard Delivery: ";
  cin >> shippingMethod;

  if (shippingMethod == 1)
  {
    if (orderCost > 0 && orderCost < 100)
      cout << "Not Available" << endl;
    else if (orderCost >= 100 && orderCost < 500)
      cout << "Total is " << (orderCost + 50.0) << endl;
    else
    {
      double grandTotal;
      grandTotal = (orderCost + (orderCost * 0.1));
      double roundedTotal = static_cast<int>(grandTotal * 100) / 100.0;
      cout << "Total is " << roundedTotal << endl;
    }
  }

  else if (shippingMethod == 2)
  {
    if (orderCost > 0 && orderCost <= 300)
    {
      double grandTotal;
      grandTotal = (orderCost + (10.0 + (orderCost * 0.02)));
      double roundedTotal = static_cast<int>(grandTotal * 100) / 100.0;
      cout << "Total is " << roundedTotal << endl;
    }
    else
      cout << "Total is " << orderCost << endl;
  }

  else if (shippingMethod == 3)
  {
    if (orderCost > 0 && orderCost < 35)
      cout << "Total is " << (orderCost + 5.0) << endl;
    else if (orderCost >= 35 && orderCost < 100)
      cout << "Total is " << (orderCost + 8.0) << endl;
    else
      cout << "Total is " << orderCost << endl;
  }
  
  else
    cout << "Bad Input" << endl;

return 0;
}