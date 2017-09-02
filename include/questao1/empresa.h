/** @since 31/08/2017
 * 
 * @date 01/09/2017
 */
#ifndef empresa_h
#define empresa_h

#include <string>
#include <vector>
#include "../../include/questao1/funcionario.h"

class empresa{
private:
	std::string nome;
	int CPNJ;
	std::vector<funcionario> funcionarios;

public:
	static int quantidade;
	friend std::ostream& operator <<(std::ostream& o,empresa& const emp);
	empresa(std::string n,int C);
	void aumento(float aum);
	std::string getNome();
	int getCPNJ();
	
};

void start(std::vector<*empresa>& empresas,std::vector<*empresa>::iterator& ite,int& valor_de_retorno1,int& valor_de_retorno2,data& const dataAtual,int& valor_de_retorno3);
void criarEmpresa(std::vector<*empresa>& empresas,int& valor_de_retorno2,std::vector<*empresa>::iterator& ite,int& i,data& const dataAtual,int& valor_de_retorno3);
void listaEmpresas(std::vector<*empresa>& empresas);
void listaFuncionarios(std::vector<*empresa>::iterator& iterat3);

#endif