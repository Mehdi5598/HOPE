#include "CL_svcClient.h"

namespace NS_svc {
    CL_svcClient::CL_svcClient(void)
    {
        this->oData = gcnew NS_Comp::CL_CAD();                                                      
        this->oMappTB_Client = gcnew NS_Comp::CL_mapClient();                                     
        this->oMappTB_Adresse_liv = gcnew NS_Comp::CL_mapAdresse();                               
        this->oMappTB_Adresse_fact = gcnew NS_Comp::CL_mapAdresse();                              
        this->oMappTB_Date_anniv = gcnew NS_Comp::CL_mapDate();                                   
        this->oMappTB_Date_Premier_achat = gcnew NS_Comp::CL_mapDate();                           
    }

    Data::DataSet^ CL_svcClient::selectionnerTousLesClients(String^ dataTableName)
    {
        String^ sql;                                                                    

        sql = this->oMappTB_Client->Select();                                                 
        return this->oData->getRows(sql, dataTableName);                                        
    }

    void CL_svcClient::ajouterUnClient(String^ nom, String^ prenom, String^ Rue_liv, String^ ville_liv, int cp_liv, String^ Rue_fact, String^ ville_fact, int cp_fact, String^ date_anniv, String^ date_premier_achat)
    {
        String^ sql;                                                                    
        int id_adresseLiv;                                                                    
        int id_adresseFact;                                                                   
        int id_dateAnniv;                                                                     
        int id_datePremierAchat;                                                              

        this->oMappTB_Adresse_liv->setRue(Rue_liv);                                       
        this->oMappTB_Adresse_liv->setVille(ville_liv);                                           
        this->oMappTB_Adresse_liv->setCp(cp_liv);                                                 

        sql = this->oMappTB_Adresse_liv->Insert();                                            
        id_adresseLiv = this->oData->actionRowsID(sql);                                                

        this->oMappTB_Adresse_fact->setRue(Rue_fact);                                     
        this->oMappTB_Adresse_fact->setVille(ville_fact);                                         
        this->oMappTB_Adresse_fact->setCp(cp_fact);                                               

        sql = this->oMappTB_Adresse_fact->Insert();                                           
        id_adresseFact = this->oData->actionRowsID(sql);                                               

        this->oMappTB_Date_anniv->setDate(date_anniv);                                            

        sql = this->oMappTB_Date_anniv->Insert();                                             
        id_dateAnniv = this->oData->actionRowsID(sql);                                                 
        this->oMappTB_Date_Premier_achat->setDate(date_premier_achat);                            

        sql = this->oMappTB_Date_Premier_achat->Insert();                                     
        id_datePremierAchat = this->oData->actionRowsID(sql);                                          
        this->oMappTB_Client->setNom(nom);                                                        
        this->oMappTB_Client->setPrenom(prenom);                                                  
        this->oMappTB_Adresse_liv->setIdAdresseLiv(id_adresseLiv);                                     
        this->oMappTB_Adresse_fact->setIdAdresseFact(id_adresseFact);                                   
        this->oMappTB_Client->setIdDateAnniv(id_dateAnniv);                                       
        this->oMappTB_Client->setIdDatePremierAchat(id_datePremierAchat);                         

        sql = this->oMappTB_Client->Insert();                                                 
        this->oData->actionRows(sql);                                                         
    }

    void CL_svcClient::modifierUnClient(int id_client, String^ nom, String^ prenom, String^ Rue_liv, String^ ville_liv, int cp_liv, String^ Rue_fact, String^ ville_fact, int cp_fact, String^ date_anniv, String^ date_premier_achat)
    {
        String^ sql;                                                                    

        this->oMappTB_Client->setIdClient(id_client);                                             

        this->oMappTB_Adresse_liv->setRue(Rue_liv);                                        
        this->oMappTB_Adresse_liv->setVille(ville_liv);                                           
        this->oMappTB_Adresse_liv->setCp(cp_liv);                                                 

        this->oMappTB_Adresse_fact->setRue(Rue_fact);                                     
        this->oMappTB_Adresse_fact->setVille(ville_fact);                                         
        this->oMappTB_Adresse_fact->setCp(cp_fact);                                               

        this->oMappTB_Date_anniv->setDate(date_anniv);                                            

        this->oMappTB_Date_Premier_achat->setDate(date_premier_achat);                            

        this->oMappTB_Client->setNom(nom);                                                        
        this->oMappTB_Client->setPrenom(prenom);                                                  

        sql = "UPDATE Client " +
            "SET Nom = '" + oMappTB_Client->getNom() + "' , Prenom = '" + oMappTB_Client->getPrenom() + "'" +
            " WHERE id_Client = " + oMappTB_Client->getIdClient() + ";" +
            " UPDATE Adresse" +
            " SET Rue = '" + oMappTB_Adresse_liv->getRue() + "', Ville = '" + oMappTB_Adresse_liv->getVille() + "', Cp = " + oMappTB_Adresse_liv->getCp() + " " +
            " FROM Adresse" +
            " INNER JOIN Client ON Adresse.id_adresse = Client.Id_client" +
            " WHERE Client.id_Client = " + oMappTB_Client->getIdClient() + ";" +
            " UPDATE Adresse" +
            " SET Rue = '" + oMappTB_Adresse_fact->getRue() + "', Ville = '" + oMappTB_Adresse_fact->getVille() + "', Cp = '" + oMappTB_Adresse_fact->getCp() + "'" +
            " FROM Adresse" +
            " INNER JOIN Client ON Adresse.id_adresse = Client.Id_client" +
            " WHERE Client.id_Client = " + oMappTB_Client->getIdClient() + ";" +
            " UPDATE Dates" +
            " SET D = '" + oMappTB_Date_anniv->getDate() + "'" +
            " FROM Dates" +
            " INNER JOIN Client ON Dates.id_date = Client.id_date_anniv" +
            " WHERE Client.id_Client = " + oMappTB_Client->getIdClient() + ";" +
            " UPDATE Dates" +
            " SET D = '" + oMappTB_Date_Premier_achat->getDate() + "'" +
            " FROM Dates" +
            " INNER JOIN Client ON Dates.id_date = Client.id_date_first" +
            "  WHERE Client.id_Client = " + oMappTB_Client->getIdClient() + ";";

        this->oData->actionRows(sql);                                                         
    }

    void CL_svcClient::supprimerUnClient(int id_client)
    {
        String^ sql;                                                                    

        this->oMappTB_Client->setIdClient(id_client);                                             

        sql = this->oMappTB_Client->Delete();                                                  
        this->oData->actionRows(sql);                                                         
    }
}