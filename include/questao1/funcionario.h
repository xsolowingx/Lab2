/** @since 31/08/2017
 * 
 * @date 02/09/2017
 */

#ifndef funcionario_h
#define funcionario_h

#include <string>
#include "data.h"
#include <vector>
#include "empresa.h"

typedef enum st_tipos{
	novato,
	veterano
}tipoExperiencia;


class funcionario{
private:
	std::string nome;
	float salario;
	int rg;
	tipoExp exp;
	data data_de_admissao;

public:
	
	static int quantidade;
	
	void setDia(int d);
	void setMes(int m);
	void setAno(int a);
	int getDia();
	int getMes();
	int getAno();

	void verificaExp(data& datac, data& dataAtual,tipoExp& exp);
	void pegaData(std::istream& i, data& dataAtual);
	void verificaData(data& datac, data& dataAtual);

	void setNome(std::string a);
	void setSalario(float s);
	void setRg(int i);
	void setExp(tipoExp topo);
	tipoExp getExp();
	int getRg();
	float getSalario();
	
	std::string getNome();
	data getData_de_admissao();
	bool operator== (funcionario& f); 
	
	friend std::ostream& operator<< (std::ostream &o, funcionario f);

	
};


void listaFuncionario(std::vector<funcionario>::iterator* iterator4);
void pegaDados(std::istream& i,funcionario& f,  data& dataAtual,std::vector<funcionario>& funcionarios,int& valor_de_retorno3);	
void criarfuncionario(std::string& opcao, std::vector<empresa>& empresas,std::vector<empresa>::iterator& ite, data& dataAtual,int& l,int& valor_de_retorno3);
bool verificaFuncionario(funcionario& f,std::vector<funcionario>& funcionarios);
void listaFuncionario_em_periodo_de_experiencia(std::vector<empresa>::iterator* iterat7);

#endif