#ifndef _INIT_H
#define _INIT_H

#include <sys/fcntl.h>
#include <sys/syscall.h>
#include <sys/types.h>

#include "syscall/sys_c.h"

#undef NULL
#define NULL 0

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

#define STR_(x) #x
#define STR(x) STR_(x)

static inline __off_t sys_c_lseek(int __fd, __off_t __offset, int __whence) {
    return sys_c_3(SYS_lseek, __fd, __offset, __whence);
}

static inline int sys_c_init_module(void *__module_image, const unsigned long __len, const char *__param) {
    return sys_c_3(SYS_init_module, (long)__module_image, __len, (long)__param);
}

static inline void *sys_c_mmap(void *__addr, size_t __len, int __prot, int __flags, int __fd, __off_t __offset) {
    return (void *)sys_c_6(SYS_mmap, (long)__addr, __len, __prot, __flags, __fd, __offset);
}

static inline int sys_c_munmap(void *__addr, size_t __len) {
    return sys_c_2(SYS_munmap, (long)__addr, __len);
}

static inline int sys_c_open(const char *__path, int __oflag, mode_t __mode) {
    return sys_c_4(SYS_openat, AT_FDCWD, (long)__path, __oflag, __mode);
}

static inline ssize_t sys_c_read(int __fd, void *__buf, size_t __nbytes) {
    return sys_c_3(SYS_read, __fd, (long)__buf, __nbytes);
}

static inline int sys_c_fstat(int __fd, struct stat *__buf) {
    return sys_c_2(SYS_fstat, __fd, (long)__buf);
}

static inline int sys_c_stat(const char *__restrict __file, struct stat *__restrict __buf) {
    return sys_c_2(SYS_stat, (long)__file, (long)__buf);
}

static inline int sys_c_close(int __fd) {
    return sys_c_1(SYS_close, __fd);
}

static inline int sys_c_ioctl(int __fd, unsigned long int __request, void *argp) {
    return sys_c_3(SYS_ioctl, __fd, __request, (long)argp);
}

static inline void sys_c_exit(int __status) {
    sys_c_1(SYS_exit, __status);
}

static inline int sys_c_mount(const char *__special_file, const char *__dir, const char *__fstype, unsigned long int __rwflag, const char *__data) {
    return sys_c_5(SYS_mount, (long)__special_file, (long)__dir, (long)__fstype, __rwflag, (long)__data);
}

static inline int sys_c_link(const char *__from, const char *__to) {
    return sys_c_3(SYS_symlinkat, (long)__from, AT_FDCWD, (long)__to);
}

static inline int sys_c_mkdir(const char *__path, __mode_t __mode) {
    return sys_c_3(SYS_mkdirat, AT_FDCWD, (long)__path, __mode);
}

static inline int sys_c_chdir(const char *__path) {
    return sys_c_1(SYS_chdir, (long)__path);
}

static inline int sys_c_mknod(const char *__path, mode_t __mode, dev_t __dev) {
    return sys_c_4(SYS_mknodat, AT_FDCWD, (long)__path, __mode, __dev);
}

static inline int sys_c_umount(const char *__special_file, int __flags) {
    return sys_c_2(SYS_umount2, (long)__special_file, __flags);
}

static inline int sys_c_chown(const char *__file, __uid_t __owner, __gid_t __group, long flag) {
    return sys_c_5(SYS_fchownat, AT_FDCWD, (long)__file, __owner, __group, flag);
}

static inline int sys_c_rm(const char *__path, int __flag) {
    return sys_c_3(SYS_unlinkat, AT_FDCWD, (long)__path, __flag);
}

static inline int sys_c_execve(const char *__path, char *const __argv[], char *const __envp[]) {
    return sys_c_3(SYS_execve, (long)__path, (long)__argv, (long)__envp);
}

static inline int sys_c_chroot(const char *__path) {
    return sys_c_1(SYS_chroot, (long)__path);
}

static inline __pid_t sys_c_fork() {
    return sys_c_0(SYS_fork);
}

static inline __pid_t sys_c_waitpid(__pid_t __pid, int *__stat_loc, int __options) {
    return sys_c_3(SYS_wait4, __pid, (long)&__stat_loc, __options);
}

size_t strlen(const char *__s) {
    const char *s = __s;
    while (*s) ++s;
    return (s - __s);
}

static inline ssize_t sys_c_write_buf(int __fd, const void *__buf, long len) {
    return sys_c_3(SYS_write, (__fd), (long)(__buf), len);
}

static inline ssize_t sys_c_write(int __fd, const char *__s) {
    return sys_c_write_buf(__fd, __s, __builtin_strlen(__s));
}

static inline size_t sys_c_ltoa(long long v, char *b) {
    char *p = b;
    long long neg = v < 0;
    if (neg) v = -v;
    char *s = p;
    do {
        *p++ = '0' + (v % 10);
        v /= 10;
    } while (v);
    if (neg) *p++ = '-';
    for (char *e = p - 1; s < e; s++, e--) {
        char tmp = *s;
        *s = *e;
        *e = tmp;
    }
    return p - b;
}

static inline ssize_t sys_c_write_n(int __fd, long long __v) {
    char buf[21];
    return sys_c_3(SYS_write, (__fd), (long)(buf), sys_c_ltoa(__v, buf));
}

#include <linux/ioctl.h>
#include <linux/major.h>
#include <linux/raid/md_u.h>

#define MD_VERSION_COLS 2
#define MD_VERSION_COLS_MAJOR 0
#define MD_VERSION_COLS_MINOR 1
#define MD_VERSION_0_90 ((const int[]){0, 90})
#define MD_VERSION_1_0 ((const int[]){1, 0})
#define MD_VERSION_1_1 ((const int[]){1, 1})
#define MD_VERSION_1_2 ((const int[]){1, 2})

#define MD_DISK_COLS 2
#define MD_DISK_COLS_MAJOR 0
#define MD_DISK_COLS_MINOR 1

static inline mdu_array_info_t md_get_array_info(const char *__file) {
    int fd = sys_c_open(__file, O_RDONLY | __O_NOATIME, NULL);
    mdu_array_info_t info_array;
    sys_c_ioctl(fd, GET_ARRAY_INFO, &info_array);
    sys_c_close(fd);
    return info_array;
}

static inline int md_a(const char *__file, const int __versions[MD_VERSION_COLS], const int __disks[][MD_DISK_COLS], const int __n_disk) {
    int fd = sys_c_open(__file, O_RDONLY | __O_NOATIME, NULL);
    mdu_array_info_t info_array = {
        .major_version = __versions[MD_VERSION_COLS_MAJOR],
        .minor_version = __versions[MD_VERSION_COLS_MINOR],
    };
    sys_c_ioctl(fd, SET_ARRAY_INFO, &info_array);
    mdu_disk_info_t info_disk;
    for (int i = 0; i < __n_disk; i++) {
        info_disk.major = __disks[i][MD_DISK_COLS_MAJOR];
        info_disk.minor = __disks[i][MD_DISK_COLS_MINOR];
        sys_c_ioctl(fd, ADD_NEW_DISK, &info_disk);
    }
    int ret = sys_c_ioctl(fd, RUN_ARRAY, NULL);
    sys_c_close(fd);
    return ret;
}
#endif  // _INIT_H