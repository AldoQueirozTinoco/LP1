#include "astro.h"

void Astronauta::Morrer()
{
        vivo = 0;
}
void Astronauta::setIdade()
{
        std::cout << "insira idade do astronauta:" << std::endl;
        std::cin >> idade;
}

void Astronauta::setNome()
{
        std::cout << "insira nome do astronauta: " << std::endl;
        std::cin >> nome;
}

void Astronauta::setCpf()
{
        std::cout << "insira o cpf do astronauta:" << std::endl;
        std::cin >> cpf;
}
void Astronauta::setDisponivel()
{
        disponivel = 1;
}

void Astronauta::setIndisponivel()
{
        disponivel = 0;
}

int Astronauta::getVivo()
{
        return vivo;
}
int Astronauta::getDisponivel()
{
        return disponivel;
}
std::string Astronauta::getCpf()
{
        return cpf;
}

std::string Astronauta::getNome()
{
        return nome;
}

int Astronauta::getIdade()
{
        return idade;
}

// Funcoes para Foguetes

void Foguetes::setPassageiro(Astronauta astro)
{
        assentos.push_back(astro);
}

void Foguetes::setCodigoDoVoo(int codigoDoVoo)
{
        this->codigoDoVoo = codigoDoVoo;
}

void Foguetes::setStatusLancar()
{
        status = "EmCurso";
        std::cout << "Foguete Lancado" << std::endl;
}

void Foguetes::setStatusExplodir()
{
        status = "FinalizadoERROR";
        std::cout << "Status: FinalizadoERROR" << std::endl;
        std::cout << "Foguete ESTOURADO (Você é um monstro)" << std::endl;

}

void Foguetes::setStatusFinalizar()
{
        status = "FinalizadoOK";
        std::cout << "Voo finalizado com SUCESSO" << std::endl;
}

void Foguetes::mataAstro(int escolha)
{
        assentos[escolha].Morrer();
}

void Foguetes::removePassageiro(int escolha)
{
	assentos.erase(assentos.begin() + escolha);

}

int Foguetes::getCodigoDoVoo()
{
        return codigoDoVoo;
}

std::string Foguetes::getStatus()
{
        return status;
}

std::vector<Astronauta> Foguetes::getAssentos()
{
        return assentos;
}

// cria um Astronauta temporario e adiciona ao vetor AstronautasExistentes, tornando-o permanente
void criaAstronauta(std::vector<Astronauta> &AstronautasExistentes)
{
	Astronauta astro;
	astro.setIdade();
	astro.setNome();
	astro.setCpf();
	AstronautasExistentes.push_back(astro);
}

// cria um voo temporario e adiciona ao vetor voosExistentes, tornando-o permanente
void criaVoo(std::vector<Foguetes> &voosExistentes)
{
        int igual = 1;
        int inteiro;
        Foguetes voo;
    
        while (igual)
        {
                /*Jogamos o cadastrador direto para este while
                1.Assumimos que o número dado é diferente de qualquer código de voo
                2.pedimos pelo numero
                3.se ele na verdade for igual, repetimos o loop.
                */
                igual=0;
                std::cout << "Insira o codigo do voo" << std::endl;
                std::cin>>inteiro;
                for (int i = 0; i < (int)voosExistentes.size(); i++)
                {
                        if (voosExistentes[i].getCodigoDoVoo() == inteiro)
                        {
                                std::cout << "Este código já está em uso por" << i + 1 << ". voo:" << voosExistentes[i].getCodigoDoVoo() << ", utilize outro" << std::endl;
                                igual = 1;

                        }
                }

        }
        voo.setCodigoDoVoo(inteiro);
        voosExistentes.push_back(voo);
        std::cout << "Voo criado!" << std::endl;
}

void listaVoos(std::vector<Foguetes> voosExistentes)
{
        for (int i = 0; i < (int)voosExistentes.size(); i++)
        {
                std::cout << "Voo " << i + 1 << ": " << voosExistentes[i].getCodigoDoVoo() << " (" << voosExistentes[i].getStatus() << ")" << std::endl;
                for (int j = 0; j < (int)voosExistentes[i].getAssentos().size(); j++)
                {
                        std::cout << voosExistentes[i].getAssentos()[j].getNome() << std::endl;
                }
        }

}

void listaAstronautas(std::vector<Astronauta> AstronautasExistentes)
{
	for (int i = 0; i < (int)AstronautasExistentes.size(); i++)
	{
		std::cout << i + 1 << ". " << AstronautasExistentes[i].getNome()<<" Disponivel: ("<<AstronautasExistentes[i].getDisponivel()<<")"<< std::endl;
                std::cout<<"Cpf: "<<AstronautasExistentes[i].getCpf()<<std::endl;
                printf("\n");
	}
}