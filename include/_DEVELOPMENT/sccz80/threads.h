
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

extern void __LIB__ call_once(once_flag *flag,void (*func)(void));
extern void __LIB__ __CALLEE__ call_once_callee(once_flag *flag,void (*func)(void));
#define call_once(a,b) call_once_callee(a,b)


extern void..mtx_destroy __LIB__ mtx_t *m();
extern void..mtx_destroy __LIB__ __CALLEE__ mtx_t *m_callee();
#define () _callee()


extern int __LIB__ mtx_init(mtx_t *m,int type);
extern int __LIB__ __CALLEE__ mtx_init_callee(mtx_t *m,int type);
#define mtx_init(a,b) mtx_init_callee(a,b)


extern int __LIB__ __FASTCALL__ mtx_lock(mtx_t *m);


extern int __LIB__ mtx_timedlock(mtx_t *m,struct timespec *ts);
extern int __LIB__ __CALLEE__ mtx_timedlock_callee(mtx_t *m,struct timespec *ts);
#define mtx_timedlock(a,b) mtx_timedlock_callee(a,b)


extern int __LIB__ __FASTCALL__ mtx_trylock(mtx_t *m);


extern int __LIB__ __FASTCALL__ mtx_unlock(mtx_t *m);


extern void __LIB__ __FASTCALL__ spinlock_acquire(char *spinlock);


extern void __LIB__ __FASTCALL__ spinlock_release(char *spinlock);


extern int __LIB__ __FASTCALL__ spinlock_tryacquire(char *spinlock);



#endif
