#pragma once
#include "CL_mapClient.h"
#include "CL_mapAdresse.h"
#include "CL_mapDate.h"
#include "CL_CAD.h"

using namespace System;
namespace NS_svc																																											           
{
	ref class CL_svcClient																																								     
	{
	private:
		NS_Comp::CL_CAD^ oData;																																								       
		NS_Comp::CL_mapClient^ oMappTB_Client;																																			       
		NS_Comp::CL_mapAdresse^ oMappTB_Adresse_liv;																																       
		NS_Comp::CL_mapAdresse^ oMappTB_Adresse_fact;																															       
		NS_Comp::CL_mapDate^ oMappTB_Date_anniv;			 																													       
		NS_Comp::CL_mapDate^ oMappTB_Date_Premier_achat;	  																											       
	public:
		CL_svcClient(void);																																								     
		Data::DataSet^ selectionnerTousLesClients(String^);																													     
		void ajouterUnClient(String^, String^, String^, String^, int, String^, String^, int, String^, String^);				     
		void modifierUnClient(int, String^, String^, String^, String^, int, String^, String^, int, String^, String^);		      
		void supprimerUnClient(int);																																						      
	};
}
