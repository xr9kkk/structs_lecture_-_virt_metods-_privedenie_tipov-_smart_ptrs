#include <iostream>
#include"doc.h"
#include <memory>

const int ARRAY_SIZE{ 5 };

//prividenie tipov
//1. (тип) <переменная>
//2. static_cast <Type> (<peremennaya>)
//3. dynamic_cast <Type_of_pointer_on_object> (<Pointer_on_object>) 
//4. reinterpret_cast <Type_of_pointer_on_object> (<Pointer_on_object_or_integral_type>)
 

class A {
private:
	int x{};
protected:
	int y{};
public:
	A() {};
	A(int x) :x(x) {};
	virtual void print() 
	{
		std::cout << "Number = " << x << std::endl;
	}
};

class B : public A {
private:
	char ch;
public:
	B(int x, char ch) : A(x), ch(ch) {} 
	void print()
	{
		A::print();
		std::cout << "Symbol = " << ch << std::endl;
	}
};

class C : public A
{
private:
	std::string line;
public:
	C(int x, std::string line) : A(x), line(line) {}
	void print()
	{
		A::print();
		std::cout << "String = " << line << std::endl;
	}

	void met(const std::string str)
	{
		std::cout << str << std::endl;
	}
};

using ptrA = A*;

void print_arr(ptrA* arr, int size)
{
	for (int i{}; i < size; ++i)
	{
		arr[i]->print();
		std::cout << "-------------------" << std::endl;
	}
}
//--------------------------------------------------------------------------
// umnie ukazateli

struct Elem
{
public:
	int x;
	Elem(int x) : x(x) {}
};

/////////////////////////////////////////////

void fill_and_print_array(std::unique_ptr<int[]> array = nullptr, size_t tmp = 0) {
	if (!array) {
		array = std::make_unique<int[]>(ARRAY_SIZE);
	}
	for (size_t i = 0; i < ARRAY_SIZE; i++) {
		array[i] = static_cast<int>(tmp * 2);
		std::cout << array[i] << ' ';
		tmp++;
	}
	std::cout << std::endl;
}

int main()
{
	ptrA arr[3] = { new A(9), new B({3, 'Z'}), new C({5, "abc"}) };
	print_arr(arr, 3);

	if (typeid(*arr[2]) == typeid(C))
		((C*)(arr[2]))->met("***");

	if (C* ptr = dynamic_cast<C*>(arr[2]))
		(ptr)->met("+++");

	if (C* ptr = reinterpret_cast<C*>(arr[0]))
		(ptr)->met("ooo");
	std::cout << std::endl << "------------------------\nSmart pointers\n------------------------\n";
	//------------------------------------
	//smart ptrs
	std::unique_ptr<Elem> ptr1(new Elem(5));
	std::unique_ptr<Elem> ptr2;

	ptr2 = std::move(ptr1);
	auto ptr3 = std::move(ptr2);
	std::cout << ptr3->x << std::endl;
	std::cout << "----------------------" << std::endl;

	std::unique_ptr<int> ptr_int = std::make_unique<int>(5);
	std::unique_ptr<Elem> ptr_Elem = std::make_unique<Elem>(5);

	//smart ptrs and dynamic arrays

	std::unique_ptr<int[]> darray(new int[5]);
	std::unique_ptr<int[]> darray2 = std::make_unique<int[]>(5);
	auto darr3 = std::make_unique<int[]>(6);


	fill_and_print_array({}, 3);
	fill_and_print_array(std::make_unique<int[]>(ARRAY_SIZE), 5); 
	fill_and_print_array(); 
	

	return 0;
}	