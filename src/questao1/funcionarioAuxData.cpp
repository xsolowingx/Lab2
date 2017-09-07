#include "funcionario.h"


void funcionario::pegaData(std::istream& i){
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
			if(a < 0 ){
				std::cout << "ano invalido, ano varia de 0 ate o ano atual. " << std::endl;
			}
			break;
		}
		std::cout << "Ano invalido, ano e um inteiro que varia de 0 ate o ano atual. " << std::endl;
	}

	data datav = new data(d, m, a);

	datav(d,m,a);
}

void funcionario::verificaData(data& datac,data& dataAtual){
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