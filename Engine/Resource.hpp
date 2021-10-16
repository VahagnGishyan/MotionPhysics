
#ifndef RESOURCE
#define RESOURCE

#include <iostream>

namespace Engine
{
    namespace Resources
    {
	using Resource = int;

	using Food = Resource;
	using Wood = Resource;
	using Stone = Resource;
	using Coal = Resource;
	using Iron = Resource;
	using Gold = Resource;

	enum Range
	{
	    Min = 0,
	    Max = 10000
	};

	namespace Manager
	{
	    Resource    Make(int var);
	}
    }
}

#endif // !RESOURCE





//class Resource;
//
//class Food;
//class Wood;
//class Stone;
//class Coal;
//class Iron;
//class Gold;


//class Resource
//{
//private:
//	int	m_value;
//
//public:
//	Resource(int value = 0);
//	Resource(const Resource& cp);
//	Resource(const Resource&& mv);
//
//	//Input, Output
//	friend std::ostream& operator<< (std::ostream &out, const Resource&point);
//	friend std::ostream& operator>> (std::ostream &in, const Resource&point);
//
//	//Assignments
//	Resource& operator=  (const Resource& drob);
//	Resource& operator=  (const Resource&& drob);
//
//	Resource& operator+= (const Resource& drob);
//	Resource& operator-= (const Resource&& drob);
//	Resource& operator*= (const Resource& drob);
//	Resource& operator/= (const Resource&& drob);
//	Resource& operator%= (const Resource& drob); 
//
//	bool operator&& (const Resource&& drob);
//	bool operator|| (const Resource& drob);
//
//	//Comparisons with Resource
//	bool operator== (const Resource& var);
//	bool operator!= (const Resource& var);
//	bool operator>  (const Resource& var);
//	bool operator<  (const Resource& var);
//	bool operator>= (const Resource& var);
//	bool operator<= (const Resource& var);
//
//	Resource operator+  (const Resource& drob);
//	Resource operator-  (const Resource&& drob);
//	Resource operator*  (const Resource& drob);
//	Resource operator/  (const Resource&& drob);
//	Resource operator%  (const Resource& drob);
//		
//
//	// SecondParameterInt
//	Resource& operator=  (const int& drob);
//
//
//	bool operator== (const int& var);
//	bool operator!= (const int& var);
//	bool operator>  (const int& var);
//	bool operator<  (const int& var);
//	bool operator>= (const int& var);
//	bool operator<= (const int& var);
//
//	Resource operator+  (const int& drob);
//	Resource operator-  (const int&& drob);
//	Resource operator*  (const int& drob);
//	Resource operator/  (const int&& drob);
//	Resource operator%  (const int& drob);
//
//	Resource& operator+= (const int& drob);
//	Resource& operator-= (const int&& drob);
//	Resource& operator*= (const int& drob);
//	Resource& operator/= (const int&& drob);
//	Resource& operator%= (const int& drob);
//
//	bool operator&& (const int&& drob);
//	bool operator|| (const int& drob);
//
//
//	//Comparisons with int 
//	friend bool operator== (const int& var, const Resource& obj);
//	friend bool operator!= (const int& var, const Resource& obj);
//	friend bool operator>  (const int& var, const Resource& obj);
//	friend bool operator<  (const int& var, const Resource& obj);
//	friend bool operator>= (const int& var, const Resource& obj);
//	friend bool operator<= (const int& var, const Resource& obj);
//
//	friend Resource operator+  (const int& drob, const Resource& obj);
//	friend Resource operator-  (const int&& drob, const Resource& obj);
//	friend Resource operator*  (const int& drob, const Resource& obj);
//	friend Resource operator/  (const int&& drob, const Resource& obj);
//	friend Resource operator%  (const int& drob, const Resource& obj);
//
//	friend int& operator+= (int& drob, const Resource& obj);
//	friend int& operator-= (int&& drob, const Resource& obj);
//	friend int& operator*= (int& drob, const Resource& obj);
//	friend int& operator/= (int&& drob, const Resource& obj);
//	friend int& operator%= (int& drob, const Resource& obj);
//
//	friend bool operator&& (const int&& drob, const Resource& obj);
//	friend bool operator|| (const int& drob, const Resource& obj);
//};
//
//
