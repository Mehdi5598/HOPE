#pragma once
#include "CL_CAD.h"
#include "CL_mapStock.h"

using namespace System;

namespace NS_svc																												         
{
	ref class CL_svcStock																									     
	{
	private:
		NS_Comp::CL_CAD^ oData;																									       
		NS_Comp::CL_mapStock^ oMappTB_Stock;																					       
	public:
		CL_svcStock(void);																									     
		Data::DataSet^ selectionnerTousLesStocks(String^);
		void ajouterArticle(String^ , int , int , double , float , float , float , float );		     
		void modifierArticle(int, String^, int, int, double, float, float, float, float);
		void supprimerArticle(int);																								      
	};
}