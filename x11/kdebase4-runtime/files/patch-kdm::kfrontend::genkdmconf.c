--- kdm/kfrontend/genkdmconf.c.orig	Mon Nov  5 21:40:03 2001
+++ kdm/kfrontend/genkdmconf.c	Sun Dec  9 22:42:26 2001
@@ -212,7 +212,7 @@
  */
 
 #ifndef HALT_CMD
-# ifdef BSD
+# if defined(BSD) || defined(__FreeBSD__)
 #  define HALT_CMD	"/sbin/shutdown -h now"
 #  define REBOOT_CMD	"/sbin/shutdown -r now"
 # elif defined(__SVR4)
@@ -1606,7 +1606,7 @@
 #endif
 "\n"
 "#exec sessreg -a -l $DISPLAY "
-#ifdef BSD
+#if defined(BSD) || defined(__FreeBSD__)
 "-x " KDMCONF "/Xservers "
 #endif
 "$USER\n"
@@ -1628,7 +1628,7 @@
 #endif
 "\n"
 "#exec sessreg -d -l $DISPLAY "
-#ifdef BSD
+#if defined(BSD) || defined(__FreeBSD__)
 "-x " KDMCONF "/Xservers "
 #endif
 "$USER\n"
@@ -1781,7 +1781,7 @@
     }
     addKdePath ("UserPath", DEF_USER_PATH);
     addKdePath ("SystemPath", DEF_SYSTEM_PATH);
-    ASPrintf (&newkdmrc, "%s/kdmrc", newdir);
+    ASPrintf (&newkdmrc, "%s/kdmrc.dist", newdir);
     f = Create (newkdmrc, kdmrcmode);
     wrconf (f);
     fclose (f);
