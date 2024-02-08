#pragma once
#include "Product.h"
class Validate
{
public:
	static bool CheckId(vector<Product> p,int id) {
		int count = 0;
		for (int i = 0; i < p.size(); i++) {
			if (p[i].id == id) {
				count++;
			}
		}
		if (count == 0) {
			return true;
		}
		else
		{
			return false;
		}
	}


	static bool CheckName(vector<Product> p, string name) {
		int count = 0;
		for (int i = 0; i < p.size(); i++) {
			if (p[i].name == name) {
				count++;
			}
		}
		if (count == 0) {
			return true;
		}
		else
		{
			return false;
		}
	}
	

};

