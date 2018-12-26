#pragma once
#include "stdafx.h"

class Product {
private:
	int productID;
	CString productName;
	float productPrice;
	int productQuantity;
public:
	void setID(int productID);
	void setName(CString productName);
	void setPrice(float productPrice);
	void setQuantity(int productQuantity);
	int getID();
	CString getName();
	float getPrice();
	int getQuantity();
	BOOL operator==(const Product& item) const
	{
		return (item.productID == productID);
	}	
};
