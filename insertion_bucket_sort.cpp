#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <fstream>
#include <chrono>

void insertionSort(std::vector<int>& valores){
    for(int i = 0; i < valores.size(); i++){
        for(int j = i; j > 0 && valores[j - 1] > valores[j]; j--){
            int aux = valores[j];
            valores[j] = valores[j - 1];
            valores[j - 1] = aux;
        }
    }
}

void fillBuckets(std::vector<int>& valores, std::vector<std::vector<int>>& buckets, int n_buckets){
    
    buckets.resize(n_buckets);

    int lower_bound = *std::min_element(valores.begin(), valores.end());
    int upper_bound = *std::max_element(valores.begin(), valores.end());
    int bucket_range = ceil(double(upper_bound - lower_bound + 1)/double(n_buckets));

    int vector_size = valores.size();
    for(int i = 0; i < vector_size; i++){
        buckets[(valores[i] - lower_bound)/bucket_range].push_back(valores[i]);
    }

}

void sortBuckets(std::vector<std::vector<int>>& buckets){
    for(auto &i : buckets)
        insertionSort(i);
    
}

void printVector(const std::vector<int>& vector){
    for (auto i : vector){
        std::cout << i << " ";
    }
    std::cout << "\n";
}

void joinBuckets(std::vector<int>& valores, const std::vector<std::vector<int>>& buckets){
    int k = 0;
    
    for(auto& i : buckets)
        for(auto j : i)
            valores[k++] = j;
}

int main (int argc, char **argv){
    std::vector<int> valores;
    std::vector<std::vector<int>> buckets;
    int n_buckets = atoi(argv[1]);
    int vector_size = atoi(argv[2]);

    std::ifstream myfile;
    std::string name_of_file;
    std::string aleatorios = "./Aleatorios/a", dec = "./Decrescentes/d", 
    ord = "./Ordenados/o", po = "./ParcialmenteOrdenados/po";
    std::string final_arq = ".txt";

    if(strcmp(argv[3], "-a") == 0){
        name_of_file = aleatorios + argv[2] + final_arq;
    }
    else if(strcmp(argv[3], "-d") == 0){
        name_of_file = dec + argv[2] + final_arq;
    }
    else if(strcmp(argv[3], "-o") == 0){
        name_of_file = ord + argv[2] + final_arq;
    }
    else if(strcmp(argv[3], "-po") == 0){
        name_of_file = po + argv[2] + final_arq;
    } 
    else{
        std::cout << "entrada invalida.\n";
        return -1;
    }
    myfile.open(name_of_file, std::ios_base::in);

    int input;
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
    /*for(int i = 0; i < vector_size; i++){
        std::cin >> input;
        valores[i] = input;
    }*/


    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    //printVector(valores);

    fillBuckets(valores, buckets, n_buckets);
    sortBuckets(buckets);
    joinBuckets(valores, buckets);

    //printVector(valores);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

    return 0;
}