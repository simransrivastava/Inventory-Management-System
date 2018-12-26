#include "stdafx.h"
#include "Product.h"

void Product::setID(int productID)
{
	this->productID = productID;
}
void Product::setName(CString productName)
{
	this->productName = productName;
}
void Product::setPrice(float productPrice)
{
	this->productPrice = productPrice;
}
void Product::setQuantity(int productQuantity)
{
	this->productQuantity = productQuantity;
}
int Product::getID()
{
	return productID;
}
CString Product::getName()
{
	return productName;
}
float Product::getPrice()
{
	return productPrice;
}
int Product::getQuantity()
{
	return productQuantity;
}