/** @since 31/08/2017
 * 
 * @date 01/09/2017
 */

#include "../../include/questao1/data.h"
#include <iostream>

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

/*std::istream& operator>> (std::istream &i,data &date){
	i >> date.dia >> date.mes >> date.ano;
	return i;
}*/


void verificaData(data& datac,data& dataAtual){
	tipo tipaux = errado;
	std::string line;

	while(tipaux != certo){
	
		if( (datac.getAno() > dataAtual.getAno()) ){
			
			std::cout << "Data invalida. o ano e maior do que o ano atual." << std::endl;
			std::cout << "Por favor digite o ano: " << std::endl;
			
			while(std::getline(std::cin , line) ){
			
			std::stringstream ss(line);
			
				if(ss >> datac.ano && ss.eof()){
					if(datac.getAno() < 0 || datac.getAno() > dataAtual.getAno()){
						std::cout << "ano invalido, ano varia de 0 ate o ano atual. " << std::endl;
					}
					break;
				}
				std::cout << "Ano invalido, ano e um inteiro que varia de 0 ate o ano atual. " << std::endl;
			}
			continue;
		}

		if( (datac.getMes() > dataAtual.getMes()) ){
			
			std::cout << "Data invalida. o mes e maior que o mes atual." << std::endl;
			std::cout << "Por favor digite o mes: " << std::endl;
			
			while(std::getline(std::cin , line) ){
			
			std::stringstream ss(line);
			
				if(ss >> datac.mes && ss.eof()){
					if(datac.getMes() < 1 || datac.getMes() > 12){
						std::cout << "Mes invalido, o mes varia de 1 a 12. " << std::endl;
					}
					break;
				}
				std::cout << "Mes invalido, o mes e um inteiro que varia de 1 a 12. " << std::endl;
			}
			continue;
		}

		if( (datac.getDia() > dataAtual.getDia()) ){
			
			std::cout << "Data invalida. o dia e maior que o dia atual." << std::endl;
			std::cout << "Por favor digite o dia: " << std::endl;
			
			while(std::getline(std::cin , line) ){
			
			std::stringstream ss(line);
			
				if(ss >> d && ss.eof()){

					if( ( datac.getDia() < 1 || datac.getDia() > 30) ){
						std::cout << "Dia invalido, os dias vao de 1 a 30. " << std::endl;
					}
					break;
				}
				std::cout << "Dia invalido, os dias sao numeros inteiros que variam de 1  a 30. " << std::endl;
			}
			continue;
		}
		tipaux = certo;
	}
}



void pegaData(std::istream& i,data& datav,data& dataAtual){
	int anoAtual = dataAtual.getAno();

	std::string line;
	int d,m,a;

	std::cout << "Por favor digite o dia: " << std::endl;

	while(std::getline(i , line) ){
		
		std::stringstream ss(line);
		
		if(ss >> d && ss.eof()){

			if( ( d < 1 || d > 30) ){
				std::cout << "Dia invalido, os dias vao de 1 a 30. " << std::endl;
			}
			break;
		}
		std::cout << "Dia invalido, os dias sao numeros inteiros que variam de 1  a 30. " << std::endl;
	}

	std::cout << "Por favor digite o mes: " << std::endl;

	while(std::getline(i , line) ){
		
		std::stringstream ss(line);
		
		if(ss >> m && ss.eof()){
			if(m < 1 || m > 12){
				std::cout << "Mes invalido, o mes varia de 1 a 12. " << std::endl;
			}
			break;
		}
		std::cout << "Mes invalido, o mes e um inteiro que varia de 1 a 12. " << std::endl;
	}
	
	std::cout << "Por favor digite o ano: " << std::endl;

	while(std::getline(i , line) ){
		
		std::stringstream ss(line);
		
		if(ss >> a && ss.eof()){
			if(a < 0 || a > anoAtual){
				std::cout << "ano invalido, ano varia de 0 ate o ano atual. " << std::endl;
			}
			break;
		}
		std::cout << "Ano invalido, ano e um inteiro que varia de 0 ate o ano atual. " << std::endl;
	}

	datav(d,m,a);
}


void pegaDataAtual(std::istream& is,data& datab){
	
	int diaAtual = dataAtual.getDia();
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
	datab(d,m,a);
}