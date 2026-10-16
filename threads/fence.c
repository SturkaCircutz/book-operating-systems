#include <stdio.h>
#include <stdatomic.h>
#include <pthread.h>

int data = 0;
atomic_int ready = 0;

void *thread1(void *arg) {
    data = 42;

    atomic_thread_fence(memory_order_release);  // Fence
    atomic_store_explicit(&ready, 1, memory_order_relaxed);

    return NULL;
}

void *thread2(void *arg) {
    while (atomic_load_explicit(&ready, memory_order_relaxed) == 0) {
        // Wait
    }

    atomic_thread_fence(memory_order_acquire);  // Fence
    printf("data = %d\n", data);

    return NULL;
}

int main(void) {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}