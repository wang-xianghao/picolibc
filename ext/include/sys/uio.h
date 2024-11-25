#ifndef _SYS_UIO_H
#define _SYS_UIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#include <sys/types.h>
#define __NEED_size_t
#define __NEED_ssize_t
#define __NEED_struct_iovec

// INFO: GNU
// #if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
// #define __NEED_off_t
// #endif

// INFO: GNU
// #ifdef _GNU_SOURCE
// #define __NEED_pid_t
// #endif

// INFO: musl-specific header
// #include <bits/alltypes.h>

#define UIO_MAXIOV 1024

// INFO: iovec should be defined in uio.h
struct iovec { void *iov_base; size_t iov_len; };

ssize_t readv (int, const struct iovec *, int);
ssize_t writev (int, const struct iovec *, int);

// INFO: GNU
// #if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
// ssize_t preadv (int, const struct iovec *, int, off_t);
// ssize_t pwritev (int, const struct iovec *, int, off_t);
// #if defined(_LARGEFILE64_SOURCE) || defined(_GNU_SOURCE)
// #define preadv64 preadv
// #define pwritev64 pwritev
// #define off64_t off_t
// #endif
// #endif

// INFO: GNU
// #ifdef _GNU_SOURCE
// ssize_t process_vm_writev(pid_t, const struct iovec *, unsigned long, const struct iovec *, unsigned long, unsigned long);
// ssize_t process_vm_readv(pid_t, const struct iovec *, unsigned long, const struct iovec *, unsigned long, unsigned long);
// #endif

#ifdef __cplusplus
}
#endif

#endif