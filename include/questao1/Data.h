#ifndef Data_h
#define Data_h

#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>
#include <string>

class Data
{
	private:
	
		std::string dia;
		std::string mes;
		std::string ano;	
	
	public:
		static Data data_atual;
		static void atribuiData_atual();
		static Data getData_atual();

		Data(std::string d,std::string m,std::string a);
		Data();
		
		void setDia(std::string d);
		void setMes(std::string m);
		void setAno(std::string a);
		std::string getDia();
		std::string getMes();
		std::string getAno();
		
		friend std::ostream& operator<< (std::ostream &o,Data datad);
		Data& operator=(Data& data_parametro);
};

typedef enum st_tipo{
	certo,
	errado			
}tipoEstado;


#endif