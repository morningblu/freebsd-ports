--- src/cvs.h.orig	Sun Feb 22 04:59:14 2004
+++ src/cvs.h	Sun Feb 22 04:59:22 2004
@@ -34,9 +34,6 @@
 #include <stdlib.h>
 
 #ifdef HAVE_UNISTD_H
-#ifndef _XOPEN_SOURCE
-#define _XOPEN_SOURCE /* Required for snprinf on GNU */
-#endif
 #define __EXTENSIONS__ /* Solaris fix */
 #include <unistd.h>
 #endif
