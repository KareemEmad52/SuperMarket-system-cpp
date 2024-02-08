#include <bits/bits-stdc++.h>
#include "FileMamger.h"
using namespace std;


vector<Product> productcart;


void AddProduct();
void AddToCart();
void SearchProduct();

void Screen1() {
	int x;
	system("cls");
	cout << "<------------------- Welcome To Market ------------------->" << endl;
	cout << "1- Show All Products " << endl;
	cout << "2- Add New Product" << endl;
	cout << "3- Search For Product" << endl;
	cout << "4- Exit" << endl;
	cout << "Enter Your Choice : ";
	cin >> x;
	switch (x)
	{
	case 1:
		AddToCart();
		break;
	case 2:
		AddProduct();
		break;
	case 3:
		SearchProduct();
		break;
	default:
		break;
	}

}



void SearchById() {
	system("cls");
	cout << "<------------------- Welcome To Market ------------------->" << endl;
	cout << "Enter Product Id : ";
	int x;
	cin >> x;
	cout << "------------------------------------------" << endl;
	cout << "Product Name : " << FileMamger::SearchProduct(x).name << endl;
	cout << "Product Id : " << FileMamger::SearchProduct(x).id << endl;
	cout << "Product Price : " << FileMamger::SearchProduct(x).price << endl;
	cout << "------------------------------------------" << endl;
}


void SearchByName() {
	system("cls");
	cout << "<------------------- Welcome To Market ------------------->" << endl;
	cout << "Enter Product Name : ";
	string name;
	cin >> name;
	cout << "------------------------------------------" << endl;
	cout << "Product Name : " << FileMamger::SearchProduct(name).name << endl;
	cout << "Product Id : " << FileMamger::SearchProduct(name).id << endl;
	cout << "Product Price : " << FileMamger::SearchProduct(name).price << endl;
	cout << "------------------------------------------" << endl;
}

void loop1() {
	cout << "1- Search For Another Product " << endl;
	cout << "2- Return " << endl;
	int x;
	cin >> x;
	switch (x)
	{
	case 1:
		SearchById();
		loop1();
		break;
	case 2:
		SearchProduct();
		break;
	default:
		break;
	}
}
void SearchProduct() {
	system("cls");
	cout << "<------------------- Welcome To Market ------------------->" << endl;
	cout << "1- Search By Id " << endl;
	cout << "2- Search By Name " << endl;
	cout << "3- Return" << endl;
	cout << "------------------------------------------" << endl;
	cout << "Enter Your Choice : ";
	int x;
	cin >> x;
	switch (x)
	{
	case 1:
		SearchById();
		loop1();
		break;
	case 2:
		SearchByName();
		cout << "1- Search For Another Product " << endl;
		cout << "2- Return " << endl;
		cin >> x;
		switch (x)
		{
		case 1:
			SearchByName();
			break;
		case 2:
			SearchProduct();
			break;

		default:
			break;
		}
		break;
	case 3:
		Screen1();
	default:
		break;
	}
}

void AddToCart() {
	FileMamger::ShowProduct();
	vector<Product> mm = FileMamger::ParseToClient();
	cout << "------------------------------------------" << endl;
	cout << "Enter The Id To Add To Cart : ";
	int x;
	cin >> x;
	cout << "### Added Successfully ###" << endl;
	productcart.push_back(FileMamger::SearchProduct(x));
	cout << "------------------------------------------" << endl;
	cout << "1- Add Another Product To Cart " << endl;
	cout << "2- Show Total Cost  " << endl;
	cout << "3- Return " << endl;
	cout << "Enter Your Choice : ";
	cin >> x;
	switch (x)
	{
	case 1:
		cout << "Enter The Id To Add To Cart : ";
		AddToCart();
		break;
	case 2:
		cout <<"----> The Total Cost = " << FileMamger::CartCalc(productcart) << endl;
		break;
	case 3:
		Screen1();
	default:
		break;
	}

}


void AddProduct() {
	system("cls");
	cout << "<------------------- Welcome To Market ------------------->" << endl;
	Product m;
	cout << "Enter Product Name : ";
	cin >> m.name;
	cout << "Enter Product Id : ";
	cin >> m.id;
	cout << "Enter Product Price : ";
	cin >> m.price;
	FileMamger::AddProduct(m);
	cout << "--------------------------" << endl;
	cout << "1- Enter Another Product" << endl;
	cout << "2- Return " << endl;
	int x;
	cout << "Enter Your Choice : ";
	cin >> x;
	switch (x)
	{
	case 1:
		AddProduct();
		break;
	case 2:
		Screen1();
		break;
	default:
		break;
	}
}




int main()
{
	

	Screen1();
	

	
}

