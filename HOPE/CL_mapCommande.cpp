#include "CL_mapCommande.h"


namespace NS_Comp {											           

	String^ CL_mapCommande::Select(void)
	{
		return " SELECT " +
			" Commande.Id_commande," +
			" Commande.referance AS [R�f�rence], " +
			" Date_emi.D AS [Date d'�mission], " +
			" Date_liv.D AS [Date de livraison] " +
			" FROM " + 
			" Commande " +
			" INNER JOIN " +
			" Dates AS Date_liv ON Date_liv.Id_date = Commande.Id_date_livr " +
			" INNER JOIN " +
			" Dates AS Date_emi ON Date_emi.Id_date = Commande.Id_date_emis;";

	}

	String^ CL_mapCommande::Insert(void)
	{


		return " INSERT INTO Commande (referance, Id_date_emis, Id_date_livr, id_client) " +
			" OUTPUT INSERTED.Id_commande " +
			" VALUES('" + this->Ref + "', '" + this->id_dateEmission + "', '" + this->id_dateLivraison + "', '" + this->id_client + "');";

	}

	String^ CL_mapCommande::Delete(void)
	{

		return "ALTER TABLE Commande NOCHECK CONSTRAINT ALL; " +
			"BEGIN TRANSACTION; " +
			"DELETE FROM Dates " +
			"WHERE Id_date IN ( " +
			"  SELECT c.Id_date_emis " +
			"  FROM Commande c " +
			"  WHERE c.Id_commande = " + this->getIdCommande() + "" +
			"); " +
			"DELETE FROM Dates " +
			"WHERE Id_date IN ( " +
			"  SELECT c.Id_date_livr " +
			"  FROM Commande c " +
			"  WHERE c.Id_commande = " + this->getIdCommande() + "" +
			"); " +
			"DELETE FROM Projet_POO.dbo.Client " +
			"WHERE id_Client IN ( " +
			"  SELECT c.id_client " +
			"  FROM Projet_POO.dbo.Commande c " +
			"  WHERE c.Id_commande = " + this->getIdCommande() + "" +
			"); " +
			"DELETE FROM Projet_POO.dbo.Commande " +
			"WHERE Id_commande = " + this->getIdCommande() + " ; " +
			"COMMIT; " +
			"ALTER TABLE Client WITH CHECK CHECK CONSTRAINT ALL;";

	}

	void CL_mapCommande::setIdCommande(int id_commande)
	{
		this->id_commande = id_commande;
	}

	void CL_mapCommande::setIdDateEmission(int id_dateEmission)
	{
		this->id_dateEmission = id_dateEmission;
	}

	void CL_mapCommande::setIdDateLivraison(int id_dateLivraison)
	{
		this->id_dateLivraison = id_dateLivraison;
	}

	int CL_mapCommande::getIdCommande(void)
	{
		return this->id_commande;
	}

	void CL_mapCommande::setIdClient(int id_client)
	{
		this->id_client = id_client;
	}

	int CL_mapCommande::getIdDateEmission(void)
	{
		return this->id_dateEmission;
	}

	int CL_mapCommande::getIdDateLivraison(void)
	{
		return this->id_dateLivraison;
	}

	void CL_mapCommande::setRef(String^ Ref)
	{
		this->Ref = Ref;
	}

	int CL_mapCommande::getIdClient(void)
	{
		return this->id_client;
	}


	void CL_mapCommande::setPrenomClient(String^ PrenomClient)
	{
		this->PrenomClient = PrenomClient;
	}

	void CL_mapCommande::setNomClient(String^ NomClient)
	{
		this->NomClient = NomClient;
	}

	void CL_mapCommande::setAnneeCommande(System::String^ AnneeCommande)
	{
		this->AnneeCommande = AnneeCommande;
	}

	void CL_mapCommande::setVilleLivraison(String^ VilleLivraison)
	{
		this->VilleLivraison = VilleLivraison;
	}

	String^ CL_mapCommande::getRef(void)
	{
		return this->Ref;
	}

	String^ CL_mapCommande::getPrenomClient(void)
	{
		return this->PrenomClient;
	}

	String^ CL_mapCommande::getNomClient(void)
	{
		return this->NomClient;
	}

	String^ CL_mapCommande::getAnneeCommande(void)
	{
		return this->AnneeCommande;
	}

	String^ CL_mapCommande::getVilleLivraison(void)
	{
		return this->VilleLivraison;
	}
}