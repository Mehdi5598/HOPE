#pragma once
#include "CL_mapPersonnel.h"
#include "CL_mapAdresse.h"
#include "CL_mapDate.h"
#include "CL_CAD.h"

using namespace System;

namespace NS_svc																																	           
{
	ref class CL_svcPersonnel																													     
	{
	private:
		NS_Comp::CL_CAD^ oData;																														       
		NS_Comp::CL_mapPersonnel^ oMappTB_Personnel;																								       
		NS_Comp::CL_mapAdresse^ oMappTB_Adresse;																									       
		NS_Comp::CL_mapDate^ oMappTB_Date;																										       
	public:
		CL_svcPersonnel(void);																													     
		Data::DataSet^ selectionnerToutesLesPersonnes(String^);																		     
		void ajouterUnePersonne(String^, String^, int, String^, String^, int, String^);			     
		void modifierPersonnel(int, String^, String^, int, String^, String^, int, String^);		      
		void supprimerPersonnel(int);																												      
	};
}
