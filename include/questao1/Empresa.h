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
	static void listOptions();

	Empresa(std::string n,std::string CP);
	Empresa();
	~Empresa();

	void setNome(std::string n);
	void setCNPJ(std::string CP);
	void addFuncionario(std::vector<Empresa*> empresas);
	int verificaRG(std::vector<Empresa*> empresas,std::string& rg_funcionario,tipoEstado& estado_rg);
	void pegaDataADM(Data& dataADM);

	std::vector<Funcionario*>::iterator getBegin();
	std::vector<Funcionario*>::iterator getEnd();

	std::string getNome();
	std::string getCNPJ();
	
	void listaFuncionarios_em_experiencia();
	std::ostream& listaFuncionarios(std::ostream& output_auxiliar);
	void aumentarSalario(float aum);
	friend std::ostream& operator<<(std::ostream& o,Empresa& emp);
};

#endif 