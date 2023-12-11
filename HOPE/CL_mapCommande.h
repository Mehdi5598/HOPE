#pragma once

using namespace System;

namespace NS_Comp												           
{
	ref class CL_mapCommande									     
	{
	private:
		String^ sSql;
		int id_commande;										      
		int id_dateEmission;									         
		int id_dateLivraison;									         
		int id_client;											         
		String^ Ref;									          
		String^ PrenomClient;							            
		String^ NomClient;								            
		String^ AnneeCommande;							         
		String^ VilleLivraison;							            
		static int increment;									           
	public:
		String^ Select(void);							        				
		String^ Insert(void);							       
		String^ Delete(void);							        
		void setIdCommande(int);								        
		void setIdDateEmission(int);							        
		void setIdDateLivraison(int);							        
		void setIdClient(int);									        
		int getIdCommande(void);								       
		int getIdDateEmission(void);							       
		int getIdDateLivraison(void);							       
		int getIdClient(void);									       
		void setRef(String^);							         
		void setPrenomClient(String^);					        
		void setNomClient(String^);						        
		void setAnneeCommande(String^);					        
		void setVilleLivraison(String^);				        
		String^ getRef(void);							        
		String^ getPrenomClient(void);					       
		String^ getNomClient(void);						       
		String^ getAnneeCommande(void);					       
		String^ getVilleLivraison(void);				       
	};
}
