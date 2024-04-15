#pragma once
#include <iostream>
#include <vector>
#include <string>

class Astronauta
{
        std::string cpf, nome;
        int idade;
        int disponivel, vivo;

public:
        Astronauta()
        {
                disponivel = 1;
                vivo = 1;
        }
        void setCpf();
        void setNome();
        void Morrer();
        void setIdade();
        void setDisponivel();
        void setIndisponivel();

        std::string getCpf();
        std::string getNome();
        int getIdade();
        int getDisponivel();
        int getVivo();
};

class Foguetes
{
        int codigoDoVoo;
        std::string status;
        std::vector<Astronauta> assentos;
        /* EmPlanejamento == voo em planejamento
         * EmCurso == voo lancado
         * FinalizadoOK== voo finalizado com sucesso
         * FinalizadoERROR == voo finalizado sem sucess
         */
public:
        Foguetes()
        {
                status = "EmPlanejamento";
        }
        void setCodigoDoVoo(int inteiro);
        void setStatusLancar();
        void setStatusExplodir();
        void setStatusFinalizar();
        void setPassageiro(Astronauta astro);
        void removePassageiro(int escolha);

        void mataAstro(int escolha);

        int getCodigoDoVoo();
        std::string getStatus();
        std::vector<Astronauta> getAssentos();
};

void criaAstronauta(std::vector<Astronauta> &AstronautasExistentes);

void criaVoo(std::vector<Foguetes> &voosExistentes);

void listaVoos(std::vector<Foguetes> voosExistentes);

void listaAstronautas(std::vector<Astronauta> AstronautasExistentes);