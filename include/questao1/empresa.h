/** @since 31/08/2017
 * 
 * @date 02/09/2017
 */

#ifndef empresa_h
#define empresa_h

#include <string>
#include <vector>
#include "funcionario.h"
#include "data.h"

class empresa{
private:
	std::string nome;
	int CPNJ;
	std::vector<funcionario> funcionarios;

public:

	static int quantidade;

	void setNome(std::string n);
	void setCPNJ(int cp);
	void aumento(float aum);
	std::string getNome();
	int getCPNJ();
	void acrescentaFuncionario();

	friend std::ostream& operator <<(std::ostream& o,  const empresa& emp);
	
	
};

void start(std::vector<empresa>* empresas,std::vector<empresa>::iterator* ite,int& valor_de_retorno1,int& valor_de_retorno2,data& dataAtual,int& valor_de_retorno3);
void criarEmpresa(std::vector<empresa>* empresas,int& valor_de_retorno2,std::vector<empresa>::iterator* ite,int& i,data& dataAtual,int& valor_de_retorno3);
void listaEmpresas(std::vector<empresa>* empresas);
void listaFuncionarios(std::vector<empresa>::iterator* iterat3);

#endif

while(nome < 0)
{
	cout << "digite acima de 0"
	cin >> nome
}

funcionario x = new funcionario(nome, idade);

funcionarios.addFuncionario(x);


addFuncionario(Funcionario y)
{
	funcionarios.push_back(y);
}