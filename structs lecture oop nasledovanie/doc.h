#pragma once
#include<iostream>
#include<string>

template <typename T = int>
class Document
{
public:
	Document(T number, std::string other) : number(number), other(other) {}
	~Document() {}
	void print() const;
private:
	T number;
	std::string other;


};

template<typename T>
inline void Document<T>::print() const
{
	std::cout << number << '\n';
	std::cout << other << '\n';
}
