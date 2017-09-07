#ifndef Empresa_h
#define Empresa_h
#include "../../include/questao1/Funcionario.h"

class Empresa
{
private:
	std::string nome;
	std::string CNPJ;
	std::vector<Funcionario*> funcionarios;
public:
	static int totalEmpresas;
	static int getTotalEmpresas();
	Empresa(std::string n,std::string CP);
	Empresa();
	~Empresa();

	void setNome(std::string n);
	void setCNPJ(std::string CP);
	void addFuncionario(Funcionario* func);

	std::string getNome();
	std::string getCNPJ();

	void listaFuncionario_em_experiencia();
	void listaFuncionarios();
	void aumento(float aum);

};

#endif 