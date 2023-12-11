#pragma once
using namespace System;
namespace NS_Comp									           
{
	ref class CL_mapStock							     
	{
	private:
		String^ sSql;
		int id_articles;							      
		String^ nom_article;					         
		double remis;						         
		int Stock;								         
		int SeuilReap;								           					         
		float Taux_tva;								           
		float Prix_HT;						           			           
		float Prix_TVA;					           
	public:
		String^ Select(void);				       
		String^ Insert(void);				       
		String^ Update(void);				        
		String^ Delete(void);				        
		void setIdArticles(int);					        
		void setnom(String^);				        
		void setRemis(double);			        
		void setStock(int);						        
		void setSeuilReap(int);						        			        
		void setTauxTVA(float);						        
		void setPrixHT(float);				        				        
		void setPrixTVA(float);				        
		int getIdArticles(void);					       
		String^ getnom(void);				       
		double gettRemis(void);			       
		int getStock(void);						       
		int getSeuilReap(void);						    			       
		float getTauxTVA(void);						       
		float getPrixHT(void);				       				       
		float getPrixTVA(void);				       
	};
}

