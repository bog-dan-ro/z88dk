
// automatically generated by m4 from headers in proto subdir


#ifndef _THREADS_H
#define _THREADS_H

#include <stdint.h>

// DATA STRUCTURES

typedef struct mtx_s
{

   uint8_t thrd_owner;
   uint8_t mutex_type;
   uint8_t lock_count;
   
   uint8_t spinlock;
   void   *q;             // p_forward_list *

} mtx_t;

typedef uint16_t       once_flag;
#define ONCE_FLAG_INIT 0x00fe

// mutex

extern void call_once(once_flag *flag,void (*func)(void));
extern void call_once_callee(once_flag *flag,void (*func)(void)) __z88dk_callee;
#define call_once(a,b) call_once_callee(a,b)


extern void..mtx_destroy mtx_t *m();
extern void..mtx_destroy mtx_t *m_callee() __z88dk_callee;
#define () _callee()


extern int mtx_init(mtx_t *m,int type);
extern int mtx_init_callee(mtx_t *m,int type) __z88dk_callee;
#define mtx_init(a,b) mtx_init_callee(a,b)


extern int mtx_lock(mtx_t *m);
extern int mtx_lock_fastcall(mtx_t *m) __z88dk_fastcall;
#define mtx_lock(a) mtx_lock_fastcall(a)


extern int mtx_timedlock(mtx_t *m,struct timespec *ts);
extern int mtx_timedlock_callee(mtx_t *m,struct timespec *ts) __z88dk_callee;
#define mtx_timedlock(a,b) mtx_timedlock_callee(a,b)


extern int mtx_trylock(mtx_t *m);
extern int mtx_trylock_fastcall(mtx_t *m) __z88dk_fastcall;
#define mtx_trylock(a) mtx_trylock_fastcall(a)


extern int mtx_unlock(mtx_t *m);
extern int mtx_unlock_fastcall(mtx_t *m) __z88dk_fastcall;
#define mtx_unlock(a) mtx_unlock_fastcall(a)


extern void spinlock_acquire(char *spinlock);
extern void spinlock_acquire_fastcall(char *spinlock) __z88dk_fastcall;
#define spinlock_acquire(a) spinlock_acquire_fastcall(a)


extern void spinlock_release(char *spinlock);
extern void spinlock_release_fastcall(char *spinlock) __z88dk_fastcall;
#define spinlock_release(a) spinlock_release_fastcall(a)


extern int spinlock_tryacquire(char *spinlock);
extern int spinlock_tryacquire_fastcall(char *spinlock) __z88dk_fastcall;
#define spinlock_tryacquire(a) spinlock_tryacquire_fastcall(a)



#endif
