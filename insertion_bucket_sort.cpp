#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

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

    int input;
    valores.resize(vector_size);
    for(int i = 0; i < vector_size; i++){
        std::cin >> input;
        valores[i] = input;
    }

    printVector(valores);

    fillBuckets(valores, buckets, n_buckets);
    sortBuckets(buckets);
    joinBuckets(valores, buckets);

    printVector(valores);

    return 0;
}