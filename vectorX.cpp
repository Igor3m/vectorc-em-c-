#include <iostream>

using namespace std;

class vectorX{
	private:
	int* vetor;
	int tam;
	
	public:
	vectorX(int n);
	~vectorX();
	void preenche(int* vec);
	void imprime();
	void concatena(vectorX* vet1, vectorX* vet2);
	void produtoInterno(vectorX* vec);
};

vectorX::vectorX(int n){
	vetor = new int[n];
	tam = n;
}
vectorX::~vectorX(){
	cout << "morri" << endl;
	delete[] vetor;
	tam = 0;
}
void vectorX::preenche(int* vec){
	for (int i=0; i<tam; i++){
		vetor[i] = vec[i];
	}
}
void vectorX::imprime(){
	for (int i=0; i<tam; i++){
		cout << vetor[i] << " ";
	}
	cout << endl;
}
void vectorX::concatena(vectorX*vet1, vectorX*vet2){
	delete[] vetor;
	tam = vet1->tam + vet2->tam;
	vetor = new int[tam];
	
	for (int i=0; i<vet1->tam; i++){
		vetor[i] = vet1->vetor[i];
	}
	for (int i=0; i<vet2->tam; i++){
		vetor[i+vet1->tam] = vet2->vetor[i];
	}
}
void vectorX::produtoInterno(vectorX* vec){
	int result = 0;
	//for (int i=0; i<tam; i++){
		//vetor[i] = vec[i];
	//}
	for (int i=0; i<tam; i++){
		result += vetor[i]*vec->vetor[i];
	}
	cout << result << endl;
}

int main(){
	int tamanho, *vec;
	cin >> tamanho;
	vec = new int[tamanho];
	vectorX* vet1;
	vet1 = new vectorX(tamanho);
	for (int i=0; i<tamanho; i++){
		cin >> vec[i];
	}
	vet1->preenche(vec);
	vet1->imprime();
	int tamanho2, *vec2;
	cin >> tamanho2;
	vec2 = new int[tamanho2];
	vectorX* vet2;
	vet2 = new vectorX(tamanho2);
	for (int i=0; i<tamanho2; i++){
		cin >> vec2[i];
	}
	vet2->preenche(vec2);
	vet2->imprime();
	int tamanho3;
	tamanho3 = tamanho+tamanho2;
	vectorX* vet3;
	vet3 = new vectorX(tamanho3);
	vet3->concatena(vet1,vet2);
	vet3->imprime();
	int* vec4, tamanho4;
	cin >> tamanho4;
	vec4 = new int[tamanho4];
	for (int i=0; i<tamanho4; i++){
		cin >> vec4[i];
	}
	vectorX* vet4;
	vet4 = new vectorX(tamanho4);
	vet4->preenche(vec4);
	vet4->produtoInterno(vet4);
	return 0;
}
