#include "CL_mapAdresse.h"

namespace NS_Comp {

    CL_mapAdresse::CL_mapAdresse(void)
    {
    }

    String^ CL_mapAdresse::Insert(void)
    {
        return "INSERT INTO Adresse (Rue, Ville, Cp) VALUES ('" + this->Rue + "','" + this->Ville + "','" + this->Cp + "');SELECT @@IDENTITY";
    }

    String^ CL_mapAdresse::Update(void)
    {
        return "UPDATE [Projet_POO].[dbo].[Adresse]" +
            "SET Adresse='" + this->getRue() + "', Ville='" + this->getVille() + "', Cp='" + this->getCp() + '"' +
            "WHERE(id_adresse='" + this->getIdAdresse() + "');SELECT @@IDENTITY";
    }

    void CL_mapAdresse::setIdAdresse(int id_adresse)
    {
        this->id_adresse = id_adresse;
    }

    void CL_mapAdresse::setRue(String^ adresse)
    {
        this->Rue = adresse;
    }

    void CL_mapAdresse::setVille(String^ ville)
    {
        this->Ville = ville;
    }

    void CL_mapAdresse::setCp(int cp)
    {
        this->Cp = cp;
    }

    int CL_mapAdresse::getIdAdresse(void)
    {
        return this->id_adresse;
    }

    String^ CL_mapAdresse::getRue(void)
    {
        return this->Rue;
    }

    String^ CL_mapAdresse::getVille(void)
    {
        return this->Ville;
    }

    int CL_mapAdresse::getCp(void)
    {
        return this->Cp;
    }
    void CL_mapAdresse::setIdAdresseLiv(int idAdresseLiv)
    {
        this->id_adresseLiv = idAdresseLiv;
    }

    void CL_mapAdresse::setIdAdresseFact(int idAdresseFact)
    {
        this->id_adresseFact = idAdresseFact;
    }
    int CL_mapAdresse::getIdAdresseLiv(void)
    {
        return this->id_adresseLiv;
    }

    int CL_mapAdresse::getIdAdresseFact(void)
    {
        return this->id_adresseFact;
    }
}