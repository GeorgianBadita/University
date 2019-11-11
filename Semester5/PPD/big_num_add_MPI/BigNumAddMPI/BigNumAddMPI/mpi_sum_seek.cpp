#include <stdio.h>
#include "mpi.h"
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <chrono>
#define MAIN 0

std::vector<int>readFromFile(const std::string& path) {
	std::vector<int> number;
	std::ifstream in(path);
	int x;
	while (in >> x) {
		number.push_back(x);
	}
	in.close();
	return number;
}

int main(int argc, char** argv) {
	std::vector<int> a, b, result; //first number, second number, result 
	int* local_result;
	int rank, procCount;

	MPI_Init(&argc, &argv); //Initialize MPI environment
	MPI_Comm_size(MPI_COMM_WORLD, &procCount); //number of processes
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); //rank of the current process

	std::string path_to_a = "C:\\Users\\georg\\Desktop\\University\\Semester5\\PPD\\big_num_add_MPI\\BigNumAddMPI\\BigNumAddMPI\\num_file_a.in"; //path to first number
	std::string path_to_b = "C:\\Users\\georg\\Desktop\\University\\Semester5\\PPD\\big_num_add_MPI\\BigNumAddMPI\\BigNumAddMPI\\num_file_b.in"; //path to second number
	std::string path_to_res = "C:\\Users\\georg\\Desktop\\University\\Semester5\\PPD\\big_num_add_MPI\\BigNumAddMPI\\BigNumAddMPI\\result.txt"; //path to result


	if (rank == MAIN) {
		a = readFromFile(path_to_a);

		int len = a.size();

		for (int i = 0; i < a.size(); i++) {
			result.push_back(-1);
		}
		procCount--;
		int start = 0, stop = 0;
		int digitsPerProc = len / procCount; //per process
		int remaining = len % procCount; //reminder

		local_result = (int*)malloc(sizeof(int) * (digitsPerProc + 1));
		auto start_time = std::chrono::steady_clock::now();
		for (int i = 1; i <= procCount; i++)
		{
			stop = start + digitsPerProc;
			if (remaining > 0) {
				stop += 1;
				remaining -= 1;
			}


			int count = stop - start;
			MPI_Send(&start, 1, MPI_INT, i, 0, MPI_COMM_WORLD); //send start
			MPI_Send(&count, 1, MPI_INT, i, 0, MPI_COMM_WORLD); //send count

			start = stop;
		}
		start = 0;
		stop = 0;

		remaining = len % procCount;

		for (int i = 1; i <= procCount; i++) {

			stop = start + digitsPerProc;
			if (remaining > 0) {
				stop += 1;
				remaining -= 1;
			}
			int count = stop - start;

			MPI_Recv(local_result, count, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //receiving result from process i

			for (int j = start; j < stop; j++) {
				result[j] = local_result[j - start];	//setting the result
			}
			start = stop;
		}
		auto stop_time = std::chrono::steady_clock::now();
		auto diff = stop_time - start_time;
		auto time = std::chrono::duration<float, std::milli>(diff).count();
		time = time * 0.001;
		printf("Total time: %f\n", time);
		free(local_result);
		std::ofstream out(path_to_res);
		int carry = 0;
		for (int i = 0; i < result.size(); i++) {
			result[i] += carry;
			carry = result[i] / 10;			//add carry operations
			result[i] %= 10;
			printf("%d", result[i]);
		}
		if (carry)
			printf("%d", carry);
	}
	else
	{
		int digitCount, start;
		MPI_Recv(&start, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //recv start
		MPI_Recv(&digitCount, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //recv count
		std::ifstream inA(path_to_a);	//open path_to_a file
		std::ifstream inB(path_to_b);	//open path_to_b file
		char* recvA = (char*)malloc(sizeof(char) * (digitCount * 2)); //2*digitCount for spaces
		char* recvB = (char*)malloc(sizeof(char) * (digitCount * 2)); //2*digitCount for spaces

		inA.seekg(2 * start);	//setting the file descriptor to positon 2*start
		inB.seekg(2 * start); //setting the file descriptor to position 2*start
		inA.read(recvA, digitCount * 2);	//reading 2*digitCount elements
		inB.read(recvB, digitCount * 2);	//reading 2*digitCount elements

		int* processResult = (int*)malloc(sizeof(int) * digitCount);
		//std::cout << rank << " " << start << " " << digitCount << "::" << recvA << ";";
		for (int i = 0; i < digitCount; i++)
		{
			processResult[i] = recvA[2 * i] + recvB[2 * i] - 2 * '0'; //add operation
			//std::cout << processResult[i] << " ";
		}
		//std::cout << '\n';
		MPI_Send(processResult, digitCount, MPI_INT, 0, 0, MPI_COMM_WORLD); //send result back to master process

		free(processResult);
		free(recvA);
		free(recvB);
	}

	MPI_Finalize();

	return 0;
}
