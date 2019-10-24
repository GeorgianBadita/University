#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
 
 
#define n 5
 
pthread_mutex_t mtx[n];
 
 
void* f(void* ptr){
 
    int id = (int)(long long)ptr;
    int turn = 0;
    int right = id;
    int left = (id+1)%n;
    int times = 10;
 
    while(times){
        if(turn%2 == id%2){  //eats
           
            turn++;
           
            if(!pthread_mutex_trylock(&mtx[left])){   //succes
                if(!pthread_mutex_trylock(&mtx[right])){    //succes
                   
                    printf("Philosofer %d eats.(s%d, s%d).\n", id, left, right);                
                    sleep(4);
                     pthread_mutex_unlock(&mtx[right]);
                }
 
                pthread_mutex_unlock(&mtx[left]);    
            }      
                           
        }
 
        else{            //thinks
            turn++;
            printf("Philosofer %d thinks...\n", id);        
            sleep(4);        
        }  
        times--;
    }
    return NULL;
}
 
 
 
 
 
 
int main(){
 
    pthread_t t[n];
   
    int i;
    for(i=0;i<n;i++){
        pthread_mutex_init(&mtx[i], NULL);
    }
 
    for(i=0;i<n;i++){
        pthread_create(&t[i], NULL, f, (void*)(long long)i);
    }
 
    for(i=0;i<n;i++){
        pthread_join(t[i], NULL);
    }
 
    return 0;
}
