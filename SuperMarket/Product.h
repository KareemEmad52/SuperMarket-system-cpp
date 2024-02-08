#pragma once
#include <bits/bits-stdc++.h>
using namespace std;
class Product
{
public:
	string name;
	int id;
	double price;

	Product() {
		name = " ";
		id = 0;
		price = 0.0;
	}
	Product(string name,int id,double price) {
		this->name = name;
		this->id = id;
		this->price = price;
	}
};
static fstream myfile;
