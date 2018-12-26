#include "stdafx.h"
#include "ProductManager.h"

ProductManager::ProductManager() {

}

ProductManager* ProductManager::instance = NULL;

ProductManager* ProductManager::getInstance()
{
	if (instance == NULL)
	{
		instance = new ProductManager;
	}
	return instance;
}