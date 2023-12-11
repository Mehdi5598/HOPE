#pragma once

using namespace  System;
namespace NS_Comp													           
{
	ref class CL_mapPersonnel										     
	{
	private:
	    String^ sSql;
		int id_personnel;											      
		String^ Prenom;										         
		String^ Nom;										         
		int id_personnel_1;										         
		int id_adresse;												      
		int id_date;												      
	public:
		String^ Select(void);								       
		String^ Insert(void);								       
		String^ Delete(void);								        
		void setId_Personnel(int);									        
		void setNom(String^);								        
		void setPrenom(String^);							        
		void setid_personnel_1(int);								        
		void setId_adresse(int);									        
		void setId_date(int);										        
		int getId_Personnel(void);									       
		String^ getNom(void);								       
		String^ getPrenom(void);							       
		int getid_personnel_1(void);								       
		int getId_adresse(void);									       
		int getId_date(void);										       
	};
}
