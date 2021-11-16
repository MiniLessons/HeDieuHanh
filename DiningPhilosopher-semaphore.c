#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t quyen;
sem_t dua[5];

void * trietgiaantoi(void *);
void an(int);
int main()
{
	int i,a[5];
	pthread_t tid[5];

	sem_init(&quyen,0,4); //khởi tạo semaphore quyen

	for(i=0;i<5;i++)
		sem_init(&dua[i],0,1); //khởi tạo semaphore dua

	for(i=0;i<5;i++){
		a[i]=i+1;
		pthread_create(&tid[i],NULL,trietgiaantoi,(void *)&a[i]); //Tạo tiểu trình
	}
	for(i=0;i<5;i++)
		pthread_join(tid[i],NULL);  //Nối tiểu trình
}

void * trietgiaantoi(void * num)
{
	int trietgia=*(int *)num;

	sem_wait(&quyen);   //Yêu cầu quyền cầm đủ đũa
	printf("\nTriết gia %d có quyền cầm một đôi đũa",trietgia);
	sem_wait(&dua[trietgia]);   //Có chiếc đũa thứ nhất
	sem_wait(&dua[(trietgia+1)%5]); //Có chiếc đũa thứ hai

	an(trietgia);   //Ăn
	sleep(2);   //Dừng tiến trình 2 giây
	printf("\nTriết gia %d ăn xong",trietgia);

	sem_post(&dua[(trietgia+1)%5]); //Trả chiếc đũa thứ hai
	sem_post(&dua[trietgia]);   //Trả chiếc đũa thứ nhất
	sem_post(&quyen);   //Trao quyền lại cho triết gia khác
}

void an(int trietgia)
{
	printf("\nTriết gia %d đang ăn",trietgia);
}
