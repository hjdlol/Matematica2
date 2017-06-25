#pragma once

class Matriz
{
public:
	float achou;
	int x = 0; int y = 0;
	Matriz();
	Matriz(float e1, float e2, float e3, float e4, float e5, float e6, float e7, float e8, float e9);
	Matriz(Matriz& MatrizToCopy);
    Matriz achar(x,y);
	Matriz Tranposta();
	Matriz Inversa();
	float Determinante();
	Matriz& operator =(Matriz base);
	Matriz& operator*(Matriz mult);

private:
	float matriz[3][3];
	
};

//Cria��o da matriz identidade
Matriz::Matriz()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j) {
				matriz[i][j] = 1;
			}
			else
				matriz[i][j] = 0;
		}
	}
}
//Cria��o de matriz aonde os valores s�o dados pelo usuario
Matriz::Matriz(float e1, float e2, float e3, float e4, float e5, float e6, float e7, float e8, float e9)
{
	matriz[0][0] = e1;
	matriz[0][1] = e2;
	matriz[0][2] = e3;
	matriz[1][0] = e4;
	matriz[1][1] = e5;
	matriz[1][2] = e6;
	matriz[2][0] = e7;
	matriz[2][1] = e8;
	matriz[2][2] = e9;
}




//Cria��o da matriz tranposta a partir dos valores da matriz dada pelo usuario
Matriz Matriz::Tranposta()
{

	Matriz transp(matriz[0][0], matriz[1][0], matriz[2][0],
		matriz[0][1], matriz[1][1], matriz[2][1],
		matriz[0][2], matriz[1][2], matriz[2][2]);

	return transp;
}



//Calculo do determinante da matriz
float Matriz::Determinante()
{
	float determinante = matriz[0][0] * matriz[1][1] * matriz[2][2]
		+ matriz[0][1] * matriz[1][2] * matriz[2][0]
		+ matriz[0][2] * matriz[1][0] * matriz[2][1]
		- matriz[0][2] * matriz[1][1] * matriz[2][0]
		- matriz[1][2] * matriz[2][1] * matriz[0][0]
		- matriz[2][2] * matriz[0][1] * matriz[1][0];

	return determinante;
}

//construtor que copia a matriz passada;
Matriz::Matriz(Matriz& MatrizToCopy) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matriz[i][j] = MatrizToCopy.matriz[i][j];
		}
	}
};


//m�todo que iguala a matriz a outra
Matriz& Matriz::operator =(Matriz base) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matriz[i][j] = base.matriz[i][j];
		}
	}
	return *this;
}

//m�todo que multiplica a matriz por outra
Matriz& Matriz::operator *(Matriz mult) {
	Matriz base(matriz[0][0] * mult.matriz[0][0] + matriz[0][1] * mult.matriz[1][0] + matriz[0][2] * mult.matriz[2][0],
		matriz[0][0] * mult.matriz[0][1] + matriz[0][1] * mult.matriz[1][1] + matriz[0][2] * mult.matriz[2][1],
		matriz[0][0] * mult.matriz[0][2] + matriz[0][1] * mult.matriz[1][2] + matriz[0][2] * mult.matriz[2][2],
		matriz[1][0] * mult.matriz[0][0] + matriz[1][1] * mult.matriz[1][0] + matriz[1][2] * mult.matriz[2][0],
		matriz[1][0] * mult.matriz[0][1] + matriz[1][1] * mult.matriz[1][1] + matriz[1][2] * mult.matriz[2][1],
		matriz[1][0] * mult.matriz[0][2] + matriz[1][1] * mult.matriz[1][2] + matriz[1][2] * mult.matriz[2][2],
		matriz[2][0] * mult.matriz[0][0] + matriz[2][1] * mult.matriz[1][0] + matriz[2][2] * mult.matriz[2][0],
		matriz[2][0] * mult.matriz[0][1] + matriz[2][1] * mult.matriz[1][1] + matriz[2][2] * mult.matriz[2][1],
		matriz[2][0] * mult.matriz[0][2] + matriz[2][1] * mult.matriz[1][2] + matriz[2][2] * mult.matriz[2][2]);
	return base;
}



