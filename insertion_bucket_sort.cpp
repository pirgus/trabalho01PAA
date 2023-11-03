#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <fstream>
#include <chrono>

void insertionSort(std::vector<int>& valores) {
    int n = valores.size();
    for (int i = 1; i < n; i++) {
        int key = valores[i];
        int j = i - 1;

        while (j >= 0 && valores[j] > key) {
            valores[j + 1] = valores[j];
            j--;
        }

        valores[j + 1] = key;
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

    std::chrono::steady_clock::time_point begin_split = std::chrono::steady_clock::now();
    fillBuckets(valores, buckets, n_buckets);
    std::chrono::steady_clock::time_point end_split = std::chrono::steady_clock::now();

    std::chrono::steady_clock::time_point begin_sorting = std::chrono::steady_clock::now();
    sortBuckets(buckets);
    std::chrono::steady_clock::time_point end_sorting = std::chrono::steady_clock::now();

    std::chrono::steady_clock::time_point begin_join = std::chrono::steady_clock::now();
    joinBuckets(valores, buckets);
    std::chrono::steady_clock::time_point end_join = std::chrono::steady_clock::now();

    //printVector(valores);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "************** " << n_buckets << "buckets " << valores.size() << " elements " << "***********\n";
    std::cout << "Total------------------------------------------\n";
    std::cout << "Microssegundos = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    std::cout << "Nanossegundos = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    std::cout << "Milissegundos: = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[m]" << std::endl;
    std::cout << "Segundos = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << "[s]" << std::endl;
    std::cout << "Minutos = " << std::chrono::duration_cast<std::chrono::minutes> (end - begin).count() << "[min]" << std::endl;
    std::cout << "Horas = " << std::chrono::duration_cast<std::chrono::hours> (end - begin).count() << "[h]" << std::endl;

    std::cout << "Split------------------------------------------\n";
    std::cout << "Microssegundos = " << std::chrono::duration_cast<std::chrono::microseconds>(end_split - begin_split).count() << "[µs]" << std::endl;
    std::cout << "Nanossegundos = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end_split - begin_split).count() << "[ns]" << std::endl;
    std::cout << "Milissegundos: = " << std::chrono::duration_cast<std::chrono::milliseconds> (end_split - begin_split).count() << "[m]" << std::endl;
    std::cout << "Segundos = " << std::chrono::duration_cast<std::chrono::seconds> (end_split - begin_split).count() << "[s]" << std::endl;
    std::cout << "Minutos = " << std::chrono::duration_cast<std::chrono::minutes> (end_split - begin_split).count() << "[min]" << std::endl;
    std::cout << "Horas = " << std::chrono::duration_cast<std::chrono::hours> (end_split - begin_split).count() << "[h]" << std::endl;

    std::cout << "Sort----------------------------------------\n";
    std::cout << "Microssegundos = " << std::chrono::duration_cast<std::chrono::microseconds>(end_sorting - begin_sorting).count() << "[µs]" << std::endl;
    std::cout << "Nanossegundos = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end_sorting - begin_sorting).count() << "[ns]" << std::endl;
    std::cout << "Milissegundos: = " << std::chrono::duration_cast<std::chrono::milliseconds> (end_sorting - begin_sorting).count() << "[m]" << std::endl;
    std::cout << "Segundos = " << std::chrono::duration_cast<std::chrono::seconds> (end_sorting - begin_sorting).count() << "[s]" << std::endl;
    std::cout << "Minutos = " << std::chrono::duration_cast<std::chrono::minutes> (end_sorting - begin_sorting).count() << "[min]" << std::endl;
    std::cout << "Horas = " << std::chrono::duration_cast<std::chrono::hours> (end_sorting - begin_sorting).count() << "[h]" << std::endl;

    std::cout << "Join----------------------------------------\n";
    std::cout << "Microssegundos = " << std::chrono::duration_cast<std::chrono::microseconds>(end_join - begin_join).count() << "[µs]" << std::endl;
    std::cout << "Nanossegundos = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end_join - begin_join).count() << "[ns]" << std::endl;
    std::cout << "Milissegundos: = " << std::chrono::duration_cast<std::chrono::milliseconds> (end_join - begin_join).count() << "[m]" << std::endl;
    std::cout << "Segundos = " << std::chrono::duration_cast<std::chrono::seconds> (end_join - begin_join).count() << "[s]" << std::endl;
    std::cout << "Minutos = " << std::chrono::duration_cast<std::chrono::minutes> (end_join - begin_join).count() << "[min]" << std::endl;
    std::cout << "Horas = " << std::chrono::duration_cast<std::chrono::hours> (end_join - begin_join).count() << "[h]" << std::endl;

    return 0;
}