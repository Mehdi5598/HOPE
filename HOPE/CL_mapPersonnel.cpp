#include "CL_mapPersonnel.h"
#include"CL_mapAdresse.h"
#include"CL_mapDate.h"


namespace NS_Comp {

    String^ CL_mapPersonnel::Select(void)
    {
        return " SELECT " +
            " [Personnel].[Id_personnel]," +
            " [Personnel].[nom]," +
            " [Personnel].[prenom]," +
            " [Personnel].[Id_personnel_1] AS[Grade]," +
            " [habit].[Rue] AS[Rue],"  + 
            " [habit].[Ville] AS[Ville]," +
            " [habit].[Cp] AS[Code postal]," +
            " [date_embauche].[D] AS[Date d'embauche]" +
            " FROM" +
            " [dbo].[Personnel]" +
            " INNER JOIN" +
            " [dbo].[adresse] AS[habit] on[Personnel].[Id_personnel] = [habit].Id_personnel" +
            " INNER JOIN" +
            " dbo.DATES AS date_embauche on Personnel.id_date = date_embauche.Id_Date;"; 

    }

    String^ CL_mapPersonnel::Insert(void)
    {
        return "INSERT INTO Personnel (Nom, Prenom, id_personnel_1,  Id_date)" +
            "VALUES('" + this->Nom + "','" + this->Prenom + "','" + this->id_personnel_1 + "','" + this->id_date + "');SELECT @@IDENTITY;";
    }

    String^ CL_mapPersonnel::Delete(void)
    {
        return
            " ALTER TABLE [POoPOo].[dbo].[Personnel] NOCHECK CONSTRAINT ALL; " +
            "BEGIN TRANSACTION; " +
            "DELETE FROM [POoPOo].[dbo].[Dates] " +
            "WHERE Id_date IN ( " +
            "SELECT p.id_date " +
            "FROM [POoPOo].[dbo].[Personnel] p " +
            "WHERE p.id_personnel = " + this->getId_Personnel() + "); " +
            "DELETE FROM [POoPOo].[dbo].[Adresse] " +
            "WHERE id_personnel IN ( " +
            "SELECT p.id_personnel " +
            "FROM [POO].[dbo].[Personnel] p " +
            "WHERE p.id_personnel = " + this->getId_Personnel() + "); " +
            "DELETE FROM [POoPOo].[dbo].[Personnel] " +
            "WHERE id_personnel = " + this->getId_Personnel() + "; " +
            "COMMIT;";


    }

    void CL_mapPersonnel::setId_Personnel(int Id)
    {
        this->id_personnel = Id;
    }

    void CL_mapPersonnel::setNom(String^ Nom)
    {
        this->Nom = Nom;
    }

    void CL_mapPersonnel::setPrenom(String^ Prenom)
    {
        this->Prenom = Prenom;
    }

    void CL_mapPersonnel::setid_personnel_1(int id_personnel_1)
    {
        this->id_personnel_1 = id_personnel_1;
    }

    void CL_mapPersonnel::setId_adresse(int id_adresse)
    {
        this->id_adresse = id_adresse;
    }

    void CL_mapPersonnel::setId_date(int id_date)
    {
        this->id_date = id_date;
    }

    int CL_mapPersonnel::getId_Personnel(void)
    {
        return this->id_personnel;
    }

    String^ CL_mapPersonnel::getNom(void)
    {
        return this->Nom;
    }

    String^ CL_mapPersonnel::getPrenom(void)
    {
        return this->Prenom;
    }

    int CL_mapPersonnel::getid_personnel_1(void)
    {
        return this->id_personnel_1;
    }

    int CL_mapPersonnel::getId_adresse(void)
    {
        return this->id_adresse;
    }

    int CL_mapPersonnel::getId_date(void)
    {
        return this->id_date;
    }

}