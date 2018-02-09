#include <iostream>


//Class is an object which allows you to store related data structures and functions together (these are called class members).
//One example might be class of Car containing informations about type of the car, weight, size, engine, ...   


//Class and three types of class members
class Object{
//Can be accessed only within the class
private:
//What is the advantage having private? And using getters/setters? -> To be certain that nothing/no one who is not qualified should be able to change the inside of the function
//Example from life: Suppose you have a car and something is wrong with your car, even if you don't have any experience with mending cars you start to mess with the inside of your car and it won't work ever again. Sounds familiar?

//Can be accessed only within the class and by inherited classes
protected:

//Members can be accesed by anything
public:

};

//-----------------------------------------------------------------
//----------------Initialization of members------------------------- 
//-----------------------------------------------------------------

//1] directly inside functions
class Building{
   private:
      //class members can be initialized directly:
      //std::string m_name = "skyscraper"; //c++98 initialization 
      std::string m_name{"skyscraper"}; //c++11 initialization 
      //Note: following conventions that data members have prefix m_


      //Every created class Building will be have set name on skyscraper,
      //We can't access the class and change the name directly, but we can create
      //getter and setter functions
   public:
      void set_name(std::string buildingName){ m_name = buildingName; }
      std::string get_name(){ return m_name; }
};





//2] Using constructor
class Car{
   private:
      std::string m_type; 
      //Constructor
   public:
// Set all members when initializing the class
      //Constructor (old versions)
//      Car(std::strig carType){
//         type = carType;
//      }

      //Constructor (moder c++11 version)
      Car(std::string carType) : m_type(carType){}
};



void class_initialization(){
Building bld;

//Err can't access private members
//std::cout << bld.m_name << std::endl;

//Works fine!
std::cout << bld.get_name() << std::endl;


}

int main(){

class_initialization();

return 0;
}
