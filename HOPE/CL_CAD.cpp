#include "CL_CAD.h"

namespace NS_Comp {

	CL_CAD::CL_CAD(void)
	{
		this->sCnx = "Data Source=MEHDI\\SQLEXPRESS;Initial Catalog=POoPOo;User ID = Mehdi\\blblb;Integrated Security = True";	     

		this->sSql = "Rien";																							   

		this->oCnx = gcnew Data::SqlClient::SqlConnection(this->sCnx);											            
		this->oCmd = gcnew Data::SqlClient::SqlCommand(this->sSql, this->oCnx);									            
		this->oDA = gcnew Data::SqlClient::SqlDataAdapter();													            
		this->oDs = gcnew Data::DataSet();																		            

		this->oCmd->CommandType = Data::CommandType::Text;														       
	}
	Data::DataSet^ CL_CAD::getRows(String^ sSql, String^ sDataTableName)
	{
		this->oDs->Clear();																								       
		this->sSql = sSql;																								       
		this->oCmd->CommandText = this->sSql;																			        
		this->oDA->SelectCommand = this->oCmd;																			   
		this->oDA->Fill(this->oDs, sDataTableName);																		        

		return this->oDs;																								         
	}
	void CL_CAD::actionRows(String^ sSql)
	{
		this->sSql = sSql;																								       
		this->oCmd->CommandText = this->sSql;																			        
		this->oDA->SelectCommand = this->oCmd;																			   
		this->oCnx->Open();																								   
		this->oCmd->ExecuteNonQuery();																					    
		this->oCnx->Close();																							   
	}
	int CL_CAD::actionRowsID(String^ sSql)
	{
		int id;																											   
		this->sSql = sSql;																								       
		this->oCmd->CommandText = this->sSql;																			        
		this->oDA->SelectCommand = this->oCmd;																			   
		this->oCnx->Open();																								   
		id = System::Convert::ToInt32(this->oCmd->ExecuteScalar());														                             
		this->oCnx->Close();																							   
		return id;																										  
	}
}