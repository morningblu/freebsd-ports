--- src/defs.h.orig	Sat Jul  3 01:49:41 2004
+++ src/defs.h	Sat Jul  3 01:50:15 2004
@@ -64,7 +64,7 @@
 #define MARK_VERSION		2
 
 #define DEFAULT_SIGNATURE	".signature"
-#define DEFAULT_INC_PATH	"/usr/bin/mh/inc"
+#define DEFAULT_INC_PATH	""
 #define DEFAULT_INC_PROGRAM	"inc"
 /* #define DEFAULT_INC_PATH	"/usr/bin/imget" */
 /* #define DEFAULT_INC_PROGRAM	"imget" */
@@ -74,7 +74,7 @@
 #ifdef _PATH_MAILDIR
 #  define DEFAULT_SPOOL_PATH	_PATH_MAILDIR
 #else
-#  define DEFAULT_SPOOL_PATH	"/var/spool/mail"
+#  define DEFAULT_SPOOL_PATH	"/var/mail"
 #endif
 
 #define BUFFSIZE			8192
