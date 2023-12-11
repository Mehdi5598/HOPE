#include "CL_svcStock.h"
namespace NS_svc {

	CL_svcStock::CL_svcStock(void)
	{
		this->oData = gcnew NS_Comp::CL_CAD();															            
		this->oMappTB_Stock = gcnew NS_Comp::CL_mapStock();											            
	}

	Data::DataSet^ CL_svcStock::selectionnerTousLesStocks(String^ dataTableName)
	{
		String^ sql;																			        

		sql = this->oMappTB_Stock->Select();															      
		return this->oData->getRows(sql, dataTableName);												        
	}

	void CL_svcStock::ajouterArticle(String^ nom, int stock, int SeuilReap, double  remis, float taux_tva, float Prix_HT, float Prix_unitaire_TTC, float Prix_TVA)
	{
		String^ sql;																			        

		this->oMappTB_Stock->setnom(nom);																          															          
		this->oMappTB_Stock->setStock(stock);														          
		this->oMappTB_Stock->setSeuilReap(SeuilReap);													          
		this->oMappTB_Stock->setRemis(remis);														          
		this->oMappTB_Stock->setTauxTVA(taux_tva);														          
		this->oMappTB_Stock->setPrixHT(Prix_HT);										          										          
		this->oMappTB_Stock->setPrixTVA(Prix_TVA);										          

		sql = this->oMappTB_Stock->Insert();															      

		this->oData->actionRows(sql);																	      
	}

	void CL_svcStock::modifierArticle(int id_article, String^ nom, int stock, int SeuilReap, double  remis, float taux_tva, float Prix_HT, float Prix_unitaire_TTC, float Prix_TVA)
	{
		String^ sql;																			        

		this->oMappTB_Stock->setIdArticles(id_article);													          
		this->oMappTB_Stock->setnom(nom);																          														          
		this->oMappTB_Stock->setStock(stock);														          
		this->oMappTB_Stock->setSeuilReap(SeuilReap);													          													          
		this->oMappTB_Stock->setTauxTVA(taux_tva);														          
		this->oMappTB_Stock->setPrixHT(Prix_HT);										          									          
		this->oMappTB_Stock->setPrixTVA(Prix_TVA);										          

		sql = this->oMappTB_Stock->Update();															       

		this->oData->actionRows(sql);																	      
	}

	void CL_svcStock::supprimerArticle(int id_article)
	{
		String^ sql;																			        

		this->oMappTB_Stock->setIdArticles(id_article);													           

		sql = this->oMappTB_Stock->Delete();															       
		this->oData->actionRows(sql);																	      
	}
}