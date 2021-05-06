# 互斥量的共享属性

原文：[互斥量的共享属性](https://blog.csdn.net/q1007729991/article/details/62235932)

本实例是在共享内存中存储互斥量`pthread_mutex_t`，实现进程间的互斥。
`pthread_mutex_t`默认是不能在进程间共享的，需要设置`PTHREAD_PROCESS_SHARED`属性才能在进程间共享。

该例子有一个很大的问题：如果其中一个进程在未释放互斥量的情况下挂掉了，将会导致其它线程永远无法获得锁，然后就死锁了。