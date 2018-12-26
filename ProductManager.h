#pragma once
#include "stdafx.h"
#include "product.h"

class ProductManager {
public:
	CList<Product, Product&> productList;
	static ProductManager* getInstance();
protected:
	ProductManager();
private:
	static ProductManager* instance;
};