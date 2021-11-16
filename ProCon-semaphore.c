#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

#define MaxItems 5      // Số items tối đa một tiến trình Producer có thể tạo hoặc một tiến trình Consumer có thể dùng
#define BufferSize 3    // Kích thước bộ đệm

sem_t empty;    //Biến kiểm soát số ô nhớ trống
sem_t full;     //Biến kiểm soát số ô nhớ đầy
int in = 0;     //Biến hoạt động của tiến trình Producer
int out = 0;    //Biến hoạt động của tiến trình Consumer
int buffer[BufferSize]; //Mảng ô nhớ
pthread_mutex_t mutex;  //Khóa kiểm soát tranh chấp

//Tiến trình Sản xuất (Producer)
void *producer(void *prod)
{   
    int item;
    for(int i = 0; i < MaxItems; i++) {
        item = rand(); // Tạo ngẫu nhiên 1 mục
        sem_wait(&empty);   //Giảm số ô nhớ trống
        pthread_mutex_lock(&mutex); //Báo hiệu vào vùng tranh chấp
        buffer[in] = item;  //thêm mục vào ô nhớ
        printf("Tiến trình Producer %d: thêm mục %d vào ô nhớ %d\n", *((int *)prod),buffer[in],in);
        in = (in+1)%BufferSize; //Trỏ đến ô nhớ kế tiếp
        pthread_mutex_unlock(&mutex);   //Ra khỏi vùng tranh chấp
        sem_post(&full);    //Tăng số ô nhớ đầy
    }
}

//Tiến trình tiêu thụ (Consumer)
void *consumer(void *cons)
{   
    for(int i = 0; i < MaxItems; i++) {
        sem_wait(&full);    //Giảm số ô nhớ đầy
        pthread_mutex_lock(&mutex); //Báo hiệu vào vùng tranh chấp
        int item = buffer[out]; //Lấy thông tin từ ô nhớ
        printf("Tiến trình Consumer %d: lấy mục %d ra khỏi ô nhớ %d\n",*((int *)cons),item, out);
        out = (out+1)%BufferSize;   //Trỏ đến ô nhớ kế tiếp
        pthread_mutex_unlock(&mutex);   //Ra khỏi vùng tranh chấp
        sem_post(&empty);   //Tăng số ô nhớ trống
    }
}


int main()
{   

    pthread_t pro[5],con[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,BufferSize);
    sem_init(&full,0,0);

    int a[5] = {1,2,3,4,5};     //Số thứ tự của tiến trình Sản xuất, Tiêu thụ

    for(int i = 0; i < 5; i++) {
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(con[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
    
}