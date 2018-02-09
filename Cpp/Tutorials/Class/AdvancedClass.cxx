#include <iostream>
#include <assert.h>

//Concept of:
//1] nested template class
//2] ring buffer class,
//3] iteratable class (implementing range based for loop)
// Basicaly trying to make this work: for(ring<T>::iterator it = r.begin(), it != r.end(); ++it )


//Ring buffer class 
template<typename T>
class ring{
   private:

      int m_size;
      int m_position;
      T* m_values;
   public:

      //Nested template class
      class Iterator;

      //Constructor
      ring(int size) : m_size(size), m_position(0), m_values(NULL){
         m_values = new T[size];
      }

      //Destructor
      ~ring(){
         delete [] m_values;
      }

      int size() { return m_size; }
      void add(T value ){
         m_values[m_position++] = value; 
         if( m_position == m_size ) m_position = 0;
      }

      T &get(int pos) {
         assert(pos <= m_size); 
         return m_values[pos];
      }


      Iterator begin(){ return Iterator(0, *this); }
      Iterator end(){ return Iterator(m_size, *this);  }

      
};


//Nested template class
template<typename T>
class ring<T>::Iterator{
   private:
      int m_position;
      ring &m_ring;
   public:

      Iterator(int position, ring &aring) : m_position(position), m_ring(aring){}

      //if we include int argument or not actually diferentiate between prefix and postfix operator
      Iterator &operator++(int){
         ++m_position;
         return *this;
      }

      //Postfix
      Iterator &operator++(){
         ++m_position;
         return *this;
      }

      //Dereference
      T &operator*(){ return m_ring.get(m_position); }

      bool operator!=(const Iterator &other) const{ return m_position != other.m_position; }
};


int main(){



ring<std::string> texts(3);
texts.add("Mat");
texts.add("Jon");
texts.add("Candice");
texts.add("Agni");

for(int i=0; i< 3; ++i){
std::cout << texts.get(i) << std::endl;
}

//C++ 98
for(ring<std::string>::Iterator it = texts.begin(); it != texts.end(); ++it){
std::cout << *it << std::endl;
}

//C++ 11
for(auto val : texts) std::cout << val << std::endl;

return 0;
}
