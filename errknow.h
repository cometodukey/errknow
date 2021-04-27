#include <errno.h>

static char *errno_names[] = {
    [0] = " ",
#ifdef EPERM
    [EPERM] = "EPERM",
#endif
#ifdef ENOENT
    [ENOENT] = "ENOENT",
#endif
#ifdef ESRCH
    [ESRCH] = "ESRCH",
#endif
#ifdef EINTR
    [EINTR] = "EINTR",
#endif
#ifdef EIO
    [EIO] = "EIO",
#endif
#ifdef ENXIO
    [ENXIO] = "ENXIO",
#endif
#ifdef E2BIG
    [E2BIG] = "E2BIG",
#endif
#ifdef ENOEXEC
    [ENOEXEC] = "ENOEXEC",
#endif
#ifdef EBADF
    [EBADF] = "EBADF",
#endif
#ifdef ECHILD
    [ECHILD] = "ECHILD",
#endif
#ifdef EAGAIN
    [EAGAIN] = "EAGAIN",
#endif
#ifdef ENOMEM
    [ENOMEM] = "ENOMEM",
#endif
#ifdef EACCES
    [EACCES] = "EACCES",
#endif
#ifdef EFAULT
    [EFAULT] = "EFAULT",
#endif
#ifdef ENOTBLK
    [ENOTBLK] = "ENOTBLK",
#endif
#ifdef EBUSY
    [EBUSY] = "EBUSY",
#endif
#ifdef EEXIST
    [EEXIST] = "EEXIST",
#endif
#ifdef EXDEV
    [EXDEV] = "EXDEV",
#endif
#ifdef ENODEV
    [ENODEV] = "ENODEV",
#endif
#ifdef ENOTDIR
    [ENOTDIR] = "ENOTDIR",
#endif
#ifdef EISDIR
    [EISDIR] = "EISDIR",
#endif
#ifdef EINVAL
    [EINVAL] = "EINVAL",
#endif
#ifdef ENFILE
    [ENFILE] = "ENFILE",
#endif
#ifdef EMFILE
    [EMFILE] = "EMFILE",
#endif
#ifdef ENOTTY
    [ENOTTY] = "ENOTTY",
#endif
#ifdef ETXTBSY
    [ETXTBSY] = "ETXTBSY",
#endif
#ifdef EFBIG
    [EFBIG] = "EFBIG",
#endif
#ifdef ENOSPC
    [ENOSPC] = "ENOSPC",
#endif
#ifdef ESPIPE
    [ESPIPE] = "ESPIPE",
#endif
#ifdef EROFS
    [EROFS] = "EROFS",
#endif
#ifdef EMLINK
    [EMLINK] = "EMLINK",
#endif
#ifdef EPIPE
    [EPIPE] = "EPIPE",
#endif
#ifdef EDOM
    [EDOM] = "EDOM",
#endif
#ifdef ERANGE
    [ERANGE] = "ERANGE",
#endif
#ifdef EDEADLK
    [EDEADLK] = "EDEADLK",
#endif
#ifdef ENAMETOOLONG
    [ENAMETOOLONG] = "ENAMETOOLONG",
#endif
#ifdef ENOLCK
    [ENOLCK] = "ENOLCK",
#endif
#ifdef ENOSYS
    [ENOSYS] = "ENOSYS",
#endif
#ifdef ENOTEMPTY
    [ENOTEMPTY] = "ENOTEMPTY",
#endif
#ifdef ELOOP
    [ELOOP] = "ELOOP",
#endif
#ifdef ENOMSG
    [ENOMSG] = "ENOMSG",
#endif
#ifdef EIDRM
    [EIDRM] = "EIDRM",
#endif
#ifdef ECHRNG
    [ECHRNG] = "ECHRNG",
#endif
#ifdef EL2NSYNC
    [EL2NSYNC] = "EL2NSYNC",
#endif
#ifdef EL3HLT
    [EL3HLT] = "EL3HLT",
#endif
#ifdef EL3RST
    [EL3RST] = "EL3RST",
#endif
#ifdef ELNRNG
    [ELNRNG] = "ELNRNG",
#endif
#ifdef EUNATCH
    [EUNATCH] = "EUNATCH",
#endif
#ifdef ENOCSI
    [ENOCSI] = "ENOCSI",
#endif
#ifdef EL2HLT
    [EL2HLT] = "EL2HLT",
#endif
#ifdef EBADE
    [EBADE] = "EBADE",
#endif
#ifdef EBADR
    [EBADR] = "EBADR",
#endif
#ifdef EXFULL
    [EXFULL] = "EXFULL",
#endif
#ifdef ENOANO
    [ENOANO] = "ENOANO",
#endif
#ifdef EBADRQC
    [EBADRQC] = "EBADRQC",
#endif
#ifdef EBADSLT
    [EBADSLT] = "EBADSLT",
#endif
#ifdef EBFONT
    [EBFONT] = "EBFONT",
#endif
#ifdef ENOSTR
    [ENOSTR] = "ENOSTR",
#endif
#ifdef ENODATA
    [ENODATA] = "ENODATA",
#endif
#ifdef ETIME
    [ETIME] = "ETIME",
#endif
#ifdef ENOSR
    [ENOSR] = "ENOSR",
#endif
#ifdef ENONET
    [ENONET] = "ENONET",
#endif
#ifdef ENOPKG
    [ENOPKG] = "ENOPKG",
#endif
#ifdef EREMOTE
    [EREMOTE] = "EREMOTE",
#endif
#ifdef ENOLINK
    [ENOLINK] = "ENOLINK",
#endif
#ifdef EADV
    [EADV] = "EADV",
#endif
#ifdef ESRMNT
    [ESRMNT] = "ESRMNT",
#endif
#ifdef ECOMM
    [ECOMM] = "ECOMM",
#endif
#ifdef EPROTO
    [EPROTO] = "EPROTO",
#endif
#ifdef EMULTIHOP
    [EMULTIHOP] = "EMULTIHOP",
#endif
#ifdef EDOTDOT
    [EDOTDOT] = "EDOTDOT",
#endif
#ifdef EBADMSG
    [EBADMSG] = "EBADMSG",
#endif
#ifdef EOVERFLOW
    [EOVERFLOW] = "EOVERFLOW",
#endif
#ifdef ENOTUNIQ
    [ENOTUNIQ] = "ENOTUNIQ",
#endif
#ifdef EBADFD
    [EBADFD] = "EBADFD",
#endif
#ifdef EREMCHG
    [EREMCHG] = "EREMCHG",
#endif
#ifdef ELIBACC
    [ELIBACC] = "ELIBACC",
#endif
#ifdef ELIBBAD
    [ELIBBAD] = "ELIBBAD",
#endif
#ifdef ELIBSCN
    [ELIBSCN] = "ELIBSCN",
#endif
#ifdef ELIBMAX
    [ELIBMAX] = "ELIBMAX",
#endif
#ifdef ELIBEXEC
    [ELIBEXEC] = "ELIBEXEC",
#endif
#ifdef EILSEQ
    [EILSEQ] = "EILSEQ",
#endif
#ifdef ERESTART
    [ERESTART] = "ERESTART",
#endif
#ifdef ESTRPIPE
    [ESTRPIPE] = "ESTRPIPE",
#endif
#ifdef EUSERS
    [EUSERS] = "EUSERS",
#endif
#ifdef ENOTSOCK
    [ENOTSOCK] = "ENOTSOCK",
#endif
#ifdef EDESTADDRREQ
    [EDESTADDRREQ] = "EDESTADDRREQ",
#endif
#ifdef EMSGSIZE
    [EMSGSIZE] = "EMSGSIZE",
#endif
#ifdef EPROTOTYPE
    [EPROTOTYPE] = "EPROTOTYPE",
#endif
#ifdef ENOPROTOOPT
    [ENOPROTOOPT] = "ENOPROTOOPT",
#endif
#ifdef EPROTONOSUPPORT
    [EPROTONOSUPPORT] = "EPROTONOSUPPORT",
#endif
#ifdef ESOCKTNOSUPPORT
    [ESOCKTNOSUPPORT] = "ESOCKTNOSUPPORT",
#endif
#ifdef EOPNOTSUPP
    [EOPNOTSUPP] = "EOPNOTSUPP",
#endif
#ifdef EPFNOSUPPORT
    [EPFNOSUPPORT] = "EPFNOSUPPORT",
#endif
#ifdef EAFNOSUPPORT
    [EAFNOSUPPORT] = "EAFNOSUPPORT",
#endif
#ifdef EADDRINUSE
    [EADDRINUSE] = "EADDRINUSE",
#endif
#ifdef EADDRNOTAVAIL
    [EADDRNOTAVAIL] = "EADDRNOTAVAIL",
#endif
#ifdef ENETDOWN
    [ENETDOWN] = "ENETDOWN",
#endif
#ifdef ENETUNREACH
    [ENETUNREACH] = "ENETUNREACH",
#endif
#ifdef ENETRESET
    [ENETRESET] = "ENETRESET",
#endif
#ifdef ECONNABORTED
    [ECONNABORTED] = "ECONNABORTED",
#endif
#ifdef ECONNRESET
    [ECONNRESET] = "ECONNRESET",
#endif
#ifdef ENOBUFS
    [ENOBUFS] = "ENOBUFS",
#endif
#ifdef EISCONN
    [EISCONN] = "EISCONN",
#endif
#ifdef ENOTCONN
    [ENOTCONN] = "ENOTCONN",
#endif
#ifdef ESHUTDOWN
    [ESHUTDOWN] = "ESHUTDOWN",
#endif
#ifdef ETOOMANYREFS
    [ETOOMANYREFS] = "ETOOMANYREFS",
#endif
#ifdef ETIMEDOUT
    [ETIMEDOUT] = "ETIMEDOUT",
#endif
#ifdef ECONNREFUSED
    [ECONNREFUSED] = "ECONNREFUSED",
#endif
#ifdef EHOSTDOWN
    [EHOSTDOWN] = "EHOSTDOWN",
#endif
#ifdef EHOSTUNREACH
    [EHOSTUNREACH] = "EHOSTUNREACH",
#endif
#ifdef EALREADY
    [EALREADY] = "EALREADY",
#endif
#ifdef EINPROGRESS
    [EINPROGRESS] = "EINPROGRESS",
#endif
#ifdef ESTALE
    [ESTALE] = "ESTALE",
#endif
#ifdef EUCLEAN
    [EUCLEAN] = "EUCLEAN",
#endif
#ifdef ENOTNAM
    [ENOTNAM] = "ENOTNAM",
#endif
#ifdef ENAVAIL
    [ENAVAIL] = "ENAVAIL",
#endif
#ifdef EISNAM
    [EISNAM] = "EISNAM",
#endif
#ifdef EREMOTEIO
    [EREMOTEIO] = "EREMOTEIO",
#endif
#ifdef EDQUOT
    [EDQUOT] = "EDQUOT",
#endif
#ifdef ENOMEDIUM
    [ENOMEDIUM] = "ENOMEDIUM",
#endif
#ifdef EMEDIUMTYPE
    [EMEDIUMTYPE] = "EMEDIUMTYPE",
#endif
#ifdef ECANCELED
    [ECANCELED] = "ECANCELED",
#endif
#ifdef ENOKEY
    [ENOKEY] = "ENOKEY",
#endif
#ifdef EKEYEXPIRED
    [EKEYEXPIRED] = "EKEYEXPIRED",
#endif
#ifdef EKEYREVOKED
    [EKEYREVOKED] = "EKEYREVOKED",
#endif
#ifdef EKEYREJECTED
    [EKEYREJECTED] = "EKEYREJECTED",
#endif
#ifdef EOWNERDEAD
    [EOWNERDEAD] = "EOWNERDEAD",
#endif
#ifdef ENOTRECOVERABLE
    [ENOTRECOVERABLE] = "ENOTRECOVERABLE",
#endif
#ifdef ERFKILL
    [ERFKILL] = "ERFKILL",
#endif
#ifdef EHWPOISON
    [EHWPOISON] = "EHWPOISON",
#endif
};
