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

int main(int argc, char **argv){
    std::vector<int> valores;
    int vector_size = atoi(argv[1]);

    int input;
    valores.resize(vector_size);
    for(int i = 0; i < vector_size; i++){
        std::cin >> input;
        valores[i] = input;
    }

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