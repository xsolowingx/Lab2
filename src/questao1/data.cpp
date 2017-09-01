/** @since 31/08/2017
 * 
 * @date 31/08/2017
 */

#include "../../include/questao1/data.h"

data::data(int d,int m, int a){
	dia = d;
	mes = m;
	ano = a;
}


int data::getDia(){
	return dia;
}

int data::getMes(){
	return mes;
}

int data::getAno(){
	return ano;
}

std::ostream& operator<< (std::ostream &o,data const datad){
	o << datad.getDia() << "/" << datad.getMes() << "/" << datad.getAno() << std::endl;
	return o;
}

std::istream& operator>> (std::istream &i,data &date){
	i >> date.dia >> date.mes >> date.ano;
	return i;
}