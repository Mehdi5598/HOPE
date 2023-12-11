#include "CL_mapStock.h"

namespace NS_Comp {
    String^ CL_mapStock::Select(void)
    {
        return "SELECT *" +
            "FROM Article";
    }

    String^ CL_mapStock::Insert(void)             
    {
        return "INSERT INTO [Articles] (nom_article,  Stock, Seuil_Reapprovisionnement, , Taux_tva, Prix_ht, remis)" +
            "VALUES ('" + this->nom_article + "','" + this->Stock + "','" + this->SeuilReap + "','" + this->Taux_tva + "','" + this->Prix_HT + "','" + this->remis + "');";
    }

    String^ CL_mapStock::Update(void)
    {
        return "UPDATE [Articles]" +
            "SET referance='" + this->nom_article + "', Stock='" + this->Stock + "', Seuil_Reapprovisionnement='" + this->SeuilReap+ "', Taux_Tva='" + this->Taux_tva + "', Prix_ht='" + this->Prix_HT + "', Remis'" + this->remis + "'" +
            "WHERE(Id_articles='" + this->id_articles + "');";
    }

    String^ CL_mapStock::Delete(void)
    {
        return "DELETE FROM [Articles]" +
            "WHERE(Id_articles='" + this->getIdArticles() + "');";
    }

    void CL_mapStock::setIdArticles(int id_articles)
    {
        this->id_articles = id_articles;
    }

    void CL_mapStock::setnom(System::String^ nom)
    {
        this->nom_article = nom;
    }

    void CL_mapStock::setRemis(double remis)
    {
        this->remis= remis;
    }

    void CL_mapStock::setStock(int Stock)
    {
        this->Stock = Stock;
    }

    void CL_mapStock::setSeuilReap(int SeuilReap)
    {
        this->SeuilReap = SeuilReap;
    }

   

    void CL_mapStock::setTauxTVA(float TVA)
    {
        this->Taux_tva = TVA;
    }

    void CL_mapStock::setPrixHT(float Prix_HT)
    {
        this->Prix_HT = Prix_HT;
    }

   

    void CL_mapStock::setPrixTVA(float PrixTVA)
    {
        this->Prix_TVA = Prix_TVA;
    }

    int CL_mapStock::getIdArticles(void)
    {
        return this->id_articles;
    }

    String^ CL_mapStock::getnom(void)
    {
        return this->nom_article;
    }

    double CL_mapStock::gettRemis(void)
    {
        return this->remis;
    }

    int CL_mapStock::getStock(void)
    {
        return this->Stock;
    }

    int CL_mapStock::getSeuilReap(void)
    {
        return this->SeuilReap;
    }

   

    float CL_mapStock::getTauxTVA(void)
    {
        return this->Taux_tva;
    }

    float CL_mapStock::getPrixHT(void)
    {
        return this->Prix_HT;
    }

        float  CL_mapStock::getPrixTVA(void)
    {
        return this->Prix_TVA;
    }
}