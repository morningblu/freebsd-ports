--- gdb/config/nm-fbsd.h	Wed Dec 31 16:00:00 1969
+++ gdb/config/nm-fbsd.h	Sun Oct 13 10:53:14 2002
@@ -0,0 +1,31 @@
+#ifndef CONFIG_NM_FBSD_H
+#define CONFIG_NM_FBSD_H
+
+extern int kernel_debugging;
+extern int kernel_writablecore;
+
+CORE_ADDR fbsd_kern_frame_saved_pc(struct frame_info *frame);
+
+#define ADDITIONAL_OPTIONS \
+       {"kernel", no_argument, &kernel_debugging, 1}, \
+       {"k", no_argument, &kernel_debugging, 1}, \
+       {"wcore", no_argument, &kernel_writablecore, 1}, \
+       {"w", no_argument, &kernel_writablecore, 1},
+
+#define ADDITIONAL_OPTION_HELP \
+       "\
+  --kernel           Enable kernel debugging.\n\
+  --wcore            Make core file writable (only works for /dev/mem).\n\
+                     This option only works while debugging a kernel !!\n\
+"
+
+#define DEFAULT_PROMPT kernel_debugging?"(kgdb) ":"(gdb) "
+
+/* misuse START_PROGRESS to test whether we're running as kgdb */   
+/* START_PROGRESS is called at the top of main */
+#undef START_PROGRESS
+#define START_PROGRESS(STR,N) \
+  if (!strcmp (STR, "kgdb")) \
+     kernel_debugging = 1;
+
+#endif /* CONFIG_NM_FBSD_H */
