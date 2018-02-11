#include <iostream>


//Class is an object which allows you to store related data structures and functions together (these are called class members).
//One example might be class of Car containing informations about type of the car, weight, size, engine, ...   


//Class and three types of class members
class TestClass{
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

//Directly inside functions
class Building{
   private:
      //class members can be initialized directly:
      //std::string m_name = "skyscraper"; //c++98 initialization 
      std::string m_name{"skyscraper"}; //c++11 initialization 
      //Note: following conventions that class members have prefix m_


      //Every created class Building will have set its name on skyscraper,
      //We can't access the class and change the name directly, but we can create
      //getter and setter functions
   public:
      void set_name(std::string buildingName){ m_name = buildingName; }
      std::string get_name(){ return m_name; }
};



//Using constructor
class Car{
   private:
      std::string m_type; 
      std::string m_colour; 

      //Constructor
   public:
      // Set all members when initializing the class
      //Constructor (old versions)
      //      Car(std::strig carType){
      //         type = carType;
      //      }

      //Base constructor of the class, which will instantiate the class
      Car();

      //Constructor can be overloaded, meaning we can have multiple constructors but with different parameters (modern c++11 initialization list)
      Car(std::string carType) : m_type(carType){
         std::cout << "Creating "<< m_type << " car object" << std::endl;
      }

      //We can have as many constructors as we want IF they differ in parameter inputs!
      Car(std::string carType, std::string carColour) : m_type(carType), m_colour(carColour){
         std::cout << "Creating "<< m_type << " car in " << m_colour << " colour" << std::endl;
      }


      //Destructor
      //Once class gets out of the scope destructor is called
      ~Car(){
         std::cout << "Destroying car object" << std::endl;
      }
};


//Initialization outside class
class Animal{
   private:
      std::string name;
      std::string sound;
   public:

      Animal();
      Animal(std::string name, std::string sound );
      ~Animal();
};

//Definition of constructors/member functions outside of class 
Animal::Animal(){}
Animal::~Animal(){}
Animal::Animal(std::string name, std::string sound){
   //this keyword is a pointer to the location of created class memory 
   //It's usefull to use to specify which variable we mean in case of the same name
   this->name = name;
   this->sound = sound;

   std::cout << "Creating " << name << " making " << sound << std::endl;
}

//Constructors can be called implicitly
class A{
   public:
      unsigned m_nElements{3};
      //This class will call impilict default constructor A::A()
};

class B{
   public:
      unsigned m_nElements{6};
      B(unsigned el) : m_nElements(el){};
      //If constructor with arguments is specified, default const is not created
};

class C{
   public:
      unsigned m_nElements{10};
      //forces default constructor to be created even though one with parameter is provided
      C() = default;
      //There are some minor diferences between the syntax above and below
      // C(){};

      //Oposite to default, this deletes impilict default constructors
      //User might want to have control over which class should have default const and which not - default/delete
      //C() = delete;

      C(unsigned el) : m_nElements(el){};
};

void constructors(){

   A a; //Calls implicit constructor
   std::cout << a.m_nElements << std::endl;

   // B b; //Error fail to compile
   B b(4); //This works
   std::cout << b.m_nElements << std::endl;

   C c; //Calls implicit constructor
   std::cout << c.m_nElements << std::endl;


}


//Copy constructors
class Weapon{
   private: 
      std::string m_type = "sword";
   public:
      Weapon() { std::cout << "Creating a weapon" << std::endl; }
};


class Plant{
   private: 
      std::string m_type = "plant";
   public:
      Plant() {std::cout << "Creating a plant" << std::endl; }
      //Overriding implicit copy constructor
      Plant(const Plant &other){

         //Can access private members
         m_type = other.m_type;
         std::cout << "Overriding default implicit copy constructor" << std::endl;
      }

      void set_type(std::string type){ m_type = type; }
      std::string get_type(){ return m_type; }

};

void copy_constructors(){

   Weapon sword;
   //Notice that creating weapon is called only once
   //Copy constructor is created implicitly, copying all members from right to left
   Weapon oneHandSword = sword;

   //We can override copy constructor
   Plant plant;
   Plant rose = plant; 
   rose.set_type("rose");
   std::cout << rose.get_type() << std::endl;

}


void class_initialization(){

   Building bld;

   //Err can't access private members
   //std::cout << bld.m_name << std::endl;

   //Works fine!
   std::cout << bld.get_name() << std::endl;

   //Notice the () brackets, without it we would get undefined reference
   //Works fine for Building as it does not have constructor
   Car Skoda();

   //Overloading Car constructor
   Car Mercedes("Mercedes");
   Car BMW("BMW", "black");

   Animal cat("cat", "Meow!!");

}



int main(){
   class_initialization();
   constructors();
   copy_constructors();
   return 0;
}

//README:
//Things covered in the file:
//Class initialization(private, protected, public)
//Constructor, destructor
//Overload constructor
//This keyword 
//Default/delete keywords
//Copy constructor
