/*Goal:
*/

#include "main.hpp"

int main()
{
    Cat c1("polly", 20.0, "cat");
    Dog d1("spot", 30.0, "dog");
    
    cout << "Polly Rate: $" << c1.calcDailyRate() << endl;
    cout << "Spot Rate: $"  << d1.calcDailyRate() << endl;
   
    return 0;
}