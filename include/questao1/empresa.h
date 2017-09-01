/** @since 31/08/2017
 * 
 * @date 31/08/2017
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
	empresa(std::string n,int C);
	void aumento(float aum);
	
};

void start();


#endif