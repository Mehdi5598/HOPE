#pragma once
using namespace System;

namespace NS_Comp
{
	ref class CL_mapAdresse
	{
	private:
		String^ sSql;
		int id_adresse;
		String^ Rue;
		String^ Ville;
		int Cp;
		int id_adresseLiv;										            
		int id_adresseFact;
	public:
		CL_mapAdresse(void);
		String^ Insert(void);
		String^ Update(void);
		void setIdAdresse(int);
		void setRue(String^);
		void setVille(String^);
		void setCp(int);
		void setIdAdresseLiv(int);								        
		void setIdAdresseFact(int);
		int getIdAdresse(void);
		String^ getRue(void);
		String^ getVille(void);
		int getCp(void);
		int getIdAdresseLiv(void);								       
		int getIdAdresseFact(void);	
	};
}

