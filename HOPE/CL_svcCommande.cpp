#include "CL_svcCommande.h"


namespace NS_svc {
	CL_svcCommande::CL_svcCommande(void)
	{
		this->oData = gcnew NS_Comp::CL_CAD();													            
		this->oMappTB_Commande = gcnew NS_Comp::CL_mapCommande();								            
		this->oMappTB_DateEmission = gcnew NS_Comp::CL_mapDate();								            
		this->oMappTB_DateLivraison = gcnew NS_Comp::CL_mapDate();							            
	}

	Data::DataSet^ CL_svcCommande::selectionnerToutesLesCommandes(String^ dataTableName)
	{
		String^ sql;																	        

		sql = this->oMappTB_Commande->Select();													      
		return this->oData->getRows(sql, dataTableName);										        
	}

	void CL_svcCommande::ajouterCommande(String^ PrenomClient, String^ NomClient, String^ DateCommande, String^ VilleLivraison, String^ dateEmission, String^ dateLivraison, int id_Client)
	{
		String^ sql;																	        
		int id_dateEm;																			      
		int id_dateLiv;																			      

		this->oMappTB_Commande->setPrenomClient(PrenomClient);									          		
		this->oMappTB_Commande->setNomClient(NomClient);										          	
		this->oMappTB_Commande->setAnneeCommande(DateCommande);									          	
		this->oMappTB_Commande->setVilleLivraison(VilleLivraison);								          	
		this->setReference();																	       

		this->oMappTB_DateEmission->setDate(dateEmission);										          

		sql = this->oMappTB_DateEmission->Insert();												      
		id_dateEm = this->oData->actionRowsID(sql);												               

		this->oMappTB_DateLivraison->setDate(dateLivraison);									          

		sql = this->oMappTB_DateLivraison->Insert();											      
		id_dateLiv = this->oData->actionRowsID(sql);											               

		this->oMappTB_Commande->setRef(this->getReference());									          	
		this->oMappTB_Commande->setIdDateEmission(id_dateEm);									          	
		this->oMappTB_Commande->setIdDateLivraison(id_dateLiv);									          	
		this->oMappTB_Commande->setIdClient(id_Client);											          

		sql = this->oMappTB_Commande->Insert();													      
		this->oData->actionRows(sql);															      
	}

	void CL_svcCommande::modifierCommande(int id_commande, String^ PrenomClient, String^ NomClient, String^ DateCommande, String^ VilleLivraison,String^ dateEmission, String^ dateLivraison, int Id_Client)
	{
		String^ sql;																	        

		this->oMappTB_Commande->setIdCommande(id_commande);										          
		this->oMappTB_Commande->setPrenomClient(PrenomClient);									          
		this->oMappTB_Commande->setNomClient(NomClient);										          	
		this->oMappTB_Commande->setAnneeCommande(DateCommande);									          	
		this->oMappTB_Commande->setVilleLivraison(VilleLivraison);								          	
		this->oMappTB_Commande->setIdClient(Id_Client);											          
		this->setReference();																	       

		this->oMappTB_DateEmission->setDate(dateEmission);										          

		this->oMappTB_DateLivraison->setDate(dateLivraison);									          

		this->oMappTB_Commande->setRef(this->getReference());									          

		sql = "UPDATE Commande" +
			" SET Reference='" + this->oMappTB_Commande->getRef() + "'" +
			" WHERE(Commande.Id_commande='" + this->oMappTB_Commande->getIdCommande() + "')" +
			" UPDATE Date" +
			" SET Date='" + this->oMappTB_DateEmission->getDate() + "'" +
			" FROM Date INNER JOIN Commande ON Date.Id_date = Commande.Id_date"
			" WHERE(Commande.Id_commande='" + this->oMappTB_Commande->getIdCommande() + "')" +
			" UPDATE Date" +
			" SET Date='" + this->oMappTB_DateLivraison->getDate() + "'" +
			" FROM Date INNER JOIN Commande ON Date.Id_date = Commande.Id_date_livre_le"
			" WHERE(Commande.Id_commande='" + this->oMappTB_Commande->getIdCommande() + "')";

		this->oData->actionRows(sql);															      
	}

	void CL_svcCommande::supprimerCommande(int id_commande)
	{
		String^ sql;																	        

		this->oMappTB_Commande->setIdCommande(id_commande);										          

		sql = this->oMappTB_Commande->Delete();													       
		this->oData->actionRows(sql);															      
	}

	void CL_svcCommande::setReference()
	{
		this->Reference = "";																	    
		for (int i = 0; i < 2; i++)
		{
			this->Reference += this->oMappTB_Commande->getPrenomClient()[i];
		}
		for (int i = 0; i < 2; i++)
		{
			this->Reference += this->oMappTB_Commande->getNomClient()[i];
		}
		for (int i = 0; i < 4; i++)
		{
			this->Reference += this->oMappTB_Commande->getAnneeCommande()[i];					      
		}
		for (int i = 0; i < 3; i++)
		{
			this->Reference += this->oMappTB_Commande->getVilleLivraison()[i];
		}
		this->Reference += this->increment;														  
		this->increment++;																		 
	}

	System::String^ CL_svcCommande::getReference(void)
	{
		return this->Reference;
	}

}