#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/fail.h>
#include <caml/callback.h>

#include <stdio.h>

#ifdef CAMLprim
#undef CAMLprim
#endif

#define CAMLprim __attribute__((used))
#define STUB { /* trace(__func__); */ return Atom(0); }

#define STUBX { err_not_implemented(); return Atom(0); }

void trace(const char *func) {
    char __buf[64];
    snprintf(__buf, sizeof(__buf), "unix stub: %s(...)\n", func);
    __wasi_trace(__buf);
}

void err_not_implemented() {
    const value *unix_error_exn = caml_named_value("Unix.Unix_error");
    if (unix_error_exn == NULL)
        caml_invalid_argument("Exception Unix.Unix_error not initialized");

    value err = caml_alloc_small(1, 0);
    Field(err, 0) = Val_int(-1);

    value name = caml_copy_string("unix");

    value res = caml_alloc_small(4, 0);
    Field(res, 0) = *unix_error_exn;
    Field(res, 1) = err;
    Field(res, 2) = name;
    Field(res, 3) = Atom(0);
    caml_raise(res);
}

CAMLprim value unix_accept(value cloexec, value sock)    STUB
CAMLprim value unix_access(value path, value perms)      STUBX
CAMLprim value unix_inet_addr_of_string(value s) STUB
CAMLprim value unix_alarm(value t) STUB
CAMLprim value unix_bind(value socket, value address) STUB
CAMLprim value unix_inchannel_of_filedescr(value fd) STUB
CAMLprim value unix_outchannel_of_filedescr(value fd) STUB
CAMLprim value unix_chdir(value path) STUB
CAMLprim value unix_chmod(value path, value perm) STUB
CAMLprim value unix_chown(value path, value uid, value gid) STUB
CAMLprim value unix_chroot(value path) STUB
CAMLprim value unix_close(value fd) STUB
CAMLprim value unix_closedir(value vd) STUB
CAMLprim value unix_connect(value socket, value address) STUB
CAMLprim value unix_dup(value cloexec, value fd) STUB
CAMLprim value unix_dup2(value cloexec, value fd1, value fd2) STUB
CAMLprim value unix_environment_unsafe(value unit) STUB
CAMLprim value unix_environment(value unit) STUB
CAMLprim value unix_error_message(value err) STUB
CAMLprim value unix_execv(value path, value args) STUB
CAMLprim value unix_execve(value path, value args, value env) STUB
CAMLprim value unix_execvp(value path, value args) STUB
CAMLprim value unix_execvpe(value path, value args, value env) STUB
CAMLprim value unix_exit(value n) STUB
CAMLprim value unix_fchmod(value fd, value perm) STUB
CAMLprim value unix_fchown(value fd, value uid, value gid) STUB
CAMLprim value unix_set_nonblock(value fd) STUB
CAMLprim value unix_clear_nonblock(value fd) STUB
CAMLprim value unix_set_close_on_exec(value fd) STUB
CAMLprim value unix_clear_close_on_exec(value fd) STUB
CAMLprim value unix_fork(value unit) STUB
CAMLprim value unix_fsync(value v) STUB
CAMLprim value unix_ftruncate(value fd, value len) STUB
CAMLprim value unix_ftruncate_64(value fd, value len) STUB
CAMLprim value unix_getaddrinfo(value vnode, value vserv, value vopts) STUB
CAMLprim value unix_getcwd(value unit) STUB
CAMLprim value unix_getegid(value unit) STUB
CAMLprim value unix_geteuid(value unit) STUB
CAMLprim value unix_getgid(value unit) STUB
CAMLprim value unix_getgrnam(value name) STUB
CAMLprim value unix_getgrgid(value gid) STUB
CAMLprim value unix_getgroups(value unit) STUB
CAMLprim value unix_gethostbyaddr(value a) STUB
CAMLprim value unix_gethostbyname(value name) STUB
CAMLprim value unix_gethostname(value unit) STUB
CAMLprim value unix_getlogin(value unit) STUB
CAMLprim value unix_getnameinfo(value vaddr, value vopts) STUB
CAMLprim value unix_getpeername(value sock) STUB
CAMLprim value unix_getpid(value unit) STUB
CAMLprim value unix_getppid(value unit) STUB
CAMLprim value unix_getprotobyname(value name) STUB
CAMLprim value unix_getprotobynumber(value proto) STUB
CAMLprim value unix_getpwnam(value name) STUB
CAMLprim value unix_getpwuid(value uid) STUB
CAMLprim value unix_getservbyname(value name, value proto) STUB
CAMLprim value unix_getservbyport(value port, value proto) STUB
CAMLprim value unix_getsockname(value sock) STUB
CAMLprim value unix_gettimeofday(value unit) STUB
CAMLprim value unix_getuid(value unit) STUB
CAMLprim value unix_gmtime(value t) STUB
CAMLprim value unix_localtime(value t) STUB
CAMLprim value unix_mktime(value t) STUB
CAMLprim value unix_initgroups(value user, value group) STUB
CAMLprim value unix_isatty(value fd) STUB
CAMLprim value unix_setitimer(value which, value newval) STUB
CAMLprim value unix_getitimer(value which) STUB
CAMLprim value unix_kill(value pid, value signal) STUB
CAMLprim value unix_link(value follow, value path1, value path2) STUB
CAMLprim value unix_listen(value sock, value backlog) STUB
CAMLprim value unix_lockf(value fd, value cmd, value span) STUB
CAMLprim value unix_lseek(value fd, value ofs, value cmd) STUB
CAMLprim value unix_lseek_64(value fd, value ofs, value cmd) STUB
CAMLprim value unix_mkdir(value path, value perm) STUB
CAMLprim value unix_mkfifo(value path, value mode) STUB
CAMLprim value caml_unix_map_file(value vfd, value vkind, value vlayout,
                                  value vshared, value vdim, value vstart)   STUB     
CAMLprim value caml_unix_map_file_bytecode(value * argv, int argn) STUB
CAMLprim value unix_nice(value incr) STUB
CAMLprim value unix_open(value path, value flags, value perm) STUB
CAMLprim value unix_opendir(value path) STUB
CAMLprim value unix_pipe(value cloexec, value vunit) STUB
CAMLprim value unix_putenv(value name, value val) STUB
CAMLprim value unix_read(value fd, value buf, value ofs, value len) STUB
CAMLprim value unix_readdir(value vd) STUB
CAMLprim value unix_readlink(value path) STUB
CAMLprim value unix_rename(value path1, value path2) STUB
CAMLprim value unix_rewinddir(value d) STUB
CAMLprim value unix_rmdir(value path) STUB
CAMLprim value unix_select(value readfds, value writefds, value exceptfds,
                           value timeout) STUB
CAMLprim value unix_recv(value sock, value buff, value ofs, value len,
                         value flags) STUB
CAMLprim value unix_recvfrom(value sock, value buff, value ofs, value len,
                             value flags) STUB
CAMLprim value unix_send(value sock, value buff, value ofs, value len,
                         value flags) STUB
CAMLprim value unix_sendto_native(value sock, value buff, value ofs, value len,
                                  value flags, value dest) STUB
CAMLprim value unix_sendto(value *argv, int argc) STUB
CAMLprim value unix_setgid(value gid) STUB
CAMLprim value unix_setgroups(value groups) STUB
CAMLprim value unix_setsid(value unit) STUB
CAMLprim value unix_setuid(value uid) STUB
CAMLprim value unix_shutdown(value sock, value cmd) STUB
CAMLprim value unix_sigprocmask(value vaction, value vset) STUB
CAMLprim value unix_sigpending(value unit) STUB
CAMLprim value unix_sigsuspend(value vset) STUB
CAMLprim value unix_sleep(value duration) STUB
CAMLprim value unix_socket(value cloexec, value domain,
                           value type, value proto)    STUB
CAMLprim value unix_socketpair(value cloexec, value domain,
                               value type, value proto) STUB
CAMLprim value unix_getsockopt(value vty, value socket, value option) STUB
CAMLprim value unix_setsockopt(value vty, value socket, value option, value val) STUB
CAMLprim value unix_stat(value path) STUB
CAMLprim value unix_lstat(value path) STUB
CAMLprim value unix_fstat(value fd) STUB
CAMLprim value unix_stat_64(value path) STUB
CAMLprim value unix_lstat_64(value path) STUB
CAMLprim value unix_fstat_64(value fd) STUB
CAMLprim value unix_string_of_inet_addr(value a) STUB
CAMLprim value unix_symlink(value to_dir, value path1, value path2) STUB
CAMLprim value unix_has_symlink(value unit) STUB
CAMLprim value unix_tcgetattr(value fd) STUB
CAMLprim value unix_tcsetattr(value fd, value when, value arg) STUB
CAMLprim value unix_tcsendbreak(value fd, value delay) STUB
CAMLprim value unix_tcdrain(value fd) STUB
CAMLprim value unix_tcflush(value fd, value queue) STUB
CAMLprim value unix_tcflow(value fd, value action) STUB
CAMLprim value unix_time(value unit) STUB
CAMLprim value unix_times(value unit) STUB
CAMLprim value unix_truncate(value path, value len) STUB
CAMLprim value unix_truncate_64(value path, value vlen) STUB
CAMLprim value unix_umask(value perm) STUB
CAMLprim value unix_unlink(value path) STUB
CAMLprim value unix_utimes(value path, value atime, value mtime) STUB
CAMLprim value unix_wait(value unit) STUB
CAMLprim value unix_waitpid(value flags, value pid_req) STUB
CAMLprim value unix_write(value fd, value buf, value vofs, value vlen) STUB
CAMLprim value unix_single_write(value fd, value buf, value vofs, value vlen) STUB
