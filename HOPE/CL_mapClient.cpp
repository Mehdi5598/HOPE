#include "CL_mapClient.h"
#include "CL_svcClient.h"

namespace NS_Comp {

    String^ CL_mapClient::Select(void)
    {
        return "SELECT " +
            "[Client].[Id_client]," +
            "[Client].[Nom]," +
            "[Client].[Prenom]," +
            "[adresse_liv].[Rue] AS [Rue livraison]," +
            "[adresse_liv].[Ville] AS [Ville livraison]," +
            "[adresse_liv].[Cp] AS [Code postal livraison]," +
            "[adresse_fact].[Rue] AS [Rue facturation]," +
            "[adresse_fact].[Ville] AS [Ville facturation]," +
            "[adresse_fact].[Cp] AS [Code postal facturation]," +
            "[date_anniv].[D] AS [Date d'anniversaire]," +
            "[date_premier_achat].[D] AS [Date premier achat]" +
            "FROM " +
            "[dbo].[Client]" +
            "INNER JOIN " +
            "[dbo].[adresse] AS [adresse_liv] ON [Client].[Id_client] = [adresse_liv].[id_adresse]" +
            "INNER JOIN " +
            "[dbo].[adresse] AS [adresse_fact] ON [Client].[Id_client] = [adresse_fact].[id_adresse]" +
            "INNER JOIN " +
            "[dbo].[DATES] AS [date_anniv] ON [Client].[id_date_anniv] = [date_anniv].[Id_Date]" +
            "INNER JOIN " +
            "[dbo].[DATES] AS [date_premier_achat] ON [Client].[id_date_first] = [date_premier_achat].[Id_Date];";
    }

    String^ CL_mapClient::Insert(void)
    {
        return "INSERT INTO Client(Nom, Prenom, id_date_anniv, id_date_first ) VALUES('" + this->Nom + " ', '" + this->Prenom + "', '" + this->id_dateAnniv + "','" + this->id_datePremierAchat + "');";
            
    }


    String^ CL_mapClient::Delete(void)
    {
        return
            " ALTER TABLE [POoPOo].[dbo].[Client] NOCHECK CONSTRAINT ALL " +
            " BEGIN TRANSACTION; " +
            " DELETE FROM [POoPOo].[dbo].[Dates] " +
            " WHERE Id_date IN ( " +
            "  SELECT c.id_date_anniv  " +
            "  FROM [POoPOo].[dbo].[Client] c " +
            "  WHERE c.id_client = " + this->getIdClient() + "); " +
            " DELETE FROM [POoPOo].[dbo].[Dates] " +
            " WHERE Id_date IN ( " +
            "  SELECT c.id_date_first " +
            " FROM [POoPOo].[dbo].[Client] c " +
            "  WHERE c.id_client = " + this->getIdClient() + "); " +
            " DELETE FROM [POoPOo].[dbo].[Adresse] " +
            " WHERE id_adresse IN ( " +
            "  SELECT c.id_client " +
            "  FROM [POoPOo].[dbo].[Client] c " +
            "  WHERE c.id_client = " + this->getIdClient() + "); " +
            " DELETE FROM [POoPOo].[dbo].[Client] " +
            " WHERE id_client = " + this->getIdClient() + "; " +
            " COMMIT; " +
            " ALTER TABLE [POoPOo].[dbo].[Client] WITH CHECK CHECK CONSTRAINT ALL;" ;





    }


    void CL_mapClient::setIdClient(int id_client)
    {
        this->id_client = id_client;
    }

    void CL_mapClient::setNom(String^ Nom)
    {
        this->Nom = Nom;
    }

    void CL_mapClient::setPrenom(String^ Prenom)
    {
        this->Prenom = Prenom;
    }

    

    void CL_mapClient::setIdDateAnniv(int idDateAnniv)
    {
        this->id_dateAnniv = idDateAnniv;
    }

    void CL_mapClient::setIdDatePremierAchat(int idDatePremierAchat)
    {
        this->id_datePremierAchat = idDatePremierAchat;
    }

    int CL_mapClient::getIdClient(void)
    {
        return this->id_client;
    }

    String^ CL_mapClient::getNom(void)
    {
        return this->Nom;
    }

    String^ CL_mapClient::getPrenom(void)
    {
        return this->Prenom;
    }

    

    int CL_mapClient::getIdDateAnniv(void)
    {
        return this->id_dateAnniv;
    }

    int CL_mapClient::getIdDatePremierAchat(void)
    {
        return this->id_datePremierAchat;
    }
}