#pragma once
using namespace System;

namespace NS_Comp
{
	ref class CL_CAD
	{
	private:
		String^ sSql;												      
		String^ sCnx;												         
		Data::SqlClient::SqlConnection^ oCnx;						          
		Data::SqlClient::SqlCommand^ oCmd;							          
		Data::SqlClient::SqlDataAdapter^ oDA;						          
		Data::DataSet^ oDs;											          
	public:
		CL_CAD(void);														       
		Data::DataSet^ getRows(String^, String^);	       
		void actionRows(String^);									        
		int actionRowsID(String^);									             
	};
}
