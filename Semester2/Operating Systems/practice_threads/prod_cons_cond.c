#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define N 10
#define P 12
#define C 5
#define PSLEEP 5
#define CSLEEP 4
int buf[N], p[P], c[C], nt[P + C];
pthread_t tid[P + C];
int indPut, indGet, val, bufgol;
pthread_mutex_t exclusbuf, exclusval, mutgol, mutplin;
pthread_cond_t gol, plin;

//afiseaza starea curenta a producatorilor si a consumatorilor
void afiseaza() {
    int i;
    for (i=0; i < P; i++) printf("P%d_%d\t", i, p[i]);
    for (i=0; i < C; i++) printf("C%d_%d\t", i, c[i]);
    printf("B: ");
    for (i=0; i < N; i++) if (buf[i] != 0) printf("%d ", buf[i]);
    printf("\n");
    fflush(stdout);
}

//rutina unui thread producator
void* producator(void* nrp) {
    int indp = *(int*)nrp;
    for ( ; ; ) {
        pthread_mutex_lock(&exclusval);
        val++;
        p[indp] = -val; // Asteapta sa depuna val in buf
        pthread_mutex_unlock(&exclusval);
        
        pthread_mutex_lock(&mutgol);
        for ( ; bufgol == 0; ) {
            pthread_cond_wait(&gol, &mutgol);
        }
        pthread_mutex_unlock(&mutgol);

        pthread_mutex_lock(&exclusbuf);
        buf[indPut] = -p[indp];
        bufgol--;
        p[indp] = -p[indp]; // A depus val in buf
        afiseaza();
        p[indp] = 0; // Elibereaza buf si doarme
        indPut = (indPut + 1) % N;
        pthread_mutex_unlock(&exclusbuf);

        pthread_mutex_lock(&mutplin);
        pthread_cond_signal(&plin);
        pthread_mutex_unlock(&mutplin);

        sleep(1 + rand() % PSLEEP);
    }
}

//rutina unui thread consumator
void* consumator(void* nrc) {
    int indc = *(int*)nrc;
    for ( ; ; ) {
        c[indc] = -1; // Asteapta sa scoata din buf
        
        pthread_mutex_lock(&mutplin);
        for ( ; bufgol == N; ) {
            pthread_cond_wait(&plin, &mutplin);
        }
        pthread_mutex_unlock(&mutplin);

        pthread_mutex_lock(&exclusbuf);
        c[indc] = buf[indGet]; // Scoate o valoare din buf
        buf[indGet] = 0; // Elibereaza locul din buf
        bufgol++;
        afiseaza();
        c[indc] = 0; // Elibereaza buf si doarme
        indGet = (indGet + 1) % N;
        pthread_mutex_unlock(&exclusbuf);

        pthread_mutex_lock(&mutgol);
        pthread_cond_signal(&gol);
        pthread_mutex_unlock(&mutgol);

        sleep(1 + rand() % CSLEEP);
    }
}

//functia principala
int main() {
    pthread_mutex_init(&exclusbuf, NULL);
    pthread_mutex_init(&exclusval, NULL);
    pthread_mutex_init(&mutgol, NULL);
    pthread_mutex_init(&mutplin, NULL);
    pthread_cond_init(&gol, NULL);
    pthread_cond_init(&plin, NULL);
    int i;
    val = 0;
    indPut = 0;
    indGet = 0;
    bufgol = N;
    for (i=0; i < N; buf[i] = 0, i++);
    for (i=0; i < P; p[i] = 0, nt[i] = i, i++);
    for (i=0; i < C; c[i] = 0, nt[i + P] = i, i++);
    
    for (i = 0; i < P; i++) pthread_create(&tid[i], NULL, producator, &nt[i]);
    for (i = P; i < P + C; i++) pthread_create(&tid[i], NULL, consumator, &nt[i]);

    for (i = 0; i < P + C; i++) pthread_join(tid[i], NULL);

    pthread_mutex_destroy(&exclusbuf);
    pthread_mutex_destroy(&exclusval);
    pthread_mutex_destroy(&mutgol);
    pthread_mutex_destroy(&mutplin);
    pthread_cond_destroy(&gol);
    pthread_cond_destroy(&plin);
    return 0; 
}

