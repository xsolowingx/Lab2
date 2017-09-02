/** @since 31/08/2017
 * 
 * @date 01/09/2017
 */
#ifndef funcionario_h
#define funcionario_h

#include <string>
#include "data.h"

typedef enum st_tipos{
	novato,
	veterano
}tipoExp;


class funcionario{
private:
	std::string nome;
	float salario;
	int rg;
	data data_de_admissao;
	tipoExp exp;

public:
	
	static int quantidade;
	
	void setNome(std::string a);
	void setSalario(float s);
	void setRg(int i);
	void setExp(tipoExp topo);
	tipoExp getExp();
	int getRg();
	float getSalario();
	
	std::string getNome();
	data getData_de_admissao();
	friend std::ostream& operator<< (std::ostream &o,funcionario const f);

	friend bool operator== (funcionario& const f); 

	//friend std::istream& operator>> (std::istream &i,funcionario &f);
};




void listaFuncionario(std::vector<funcionario>::iterator& iterator4);
void pegaDados(std::istream& i,funcionario& f,data& const dataAtual,std::vector<funcionario>& funcionarios);	
void criarfuncionario(std::string& opcao,std::vector<empresa>& const empresas,std::vector<empresa>::iterator& ite,data& const dataAtual,int& l,int& valor_de_retorno3);
bool verificaFuncionario(funcionario& f,std::vector<funcionario>& funcionarios);
void verificaExp(data& datac,data& const dataAtual,tipoExp& exp);

#endif