#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


double pi(unsigned int r, unsigned int from, unsigned int to){
    unsigned int count = 0, x, y;
    for (x = from; x < to; x++){
        for(y = 0; y < r; y++){
            if (x*x + y*y <= r*r){
                count++;
            }
        }
    }
    return 4.0 * count / (r*r);

}

struct work {
    unsigned int r, from, to;
    double res;
};

void* thread(void* arg){
    struct work* w = (struct work*) arg;
    w->res = pi(w->r, w->from, w->to);
    return NULL;
}


int main(){
    struct work w1 = {1000000, 0, 500000}, w2 = {1000000, 500000, 1000000};
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread, &w1);
    pthread_create(&t2, NULL, thread, &w2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("pi = %f\n", w1.res + w2.res);
    return 0;

}