#include <regex>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>

#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string &str) {
  std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const {
  // Neste exemplo usaremos expressoes regulares para verificar se uma linha
  // eh valida ou nao.
  //
  // Esta expressao regular eh formada por cinco partes. Cada uma dessas
  // partes eh um dos tres tipos de padrao regular abaixo:
  //
  // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
  // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
  // \\d+ eh qualquer sequencia de um ou mais digitos
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

  // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
  // a expressao regular que acabamos de criar:
  return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str) {
  //
  // Em geral eh mais facil ler dados de uma string se a string eh transformada
  // em um objeto do tipo stringstream:
  std::stringstream ss(str);
  //
  // Iremos ler os dados da string nestas tres variaveis abaixo:
  std::string nomePais;
  unsigned populacao, percUrbana;
  //
  // Como sabemos que a linha contem string int int, podemos fazer a leitura
  // facilmente usando o operador de streaming:
  ss >> nomePais >> populacao >> percUrbana;
  //
  // Note que precisamos arredondar o valor que serah impresso. O arredondamento
  // serah feito via a funcao floor. Ou seja, decimais serao sempre
  // arredondados para baixo:
  unsigned popRural = floor(populacao - (populacao * (percUrbana/100.0)));
  //
  // Uma vez encontrados os valores que precisam ser impressos, seguimos o
  // modelo do enunciado do exercicio:
  std::cout << popRural << " pessoas vivem no campo no " << nomePais <<
    std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const {
  std::regex regularExpr("^[0-9| ]+$");
  return std::regex_match(str, regularExpr);
}

void ContadorNumNaturais::processaLinha(const std::string &str) {
  unsigned aux, soma = 0;
  std::stringstream ss(str);
  while(ss >> aux){
    soma += aux;
  }
  std::cout << soma << std::endl;
}

bool LeitorDeFutebol::linhaValida(const std::string &str) const {
  std::regex regularExpr("\\s*\\w+\\s*\\d+\\s*\\w+\\s*\\d+");
  return std::regex_match(str, regularExpr);
}

void LeitorDeFutebol::processaLinha(const std::string &str) {
  std::stringstream ss(str);
  std::string time1, time2;
  unsigned gols1, gols2;
  ss >> time1 >> gols1 >> time2 >> gols2;
  if(gols1 > gols2){
    std::cout << "Vencedor: " << time1 << std::endl;
  }
  else if(gols1 == gols2){
    std::cout << "Empate" << std::endl;
  }
  else{
    std::cout << "Vencedor: " << time2 << std::endl;
  }
}

void ContadorDePalavras::processaLinha(const std::string &str) {
  unsigned soma = 0;
  std::string aux;
  std::stringstream ss(str);
  while(ss >> aux){
    soma ++;
  }
  std::cout << soma << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const {
  std::regex regularExpr("^[A-Za-z| ]+$");
  return std::regex_match(str, regularExpr);
}

void InversorDeFrases::processaLinha(const std::string &str) {
    std::vector<std::string> v;
    std::string boi, finalstring = "";
    std::stringstream ss(str);
    while(ss >> boi){
    v.push_back(boi);
    }
    for(auto it = v.end()-1; it != v.begin()-1; it--){
        finalstring += *it;
        if(it != v.begin()){
            finalstring += " ";
        }
    }
    std::cout << finalstring << std::endl;
}

bool EscritorDeDatas::linhaValida(const std::string &str) const {
  std::string dateFormat = "\\s*\\d\\d?/\\d\\d?/\\d{4}";
 std::regex regularExpr(dateFormat);
  return std::regex_match(str, regularExpr);
}

void EscritorDeDatas::processaLinha(const std::string &str) {
  int aux = 0; //01/01/2020
  std::string mes, mesString;
  for (int i = 0; i < str.length(); i++){
    if(str[i] == '/'){
        aux++;
        continue;
    }
    if(aux == 1){
        mes += str[i];
    }
    if(aux == 2){
        break;
    }
  }
  int mesNum = std::stoi(mes);
    switch (mesNum) {
        case 1:
            mesString = "Jan";
            break;
        case 2:
            mesString = "Fev";
            break;
        case 3:
            mesString = "Mar";
            break;
        case 4:
            mesString = "Abr";
            break; 
        case 5:
            mesString = "Mai";
            break;
        case 6:
            mesString = "Jun";
            break;
        case 7:
            mesString = "Jul";
            break;
        case 8:
            mesString = "Ago";
            break;
        case 9:
            mesString = "Set";
            break;
        case 10:
            mesString = "Out";
            break;
        case 11:
            mesString = "Nov";
            break;
        case 12:
            mesString = "Dez";
            break;
    }
  std::cout << mesString << std::endl;
}