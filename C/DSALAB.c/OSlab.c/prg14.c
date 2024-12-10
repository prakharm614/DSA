#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct {
    int value;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} my_semaphore;

int my_sem_init(my_semaphore *sem, int pshared, unsigned int value) {
    sem->value = value;
    if (pthread_mutex_init(&sem->mutex, NULL) != 0) {
        return -1;
    }
    if (pthread_cond_init(&sem->cond, NULL) != 0) {
        pthread_mutex_destroy(&sem->mutex);
        return -1;
    }
    return 0;
}

int my_sem_wait(my_semaphore *sem) {
    if (pthread_mutex_lock(&sem->mutex) != 0) {
        return -1;
    }
    while (sem->value <= 0) {
        if (pthread_cond_wait(&sem->cond, &sem->mutex) != 0) {
            pthread_mutex_unlock(&sem->mutex);
            return -1;
        }
    }
    sem->value--;
    if (pthread_mutex_unlock(&sem->mutex) != 0) {
        return -1;
    }
    return 0;
}

int my_sem_post(my_semaphore *sem) {
    if (pthread_mutex_lock(&sem->mutex) != 0) {
        return -1;
    }
    sem->value++;
    if (pthread_cond_signal(&sem->cond) != 0) {
        pthread_mutex_unlock(&sem->mutex);
        return -1;
    }
    if (pthread_mutex_unlock(&sem->mutex) != 0) {
        return -1;
    }
    return 0;
}

int my_sem_destroy(my_semaphore *sem) {
    if (pthread_mutex_destroy(&sem->mutex) != 0) {
        return -1;
    }
    if (pthread_cond_destroy(&sem->cond) != 0) {
        return -1;
    }
    return 0;
}

my_semaphore x, y;
int readercount = 0;

void *reader(void *param) {
    my_sem_wait(&x);
    readercount++;
    if (readercount == 1) {
        my_sem_wait(&y);
    }
    my_sem_post(&x);

    printf("Reader %lu is inside\n", pthread_self());
    usleep(1000);

    my_sem_wait(&x);
    readercount--;
    if (readercount == 0) {
        my_sem_post(&y);
    }
    my_sem_post(&x);

    printf("Reader %lu is leaving\n", pthread_self());
    return NULL;
}

void *writer(void *param) {
    printf("Writer %lu is trying to enter\n", pthread_self());
    my_sem_wait(&y);
    printf("Writer %lu has entered\n", pthread_self());
    usleep(1000);
    my_sem_post(&y);
    printf("Writer %lu is leaving\n", pthread_self());
    return NULL;
}

int main() {
    int n_readers, n_writers, i;
    printf("Enter the number of readers: ");
    scanf("%d", &n_readers);
    printf("Enter the number of writers: ");
    scanf("%d", &n_writers);

    pthread_t readerthreads[n_readers], writerthreads[n_writers];

    my_sem_init(&x, 0, 1);
    my_sem_init(&y, 0, 1);

    for (i = 0; i < n_readers; i++) {
        pthread_create(&readerthreads[i], NULL, reader, NULL);
    }

    for (i = 0; i < n_writers; i++) {
        pthread_create(&writerthreads[i], NULL, writer, NULL);
    }

    for (i = 0; i < n_readers; i++) {
        pthread_join(readerthreads[i], NULL);
    }

    for (i = 0; i < n_writers; i++) {
        pthread_join(writerthreads[i], NULL);
    }

    my_sem_destroy(&x);
    my_sem_destroy(&y);

    return 0;
}
