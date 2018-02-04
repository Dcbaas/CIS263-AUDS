 /************************************************************************
 *The AUDS class defines the Almost Useless Data Structure. It takes a 
 *generic data type and stores it in a data stucture that is basically
 *an ArrayList data type from Java.
 *
 *Author: David Baas
 *Version: 1.0
 *
 **********************************************************************/

#include <cstdlib>
#include <exception>
#include <stdexcept>

template <typename T>

class AUDS{
public:
	/**************************************************************
 	*The constructor for AUDS creates an initial Array of size 100		
	*in the heap for use later. 
	**************************************************************/
	AUDS(){
		data = new T[structureSize];
	}

	/**************************************************************
	 *The destructor removes the array created in the heap.
 	**************************************************************/
	~AUDS(){
		delete [] data;
	}
	/**************************************************************
 	*The copy constructor creates a deep copy of an AUDS obeject 
 	*when it is initializied as equal to a different AUDS object.
        ***************************************************************/
	AUDS(const AUDS &other){
		structureSize = other.structureSize;
		listSize = other.listSize;
		data = new T[structureSize];
		for(int i{0}; i < listSize; i++){
			data[i] = other.data[i];
		}	
	}
	/**************************************************************
	*The copy operator creates a deep copy of an AUDS object when
 	*this AUDS object is set equal to it using the '=' symbol
	*
	*@return *this instance of AUDS
	*
 	**************************************************************/
	AUDS& operator =(AUDS other){
		std::swap(data, other.data);
		std::swap(listSize, other.listSize);
		std::swap(structureSize, other.structureSize);

		return *this;
	}

	/**************************************************************
	*The size method returns the size of the list.
	*
	*@return listSize int that is the size of the list.
 	***************************************************************/
	int size(){
		return listSize;
	}	

	/*************************************************************
 	*The push method adds a new element to the data list. The 
 	*item is added to the end of the list. Following the item 
	*being added to the list, the method expandArray is called
	*to check if the data structure itself is full and needs to
	*be expanded. 
	*
	*@param &x the address of a generic object being added.
	*************************************************************/
	void push(const T&  x){
		data[listSize++] = x;
		expandArray();	
	}

	/*************************************************************
 	* The pop method take a random element in the list and returns
 	* and removes it from the list. The element being removed is
 	* overwritten by the item in the last index filled. Following
 	* that, the last index filled is no longer referenced 
	* by the listSize counter; allowing it to be removed when 
	* another pushed item overwites it. If there is an attempt 
	* to pop from an empty list a runtime exception is thrown.
	*
	* @return random element of type T
	* @throws runtime_error if pop is invoked on an empty list.  
 	*************************************************************/
	T pop(){
		if(listSize == 0)
	 		throw std::runtime_error("There is no list");	
			
		int removed = rand() % listSize;
		T popped = data[removed];
		data[removed] = data[listSize--];
		return popped;
	}

private:
	//A integer to track the size of the data structure itself
	//This will be different to the size of the list.
	int structureSize{100};

	//A integer to track the size of the list
	int listSize{0};
	
	//A generic type data structure that is defined in the 
	//constructor and expanded as needed.
	T* data;

	/**************************************************************
	 * The private method expandArray is called everytime an element
	 * is added to the array to check if the array is full. If full,
	 * The array is expanded by 50% to accomidate more items
	 *************************************************************/
	void expandArray(){
		if(listSize == structureSize - 1){
			structureSize *= 1.5;
			T* temp = new T[structureSize];

			//Trasnfer the elements of data into the new list
			for(int i{0};i <= listSize; i++){
				temp[i] = data[i];
			}
			//Delete the old list and set data to point to temp
			delete[] data;
			
			data = temp; 	
		}
	}
};
