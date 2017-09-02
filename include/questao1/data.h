/** @since 31/08/2017
 * 
 * @date 01/09/2017
 */

#ifndef data_h
#define data_h

class data{
	private:
		int dia;
		int mes;
		int ano;	
	public:
		data(int d,int m,int a);
		int getDia();
		int getMes();
		int getAno();

		friend std::ostream& operator<< (std::ostream &o,data const datad);
		//friend std::istream& operator>> (std::istream &i,data &date);
};

typedef enum st_tipo{
	certo,
	errado,
	ajudante,
	auxiliar			
}tipo;

void verificaData(data& datac,data& const dataAtual);
void pegaData(std::istream& i,data& datav,data& const dataAtual);
void pegaDataAtual(std::istream& i,data& datav);


#endif