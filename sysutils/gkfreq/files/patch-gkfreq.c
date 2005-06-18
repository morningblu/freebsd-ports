Index: gkfreq.c
diff -u -p gkfreq.c.orig gkfreq.c
--- gkfreq.c.orig	Wed Jun  8 01:42:00 2005
+++ gkfreq.c	Fri Jun 17 01:06:15 2005
@@ -9,6 +9,9 @@
 #include <sys/time.h>
 #include <string.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#endif
 
 #define	CONFIG_NAME	"gkfreq"
 #define	STYLE_NAME	"gkfreq"
@@ -17,6 +20,10 @@ static GkrellmMonitor	*monitor;
 static GkrellmPanel	*panel;
 static GkrellmDecal	*decal_text1;
 static gint	style_id;
+#ifdef __FreeBSD__
+static int	oid_freq[CTL_MAXNAME + 2];
+static size_t	oid_freq_len = 0;
+#endif
 
 
 __inline__ unsigned long long int rdtsc()
@@ -31,6 +38,16 @@ __inline__ unsigned long long int rdtsc(
 static
 void read_MHz(char* buffer_, size_t bufsz_)
 {
+#ifdef __FreeBSD__
+	int freq;
+	int len = sizeof(freq);
+
+	if (oid_freq_len <= 0 ||
+	    sysctl(oid_freq, oid_freq_len, &freq, &len, 0, 0) < 0)
+		snprintf(buffer_, bufsz_, "n/a MHz");
+	else
+		snprintf(buffer_, bufsz_, "%d MHz", freq);
+#else
    FILE *f;
    if ( (f = fopen("/sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq", "r")) == NULL) {
        /* this can happen if the the scaling is built as a module but it aint
@@ -44,6 +61,7 @@ void read_MHz(char* buffer_, size_t bufs
        snprintf(buffer_, bufsz_, "%d MHz", i/1000 );
        fclose(f);
    }
+#endif
 }
 
 static gint
@@ -106,6 +124,12 @@ create_plugin(GtkWidget *vbox, gint firs
 	if (first_create)
 	    g_signal_connect(G_OBJECT (panel->drawing_area), "expose_event",
     	        G_CALLBACK (panel_expose_event), NULL);
+
+#ifdef __FreeBSD__
+	oid_freq_len = sizeof(oid_freq);
+	if (sysctlnametomib("dev.cpu.0.freq", oid_freq, &oid_freq_len) < 0)
+		oid_freq_len = 0;
+#endif
 }
 
 
