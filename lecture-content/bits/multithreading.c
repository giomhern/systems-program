#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
/*
### Overview
This program estimates the value of \(\pi\) using a Monte Carlo method. It divides the computational work into two parts, each executed in a separate thread. The basic idea is to count the number of points that fall inside a quarter-circle (of a given radius `r`) and then use this count to estimate \(\pi\).

### Key Components
1. **`pi` Function:**
   - This function calculates the fraction of points that fall within a quarter-circle of radius `r`.
   - It iterates over a range of `x` (from `from` to `to`) and for each `x`, it iterates over all `y` values from 0 to `r`.
   - If a point `(x, y)` is inside the quarter-circle (`x*x + y*y <= r*r`), it increments the count.
   - The function returns an estimate of \(\pi\) based on the count.

2. **`work` Structure:**
   - This structure holds the data needed for each thread, including the radius (`r`), the range of `x` values (`from` and `to`), and a place to store the result (`res`).

3. **`thread` Function:**
   - This function is the entry point for each thread.
   - It takes a `void*` argument, which it casts to a `struct work*`.
   - It calls the `pi` function with the parameters from the `struct work` and stores the result in `res`.

4. **Creating and Running Threads in `main`:**
   - Two `struct work` instances (`w1` and `w2`) are created, dividing the range of `x` values into two halves.
   - Two threads (`t1` and `t2`) are created using `pthread_create`. Each thread executes the `thread` function with one of the `work` structures as its argument.
   - The `pthread_create` function starts a new thread in the calling process.
   - The `pthread_join` function waits for the threads to finish their execution.

5. **Calculating \(\pi\) in `main`:**
   - After both threads complete, the `main` function calculates the final estimate of \(\pi\) by adding the results from both threads (`w1.res + w2.res`) and prints it.

### Multithreading Concept
- In this program, multithreading is used to parallelize the computation of \(\pi\).
- The workload is divided into two parts, and each part is processed in a separate thread.
- This can potentially reduce the total computation time, especially on multi-core processors.
- Threads share the same memory space, so data structures like `struct work` can be easily passed to threads.

### Efficiency and Use Case
- This approach is efficient for CPU-bound tasks like this numerical computation.
- Multithreading is especially effective in scenarios where tasks can be divided and executed concurrently without needing to share much data.

### Caution
- Multithreading requires careful consideration of potential issues like race conditions, especially when threads access shared data. However, in this example, each thread works with its own data, so there is no risk of race conditions.

In summary, the program demonstrates how to use multithreading to parallelize tasks in C using pthreads, resulting in potentially faster computations for suitable problems.
*/

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