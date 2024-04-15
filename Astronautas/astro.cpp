#include <iostream>
#include <string>
#include <vector>
#include "astro.h"

/* README
		Para a navegação, nada de colocar numeros na doida! Só o numero da operação e cabou.
	ele não vai reagir a numeros fora desse escopom
	NADA DE COLOCAR LETRAS OU OUTROS CARACTERES!!!				
*/

int main()
{
	int rodando = 1;
	// vetor de astronautas e vetor de foguetes
	std::vector<Astronauta> AstronautasExistentes;
	std::vector<Foguetes> voosExistentes;

	while (rodando)
	{
		int escolha = 0, escolha2 = 0;
		std::cout << "O que deseja fazer?" << std::endl;
		std::cout << "1.Mexer no astronauta (Add,AddVoo,List,ListMortos)" << std::endl;
		std::cout << "2.Mexer nos voos (CadVoo,RemAstroVoo,LanVoo,ExpVoo,FinalVoo,ListVooeAstro)" << std::endl;
		std::cout << "3.Tchau" << std::endl;
		std::cin >> escolha;
		// Astronautas:
		switch (escolha)
		{
		case 1:
			std::cout << "1.Cadastrar astronauta" << std::endl;
			std::cout << "2.Adicionar astronauta em voo" << std::endl;
			std::cout << "3.listar Astronautas" << std::endl;
			std::cout << "4.Listar todos os astronautas mortos X-X" << std::endl;
			std::cout << "5.Voltar" << std::endl;
			escolha = 0;
			std::cin >> escolha;
			switch (escolha)
			{
			case 1: // Cria Astronautas
/*
					1.Cadastrar astronauta:
					Cadastra os astronautas recebendo a quantia,a idade, o nome e o CPF 
					e empurrando eles no final do vetor Astronautas Existentes
*/
				std::cout << "Quantos astronautas quer criar?" << std::endl;
				std::cin >> escolha;
				// Repete a funcao de criar para a quantia de astronautas selecionada
				for (int i = 0; i != escolha; i++)
				{
					criaAstronauta(AstronautasExistentes);
					std::cout << "Astronauta criado!" << std::endl;
				}
				std::cout << "Astronautas:" << std::endl;
				listaAstronautas(AstronautasExistentes);
				break;
			case 2: 
/*
					2.Adiciona astronautas nos voos se existem voos E astronautas
					permite a escolha de um astronauta dentre os presentes na lista de astronautas 
					e se ele estiver disponivel e o voo em planejamento, empurra-o no vetor de assentos do voo
*/
				if ((int)voosExistentes.size() > 0 && (int)AstronautasExistentes.size() > 0)
				{
					std::cout << "Qual astronauta deseja adicionar a um voo?" << std::endl;
					listaAstronautas(AstronautasExistentes);
					std::cin >> escolha;
					escolha -= 1;
					if (AstronautasExistentes[escolha].getDisponivel() == 1)
					{
						// Confere se o astronauta esta disponivel
						std::cout << "Em Qual voo?" << std::endl;
						listaVoos(voosExistentes);
						std::cin >> escolha2;
						escolha2 -= 1;
						if (voosExistentes[escolha2].getStatus().compare("EmCurso") != 0)
						{
							// Confere se o voo nao esta em curso
							voosExistentes[escolha2].setPassageiro(AstronautasExistentes[escolha]);
							// Escolhe o voo da lista e utiliza push_back para colocar o astronauta escolhido no final do vetor
							// Assentos, presente em todas as classes Foguetes
							AstronautasExistentes[escolha].setIndisponivel();
							std::cout << "Astronauta Adicionado!" << std::endl;
							// Astronauta vira indisponivel
						}
						else
						{
							std::cout << "O voo selecionado esta indisponivel!" << std::endl;
							break;
						}
					}
					else
					{
						std::cout << "O astronauta selecionado esta indisponivel!" << std::endl;
						break;
					}
				}
				else
				{
					std::cout << "Nao ha astronautas para adicionar ou nao ha voos para os adicionar!" << std::endl;
				}
				break;
			case 3: // Listar astronautas se a lista for maior que 0
				if ((int)AstronautasExistentes.size() > 0)
				{
					listaAstronautas(AstronautasExistentes);
				}
				else
				{
					std::cout << "Nao ha astronautas criados" << std::endl;
					break;
				}
				break;

			case 4: // Listar mortes se a lista for maior que 0
/*
					Caso interessante:
					No programa, os astronautas adicionados a um voo podem ser mortos se o voo está em curso certo?
					a lista de mortos trabalha com os valores exibidos em AstronautasExistentes, no entanto,
					os astronautas eram declarados como mortos apenas dentro dos vetores dos voos, e não na lista
					de astronautas, o que acabou resultando neles estarem vivos nas listas e mortos nos voos, 
					corrigiu-se o problema matando tambêm os astronautas na lista de astronautas.
*/
				escolha = 0;
				if ((int)AstronautasExistentes.size() > 0)
				{
					for (int i = 0; i < (int)AstronautasExistentes.size(); i++)
					{
						// Para cada elemento da lista verificar se Vivo =0 e adicionar 1 ao contador para evitar a mensagem de mortes
						if (AstronautasExistentes[i].getVivo() == 0)
						{
							std::cout << "RIP: " << AstronautasExistentes[i].getNome() << std::endl;
							escolha++;
						}
					}
					if (escolha == 0)
					{
						std::cout << "Nao ha mortes até então!" << std::endl;
					}
				}
				else
				{
					std::cout << "Nao ha astronautas criados" << std::endl;
					break;
				}
				break;
			case 5://VOLTAR
				break;
			}
			break;
		case 2://VOOS!!!
			std::cout << "1.Cadastrar voo" << std::endl;
			std::cout << "2.Remover astronauta de voo" << std::endl;
			std::cout << "3.Lancar voo" << std::endl;
			std::cout << "4.Explodir voo" << std::endl;
			std::cout << "5.Finalizar um voo" << std::endl;
			std::cout << "6.Listar voos (e astronautas)" << std::endl;
			std::cout << "7.Voltar" << std::endl;

			std::cin >> escolha;
			switch (escolha)
			{
			case 1:
				// Cadastra um voo na lista por meio da funcao
				criaVoo(voosExistentes);
				break;
			case 2:
				// Remove astronauta de voos se Existem voos e astronautas
				if ((int)AstronautasExistentes.size() > 0 && (int)voosExistentes.size() > 0)
				{
					std::cout << "De qual voo deseja retirar?" << std::endl;
					listaVoos(voosExistentes);
					std::cin >> escolha;
					escolha -= 1;
					std::cout << "Qual astronauta deseja retirar?" << std::endl;
					// Confere se existem pessoas no voo
					if ((int)voosExistentes[escolha].getAssentos().size() > 0)
					{
						for (int i = 0; i < (int)voosExistentes[escolha].getAssentos().size(); i++)
						{//Para o voo escolhido, mostrar os astronautas presentes em cada assento do voo
							std::cout << i+1<< " " <<voosExistentes[escolha].getAssentos()[i].getNome() << std::endl;
						}
						std::cin >> escolha2;
						escolha2 -= 1;
						//Torna-lo disponivel novamente:
						//pegar passageiro escolhido e compara-lo com o vetor de astronautas
						for(int i=0;i<(int)AstronautasExistentes.size();i++){
							if(voosExistentes[escolha].getAssentos()[escolha2].getCpf().compare(AstronautasExistentes[i].getCpf())==0)
							{
								AstronautasExistentes[i].setDisponivel();
							}
						}
						voosExistentes[escolha].removePassageiro(escolha2);//Funcao para remover passageiro
					}
					else
					{
						std::cout << "Nao ha ninguem no voo" << std::endl;
						break;
					}
				}
				else
				{
					std::cout << "Nao ha voos ou nao ha astronautas para retirar" << std::endl;
					break;
				}
				break;
			case 3:
				// Lanca um voo se existem voos
				if ((int)voosExistentes.size() > 0)
				{
					std::cout << "Qual voo deseja lancar?" << std::endl;
					listaVoos(voosExistentes);
					std::cin >> escolha;
					escolha -= 1;

					if (voosExistentes[escolha].getStatus().compare("EmPlanejamento") == 0 || voosExistentes[escolha].getStatus().compare("FinalizadoOK"))
					{
						// se o voo está em planejamento, muda o Status do voo para "EmCurso"
						voosExistentes[escolha].setStatusLancar();
						std::cout << "Status: " << voosExistentes[escolha].getStatus() << std::endl;
					}
					else
					{
						std::cout << "voo selecionado nao pode ser lancado" << std::endl;
						break;
					}
				}
				else
				{
					std::cout << "Nao ha voos criados!" << std::endl;
					break;
				}
				break;
			case 4://Explodir voos...
				std::cout << "Haverá sangue..." << std::endl;
				std::cout << "Tem certeza que quer prosseguir?" << std::endl;
				std::cout << "1.Sim" << std::endl;
				std::cout << "2.Nao, mudei de ideia, É fácil esmagar um inimigo externo, mas impossível derrotar um inimigo interno." << std::endl;
				std::cin >> escolha;
				// Hora de Explodir!
				if (escolha == 1)
				{
					std::cout << "\033[1;31mEscolha sua vitima:\033[0m" << std::endl;
					// Lista dos voos disponiveis
					listaVoos(voosExistentes);
					std::cin >> escolha;
					escolha -= 1;
					// Perceba que:
					// se" Finalizados (com os astronautas que estavam nele) 
					//		-sinalizar se finalizado com sucesso ou não"
					// Logo: Um voo só explode se está em curso

					if (voosExistentes[escolha].getStatus().compare("EmCurso") == 0)
					{
						// Se o voo estiver em Curso exploda o voo

							voosExistentes[escolha].setStatusExplodir();

						if ((int)voosExistentes[escolha].getAssentos().size() > 0)
						{
							// se o voo nao estiver vazio mate os passageiros
							for(int i=0;i<(int)voosExistentes[escolha].getAssentos().size();i++){
							voosExistentes[escolha].mataAstro(i);
							}
							/*Oba! Os astronautas foram mortos nos voos
							Agora precisamos marca-los como mortos na lista de astronautas
							*/
							for(int i=0;i<(int)AstronautasExistentes.size();i++)
							{
								for(int j=0;j<(int)voosExistentes[escolha].getAssentos().size();j++){
									//nested for loop para comparar o cpf de todos os astronautas da lista com os astronautas do voo

								if(AstronautasExistentes[i].getCpf().compare(voosExistentes[escolha].getAssentos()[j].getCpf())==0)
								{
								//simples! Se seu cpf esta na lista como esta no voo, voce morre! Duas pessoas podem ter o mesmo nome, mas nao o mesmo CPF
								//detalhe... se tiverem infelizmente morrerao os dois!
									AstronautasExistentes[i].Morrer();
								}

								}
							}
							// Frase de culpa:
							std::cout << "Ninguém vai te salvar de mim! Ha ha ha!!" << std::endl;
							std::cout << "Disse o maldito diante da tela do computador" << std::endl;
						}
						else
						{
							std::cout << "Voo vazio..." << std::endl;
						}
					}
				}
				else
				{
					// Frase de consolo
					std::cout << "Você fez a escolha \033[1;32mCerta\033[0m" << std::endl;
				}
				break;
			case 5://Finalizar voo

				std::cout << "Qual voo deseja finalizar?" << std::endl;
				listaVoos(voosExistentes);
				std::cin >> escolha;
				escolha -= 1;
				// Se o voo escolhido estiver em curso
				if (voosExistentes[escolha].getStatus().compare("EmCurso") == 0)
				{
					voosExistentes[escolha].setStatusFinalizar();
					std::cout << "Status: " << voosExistentes[escolha].getStatus() << std::endl;
					for(int i=0;i<voosExistentes[escolha].getAssentos().size();i++)
					{
						for(int j=0;j<AstronautasExistentes.size();j++)
						{
							if(voosExistentes[escolha].getAssentos()[i].getCpf().compare(AstronautasExistentes[j].getCpf())==0)
							{
								//Se o astronauta for o mesmo na lista do que o presente no fuguete, sua disponibilidade voltara para 1
								AstronautasExistentes[j].setDisponivel();
							}
						}
					}
					//Limpar assentos do voo removendo 1 por 1
					for (int i=0;i<voosExistentes[escolha].getAssentos().size();i++)
					{
					voosExistentes[escolha].removePassageiro(i);	
					}
				}
				else
				{
					std::cout << "Voo nao esta em curso" << std::endl;
				}
				break;
			case 6:
			//Listagem dos voos
				listaVoos(voosExistentes);

				break;
			case 7://Voltar
				break;
			} // Fim do switch escolha em mexer em voo
			break;
		case 3:
			rodando = 0;
			break;
		} // fim do switch de escolha no loop
	}	  // fim do while loop
	return 0;
} // fim da main

/*

*/
