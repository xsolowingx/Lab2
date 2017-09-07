/** @since 31/08/2017
 * 
 * @date 02/09/2017
 */

#include "../../include/questao1/data.h"
#include <iostream>

data::data(int d,int m, int a){
	dia = d;
	mes = m;
	ano = a;
}

void data::setDia(int d){
	dia = d;
}

void data::setMes(int m){
	mes = m;
}

void data::setAno(int a){
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


void pegaDataAtual(std::istream& is,data& datab){
	
	std::string line;
	int d,m,a;

	std::cout << "Por favor digite o dia: " << std::endl;

	while(std::getline(is , line) ){
		
		std::stringstream ss(line);
		
		if(ss >> d && ss.eof()){
			if(d < 1 || d > 30){
				std::cout << "Dia invalido, os dias variam de 1 a 30. " << std::endl;
			}
			break;
		}
		std::cout << "Dia invalido, os dias sao numeros inteiros que variam de 1  a 30. " << std::endl;
	}
	
	datab.setDia(d);

	std::cout << "Por favor digite o mes: " << std::endl;

	while(std::getline(is , line) ){
		
		std::stringstream ss(line);
		
		if(ss >> m && ss.eof()){
			if(m < 1 || m > 12){
				std::cout << "Mes invalido, o mes varia de 1 a 12. " << std::endl;
			}
			break;
		}
		std::cout << "Mes invalido, o mes e um inteiro que varia de 1 a 12. " << std::endl;
	}

	datab.setMes(m);

	std::cout << "Por favor digite o ano: " << std::endl;

	while(std::getline(is , line) ){
		
		std::stringstream ss(line);
		
		if(ss >> a && ss.eof()){
			if(a < 0){
				std::cout << "ano invalido, ano varia de 0 ate o ano atual. " << std::endl;
			}
			break;
		}
		std::cout << "ano invalido, ano e um inteiro que varia de 0 ate o ano atual. " << std::endl;
	}

	datab.setAno(a);

}