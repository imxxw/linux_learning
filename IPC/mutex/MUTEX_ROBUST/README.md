# 互斥量的鲁棒属性

原文：[互斥量的鲁棒属性](https://blog.csdn.net/q1007729991/article/details/62424302)

本实例是在共享内存中存储互斥量`pthread_mutex_t`，实现进程间的互斥。

为了能够让进程在异常终止时，释放掉互斥锁，需要指定 ROBUST 属性，即设置`PTHREAD_MUTEX_ROBUST`属性。
