#include <stdio.h>
#include "mpi.h"
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#define MASTER 0 //id of the master process

//read number from file
std::vector<int>readVecFromFile(const std::string& path) {
	std::vector<int> number;	
	std::ifstream in(path);
	int x;
	while (in >> x) {
		number.push_back(x);
	}
	std::reverse(number.begin(), number.end());
	in.close();
	return number;
}

//function to print a simple vector
void print_vector(int* v, int n) {
	for (int i = n - 1; i >= 0; i--) {
		printf("%d", v[i]);
	}
	printf("\n");
}



int main(int argc, char** argv) {
	std::vector<int> a; //first number
	std::vector<int> b; //second number
	std::vector<int> result; // result number
	int* for_process_a; //subarray of a to be send to a process
	int* for_process_b; //subarray of b to be send to a process
	int* local_res; //result of for_process_a + for_process_b
	int rank, num_proc; //rank of the current process, number of processes
	int isExtra = 0; //isExtra = 0, if there is no extra carry, 1 otherwise

	//Initialize MPI environment
	MPI_Init(&argc, &argv);
	//Total number of processes
	MPI_Comm_size(MPI_COMM_WORLD, &num_proc);
	//Rank of the current process
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);


	std::string path_to_a = "C:\\Users\\georg\\Desktop\\University\\Semester5\\PPD\\big_num_add_MPI\\BigNumAddMPI\\BigNumAddMPI\\num_file_a.in"; //path to first number
	std::string path_to_b = "C:\\Users\\georg\\Desktop\\University\\Semester5\\PPD\\big_num_add_MPI\\BigNumAddMPI\\BigNumAddMPI\\num_file_b.in"; //path to second number

	if (rank == MASTER) { //if the current process is the master process
		a = readVecFromFile(path_to_a); //read first number
		b = readVecFromFile(path_to_b); //read second number 
		int len1 = a.size();
		int len2 = b.size();

		if (len1 > len2) {
			for (int i = 0; i < len1 - len2; i++) {  /*
													 Completing with 0s if one number has more digits than the other
													 */
				b.push_back(0);
			}
		}
		else {
			for (int i = 0; i < len2 - len1; i++) {
				a.push_back(0);
			}
		}
		for (int i = 0; i < a.size(); i++) {
			result.push_back(-1);
		}
		num_proc--; //the master processes only reads and distributes the numbers there are num_proc - 1 proceses for calculation
		int per_process = result.size() / num_proc; //per process
		int rem = result.size() % num_proc; //rem

		int start = 0, stop = 0;
		for_process_a = (int*)malloc(sizeof(int)*(per_process + 1)); //allocate memory for for_process_a
		for_process_b = (int*)malloc(sizeof(int)*(per_process + 1)); //allocate memory for for_process_b

		local_res = (int*)malloc(sizeof(int)*(per_process + 1)); //allocate memory for local_Res

		for (int i = 1; i <= num_proc; i++) {
			stop = start + per_process;
			if (rem > 0) {
				stop += 1;
				rem -= 1;
			}

			for (int j = start; j < stop; j++) {
				for_process_a[j - start] = a[j]; //copy digits of a
				for_process_b[j - start] = b[j]; //copy digits of b
			}
		
			int count = stop - start; //number of digits between start and stop
			
			MPI_Send(&count, 1, MPI_INT, i, 0, MPI_COMM_WORLD); //sending number of digits
			MPI_Send(for_process_a, count, MPI_INT, i, 0, MPI_COMM_WORLD); //sending count digits from a
			MPI_Send(for_process_b, count, MPI_INT, i, 0, MPI_COMM_WORLD); //sending count digits from b
			MPI_Recv(local_res, count, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //recv the calculated result
			MPI_Recv(&isExtra, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //recv the extra flag
			for (int j = start; j < stop; j++) {
				result[j] = local_res[j - start]; //updating result
			}
			start = stop;
		}
		free(for_process_a);
		free(for_process_b);
		free(local_res); //free vectors
	}
	else{
		int count, local_extra = 0; //number of digits and local_extra_carry
		MPI_Recv(&count, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //recv number of digits
		int* recv_a = (int*)malloc(sizeof(int)*count); //allocate memory
		int* recv_b = (int*)malloc(sizeof(int)*count);
		int* local_res = (int*)malloc(sizeof(int)*count);
		MPI_Recv(recv_a, count, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //recv the digits from a
		MPI_Recv(recv_b, count, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //recv the digits from b
		for (int i = 0; i < count; i++) {
			local_res[i] = -1; //putting -1 in local_res
		}
		int curr = 0;
		while (curr < count) {
			if (recv_a[curr] + recv_b[curr] > 9) {
				if (curr + 1 < count) {
					local_res[curr + 1] = (recv_a[curr + 1] + recv_b[curr + 1] + 1) % 10;
				}
				else if (curr + 1 == count) {
					local_extra = 1;
					break;
				}

				bool to_break = false;
				curr += 1;
				while (recv_a[curr] + recv_b[curr] == 9) {
					if (curr + 1 < count) {
						local_res[curr + 1] = (recv_a[curr + 1] + recv_b[curr + 1] + 1) % 10;
					}
					else if (curr + 1 == count) {
						local_extra = 1;
						to_break = true;
						break;
					}

					curr += 1;
				}
				if (to_break) {
					break;
				}
			}
			else {
				if (curr + 1 < count && local_res[curr + 1] == -1) {
					local_res[curr + 1] = (recv_a[curr + 1] + recv_b[curr + 1]) % 10;
				}

				curr += 1;
			}
		}

		local_res[0] = (recv_a[0] + recv_b[0]) % 10; //first digit of local_res
		 
		MPI_Send(local_res, count, MPI_INT, 0, 0, MPI_COMM_WORLD); //sending the local_res
		MPI_Send(&local_extra, 1, MPI_INT, 0, 0, MPI_COMM_WORLD); //sending the local_extra flag
		free(local_res);
		free(recv_a);
		free(recv_b); //free vectors
	}

	if (rank == MASTER) {
		if (isExtra == 1) {
			result.push_back(1); //if isExtra is 1 at the final add the extra carry to the result
		}
		for (int i = result.size() - 1; i >= 0; i--) {
			printf("%d", result[i]);	//print the result
		}
	}

	MPI_Finalize();
	return 0;
}