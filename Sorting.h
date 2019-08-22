#include <vector>
template<typename T>
struct Sorting{
  
  void Bubble(vector<T>& lista){
	int tamano = lista.size();
	if(tamano>1){
		for (int j = 0; j < tamano; j++) {
			for(int k = 0; k < tamano - 1; k++){
          if(lista[j]<lista[k]){
            T aux = lista[k];
            lista[k]=lista[j];
            lista[j] = aux;
          }
			}
		}
	}
}
  
}
