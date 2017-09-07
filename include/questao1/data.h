/** @since 31/08/2017
 * 
 * @date 02/09/2017
 */

#ifndef data_h
#define data_h

#include <ostream>
#include <sstream>

class data{
	private:
		int dia;
		int mes;
		int ano;	
	public:
		data(int d,int m,int a);
		void setDia(int d);
		void setMes(int m);
		void setAno(int a);
		int getDia();
		int getMes();
		int getAno();

		friend std::ostream& operator<< (std::ostream &o,data const datad);
};

typedef enum st_tipo{
	certo,
	errado,
	ajudante,
	auxiliar			
}tipo;

void pegaDataAtual(std::istream& i,data& datav);


#endif