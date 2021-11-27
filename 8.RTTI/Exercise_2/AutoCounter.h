//: C16:AutoCounter.h
#ifndef AUTOCOUNTER_H
#define AUTOCOUNTER_H

#include "require.h"
#include <iostream>
#include <set>
#include <string>



// First way
template <typename T>
class AutoCounter{
	// count for every input type has own
	static int count; // Number of all created objects of this type
	int id; // Unique number of concrete object
	template<typename Type>
	class CleanupCheck{
		std::set<AutoCounter<Type>*> trace;
		public:
		void add(AutoCounter<Type>* ap){
			trace.insert(ap);
		}
		void remove(AutoCounter<Type>* ap)
		{
			std::string err_msg = "Attempt to delete ";
			err_msg += typeid(Type).name(); 
			err_msg += " twice";
			// method erase of set in this version
			// erase this element and return erased 
			// number of element (0 or 1)
			require(trace.erase(ap) == 1,
					err_msg.c_str());
		}
		~CleanupCheck(){
			std::string err_msg = "All ";
			err_msg += typeid(Type).name();
			err_msg += " objects not cleaned up";
			std::cout << "~CleanupCheck()" << std::endl;
			require(trace.size() == 0,
					err_msg.c_str());
		}
	};
	static CleanupCheck<T> verifier;
	AutoCounter() : id(count++)
	{
		verifier.add(this); // Register itself
		std::cout << "created[" << id << "] of type " << typeid(T).name()
			<< std::endl;
	}
	// Prohibision of copy constructor and copy assignment operator
	AutoCounter(const AutoCounter<T>&);
	AutoCounter<T>& operator=(const AutoCounter<T>&);
	// From C++11 you can use delete key word
	public:
	//AutoCounter(const AutoCounter&) = delete;
	//AutoCounter& operator=(const AutoCounter&) = delete;
	// Object can be created only like:
	static AutoCounter<T>* create()
	{
		return new AutoCounter<T>();
	}
	~AutoCounter()
	{
		std::cout << "destroying[" << id
			<< "]" << " of type " << typeid(T).name() << std::endl;
		verifier.remove(this);
	}
	//template<typename Type>
	friend std::ostream& operator<<(std::ostream& os, 
			const AutoCounter<T>& ac){
		return os << "AutoCounter " << typeid(T).name() << " " << ac.id;
	}
	//template<typename Type>
	friend std::ostream& operator<<(std::ostream& os, 
			const AutoCounter<T>* ac){
		return os << "AutoCounter " << typeid(T).name() << " " << ac->id;
	}
};

template<typename T>
AutoCounter<T>::CleanupCheck<T> AutoCounter<T>::verifier;

template<typename T>
int AutoCounter<T>::count;


// Second way
//template <typename T>
//class AutoCounter{
//	// count for every input type has own
//	static int count; // Number of all created objects of this type
//	int id; // Unique number of concrete object
//	class CleanupCheck{
//		std::set<AutoCounter<T>*> trace;
//		public:
//		void add(AutoCounter<T>* ap){
//			trace.insert(ap);
//		}
//		void remove(AutoCounter<T>* ap)
//		{
//			std::string err_msg = "Attempt to delete ";
//			err_msg += typeid(T).name(); 
//			err_msg += " twice";
//			// method erase of set in this version
//			// erase this element and return erased 
//			// number of element (0 or 1)
//			require(trace.erase(ap) == 1,
//					err_msg.c_str());
//		}
//		~CleanupCheck(){
//			std::string err_msg = "All ";
//			err_msg += typeid(T).name();
//			err_msg += " objects not cleaned up";
//			std::cout << "~CleanupCheck()" << std::endl;
//			require(trace.size() == 0,
//					err_msg.c_str());
//		}
//	};
//	static CleanupCheck verifier;
//	AutoCounter() : id(count++)
//	{
//		verifier.add(this); // Register itself
//		std::cout << "created[" << id << "] of type " << typeid(T).name()
//			<< std::endl;
//	}
//	// Prohibision of copy constructor and copy assignment operator
//	AutoCounter(const AutoCounter<T>&);
//	AutoCounter<T>& operator=(const AutoCounter<T>&);
//	// From C++11 you can use delete key word
//	public:
//	//AutoCounter(const AutoCounter&) = delete;
//	//AutoCounter& operator=(const AutoCounter&) = delete;
//	// Object can be created only like:
//	static AutoCounter<T>* create()
//	{
//		return new AutoCounter<T>();
//	}
//	~AutoCounter()
//	{
//		std::cout << "destroying[" << id
//			<< "]" << " of type " << typeid(T).name() << std::endl;
//		verifier.remove(this);
//	}
//	//template<typename Type>
//	friend std::ostream& operator<<(std::ostream& os, 
//			const AutoCounter<T>& ac){
//		return os << "AutoCounter " << typeid(T).name() << " " << ac.id;
//	}
//	//template<typename Type>
//	friend std::ostream& operator<<(std::ostream& os, 
//			const AutoCounter<T>* ac){
//		return os << "AutoCounter " << typeid(T).name() << " " << ac->id;
//	}
//};
//
//template<typename T>
//typename AutoCounter<T>::CleanupCheck AutoCounter<T>::verifier;
//
//template<typename T>
//int AutoCounter<T>::count;


// Third way
// Using forward declaration
//template<typename T>
//class CleanupCheck;
//
//template <typename T>
//class AutoCounter{
//	// count for every input type has own
//	static int count; // Number of all created objects of this type
//	int id; // Unique number of concrete object
//	static CleanupCheck<T> verifier;
//	AutoCounter() : id(count++)
//	{
//		verifier.add(this); // Register itself
//		std::cout << "created[" << id << "] of type " << typeid(T).name()
//			<< std::endl;
//	}
//	// Prohibision of copy constructor and copy assignment operator
//	AutoCounter(const AutoCounter<T>&);
//	AutoCounter<T>& operator=(const AutoCounter<T>&);
//	// From C++11 you can use delete key word
//	public:
//	//AutoCounter(const AutoCounter&) = delete;
//	//AutoCounter& operator=(const AutoCounter&) = delete;
//	// Object can be created only like:
//	static AutoCounter<T>* create()
//	{
//		return new AutoCounter<T>();
//	}
//	~AutoCounter()
//	{
//		std::cout << "destroying[" << id
//			<< "]" << " of type " << typeid(T).name() << std::endl;
//		verifier.remove(this);
//	}
//	//template<typename Type>
//	friend std::ostream& operator<<(std::ostream& os, 
//			const AutoCounter<T>& ac){
//		return os << "AutoCounter " << typeid(T).name() << " " << ac.id;
//	}
//	//template<typename Type>
//	friend std::ostream& operator<<(std::ostream& os, 
//			const AutoCounter<T>* ac){
//		return os << "AutoCounter " << typeid(T).name() << " " << ac->id;
//	}
//};
//
//
//template<typename T>
//class CleanupCheck{
//	std::set<AutoCounter<T>*> trace;
//	public:
//	void add(AutoCounter<T>* ap){
//		trace.insert(ap);
//	}
//	void remove(AutoCounter<T>* ap)
//	{
//		std::string err_msg = "Attempt to delete ";
//		err_msg += typeid(T).name(); 
//		err_msg += " twice";
//		// method erase of set in this version
//		// erase this element and return erased 
//		// number of element (0 or 1)
//		require(trace.erase(ap) == 1,
//				err_msg.c_str());
//	}
//	~CleanupCheck(){
//		std::string err_msg = "All ";
//		err_msg += typeid(T).name();
//		err_msg += " objects not cleaned up";
//		std::cout << "~CleanupCheck()" << std::endl;
//		require(trace.size() == 0,
//				err_msg.c_str());
//	}
//};
//
//
//// Cleanup separate class - we need not to use AutoCounter::
//template<typename T>
//CleanupCheck<T> AutoCounter<T>::verifier;
//
//template<typename T>
//int AutoCounter<T>::count;



#endif
