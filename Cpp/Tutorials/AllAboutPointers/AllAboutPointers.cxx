#include <iostream>
#include <vector>

#include <memory>  //for smart pointers

using namespace std;

//--------------POINTERS-------------------
//Pointers, References and Dynamic Memory Allocation are the most powerful features in C/C++ language, which allows programmers to directly manipulate memory to efficiently manage the memory - the most critical and scarce resource in computer - for best performance. However, "pointer" is also the most complex and difficult feature in C/C++ language.

//Pointers are extremely powerful because they allows you to access addresses and manipulate their contents. But they are also extremely complex to handle. Using them correctly, they could greatly improve the efficiency and performance. On the other hand, using them incorrectly could lead to many problems, from un-readable and un-maintainable codes, to infamous bugs such as memory leaks and buffer overflow, which may expose your system to hacking. Many new languages (such as Java and C#) remove pointer from their syntax to avoid the pitfalls of pointers, by providing automatic memory management.

//Although you can write C/C++ programs without using pointers, however, it is difficult not to mention pointer in teaching C/C++ language. Pointer is probably not meant for novices and dummies.
//Source: https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp4_PointerReference.html  



//If we dont use a pointer or a reference the passed value can not be actualy internally changed inside the function since we are
//creating a copy of that value and store it in the difirent adress
void increment_int(int *number){
   *number += 1;
   return;
}

void multiply_int(int &number){
   number *= 2;
   return;
}




/** */
void use_of_pointers(){
   //Memory location contains information about its adress and data stored at that adress. Both are represented by numerical numbers (adress holds 8bit(1 byte) of data). Its complicated/not readable to handle them as numbers, so people introduced variables. A variable is a named location thatcan store a value of a particular type. Types (int, float, double, ...) represent data and names are attached to a specific adress.  

   //A pointer variable (or pointer in short) is basically the same as the other variables, which can store a piece of data. Unlike normal variable which stores a value (such as an int, a double, a char), a pointer stores a memory address. 

   cout << "Basic use of pointers" << endl;
   //Alocating memory
   int number = 5;

   //Create a pointer to an integer and initializing it to an adress of number using ampersand
   int *pnumber = &number;
   //This will print out the adress of number
   cout <<  "Printing the adress of number: " <<pnumber << endl;
   //To print out the actual value stored in the adress we need to "dereference" it using asterisk 
   cout << "Printing the  number: " <<*pnumber << endl;

   //To be able to change a variable inside a function, we need to use pointers (or reference)
   //If we dont use a pointer or a reference the passed value can not be actualy internally changed inside the function since we are
   //passing by a value, meaning creating a copy of that value and store it in the different adress
   increment_int(pnumber);
   cout << "Printing incremented  number (using pointers): " << number << endl;

   //We can actually use directly the adress of the object by using &
   increment_int(&number);
   cout << "Printing incremented the number (using adress of number): " << number << endl;


   //You may find yourself looking at double pointers (int **pointer)
   //Before pointers served as a tool to change value of variables inside functions
   //Pointers to pointers can serve as a tool to change adress of pointers inside functions
   //Good example of double pointer is a pointer to string (which itself is a pointer)

   //If you want to have a list of characters (a word), you can use char *word
   //If you want a list of words (a sentence), you can use char **sentence
   //If you want a list of sentences (a monologue), you can use char ***monologue
   //If you want a list of monologues (a biography), you can use char ****biography
   //If you want a list of biographies (a bio-library), you can use char *****biolibrary
   //If you want a list of bio-libraries (a ??lol), you can use char ******lol
   // Source https://stackoverflow.com/questions/5580761/why-use-double-pointer-or-why-use-pointers-to-pointers 

   //TODO: some examples with double pointers
}



/** */
void use_of_references(){
   //Reference is basically other name for a variable (alias)
   //It needs to be initialized at the point of definition!


   cout << "Basic use of reference" << endl;

   int number = 5;
   int &value = number;

   cout << "Printing the number: " << number << endl;
   cout << "Printing value which is a reference to number: " << number << endl;

   //Note that & sign when declared has the meaning of a reference whether when applied for instance passed as argument to the function it has a meaning of adress of a given object
   increment_int(&value);
   cout << "Printing incremented value (using adress of value): " << number << endl;

   //Passed by a reference
   multiply_int(value);
   cout << "Printing multiplied value (using passing by a reference ): " << number << endl;



}
/** */
void general_concept(){
   
   use_of_pointers();
   use_of_references();

   return;
}





void greet_in_english(){
cout << "Hello" << endl;
return;
}

void greet_in_german(){
cout << "Hallo" << endl;
return;
}

void call_name(string name){
cout << name << "!!!"<< endl;
return;
}

//return true if the first name of the person is Martin
bool match(string name){
return (name.find("Martin") ) ? true :false;
}

//Using function pointer inside function to calculate appearences of name Martin
int count_Martin( vector<string> &people, bool (*match)(string)){
   unsigned int nMartin= 0;
   for(auto name : people){
      if( match(name) ) ++nMartin;
   }
   return nMartin; 
}

//TODO: right know fp just copy pasted, create a header file? included smart pointers as well? 
//TODO: might be usefull to already use doxygen documentation if the file size and number of function will increase

int function_pointers(){
   //Creating variable of function pointer;
   void (*pFunction)();
   pFunction = &greet_in_english;
   //Can be used also without ampersand character, name of the function is actually a pointer to the function
   //pFunction = greet;
   (*pFunction)();
   pFunction();


   //Can be initialized directly when declared
   void (*pNewFunction)() = greet_in_german;
   //We dont event need to dereference the function and can call it without *
   pNewFunction();

   void (*pAnotherNewFunction)(string) = call_name;
   pAnotherNewFunction("Martin");

   vector<string> people; people.reserve(10);
   people.push_back("Petr Novak");
   people.push_back("Martin Lopata");
   people.push_back("Ivana Frokova");
   people.push_back("Martin Steindl");

   cout << count_Martin(people, match) << endl;

   return 0; 
}



/////////////////////////////////////////////
///////////////---MAIN----///////////////////
/////////////////////////////////////////////

int main(){

//Introduction to pointers
general_concept();

//TODO: smart pointers
//smart_pointers();

//TODO: Finish
//Use of function pointers
function_pointers();


   return 0;
}
