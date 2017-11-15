/*Goal: study generic classes
**Fix the program by completing
**the constructor. It should 
**assign a default value to each
**element in the array.*/

#include "main.hpp"

int main()
{
    //StudentRecord is the generic class
    //The constructor sets the grade value
    StudentRecord<int> srInt(-1);//add a default value using a constructor
    srInt.setId(111111);
    int arrayInt[SIZE]={4,3,2,1,4};
    srInt.setGrades(arrayInt);
    srInt.printGrades();
 
    StudentRecord<char> srChar('U');//add a default value using a constructor
    srChar.setId(222222);
    char arrayChar[SIZE]={'A','B','C','D','F'};
    srChar.setGrades(arrayChar);
    srChar.printGrades();
   
    StudentRecord<float> srFloat(-1.0);//add a default value using a constructor
    srFloat.setId(333333);
    float arrayFloat[SIZE]={2.75,4.0,3.7,2.8,3.99};
    srFloat.setGrades(arrayFloat);
    srFloat.printGrades();
    
    StudentRecord<string> srString("U");//add a default value using a constructor
    srString.setId(4444);
    string arrayString[SIZE]={"B","B-","C+","B","A"};
    srString.setGrades(arrayString);
    srString.printGrades();
    
    return 0;
}
