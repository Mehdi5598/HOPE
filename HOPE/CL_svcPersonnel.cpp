#include "CL_svcPersonnel.h"

namespace NS_svc {
	CL_svcPersonnel::CL_svcPersonnel(void)
	{
		this->oData = gcnew NS_Comp::CL_CAD();									            
		this->oMappTB_Personnel = gcnew NS_Comp::CL_mapPersonnel();			            
		this->oMappTB_Adresse = gcnew NS_Comp::CL_mapAdresse();				            
		this->oMappTB_Date = gcnew NS_Comp::CL_mapDate();						            
	}
	Data::DataSet^ CL_svcPersonnel::selectionnerToutesLesPersonnes(String^ dataTableName)
	{
		String^ sql;													        

		sql = this->oMappTB_Personnel->Select();								      
		return this->oData->getRows(sql, dataTableName);						        
	}
	void CL_svcPersonnel::ajouterUnePersonne(String^ nom, String^ prenom, int id_personel1, String^ rue, String^ ville, int cp, String^ date)
	{
		String^ sql;													        
		int Id_date;															      
		int Id_adresse;															      

		this->oMappTB_Adresse->setRue(rue);								          
		this->oMappTB_Adresse->setVille(ville);									          
		this->oMappTB_Adresse->setCp(cp);										          

		sql = this->oMappTB_Adresse->Insert();									      
		Id_adresse = this->oData->actionRowsID(sql);							               

		this->oMappTB_Date->setDate(date);										          

		sql = this->oMappTB_Date->Insert();										      
		Id_date = this->oData->actionRowsID(sql);								               

		this->oMappTB_Personnel->setNom(nom);									          
		this->oMappTB_Personnel->setPrenom(prenom);								          
		this->oMappTB_Personnel->setid_personnel_1(id_personel1);								          
		this->oMappTB_Personnel->setId_date(Id_date);							          
		this->oMappTB_Adresse->setIdAdresse(Id_adresse);						          

		sql = this->oMappTB_Personnel->Insert();								      
		this->oData->actionRows(sql);											      
	}

	void CL_svcPersonnel::modifierPersonnel(int id_personnel, String^ nom, String^ prenom, int id_personel1, String^ rue, String^ ville, int cp, String^ date_embauche)
	{
		String^ sql;													        

		this->oMappTB_Personnel->setId_Personnel(id_personnel);					          



		this->oMappTB_Adresse->setRue(rue);								          
		this->oMappTB_Adresse->setVille(ville);									          
		this->oMappTB_Adresse->setCp(cp);										          

		this->oMappTB_Date->setDate(date_embauche);								          

		this->oMappTB_Personnel->setNom(nom);									          
		this->oMappTB_Personnel->setPrenom(prenom);								          
		this->oMappTB_Personnel->setid_personnel_1(id_personel1);								          

		sql =
			" UPDATE Personnel "+
			" SET Nom = '" + this->oMappTB_Personnel->getNom() + "', Prenom = '" + this->oMappTB_Personnel->getPrenom() + "'"+
			" WHERE id_personnel = '" + this->oMappTB_Personnel->getId_Personnel() + "';"+

			" UPDATE Adresse"+
			" SET Rue = '" + this->oMappTB_Adresse->getRue() + "', Ville = '" + this->oMappTB_Adresse->getVille() + "', Cp = '" + this->oMappTB_Adresse->getCp() + "'"+
			" FROM Adresse"+
			" INNER JOIN Personnel ON Adresse.id_personnel = Personnel.id_personnel"+
			" WHERE Personnel.id_personnel = '" + this->oMappTB_Personnel->getId_Personnel() + "';"+

			" UPDATE Dates"+
			"	SET D = '" + this->oMappTB_Date->getDate() + "'"+
			"	FROM Dates"+
			" INNER JOIN Personnel ON Dates.Id_date = Personnel.Id_date"+
			" WHERE Personnel.id_personnel = '" + this->oMappTB_Personnel->getId_Personnel() + "';";

		this->oData->actionRows(sql);											      

	}

	void CL_svcPersonnel::supprimerPersonnel(int id_personnel)
	{
		String^ sql;													        

		this->oMappTB_Personnel->setId_Personnel(id_personnel);					          

		sql = this->oMappTB_Personnel->Delete();								       
		this->oData->actionRows(sql);											      
	}
}