//simulador de jogo de dados craps
#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>//contém os protótipos para as funções srand e rand;
using std::rand;
using std::srand;

#include <ctime>//contém o protótipo para a função time
using std::time;

int rollDice();//rola os dados

int main(){
	//enumeração de com constantes que representam o status do jogo
	enum Status {CONTINUA, VENCEU, PERDEU};
	
	int myPoint;//pontos se não ganhar ou perder na primeira rolagem
	Status gameStatus;// pode conter CONTINUA, VENCEU, PERDEU
	
	//aleatoriza os dados utilizando a hora atual
	srand( time(0) ); 
	int sumOfDice = rollDice();//primeira rolagem
	//determina status e pontuação do jogo(se necessário) com base na primeira rolagem

	switch(sumOfDice){

		//ganha na primeira rolagem
		case 7:
		case 11:
		gameStatus = VENCEU;
		break;

		//perde na primeira rolagem
		case 2:
		case 3:
		case 12:
		gameStatus = PERDEU;
		break;
		
		//jogo continua pois não terminou na primeira rolagem, registra a pontuação
		default:
		gameStatus = CONTINUA;
		myPoint = sumOfDice;
		cout << "A pontuação é " << myPoint <<endl;
		break;
		
	} //fim do switch

	//continua o jogo até o fim
	while (gameStatus == CONTINUA){
		sumOfDice = rollDice();

		//testa pra ver se o número rolados é igual a pontuação
		if(sumOfDice == myPoint)
			gameStatus = VENCEU;
			else
				if(sumOfDice == 7)
					gameStatus = PERDEU;	
	}//fim do while
	if (gameStatus == VENCEU)
		cout << "O jogador venceu!" <<endl;
	else
	cout << "O jogador perdeu" <<endl;
	return 0;
}//fim de main

int rollDice(){

	//seleciona valores aleatórios dos dados
	int die1 = 1+rand()%6;
	int die2 = 1+rand()%6;
	
	//soma os valores dos dados
	int sum = die1 + die2;
	
	//exibe o resultado
	cout << "O Jogador rolou " << die1 <<" + "<< die2 << " = " << sum << endl;
	
	//retorna a soma dos dados
	return sum;
} 
