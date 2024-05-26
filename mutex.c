#include <stdio.h>
#include <pthread.h>
#define MAX_COUNT 10
int counter = 0;
pthread_mutex_t mutex;
void *up_counter(void *arg) {
pthread_mutex_lock(&mutex);
    for (int i = 0; i < MAX_COUNT; ++i) {
                counter++;
        printf("Upcount: %d\n", counter);
           }
 pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

void *down_counter(void *arg) {
  pthread_mutex_lock(&mutex);
    for (int i = 0; i < MAX_COUNT; ++i) {
     
        counter--;
        printf("Downcount: %d\n", counter);
        
    }
pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread_up, thread_down;

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_create(&thread_up, NULL, up_counter, NULL);
    pthread_create(&thread_down, NULL, down_counter, NULL);

    // Join threads
    pthread_join(thread_up, NULL);
    pthread_join(thread_down, NULL);

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}
