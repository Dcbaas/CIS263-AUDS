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

template <typename T>

class AUDS{
public:
	/**************************************************************
 	*The constructor for AUDS creates an initial Array of size 100		
	*in the heap for use later. 
 	*	
 	*
 	*
 	************************************************************ */
	AUDS(){
		data = new T[structureSize];
	}

	~AUDS(){
		delete [] data;
	}

	AUDS(const AUDS &other){
		
	}

	AUDS& operator =(AUDS other){
		std::swap(data, other.data);
		std::swap(listSize, other.listSize);
		std::swap(structureSize, other.structureSize);

		return *this;
	}

	int size(){
		return listSize;
	}	

	void push(const T&  x){
		data[listSize++] = x;
		expandArray();	
	}

	T pop(){
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
	 *The private method expandArray is called everytime an element
	 *is added to the array to check if the array is full. If full,
	 *The array is expanded by 50% to accomidate more items
	 *
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

