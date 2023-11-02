#include <vector>
#include <iostream>
#include <chrono>
#include <fstream>
#include <string.h>

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
    std::ifstream myfile;
    std::string name_of_file;
    std::string aleatorios = "./Aleatorios/a", dec = "./Decrescentes/d", 
    ord = "./Ordenados/o", po = "./ParcialmenteOrdenados/po";
    std::string final_arq = ".txt";

    
    if(strcmp(argv[2], "-a") == 0){
        name_of_file = aleatorios + argv[1] + final_arq;
    }
    else if(strcmp(argv[2], "-d") == 0){
        name_of_file = dec + argv[1] + final_arq;
    }
    else if(strcmp(argv[2], "-o") == 0){
        name_of_file = ord + argv[1] + final_arq;
    }
    else if(strcmp(argv[2], "-po") == 0){
        name_of_file = po + argv[1] + final_arq;
    } 
    else{
        std::cout << "entrada invalida.\n";
        return -1;
    }
    myfile.open(name_of_file, std::ios_base::in);
    //std::string current_num;

    valores.resize(vector_size);
    int current_num = 0;

    if(myfile.is_open()){
        for(int i = 0; i < vector_size && myfile >> current_num; i++){
            //std::cout << current_num << "\n";
            valores[i] = current_num;
            //std::cout << "iteracao = " << i << "\n";
        }
    }
    else{
        std::cout << "falha ao abrir o arquivo\n";
        return -1;
    }

    //int input;
    /*
    for(int i = 0; i < vector_size; i++){
        std::cin >> input;
        valores[i] = input;
    }*/

    /*for(auto i : valores){
        std::cout << i << ", ";
    }*/

    //std::cout << "\n";

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    insertionSort(valores);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    /*for(auto i : valores){
        std::cout << i << ", ";
    }*/

    //std::cout << "\n";


    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;


    return 0;

}