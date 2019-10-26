#include <iostream>
#include "BigNum.h"
#include "BigNumParal.h"
#include "Helper.h"
#include <fstream>
#include <ctime>
#include <chrono>

int maian() {
    auto help = Helper();
    std::string pathToA = R"(C:\Users\georg\Desktop\An3_sem1\PPD\lab1_cpp\num_file_a.txt)";
    std::string pathToB = R"(C:\Users\georg\Desktop\An3_sem1\PPD\lab1_cpp\num_file_b.txt)";
    std::string toParall = R"(C:\Users\georg\Desktop\An3_sem1\PPD\lab1_cpp\parallel_res.txt)";
    std::string toSecv = R"(C:\Users\georg\Desktop\An3_sem1\PPD\lab1_cpp\secv_res.txt)";
    std::string toNum = R"(C:\Users\georg\Desktop\An3_sem1\PPD\lab1_cpp\num.txt)";
    std::string toNum1 =R"(C:\Users\georg\Desktop\An3_sem1\PPD\lab1_cpp\num1.txt)";
    std::vector<int> A = help.readBigFromFile(pathToA);
    std::vector<int> B = help.readBigFromFile(pathToB);

    auto num = BigNum(A);
    auto num1 = BigNum(B);
    double execTime = 0.0;
    auto start = std::chrono::steady_clock::now();
    auto rez = num + num1;
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    auto time = std::chrono::duration <double, std::milli> (diff).count();
    time = time*0.001;

    std::cout << "Secvential: " << time << '\n';
    /*
    std::ofstream out(toSecv);
    for(int i = rez.getNum().size() - 1; i>=0; i--){
        out << rez.getNum()[i];
    }

    out.close();*/
    rez = addNumsParallelBad(num, num1, 100, execTime);
    std::cout << "Paralel bad: " << execTime << '\n';
    /*
    std::ofstream out1(toParall);
    for(int i = rez.getNum().size() - 1; i>=0; i--){
        out1 << rez.getNum()[i];
    }

    out1.close();*/
    rez = addNumsParallelGood(num, num1, 100, execTime);
    std::cout << "Parallel good: " << execTime << '\n';
    return 0;
}


void print(std::vector<int> v){
    for(int i:v){
        std::cout << i << " ";
    }
    std::cout << "\n";
}

bool compare(std::vector<int> a,std::vector<int> b){
    for(int i=0;i<a.size();i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}

int maasdin() {
    ///demo for lab0
    //std::cout << "Hello, World!" << std::endl;
    //string a = string("random.txt");





    //generateRandomIntegers(a,50*50,1,40);
    //cout << similarFiles(string("a.txt"), string("b.txt"));
    //writeToExcel(string("C:\\Users\\mihai\\Desktop\\a.csv"), vector<string>{string("A"),string("B"),string("55")});
    //cout << runMultiple(string("C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe"),2);

    ///demo for lab1
    bool match;
    do{
        srand(time(NULL));
        int TEST_SIZE = 20;
        int THREAD_COUNT = 5;
        auto a = std::vector<int>();
        auto b = std::vector<int>();

        for(int i=0;i<TEST_SIZE;i++){
            a.push_back(rand()%10);
            b.push_back(rand()%10);
        }
        auto A = BigNum(a);
        auto B = BigNum(b);

        auto aa = A.getNum();
        auto bb = B.getNum();

        std::reverse(aa.begin(), aa.end());
        std::reverse(bb.begin(), bb.end());
        print(aa);
        print(bb);
        std::cout<<"\n";

        auto res = A + B;
        auto ress = res.getNum();
        std::reverse(ress.begin(), ress.end());
        print(ress);




        double execTime = 0.0;
        auto res1 = addNumsParallelGood(A, B, THREAD_COUNT, execTime);
        auto ress1 = res1.getNum();
        std::reverse(ress1.begin(), ress1.end());
        print(ress1);

        match = compare(res.getNum(),res1.getNum());
        std::cout<<"Match: " << match << "\n";
    }while(match);
    return 0;
}