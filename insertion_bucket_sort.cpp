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
    int bucket_range = ceil(double(upper_bound - lower_bound)/n_buckets);

    std::cout << bucket_range << " \n";
    for(auto i: valores){
       //buckets[]; 
    }
}

int main (){
    std::vector<int> valores;
    std::vector<std::vector<int>> buckets;
    int n_buckets = 2;

    valores = {100,101,102,103,104};
    fillBuckets(valores, buckets, n_buckets);

    return 0;
}