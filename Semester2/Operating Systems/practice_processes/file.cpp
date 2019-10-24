#include <fstream>
#include <cmath>
using namespace std;

ifstream f("Numere.txt");
ofstream g("Rez.txt");

int main(){
	int n, x;
	int first_prime = -1;
	int second_prime = -1;
	bool was_a_prime = false;
	bool is_div_5 = false;
	bool is_desc = true;	

	f >> x;
	
	//cerinta a
	if(x % 2 == 0){
		g << x << ' ';
	}
	
	//cerinta b
	int copie = x;
	bool is_prime = true;
	if(copie < 2){
		is_prime = false;
	}
	else if(copie == 2){
		is_prime = true;
	}
	else if(copie % 2 == 0){
		is_prime = false;
	}
	else{
		for(int i = 3; i<=sqrt(copie); i+=2){
			if(copie % i == 0){
				is_prime = false;
				break;
			}
		}
	}

	if(is_prime == true && was_a_prime == false){
		first_prime = x;
		was_a_prime = true;
	}
	
	//cerinta c
	if(x % 5 == 0){
		is_div_5 = true;
	}

	while(f >> n){
		//cerinta a)
		if(n % 2 == 0){
			g << n << ' ';
		}	
		g << '\n';
		//cerinta b
		int copie = n;
		bool is_prime = true;
		if(copie < 2){
			is_prime = false;
		}
		else if(copie == 2){
			is_prime = true;
		}
		else if(copie % 2 == 0){
			is_prime = false;
		}
		else{
			for(int i = 3; i<=sqrt(copie); i+=2){
				if(copie % i == 0){
					is_prime = false;
					break;
				}
			}
		}
		
		if(is_prime == true && was_a_prime == false){
			first_prime = n;
			was_a_prime = true;
		}
		else if(is_prime == true){
			second_prime = n;
		}
		//cerinta c
		if(n % 5 == 0){
			is_div_5 = true;
		}
	
		//cerinta d
		if(x < n){
			is_desc = false;
		}
		x = n;
	}

	if(first_prime != -1 && second_prime != -1){
		g << first_prime << ' ' << second_prime << '\n';
	}
	else{
		g << "Nu exista 2 numere prime!\n";
	}
	
	if(is_div_5 == true){
		g << "Exista numere divizibile cu 5!\n";
	}
	else{
		g << "Nu exista numere divizibile cu 5!\n";
	}

	if(is_desc == true){
		g << "Sirul este sortat descrescator!\n";
	}
	else{
		g << "Sirul nu este sortat descrescator!\n";
	}
	return 0;
}
