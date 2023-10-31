#include <vector>
#include <iostream>

void insertionSort(std::vector<int>& valores){
    for(int i = 0; i < valores.size(); i++){
        for(int j = i; j > 0 && valores[j - 1] > valores[j]; j--){
            int aux = valores[j];
            valores[j] = valores[j - 1];
            valores[j - 1] = aux;
        }
    }
}

int main(){
    std::vector<int> valores;
    valores = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    for(auto i : valores){
        std::cout << i << ", ";
    }

    std::cout << "\n";

    insertionSort(valores);

    for(auto i : valores){
        std::cout << i << ", ";
    }

    std::cout << "\n";

    return 0;

}