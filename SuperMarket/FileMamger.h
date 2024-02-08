#pragma once
#include "Product.h"
#include "Validate.h"
class FileMamger
{
public:
	

	static vector<string> Splited(string line) {
		vector<string> returnedvector;
		string part;
		stringstream ss(line);
		while (getline(ss, part, '|'))
		{
			returnedvector.push_back(part);
		}
		return returnedvector;
	}
	

	static vector<Product> ParseToClient() {
		string lines;
		vector<Product> c;
		Product b;
		vector<string> splitedvector;
		myfile.open("product.txt", ios::in);
		while (getline(myfile, lines, '\n'))
		{
			splitedvector = Splited(lines);
			b.name = splitedvector[0];
			b.id = stod(splitedvector[1]);
			b.price = stod(splitedvector[2]);
			c.push_back(b);
		}
		myfile.close();
		return c;
	}


	static void SaveLast(vector<Product> b) {
		myfile.open("product.txt", ios::out);
		for (int i = 0; i < b.size(); i++)
		{
			myfile << b[i].name << "|" << b[i].id << "|" << b[i].price << endl;
		}
		myfile.close();
	}
	static void ShowProduct() {
		vector<Product> mm = FileMamger::ParseToClient();
		system("cls");
		cout << "<------------------- Welcome To Market ------------------->" << endl;
		int x = 0;
		for (int i = 0; i < mm.size(); i++) {
			cout << x + 1 << "- " << mm[i].name <<  "[" << mm[i].id << "]" << " ----> " << mm[i].price << "L.E" << endl;
			x++;
		}
	}


	static void AddProduct(Product p) {
		vector<Product> mm = FileMamger::ParseToClient();
		if (Validate::CheckId(mm, p.id) && Validate::CheckName(mm, p.name)) {
			mm.push_back(p);
		}
		else {
			cout << "The Name or Id Is Aleady avilabile " << endl;
		}
		FileMamger::SaveLast(mm);
	}



	static Product SearchProduct(int id) {
		vector<Product> mm = FileMamger::ParseToClient();
		Product p;
		for (int i = 0; i < mm.size(); i++) {
			if (mm[i].id == id) {
				p.name = mm[i].name;
				p.id = mm[i].id;
				p.price = mm[i].price;
				break;
				
			}
		}
		return p;
	}

	static Product SearchProduct(string name) {
		vector<Product> mm = FileMamger::ParseToClient();
		Product p;
		for (int i = 0; i < mm.size(); i++) {
			if (mm[i].name == name) {
				p.name = mm[i].name;
				p.id = mm[i].id;
				p.price = mm[i].price;
				break;

			}
		}
		return p;
	}


	static double CartCalc(vector<Product> p) {
		double sum = 0;
		for (int i = 0; i < p.size(); i++) {
			sum = sum + p[i].price;
		}
		return sum;
	}

};

