--- src/gdevdmpr.c.orig	Tue May 13 20:43:37 1997
+++ src/gdevdmpr.c	Sun Nov 10 21:19:41 2002
@@ -41,7 +41,7 @@
 /* include library header. */
 #include "dviprlib.h"
 
-extern FILE *lib_fopen(P1(const char *));
+extern FILE *lib_fopen(const char *);
 
 #define LOCAL_DEBUG 0
 
@@ -87,12 +87,12 @@
 private dev_proc_close_device(gdev_dmprt_close);
 
 /* declarations of sub functions to get printer properties. */
-private void gdev_dmprt_init_printer_props(P1(gx_device_dmprt *));
-private int gdev_dmprt_get_printer_props(P2(gx_device_dmprt *,char *));
-private int gdev_dmprt_check_code_props(P2(byte * ,int ));
-private FILE *gdev_dmprt_dviprt_lib_fopen(P2(const char *,char *));
+private void gdev_dmprt_init_printer_props(gx_device_dmprt *);
+private int gdev_dmprt_get_printer_props(gx_device_dmprt *,char *);
+private int gdev_dmprt_check_code_props(byte * ,int );
+private FILE *gdev_dmprt_dviprt_lib_fopen(const char *,char *);
 
-private int gdev_dmprt_error_no_dviprt_to_gs(P1(int ));
+private int gdev_dmprt_error_no_dviprt_to_gs(int );
 
 /* The device descriptor */
 gx_device_procs prn_dmprt_procs = {
@@ -846,7 +846,7 @@
     if (env) {
       strcpy(fname,env);
       strcat(fname,
-        gp_file_name_concat_string(env,strlen(env),fname,strlen(fnamebase)));
+        gp_file_name_concat_string(env,strlen(env)));
       strcat(fname,fnamebase);
       fp = fopen(fname,gp_fmode_rb);
     }
