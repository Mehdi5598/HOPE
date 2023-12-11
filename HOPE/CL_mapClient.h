#pragma once
#include "CL_mapAdresse.h"
#include "CL_mapDate.h"

using namespace System;

namespace NS_Comp												           
{
	ref class CL_mapClient									     
	{
	private:
		String^ sSql;
		int id_client;											      
		String^ Nom;									         
		String^ Prenom;									         
		int id_dateAnniv;										            
		int id_datePremierAchat;								              
	public:
		String^ Select(void);							       
		String^ Insert(void);							       
		String^ Delete(void);							        
		void setIdClient(int);									        
		void setNom(String^);							        
		void setPrenom(String^);						        								        
		void setIdDateAnniv(int);								        
		void setIdDatePremierAchat(int);						        
		int getIdClient(void);									       
		String^ getNom(void);							       
		String^ getPrenom(void);						       							       
		int getIdDateAnniv(void);								       
		int getIdDatePremierAchat(void);						       
	};
}

