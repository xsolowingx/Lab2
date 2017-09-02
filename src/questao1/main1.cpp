#include <iostream>
#include "../../include/questao1/empresa.h"
#include "../../include/questao1/funcionario.h"
#include "../../include/questao1/data.h"

int main(){
	std::vector<*empresa> empresas;
	std::vector<*empresa>::iterator ite = empresas.begin();
	int valor_de_retorno1;
	int valor_de_retorno2;
	int valor_de_retorno3;
	int i = 0;
	data dataAtual;
	start(empresas,ite,valor_de_retorno1,valor_de_retorno2,i,dataAtual,valor_de_retorno3);
	if(valor_de_retorno1 == -1){
		return -1;
	}
	return 0;
}