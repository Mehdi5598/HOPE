#pragma once
#include "CL_CAD.h"
#include "CL_mapCommande.h"
#include "CL_mapDate.h"

using namespace System;

namespace NS_svc																																	           
{
	ref class CL_svcCommande																														     
	{
	private:
		NS_Comp::CL_CAD^ oData;																														       
		NS_Comp::CL_mapCommande^ oMappTB_Commande;																								       
		NS_Comp::CL_mapDate^ oMappTB_DateEmission;																								       
		NS_Comp::CL_mapDate^ oMappTB_DateLivraison;																								       
		String^ Reference;																													   
		int increment;																																   
	public:
		CL_svcCommande(void);																													     
		Data::DataSet^ selectionnerToutesLesCommandes(String^);																		     
		void ajouterCommande(String^, String^, String^,String^, String^, String^, int);			     
		void modifierCommande(int, String^, String^, String^, String^, String^, String^, int);		      
		void supprimerCommande(int);																												      

		void setReference();																														    
		String^ getReference(void);																											    
	};
}