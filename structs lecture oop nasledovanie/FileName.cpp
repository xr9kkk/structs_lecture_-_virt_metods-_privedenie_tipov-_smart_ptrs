#include <iostream>
#include"doc.h"
#include <memory>
#include <algorithm>

const int ARRAY_SIZE{ 5 };

//prividenie tipov
//1. (тип) <переменна€>
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
	//int x;
	char ch;
	std::weak_ptr<Elem> sh_ptr;
	std::weak_ptr<Elem> weak_ptr;
	/*Elem(int x, int y) : x(x) {
		this->y = std::move(std::make_unique<int>(y));
		this->z = new int(z);
	}*/
	Elem(char ch) : ch(ch)
	{
		std::cout << "elem " << ch << " was created\n";
	}

	~Elem()
	{
		std::cout << "elem " << ch << " was destroyed\n";
	}

	void set_ptr(std::shared_ptr<Elem> ptr)
	{
		sh_ptr = ptr;
	}

	const std::shared_ptr<Elem> get_ptr() const
	{
		return sh_ptr.lock();  
	}

	void set_weak_ptr(std::shared_ptr<Elem> ptr)
	{
		weak_ptr = ptr;
	}

	

	/*void print()
	{
		std::cout << x << " " << *y << " " << *z << "\n";
	}*/
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

void fill_and_print_array(std::unique_ptr<int[]> array, int n)
{
	array = std::make_unique<int[]>(n);
	for (size_t i{}; i < n; ++i)
	{
		array[i] = static_cast<int>(i * 2);
		std::cout << array[i] << ' ';
	}
	std::cout << '\n';
}

void fill_and_print_array(size_t tmp, std::unique_ptr<int[]> array = std::make_unique<int[]>(ARRAY_SIZE))
{
	for (size_t i{}; i < ARRAY_SIZE; ++i)
	{
		array[i] = static_cast<int>(tmp * 2);
		std::cout << array[i] << ' ';
		tmp += 3;
	}
	std::cout << '\n';
}
/////////////////////////////////////////////////////////////////

//std::unique_ptr<double> average(int* arr, int size)
//{
//	std::unique_ptr<double> result{};
//	double sum{};
//	int cnt{};
//	for (int i{}; i < size; ++i)
//	{
//		if (arr[i] % 2 == 0)
//		{
//			sum += arr[i];
//			cnt += 1;
//		}
//	}
//	if (cnt)
//	{
//		//std::unique_ptr<double> tmp(new double(sum / cnt));
//		/*std::unique_ptr<double> tmp = std::make_unique<double>(sum / cnt);
//		result = std::move(tmp);*/
//		result = std::move(std::make_unique<double>(sum / cnt));
//	}
//	return result;
//}
//
//void foo(std::unique_ptr<Elem> ptr)
//{
//	if (ptr)
//		std::cout << ptr->x << '\n';
//}


//std::unique_ptr<int> foo(int x)
//{
//	return std::make_unique<int>(x);
//}





int main()
{
	/*ptrA arr[3] = { new A(9), new B({3, 'Z'}), new C({5, "abc"}) };
	print_arr(arr, 3);

	if (typeid(*arr[2]) == typeid(C))
		((C*)(arr[2]))->met("***");

	if (C* ptr = dynamic_cast<C*>(arr[2]))
		(ptr)->met("+++");

	if (C* ptr = reinterpret_cast<C*>(arr[0]))
		(ptr)->met("ooo");
	std::cout << std::endl << "------------------------\nSmart pointers\n------------------------\n";*/
	//------------------------------------
	//smart ptrs
	/*std::unique_ptr<Elem> ptr1(new Elem(5));
	std::unique_ptr<Elem> ptr2;

	ptr2 = std::move(ptr1);
	auto ptr3 = std::move(ptr2);
	std::cout << ptr3->x << std::endl;
	std::cout << "----------------------" << std::endl;

	std::unique_ptr<int> ptr_int = std::make_unique<int>(5);
	std::unique_ptr<Elem> ptr_Elem = std::make_unique<Elem>(5);*/

	//smart ptrs and dynamic arrays

	/*std::unique_ptr<int[]> darray(new int[5]);
	std::unique_ptr<int[]> darray2 = std::make_unique<int[]>(5);
	auto darr3 = std::make_unique<int[]>(6);
	std::unique_ptr <int[]> darr;

	fill_and_print_array({}, 3);
	fill_and_print_array(std::move(darr), 10);
	fill_and_print_array(std::make_unique<int[]>(ARRAY_SIZE), 5); 
	fill_and_print_array(3);
	fill_and_print_array();

	int arr6[7];
	std::unique_ptr<double> ptr_double = average(arr6, 7);
	if (ptr_double)
		std::cout << *ptr_double << ' ' << *ptr_double.get() << '\n';
	else
		std::cout << "No!\n";*/

	/*auto ptr = std::make_unique < Elem>(5);
	foo(std::move(ptr));*/

	/*Elem elem(1, 2, 3);
	elem.print();
	
	int* ptr_int = new int(5);
	std::unique_ptr<int> ptr1 = std::make_unique<int>(*ptr_int);
	std::unique_ptr<int> ptr2 = std::make_unique<int>(*ptr_int);
	std::cout << ptr_int << "\n";
	std::cout << ptr1.get()<< "\n";
	std::cout << ptr2.get() << "\n";
	delete ptr_int;*/
	/////////////////////////////shared_ptrs

	/*int* ptr_int = new int(5);
	{
		std::shared_ptr<int> ptr2(ptr1);
		std::shared_ptr<int> ptr2 = ptr1;
		auto ptr2 = ptr1;
		std::cout << ptr_int << "\n";
		std::cout << ptr1.get() << "\n";
		std::cout << ptr2.get() << "\n";
	}*/

	/*std::unique_ptr<int> ptr1 = std::make_unique<int>(7);
	std::shared_ptr<int> ptr2 = std::move(ptr1);

	if (!ptr1)
		std::cout << " ptr1 = nullptr!\n";

	std::unique_ptr<int> uptr = foo(5);
	std::shared_ptr<int> sptr = foo(7);*/

	//shared ne unichtozitsya dolzhim obrazom po dvum prichinam 1: bil cozdan dinamicheski i ne udalen dolzhnim obrazom 2: bil chast`iu ob`ekta kotoriy ne bil udalen korrektno. pri rabote s shared ptrom neobhodimo udalyat vse ukazateli vladeushie resursom

	{
		std::shared_ptr<Elem> elemA = std::make_shared<Elem>('a');
		auto elemB = std::make_shared<Elem>('b');

		elemA->set_ptr(elemB);  // ”станавливаем сильную ссылку
		elemB->set_weak_ptr(elemA);
		std::cout << elemA->sh_ptr.lock()<<"\n";
	}

	return 0;
}	