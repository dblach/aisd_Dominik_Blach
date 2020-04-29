#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <ctime>
#include <sstream>

const int max_number=1'000'000;

std::istringstream create_test_stream(int num_numbers,bool random){
    std::ostringstream out;
    std::mt19937_64 generator(std::time(nullptr));
    std::uniform_int_distribution<int> distribution(0,::max_number);
    
    for(int i=0;i<num_numbers;i++){
        if(random) out<<distribution(generator)<<"\n";
        else out<<i<<"\n";
    }

    std::istringstream result_stream(out.str());
    return result_stream;
}

int max_consecutive_sum(std::istream& in,size_t K){
    int sum=0;
    std::vector<int> buffer(K);

    for(size_t i=0;i<K;i++){
        in>>buffer[i];
        sum+=buffer[i];
    }
    int max_sum=sum;
    int tmp;
    size_t current_index=0;
    while(in>>tmp){
        sum-=buffer[current_index];
        sum+=tmp;
        buffer[current_index]=tmp;
        if(max_sum<sum) max_sum=sum;
        current_index++;
        if(current_index==buffer.size()) current_index=0;
    }
    return max_sum;
}

int main(){
    const int N=1'000'000;
    const int K=1000;
    std::istringstream in_stream=create_test_stream(N,true);
    auto max_sum=max_consecutive_sum(in_stream,K);
    std::cout<<max_sum<<"\t"<<"average element value: "<<max_sum/float(K)<<"\n";
    
    in_stream=create_test_stream(N,false);
    max_sum=max_consecutive_sum(in_stream,K);
    std::cout<<max_sum<<"\t"<<"average element value: "<<max_sum/float(K)<<"\n";
    
}